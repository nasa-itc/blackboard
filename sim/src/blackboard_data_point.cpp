#include <ItcLogger/Logger.hpp>
#include <blackboard_data_point.hpp>

namespace Nos3
{
    extern ItcLogger::Logger *sim_logger;

    BlackboardDataPoint::BlackboardDataPoint(int16_t spacecraft, const boost::shared_ptr<Sim42DataPoint> dp) : _dp(*dp), _sc(spacecraft), _not_parsed(true)
    {
        sim_logger->trace("BlackboardDataPoint::BlackboardDataPoint:  42 Constructor executed");

        /* Initialize data */
    }
    
    void BlackboardDataPoint::do_parsing(void) const
    {
        try {
            /*
            ** Declare 42 telemetry string prefix
            ** 42 variables defined in `42/Include/42types.h`
            ** 42 data stream defined in `42/Source/IPC/SimWriteToSocket.c`
            */
            std::string key;
            key.append("SC[").append(std::to_string(_sc)).append("].svb"); // SC[N].svb

            /* Parse 42 telemetry */
            std::string values = _dp.get_value_for_key(key);

            std::vector<double> data;
            data.reserve(3);
            parse_double_vector(values, data);

            _not_parsed = false;

            /* Debug print */
            sim_logger->trace("BlackboardDataPoint::BlackboardDataPoint:  Parsed svb = ");
        } catch (const std::exception &e) {
            sim_logger->error("BlackboardDataPoint::BlackboardDataPoint:  Error parsing svb.  Error=%s", e.what());
        }
    }

    /* Used for printing a representation of the data point */
    std::string BlackboardDataPoint::to_string(void) const
    {
        sim_logger->trace("BlackboardDataPoint::to_string:  Executed");
        
        std::stringstream ss;

        ss << std::fixed << std::setfill(' ');
        ss << "Blackboard Data Point: ";
        ss << std::setprecision(std::numeric_limits<double>::digits10); /* Full double precision */
        ss << " Blackboard Data: ";

        return ss.str();
    }
} /* namespace Nos3 */
