/*
 * MC_temperatures_1.cpp - CAN message parser: RMS Motor Controller temperatures 1 message
 * Created by Nathan Cheek, November 22, 2016.
 */

#pragma once
#include <string.h>
#include <cstdint>

#pragma pack(push,1)

class MC_temperatures_1 {
public:
    MC_temperatures_1() = default;
    MC_temperatures_1(uint8_t buf[8]) { load(buf); }

    inline void load(uint8_t buf[]) { memcpy(this, buf, sizeof(*this)); }
    inline void write(uint8_t buf[]) { memcpy(buf, this, sizeof(*this)); }

    inline int16_t get_module_a_temperature() { return module_a_temperature; }
    inline int16_t get_module_b_temperature() { return module_b_temperature; }
    inline int16_t get_module_c_temperature() { return module_c_temperature; }
    inline int16_t get_gate_driver_board_temperature() { return gate_driver_board_temperature; }
private:
    int16_t module_a_temperature;
    int16_t module_b_temperature;
    int16_t module_c_temperature;
    int16_t gate_driver_board_temperature;
} CAN_message_mc_temperatures_1_t;

#pragma pack(pop)