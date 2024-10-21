#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp4921_spi {

class MCP4921SPI : public sensor::Sensor,
                       public PollingComponent,
                       public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING,
                                            spi::DATA_RATE_1KHZ> {
 public:
  void setup() override;
  void update() override;
  void loop() override;
  void dump_config() override;


  // Traits for the number component
  void set_traits() {
    this->traits.set_min_value(0.0f);
    this->traits.set_max_value(4095.0f);
    this->traits.set_step(1.0f);
    this->traits.set_mode(number::NUMBER_MODE_SLIDER);  // Set default mode
    this->traits.set_unit_of_measurement("V");  // Set unit
    this->traits.set_device_class("voltage");  // Set device class
  }

  void on_enable() override {
    this->set_traits();  // Set traits when enabled
  }

};

}  // namespace mcp4921_spi
}  // namespace esphome