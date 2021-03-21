#pragma once
#include <string.h>
#include <stdint.h>
#include "Arduino.h"

#pragma pack(push,1)

// @Parseclass
class BMS_onboard_temperatures {
public:
    BMS_onboard_temperatures() = default;
    BMS_onboard_temperatures(uint8_t buf[]) { load(buf); }
    BMS_onboard_temperatures(int16_t average_temperature, int16_t low_temperature, int16_t high_temperature) {
        set_average_temperature(average_temperature);
        set_low_temperature(low_temperature);
        set_high_temperature(high_temperature);
    }

    inline void load(uint8_t buf[])         { memcpy(this, buf, sizeof(*this)); }
    inline void write(uint8_t buf[])  const { memcpy(buf, this, sizeof(*this)); }

    inline int16_t get_average_temperature()    const { return average_temperature; }
    inline int16_t get_low_temperature()        const { return low_temperature; }
    inline int16_t get_high_temperature()       const { return high_temperature; }

    inline void set_average_temperature(int16_t average_temperature)    { this->average_temperature = average_temperature; }
    inline void set_low_temperature(int16_t low_temperature)            { this->low_temperature = low_temperature; }
    inline void set_high_temperature(int16_t high_temperature)          { this->high_temperature = high_temperature; }

    void print() {
        Serial.println("\n\nBMS ONBOARD TEMPERATURES");
        Serial.println    ("------------------------");
        Serial.print("AVERAGE TEMPERATURE: ");  Serial.println(average_temperature / 100., 2);
        Serial.print("LOW TEMPERATURE:     ");  Serial.println(low_temperature / 100., 2);
        Serial.print("HIGH TEMPERATURE:    ");  Serial.println(high_temperature / 100., 2);
    }

private:
    int16_t average_temperature;    // @Parse @Scale(100) @Unit(C)
    int16_t low_temperature;        // @Parse @Scale(100) @Unit(C)
    int16_t high_temperature;       // @Parse @Scale(100) @Unit(C)
};

#pragma pack(pop)