import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import spi, number
from esphome.const import CONF_ID, CONF_MIN_VALUE, CONF_MAX_VALUE, CONF_STEP

DEPENDENCIES = ["spi"]
# Definiere ein Namespace für die MCP4921-Komponente

mcp4921_spi_ns = cg.esphome_ns.namespace("mcp4921_spi")
MCP4921SPIComponent = mcp4921_spi_ns.class_(
    "MCP4921SPI", number.Number, cg.Component, spi.SPIDevice
)

# Konfigurationsschema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(MCP4921SPIComponent),
    cv.Optional(CONF_MIN_VALUE, default=0): cv.float_,   # Minimum für den DAC-Wert
    cv.Optional(CONF_MAX_VALUE, default=4095): cv.float_, # Maximum für den DAC-Wert
    cv.Optional(CONF_STEP, default=1): cv.float_,        # Schrittweite für die Anpassung
}).extend(cv.COMPONENT_SCHEMA).extend(spi.SPI_DEVICE_SCHEMA)


# Code-Generierung
def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    cg.add(var.set_min_value(config[CONF_MIN_VALUE]))
    cg.add(var.set_max_value(config[CONF_MAX_VALUE]))
    cg.add(var.set_step(config[CONF_STEP]))

    # SPI Konfiguration
    cg.add(var.set_spi_pins())
    cg.register_component(var, config)
    number.register_number(var, config)

