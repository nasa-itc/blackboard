#ifndef NOS3_BLACKBOARDDATAPOINT_HPP
#define NOS3_BLACKBOARDDATAPOINT_HPP

#include <boost/shared_ptr.hpp>
#include <sim_42data_point.hpp>

namespace Nos3
{
    /* Standard for a data point used transfer data between a data provider and a hardware model */
    class BlackboardDataPoint : public Sim42DataPoint
    {
    public:
        /* Constructors */
        BlackboardDataPoint(int16_t spacecraft, const boost::shared_ptr<Sim42DataPoint> dp);

        /* Accessors */
        /* Provide the hardware model a way to get the specific data out of the data point */
        double get_qn_0(void) {parse_data_point(); return _qn[0];}
        double get_qn_1(void) {parse_data_point(); return _qn[1];}
        double get_qn_2(void) {parse_data_point(); return _qn[2];}
        double get_qn_3(void) {parse_data_point(); return _qn[3];}
        double get_wn_x(void) {parse_data_point(); return _wn[0];}
        double get_wn_y(void) {parse_data_point(); return _wn[1];}
        double get_wn_z(void) {parse_data_point(); return _wn[2];}
        double get_svb_x(void) {parse_data_point(); return _svb[0];}
        double get_svb_y(void) {parse_data_point(); return _svb[1];}
        double get_svb_z(void) {parse_data_point(); return _svb[2];}
        double get_bvb_x(void) {parse_data_point(); return _bvb[0];}
        double get_bvb_y(void) {parse_data_point(); return _bvb[1];}
        double get_bvb_z(void) {parse_data_point(); return _bvb[2];}
        double get_Hvb_x(void) {parse_data_point(); return _Hvb[0];}
        double get_Hvb_y(void) {parse_data_point(); return _Hvb[1];}
        double get_Hvb_z(void) {parse_data_point(); return _Hvb[2];}
        double get_WhlH_x(void) {parse_data_point(); return _WhlH[0];}
        double get_WhlH_y(void) {parse_data_point(); return _WhlH[1];}
        double get_WhlH_z(void) {parse_data_point(); return _WhlH[2];}
        double get_GyroRate_x(void) {parse_data_point(); return _GyroRate[0];}
        double get_GyroRate_y(void) {parse_data_point(); return _GyroRate[1];}
        double get_GyroRate_z(void) {parse_data_point(); return _GyroRate[2];}
        double get_MagField_x(void) {parse_data_point(); return _MagField[0];}
        double get_MagField_y(void) {parse_data_point(); return _MagField[1];}
        double get_MagField_z(void) {parse_data_point(); return _MagField[2];}
        double get_CSSValid_0(void) {parse_data_point(); return _CSSValid[0];}
        double get_CSSValid_1(void) {parse_data_point(); return _CSSValid[1];}
        double get_CSSValid_2(void) {parse_data_point(); return _CSSValid[2];}
        double get_CSSValid_3(void) {parse_data_point(); return _CSSValid[3];}
        double get_CSSValid_4(void) {parse_data_point(); return _CSSValid[4];}
        double get_CSSValid_5(void) {parse_data_point(); return _CSSValid[5];}
        double get_CSSIllum_0(void) {parse_data_point(); return _CSSIllum[0];}
        double get_CSSIllum_1(void) {parse_data_point(); return _CSSIllum[1];}
        double get_CSSIllum_2(void) {parse_data_point(); return _CSSIllum[2];}
        double get_CSSIllum_3(void) {parse_data_point(); return _CSSIllum[3];}
        double get_CSSIllum_4(void) {parse_data_point(); return _CSSIllum[4];}
        double get_CSSIllum_5(void) {parse_data_point(); return _CSSIllum[5];}
        double get_FSSValid(void) {parse_data_point(); return _FSSValid;}
        double get_FSSSunAng_alpha(void) {parse_data_point(); return _FSSSunAng[0];}
        double get_FSSSunAng_beta(void) {parse_data_point(); return _FSSSunAng[1];}
        double get_STValid(void) {parse_data_point(); return _STValid;}
        double get_STqn_0(void) {parse_data_point(); return _STqn[0];}
        double get_STqn_1(void) {parse_data_point(); return _STqn[1];}
        double get_STqn_2(void) {parse_data_point(); return _STqn[2];}
        double get_STqn_3(void) {parse_data_point(); return _STqn[3];}
        double get_GPSValid(void) {parse_data_point(); return _GPSValid;}
        double get_GPSRollover(void) {parse_data_point(); return _GPSRollover;}
        double get_GPSWeek(void) {parse_data_point(); return _GPSWeek;}
        double get_GPSSec(void) {parse_data_point(); return _GPSSec;}
        double get_GPSPosN_x(void) {parse_data_point(); return _GPSPosN[0];}
        double get_GPSPosN_y(void) {parse_data_point(); return _GPSPosN[1];}
        double get_GPSPosN_z(void) {parse_data_point(); return _GPSPosN[2];}
        double get_GPSVelN_x(void) {parse_data_point(); return _GPSVelN[0];}
        double get_GPSVelN_y(void) {parse_data_point(); return _GPSVelN[1];}
        double get_GPSVelN_z(void) {parse_data_point(); return _GPSVelN[2];}
        double get_GPSPosW_x(void) {parse_data_point(); return _GPSPosW[0];}
        double get_GPSPosW_y(void) {parse_data_point(); return _GPSPosW[1];}
        double get_GPSPosW_z(void) {parse_data_point(); return _GPSPosW[2];}
        double get_GPSVelW_x(void) {parse_data_point(); return _GPSVelW[0];}
        double get_GPSVelW_y(void) {parse_data_point(); return _GPSVelW[1];}
        double get_GPSVelW_z(void) {parse_data_point(); return _GPSVelW[2];}
        double get_GPSLng(void) {parse_data_point(); return _GPSLng;}
        double get_GPSLat(void) {parse_data_point(); return _GPSLat;}
        double get_GPSAlt(void) {parse_data_point(); return _GPSAlt;}
        double get_AccelAcc_x(void) {parse_data_point(); return _AccelAcc[0];}
        double get_AccelAcc_y(void) {parse_data_point(); return _AccelAcc[1];}
        double get_AccelAcc_z(void) {parse_data_point(); return _AccelAcc[2];}

