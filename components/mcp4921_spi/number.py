# mcp4921_spi
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components.number import number
from esphome.components import spi


DEPENDENCIES = ["spi"]
# Definiere ein Namespace für die MCP4921-Komponente

mcp4921_spi_ns = cg.esphome_ns.namespace("mcp4921_spi")
MCP4921SPIComponent = mcp4921_spi_ns.class_(
    "MCP4921SPI", number, cg.Component, spi.SPIDevice
)


# Define the configuration schema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(MCP4921SPIComponent),
    cv.Required('name'): cv.string,
    cv.Optional('min_value', default=0.0): cv.float_,
    cv.Optional('max_value', default=4095.0): cv.float_,
}).extend(spi.spi_device_schema()).extend(Number.SCHEMA)

# Define the setup function
async def to_code(config):
    var = cg.new_Pvariable(config[CONF_MCP4921_SPI])
    await cg.register_component(var, config)
    
    # Set the name
    cg.add(var.set_name(config['name']))
    
    # Set min and max values
    cg.add(var.set_min_value(config['min_value']))
    cg.add(var.set_max_value(config['max_value']))
