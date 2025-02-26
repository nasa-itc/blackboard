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
            std::string values;
            std::vector<double> data;
            data.reserve(6);

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].svb"); // SC[N].svb
            parse_double_vector(_dp.get_value_for_key(key), data);
            _svb[0] = data[0];
            _svb[1] = data[1];
            _svb[2] = data[2];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].bvb"); // SC[N].bvb
            parse_double_vector(_dp.get_value_for_key(key), data);
            _bvb[0] = data[0];
            _bvb[1] = data[1];
            _bvb[2] = data[2];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].Hvb"); // SC[N].Hvb
            parse_double_vector(_dp.get_value_for_key(key), data);
            _Hvb[0] = data[0];
            _Hvb[1] = data[1];
            _Hvb[2] = data[2];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Gyro[0].Rate"); // SC[N].AC.Gyro[0].Rate
            _GyroRate[0] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Gyro[1].Rate"); // SC[N].AC.Gyro[1].Rate
            _GyroRate[1] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Gyro[2].Rate"); // SC[N].AC.Gyro[2].Rate
            _GyroRate[2] = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[0].Valid"); // SC[N].AC.CSS[0].Valid
            _CSSValid[0] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[1].Valid"); // SC[N].AC.CSS[1].Valid
            _CSSValid[1] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[2].Valid"); // SC[N].AC.CSS[2].Valid
            _CSSValid[2] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[3].Valid"); // SC[N].AC.CSS[3].Valid
            _CSSValid[3] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[4].Valid"); // SC[N].AC.CSS[4].Valid
            _CSSValid[4] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[5].Valid"); // SC[N].AC.CSS[5].Valid
            _CSSValid[5] = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[0].Illum"); // SC[N].AC.CSS[0].Illum
            _CSSIllum[0] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[1].Illum"); // SC[N].AC.CSS[1].Illum
            _CSSIllum[1] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[2].Illum"); // SC[N].AC.CSS[2].Illum
            _CSSIllum[2] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[3].Illum"); // SC[N].AC.CSS[3].Illum
            _CSSIllum[3] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[4].Illum"); // SC[N].AC.CSS[4].Illum
            _CSSIllum[4] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.CSS[5].Illum"); // SC[N].AC.CSS[5].Illum
            _CSSIllum[5] = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.FSS[0].Valid"); // SC[N].AC.FSS[0].Valid
            _FSSValid = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.FSS[0].SunAng"); // SC[N].AC.FSS[0].SunAng
            parse_double_vector(_dp.get_value_for_key(key), data);
            _FSSSunAng[0] = data[0];
            _FSSSunAng[1] = data[1];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.ST[0].Valid"); // SC[N].AC.ST[0].Valid
            _STValid = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.ST[0].qn"); // SC[N].AC.ST[0].qn
            parse_double_vector(_dp.get_value_for_key(key), data);
            _STqn[0] = data[0];
            _STqn[1] = data[1];
            _STqn[2] = data[2];
            _STqn[3] = data[3];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.GPS[0].PosN"); // SC[N].AC.GPS[0].PosN
            parse_double_vector(_dp.get_value_for_key(key), data);
            _GPSPosN[0] = data[0];
            _GPSPosN[1] = data[1];
            _GPSPosN[2] = data[2];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.GPS[0].VelN"); // SC[N].AC.GPS[0].VelN
            parse_double_vector(_dp.get_value_for_key(key), data);
            _GPSVelN[0] = data[0];
            _GPSVelN[1] = data[1];
            _GPSVelN[2] = data[2];

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Accel[0].Acc"); // SC[N].AC.Accel[0].Acc
            _AccelAcc[0] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Accel[1].Acc"); // SC[N].AC.Accel[1].Acc
            _AccelAcc[1] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Accel[2].Acc"); // SC[N].AC.Accel[2].Acc
            _AccelAcc[2] = std::stof(_dp.get_value_for_key(key));

            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Whl[0].H"); // SC[N].AC.Whl[0].H
            _WhlH[0] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Whl[1].H"); // SC[N].AC.Whl[1].H
            _WhlH[1] = std::stof(_dp.get_value_for_key(key));
            key = "";
            key.append("SC[").append(std::to_string(_sc)).append("].AC.Whl[2].H"); // SC[N].AC.Whl[2].H
            _WhlH[2] = std::stof(_dp.get_value_for_key(key));


            _not_parsed = false;

            /* Debug print */
            sim_logger->trace("BlackboardDataPoint::BlackboardDataPoint:  Parsed point = ");
        } catch (const std::exception &e) {
            if (get_lines().size() > 0) {
                sim_logger->error("BlackboardDataPoint::BlackboardDataPoint:  Error parsing point.  Error=%s.  Data=%s", e.what(), to_string().c_str());
            }
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
        std::vector<std::string> lines = get_lines();
        for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++) {
            ss << *it;
        }

        return ss.str();
    }
} /* namespace Nos3 */
