# mcp4921_spi
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import spi, number
from esphome.const import (
    CONF_ID, CONF_NAME, CONF_MIN_VALUE, CONF_MAX_VALUE, CONF_STEP, 
    CONF_MODE, CONF_DISABLED_BY_DEFAULT, CONF_DEVICE_CLASS, CONF_UNIT_OF_MEASUREMENT
)

# Import number modes (AUTO, SLIDER, BOX, etc.)
NumberMode = number.number.NumberMode


DEPENDENCIES = ["spi"]
# Definiere ein Namespace für die MCP4921-Komponente

mcp4921_spi_ns = cg.esphome_ns.namespace("mcp4921_spi")
MCP4921SPIComponent = mcp4921_spi_ns.class_(
    "MCP4921SPI", number.Number, cg.Component, spi.SPIDevice
)

# Konfigurationsschema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(MCP4921SPIComponent),
    cv.Required(CONF_NAME): cv.string,  # Name is required for the number component
    cv.Optional(CONF_MIN_VALUE, default=0): cv.float_,   # Minimum für den DAC-Wert
    cv.Optional(CONF_MAX_VALUE, default=4095): cv.float_, # Maximum für den DAC-Wert
    cv.Optional(CONF_STEP, default=1): cv.float_,        # Schrittweite für die Anpassung
    cv.Optional(CONF_MODE, default="AUTO"): cv.enum({
        "AUTO": NumberMode.NUMBER_MODE_AUTO,
        "SLIDER": NumberMode.NUMBER_MODE_SLIDER,
        "BOX": NumberMode.NUMBER_MODE_BOX,
    }),  # Optional mode for number component
    cv.Optional(CONF_DEVICE_CLASS, default=None): cv.string,  # Optional device class
    cv.Optional(CONF_UNIT_OF_MEASUREMENT, default=None): cv.string,  # Optional unit of measurement    
    cv.Optional(CONF_DISABLED_BY_DEFAULT, default=False): cv.boolean,  # Optional, default is False
    

}).extend(cv.COMPONENT_SCHEMA).extend(spi.spi_device_schema()) 


async def to_code(config):  # async Funktion verwenden
    var = cg.new_Pvariable(config[CONF_ID])
    cg.add(var.set_name(config[CONF_NAME]))  # Set the name of the number component
    cg.add(var.set_min_value(config[CONF_MIN_VALUE]))
    cg.add(var.set_max_value(config[CONF_MAX_VALUE]))
    cg.add(var.set_step(config[CONF_STEP]))
    cg.add(var.traits.set_mode(config[CONF_MODE]))

    # Handle disabled_by_default if present
    if CONF_DISABLED_BY_DEFAULT in config:
        cg.add(var.set_disabled_by_default(config[CONF_DISABLED_BY_DEFAULT]))

    # Set device class if specified
    if CONF_DEVICE_CLASS in config:
        cg.add(var.set_device_class(config[CONF_DEVICE_CLASS]))

    # Set unit of measurement if specified
    if CONF_UNIT_OF_MEASUREMENT in config:
        cg.add(var.set_unit_of_measurement(config[CONF_UNIT_OF_MEASUREMENT]))

    # SPI Konfiguration
    await cg.register_component(var, config)  # await hinzufügen
    await number.register_number(
        var, 
        config, 
        min_value=config[CONF_MIN_VALUE], 
        max_value=config[CONF_MAX_VALUE], 
        step=config[CONF_STEP]
    )

