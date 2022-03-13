# ------------------------------------------------------------------------
# Author     : Jiabin Hsu  | zsiothsu@zhishan-iot.tk
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2022-03-13
# Description: compile parametes define
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : CMake
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc90.html
# Project    : HML_FwLib_STC90
# Version    : v0.0.2
# ------------------------------------------------------------------------

# Init variables
set(MCU_MODEL "")
set(CODE_SIZE 0)
set(XRAM_SIZE 0)

# [CLKFRE] frequency of MCU clock
if(CLKFRE MATCHES "^[0-9]+$")
    set(CLOCK_FREQUENCY ${CLKFRE})
else()
    message(FATAL_ERROR "invalid CLKFRE value")
endif()

#  [PRESCALER] Specify MCU prescaler factor, the value must be 6(6T mode) or
#    12(12T mode).
if(NOT DEFINED PRESCALER)
    set(PRESCALER_FACTOR 12)
elseif(${PRESCALER} STREQUAL 12)
    set(PRESCALER_FACTOR 12)
elseif(${PRESCALER} STREQUAL 6)
    set(PRESCALER_FACTOR 6)
else()
    message(FATAL_ERROR "invalid PRESCALER value, the value must be 6 or 12!")
endif()

# [MCU] MCU model
#   Default value of CODE and XRAM is ruled by MCU model. However, if user
#   specify them manually, value of related variables will be overridden.
if(DEFINED MCU)
    string(TOUPPER ${MCU} MCU_MODEL)
    if(${MCU_MODEL} STREQUAL STC90C51)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC90LE51)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC90C52)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC90LE52)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 0)
    elseif(${MCU_MODEL} STREQUAL STC90C51RC)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90LE51RC)
        set(CODE_SIZE 4096)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90C52RC)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90LE52RC)
        set(CODE_SIZE 8192)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90C53RC)
        set(CODE_SIZE 13312)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90LE53RC)
        set(CODE_SIZE 13312)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90C12RC)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90LE12RC)
        set(CODE_SIZE 12288)
        set(XRAM_SIZE 256)
    elseif(${MCU_MODEL} STREQUAL STC90C54RD+)
        set(CODE_SIZE 16384)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE54RD+)
        set(CODE_SIZE 16384)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90C58RD+)
        set(CODE_SIZE 32768)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE58RD+)
        set(CODE_SIZE 32768)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90C510RD+)
        set(CODE_SIZE 40960)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE510RD+)
        set(CODE_SIZE 40960)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90C512RD+)
        set(CODE_SIZE 49152)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE512RD+)
        set(CODE_SIZE 49152)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90C514RD+)
        set(CODE_SIZE 57344)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE514RD+)
        set(CODE_SIZE 57344)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90C516RD+)
        set(CODE_SIZE 62464)
        set(XRAM_SIZE 1024)
    elseif(${MCU_MODEL} STREQUAL STC90LE516RD+)
        set(CODE_SIZE 62464)
        set(XRAM_SIZE 1024)
    else()
        message(FATAL_ERROR "unknow MCU model: ${MCU}")
    endif()
else()
    message(FATAL_ERROR "user must specify MCU model")
endif()
# replace "+" in muc module to "P"
# example, replace STC90LE516RD+ to STC90LE516RDP
string(REPLACE "+" "P" MCU_MACRO "${MCU_MODEL}")

# [CODE] internal ROM
if(DEFINED CODE)
    math(EXPR CODE_SIZE "${CODE} * 1024")
endif()

# [IRAM] internal RAM
# for stc90, this value is fixed to 256
set(IRAM_SIZE 256)

# [XRAM] external RAM
if(DEFINED XRAM)
    math(EXPR XRAM_SIZE "${XRAM} * 1024")
endif()

# Compile parameters define
add_compile_options(
   --std-sdcc99
   --fsigned-char
   --opt-code-size
   "SHELL: --code-loc 0x0000 --code-size ${CODE_SIZE}"
   "SHELL: --iram-size ${IRAM_SIZE}"
   "SHELL: --xram-size ${XRAM_SIZE}"
)
add_definitions(
    -D__CONF_FRE_CLKIN=${CLOCK_FREQUENCY}UL
    -D__CONF_MCU_MODEL=MCU_MODEL_${MCU_MACRO}
    -D__CONF_MCU_PRESCALER=${PRESCALER_FACTOR}
)

# Print config information
message("model    : ${MCU_MODEL}")
message("memory   : code=${CODE_SIZE}B, iram=${IRAM_SIZE}B, xram=${XRAM_SIZE}B")
message("clock    : ${CLOCK_FREQUENCY}Hz")
message("prescaler: ${PRESCALER_FACTOR}T mode")
