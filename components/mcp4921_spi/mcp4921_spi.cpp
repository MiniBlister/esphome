#include "esphome/core/log.h"
#include "mcp4921_spi.h"

namespace esphome {
namespace mcp4921_spi {

static const char *TAG = "mcp4921_spi";

void MCP4921SPI::setup() {
    ESP_LOGI(TAG, "MCP4921SPI setup started!");
    this->spi_setup();
    ESP_LOGI(TAG, "SPI setup finished!");
    MCP4921SPI::setup();
}

void MCP4921SPI::update() {

}

void MCP4921SPI::loop() {

}

void MCP4921SPI::dump_config(){
    ESP_LOGCONFIG(TAG, "Empty SPI sensor");
    MCP4921SPI::dump_config();
}

}  // namespace mcp4921_spi
}  // namespace esphome