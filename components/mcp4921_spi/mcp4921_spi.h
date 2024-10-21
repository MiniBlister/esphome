#pragma once

#include "esphome/core/component.h"
#include "esphome/components/number/number.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp4921_spi {

class MCP4921SPI : public number::Number,
                   public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING,
                                        spi::DATA_RATE_1KHZ> {
 public:
  void setup() override;  // Nur Deklaration hier
  void dump_config() override;
  void on_value(float value) override;

 protected:
  void write_value(float value); // Methode zum Schreiben des Wertes an den DAC
  void set_traits();  // Setze die Traits für die Number-Komponente
};

}  // namespace mcp4921_spi
}  // namespace esphome