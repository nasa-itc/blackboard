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
        double get_svb_x(void) {parse_data_point(); return _svb[0];}
        double get_svb_y(void) {parse_data_point(); return _svb[1];}
        double get_svb_z(void) {parse_data_point(); return _svb[2];}
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
        double _svb[3];
    };
}

#endif