        std::string to_string(void) const;
    
    private:
        /* Disallow these */
        BlackboardDataPoint(void) {};
        BlackboardDataPoint(const BlackboardDataPoint& sdp) : Sim42DataPoint(sdp) {};
        ~BlackboardDataPoint(void) {};

        // Private mutators
        inline void parse_data_point(void) const {if (_not_parsed) do_parsing();}
        void do_parsing(void) const;

        mutable Sim42DataPoint _dp;
        int16_t _sc;
        // mutable below so parsing can be on demand:
        mutable bool _not_parsed;
        /* Specific data you need to get from the data provider to the hardware model */
        /* You only get to this data through the accessors above */
        mutable double _qn[4];
        mutable double _wn[3];
        mutable double _svb[3];
        mutable double _bvb[3];
        mutable double _Hvb[3];
        mutable double _WhlH[3];
        mutable double _GyroRate[3];
        mutable double _MagField[3];
        mutable int    _CSSValid[6];
        mutable double _CSSIllum[6];
        mutable int    _FSSValid;
        mutable double _FSSSunAng[2];
        mutable int    _STValid;
        mutable double _STqn[4];
        mutable int    _GPSValid;
        mutable int    _GPSRollover;
        mutable int    _GPSWeek;
        mutable double _GPSSec;
        mutable double _GPSPosN[3];
        mutable double _GPSVelN[3];
        mutable double _GPSPosW[3];
        mutable double _GPSVelW[3];
        mutable double _GPSLng;
        mutable double _GPSLat;
        mutable double _GPSAlt;
        mutable double _AccelAcc[3];
    };
}

#endif
