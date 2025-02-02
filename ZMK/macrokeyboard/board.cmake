# Copyright (c) 2021 Nick Winans
# SPDX-License-Identifier: MIT

# Define a subfamília do chip NRF52 para ser usada pelo OpenOCD
set(OPENOCD_NRF5_SUBFAMILY nrf52)

# Define argumentos para o runner "nrfjprog", especificando a família do chip e o tipo de reset
board_runner_args(nrfjprog "--nrf-family=NRF52" "--softreset")

# Inclui suporte para a ferramenta de flashing UF2
include(${ZEPHYR_BASE}/boards/common/uf2.board.cmake)

# Inclui suporte para a ferramenta de flashing "nrfjprog" (oficial da Nordic)
include(${ZEPHYR_BASE}/boards/common/nrfjprog.board.cmake)

# Inclui suporte para OpenOCD (depuração via SWD/JTAG para chips NRF5)
include(${ZEPHYR_BASE}/boards/common/openocd-nrf5.board.cmake)

# Essas configurações garantem que a placa pode ser programada usando UF2, nrfjprog e OpenOCD, dependendo do ambiente de desenvolvimento.