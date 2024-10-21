#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp4921_spi {

class MCP4921SPI : public number::Number,
                       public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING,
                                            spi::DATA_RATE_1KHZ> {
 public:
  void setup() override;  // Nur Deklaration hier
  void write_value(float value);
  void dump_config() override;

 protected:
  void on_value(float value) override;

 private:
  void set_traits();  // Nur Deklaration hier

};

}  // namespace mcp4921_spi
}  // namespace esphome