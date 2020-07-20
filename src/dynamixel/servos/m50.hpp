#ifndef DYNAMIXEL_SERVOS_M50_HPP_
#define DYNAMIXEL_SERVOS_M50_HPP_

#include <stdint.h>

#include "servo.hpp"
#include "../protocols/protocol2.hpp"

namespace dynamixel {
    namespace servos {
        class M50;

        template <>
        struct ModelTraits<M50> {
            typedef protocols::Protocol2 protocol_t;

            struct CT {
                static const protocol_t::address_t model_number = 0;
                typedef uint16_t model_number_t;
                static const model_number_t model_number_value = 0x3201;
                static const protocol_t::address_t firmware_version = 2;
                typedef uint8_t firmware_version_t;
                static const protocol_t::address_t id = 3;
                typedef protocol_t::id_t id_t;
                static const protocol_t::address_t baudrate = 4;
                typedef uint8_t baudrate_t;
                static const protocol_t::address_t return_delay_time = 5;
                typedef uint8_t return_delay_time_t;
                static const protocol_t::address_t operating_mode = 6;
                typedef uint8_t operating_mode_t;
                static const protocol_t::address_t cw_angle_limit = 7;
                typedef uint16_t cw_angle_limit_t;
                static const protocol_t::address_t ccw_angle_limit = 9;
                typedef uint16_t ccw_angle_limit_t;

                static const protocol_t::address_t highest_temperature_limit = 11;
                typedef uint8_t highest_temperature_limit_t;
                static const protocol_t::address_t lowest_voltage_limit = 12;
                typedef uint8_t lowest_voltage_limit_t;
                static const protocol_t::address_t highest_voltage_limit = 13;
                typedef uint8_t highest_voltage_limit_t;


                static const protocol_t::address_t torque_limit = 14;
                typedef uint16_t torque_limit_t;


                static const protocol_t::address_t angular_velocity_limit = 16;
                typedef uint16_t angular_velocity_limit_t;
                static const protocol_t::address_t acceleration_limit = 18;
                typedef uint16_t acceleration_limit_t;
                static const protocol_t::address_t home_position_offset = 20;
                typedef uint32_t home_position_offset_t;
                static const protocol_t::address_t moving_threshold = 24;
                typedef uint16_t moving_threshold_t;

                /*
                 * --- unused, but need to be here to prevent compile errors
                 */
                static const protocol_t::address_t status_return_level = 26; // unused
                typedef uint8_t status_return_level_t;
                static const protocol_t::address_t alarm_shutdown = 27;  // unused
                typedef uint8_t alarm_shutdown_t;
                /*
                 * --- end of unused bit
                 */

                // --- ram
                static const protocol_t::address_t torque_enable = 48;
                typedef uint8_t torque_enable_t;

                static const protocol_t::address_t pKd = 50;
                typedef uint16_t pKd_t;

                static const protocol_t::address_t pKi = 52;
                typedef uint16_t pKi_t;

                static const protocol_t::address_t pKp = 54;
                typedef uint16_t pKp_t;

                static const protocol_t::address_t pKff1 = 56;
                typedef uint16_t pKff1_t;
                static const protocol_t::address_t pKff2 = 58;
                typedef uint16_t pKff2_t;

                static const protocol_t::address_t vKi = 60;
                typedef uint16_t vKi_t;
                static const protocol_t::address_t vKp = 62;
                typedef uint16_t vKp_t;

                static const protocol_t::address_t angular_velocity_profile = 68;
                typedef uint16_t angular_velocity_profile_t;
                static const protocol_t::address_t acceleration_velocity_profile = 70;
                typedef uint16_t acceleration_velocity_profile_t;
                static const protocol_t::address_t dead_zone = 72;
                typedef uint16_t dead_zone_t;

                static const protocol_t::address_t goal_position = 78; //  aka target_position
                typedef int32_t goal_position_t;
                static const goal_position_t min_goal_position = -2048;
                static const goal_position_t max_goal_position = 2047;
                static const uint16_t min_goal_angle_deg = 0;
                static const uint16_t max_goal_angle_deg = 360;

                static const protocol_t::address_t moving_speed = 82; // aka target_angular velocity
                typedef uint16_t moving_speed_t;
                static const moving_speed_t min_goal_speed = 0;
                static const moving_speed_t max_goal_speed = 1023;
                static constexpr double rpm_per_tick = 0.111; // TODO: need to work this out 
                static constexpr bool speed_sign_bit = true;

                static const protocol_t::address_t target_torque = 84;
                typedef uint16_t target_torque_t;

                static const protocol_t::address_t present_position = 86; // aka actual position
                typedef int32_t present_position_t;

                static const protocol_t::address_t present_speed = 90;  // aka actual angular velocity
                typedef uint16_t present_speed_t;

                static const protocol_t::address_t present_torque = 92;  // aka actual angular velocity
                typedef uint16_t present_torque_t;

                static const protocol_t::address_t present_voltage = 94;
                typedef uint8_t present_voltage_t;
                static const protocol_t::address_t present_current = 95;
                typedef uint16_t present_current_t;
                static const protocol_t::address_t present_temperature = 97;
                typedef uint8_t present_temperature_t;

                static const protocol_t::address_t moving = 99;
                typedef uint8_t moving_t;

                static const protocol_t::address_t registered = 101; // aka registered shadow instruction
                typedef uint8_t registered_t;

            };
        };

        class M50 : public Servo<M50> {
        public:
            typedef M50 Model;

            M50(typename protocol_t::id_t id) : Servo<M50>(id){};

            MODEL_NAME(M50);

            // Here we add the fields that are not common to all dynamixels
            READ_WRITE_FIELD(operating_mode);
            READ_WRITE_FIELD(cw_angle_limit);
            READ_WRITE_FIELD(ccw_angle_limit);

            READ_WRITE_FIELD(torque_limit);

            READ_WRITE_FIELD(angular_velocity_limit);
            READ_WRITE_FIELD(acceleration_limit);
            READ_WRITE_FIELD(home_position_offset);

            READ_WRITE_FIELD(pKd);
            READ_WRITE_FIELD(pKi);
            READ_WRITE_FIELD(pKp);

            READ_WRITE_FIELD(pKff1);
            READ_WRITE_FIELD(pKff2);
            READ_WRITE_FIELD(vKi);
            READ_WRITE_FIELD(vKp);

            READ_WRITE_FIELD(angular_velocity_profile);
            READ_WRITE_FIELD(acceleration_velocity_profile);
            READ_WRITE_FIELD(dead_zone);

            READ_WRITE_FIELD(target_torque);
            READ_WRITE_FIELD(present_torque);
        };
    }
}

#endif
