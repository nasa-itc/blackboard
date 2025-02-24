#include <blackboard_hardware_model.hpp>

namespace Nos3
{
    REGISTER_HARDWARE_MODEL(BlackboardHardwareModel,"BLACKBOARD");

    extern ItcLogger::Logger *sim_logger;

    BlackboardHardwareModel::BlackboardHardwareModel(const boost::property_tree::ptree& config) : SimIHardwareModel(config), 
    _enabled(BLACKBOARD_SIM_SUCCESS)
    {
        /* Get the NOS engine connection string */
        std::string connection_string = config.get("common.nos-connection-string", "tcp://127.0.0.1:12001"); 
        sim_logger->info("BlackboardHardwareModel::BlackboardHardwareModel:  NOS Engine connection string: %s.", connection_string.c_str());

        /* Get a data provider */
        std::string dp_name = config.get("simulator.hardware-model.data-provider.type", "BLACKBOARD_PROVIDER");
        _blackboard_dp = SimDataProviderFactory::Instance().Create(dp_name, config);
        sim_logger->info("BlackboardHardwareModel::BlackboardHardwareModel:  Data provider %s created.", dp_name.c_str());

        /* Get on the command bus*/
        std::string time_bus_name = "command";
        if (config.get_child_optional("hardware-model.connections")) 
        {
            /* Loop through the connections for the hardware model */
            BOOST_FOREACH(const boost::property_tree::ptree::value_type &v, config.get_child("hardware-model.connections"))
            {
                /* v.first is the name of the child */
                /* v.second is the child tree */
                if (v.second.get("type", "").compare("time") == 0) // 
                {
                    time_bus_name = v.second.get("bus-name", "command");
                    /* Found it... don't need to go through any more items*/
                    break; 
                }
            }
        }
        _time_bus.reset(new NosEngine::Client::Bus(_hub, connection_string, time_bus_name));
        sim_logger->info("BlackboardHardwareModel::BlackboardHardwareModel:  Now on time bus named %s.", time_bus_name.c_str());

        /* Construction complete */
        sim_logger->info("BlackboardHardwareModel::BlackboardHardwareModel:  Construction complete.");
    }


    BlackboardHardwareModel::~BlackboardHardwareModel(void)
    {        
        /* Clean up the data provider */
        delete _blackboard_dp;
        _blackboard_dp = nullptr;

        /* The bus will clean up the time node */
    }


    /* Automagically set up by the base class to be called */
    void BlackboardHardwareModel::command_callback(NosEngine::Common::Message msg)
    {
        /* Get the data out of the message */
        NosEngine::Common::DataBufferOverlay dbf(const_cast<NosEngine::Utility::Buffer&>(msg.buffer));
        sim_logger->info("BlackboardHardwareModel::command_callback:  Received command: %s.", dbf.data);

        /* Do something with the data */
        std::string command = dbf.data;
        std::string response = "BlackboardHardwareModel::command_callback:  INVALID COMMAND! (Try HELP)";
        boost::to_upper(command);
        if (command.compare("HELP") == 0) 
        {
            response = "BlackboardHardwareModel::command_callback: Valid commands are HELP, ENABLE, DISABLE, STATUS=X, or STOP";
        }
        else if (command.compare(0,6,"ENABLE") == 0) 
        {
            _enabled = BLACKBOARD_SIM_SUCCESS;
            response = "BlackboardHardwareModel::command_callback:  Enabled\n";
        }
        else if (command.compare(0,7,"DISABLE") == 0) 
        {
            _enabled = BLACKBOARD_SIM_ERROR;
            response = "BlackboardHardwareModel::command_callback:  Disabled";
        }
        else if (command.compare(0,4,"STOP") == 0) 
        {
            _keep_running = false;
            response = "BlackboardHardwareModel::command_callback:  Stopping";
        }
        /* TODO: Add anything additional commands here */

        /* Send a reply */
        sim_logger->info("BlackboardHardwareModel::command_callback:  Sending reply: %s", response.c_str());
        _command_node->send_reply_message_async(msg, response.size(), response.c_str());
    }


}
