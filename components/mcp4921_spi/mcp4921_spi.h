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
};

}  // namespace mcp4921_spi
}  // namespace esphome