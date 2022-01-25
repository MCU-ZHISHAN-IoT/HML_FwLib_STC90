# HML_FwLib_STC90
[![Jenkins](https://img.shields.io/jenkins/build?jobUrl=http%3A%2F%2Fjenkins.zhishan-iot.tk%3A12463%2Fjob%2FHML_FwLib_STC90)](http://jenkins.zhishan-iot.tk:12463/job/HML_FwLib_STC90)
[![GitHub repo size](https://img.shields.io/github/repo-size/MCU-ZHISHAN-IoT/HML_FwLib_STC90)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC90)
[![GitHub](https://img.shields.io/github/license/MCU-ZHISHAN-IoT/HML_FwLib_STC90)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC90/blob/master/LICENSE)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/MCU-ZHISHAN-IoT/HML_FwLib_STC90?color=26a69a)](https://github.com/MCU-ZHISHAN-IoT/HML_FwLib_STC90/tags)
## What is HML_FwLib_STC90
HML_FwLib_STC90 is a member component of HML firmware library, **providing a group of interface functions for users to operate 
on-chip resource of STC90 MCUs**, including GPIO, ISP, timer, UART, external interrupt and watchdog. The STC90 MCU is a kind of
Intel MCS-51 based MCU which released by [STC Micro](http://www.stcmcu.com/)(*宏晶*). This series MCU have more on-chip resource 
than classical 8051 MCU.

We intend to provide a lite and easy-use firmware library that can help future developers to complete projects based on STC90 
MCUs more easily and quickly. All source codes are written in C language and for [SDCC compiler](http://sdcc.sourceforge.net/),
i.e., it can only be compiled by SDCC. This choice is motivated by the fact that SDCC is free and highly efficient, while there
are very few examples of application about SDCC on the Internet. We hope that, as one of the early attempts to develop MCU 
projects using SDCC, this work will make SDCC become more popular among MCU developers.

Please visit [detail page](https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc90.html) for more information to get started it!

## Feature
+ :dart:Based on [SDCC compiler](http://sdcc.sourceforge.net/).
+ Cover all on-chip resource of STC90 series MCUs.
+ Open all source code on [Github](https://github.com) and licensed under the [WTPL2](http://wtfpl2.com/).
+ Readable code and provide examples to help you get started it.

## What's working
Here is a list of the all on-chip peripheral drivers and examples that need to be ported.

| Peripheral | Description | Status |
| --- | --- | --- |
| ADC | analog-to-digital Converter | plan |
| extended bus | Intel 8080 bus receiver/transmitter | supported |
| EXTI | extern interrupt | supported |
| GPIO | I/O peripheral | supported  |
| ISP | internal EEPROM | supported  |
| RST | reset control | supported |
| TIM | timer | supported |
| UART | universal asynchronous receiver/transmitter | supported |
| WDT | watchdog | supported |

## Config
There are several parameters with compile macro format need to be configured by user manually. They are all defined in 
*hml/conf.h*.
### \_\_CONF\_COMPILE\_xxx (for conditional compilation)
In order to ensure the projects based on HML_FwLib_STC90 can be downloaded into the limited on-chip flash space of STC90 MCUs,
the developers can modify value of the macro definition named `__CONF_COMPILE_xxx` in *hml/conf.h* as `1` to specify which piece 
of code will take part in compilation, then it will reduce size of final .hex file. If user only use GPIO module, then user just 
need to enable `__CONF_COMPILE_GPIO` macro in *hml/conf.h*. Some macros for conditional compilation rely on others. For example, 
before you enable the macro definition `__CONF_COMPILE_UART`, the macro `__CONF_COMPILE_TIM` and `__CONF_COMPILE_TIM2` should be 
enabled, otherwise the compilation would be failed.
###  \_\_CONF\_FRE\_CLKIN
This macro marks frequency of clock source, including extern crystal oscillator or internal RC oscillating circuit, and it's 
defined in *conf.h*.
### \_\_CONF\_MCU\_MODEL
This macro marks the model of target MCU and is defined in *hml/conf.h*.

## Building
We provide two kinds of build system support:
* cmake
* gmake

### cmake
Run this command for initialization. Add option `-GNinja` if you expect to build project via Ninja.
```
$ cmake -S . -B build
```
Run this command for building project. Add option `--clean-first` if you want to execute clean operation before building.
```
$ cmake --build build -j$(nproc)
```
You can execute command `cmake --build build -t usage` for usage. If you want to adjust build details, please modify `cmake/config.cmake`.

### gmake
There is a source file named *test.c* under *usr* directory, we have put a main function here. Execute this command for building HML_FwLib_STC90 with GNU Make.
```
$ make -j$(nproc)
```
You can execute command `make help` for usage. If you want to adjust build details, please modify `mk/config.mk`.

## Contributing
Welcome suggestions and contribution from you! You can fork it or contact us via *[mcu@zhishan-iot.tk](mailto:mcu@zhishan-iot.tk)*.

## License
HML_FwLib_STC90 is licensed under the [WTFPL2](http://wtfpl2.com/).

##  Team

|member        | role              |e-mail                        |
|--------------|-------------------|------------------------------|
| Amy Chung    | Testing           |[zhongliguo@zhishan-iot.tk](mailto:zhongliguo@zhishan-iot.tk) |
| Jiabin Hsu   | MCU developer     |[zsiothsu@zhishan-iot.tk](mailto:zsiothsu@zhishan-iot.tk) |
| Weilun Fong  | **Director**      |[wlf@zhishan-iot.tk](mailto:wlf@zhishan-iot.tk) |
