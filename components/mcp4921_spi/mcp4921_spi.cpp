#include "esphome/core/log.h"
#include "mcp4921_spi.h"

namespace esphome {
namespace mcp4921_spi {

static const char *TAG = "mcp4921_spi";

void MCP4921SPI::setup() {
    ESP_LOGI(TAG, "MCP4921SPI setup started!");
    this->spi_setup();  // SPI-Konfiguration
    ESP_LOGI(TAG, "SPI setup finished!");
    this->set_traits();  // Setze die Traits für die Number-Komponente
}

void MCP4921SPI::write_value(float value) {
    // Konvertiere den float-Wert in einen 12-Bit-Wert für den DAC
    uint16_t dac_value = static_cast<uint16_t>(value);
    // Erzeuge das SPI-Datenpaket für den MCP4921
    uint8_t data[2];
    data[0] = 0x30 | ((dac_value >> 8) & 0x0F); // Kommando + obere 4 Bit
    data[1] = dac_value & 0xFF; // untere 8 Bit

    // Sende das Datenpaket über SPI
    this->write(data, sizeof(data));
}

void MCP4921SPI::dump_config() {
    ESP_LOGCONFIG(TAG, "MCP4921SPI Configuration:");
    // Hier kannst du weitere Konfigurationsdetails protokollieren
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