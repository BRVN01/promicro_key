#
# Copyright (c) 2024 The ZMK Contributors
# SPDX-License-Identifier: MIT
#

# Suprime o aviso sobre endereços de unidade duplicados para power, clock, ACL e controlador de flash.
#
# Copiei isso do 'nice!60' !
#
# https://docs.zephyrproject.org/latest/build/dts/intro-input-output.html

list(APPEND EXTRA_DTC_FLAGS "-Wno-unique_unit_address_if_enabled")