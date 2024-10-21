#include "esphome/core/log.h"
#include "mcp4921_spi.h"

namespace esphome {
namespace mcp4921_spi {

static const char *TAG = "mcp4921_spi";

void MCP4921SPI::setup() {
    ESP_LOGI(TAG, "MCP4921SPI setup started!");
    this->spi_setup();
    ESP_LOGI(TAG, "SPI setup finished!");
    this->set_traits();
}

void MCP4921SPI::write_value(float value) {
  // Code, um den Wert an den MCP4921 DAC über SPI zu senden
}

void MCP4921SPI::dump_config(){
    ESP_LOGCONFIG(TAG, "Empty SPI sensor");
}

void MCP4921SPI::on_value(float value) {
  write_value(value);  // Schreibe den Wert an den DAC
}

void MCP4921SPI::set_traits() {
  this->traits.set_min_value(0.0f);
  this->traits.set_max_value(4095.0f);
  this->traits.set_step(1.0f);
  this->traits.set_mode(number::NUMBER_MODE_SLIDER);  // Setze den Modus
  this->traits.set_unit_of_measurement("V");  // Setze die Einheit
  this->traits.set_device_class("voltage");  // Setze die Geräteklasse
}


}  // namespace mcp4921_spi
}  // namespace esphome