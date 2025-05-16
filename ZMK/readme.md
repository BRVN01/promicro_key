## Arquivos de Configuração da Board no ZMK

| Arquivo | Função |
|------------|-----------|
| `board.cmake` | Arquivo CMake que define como a board será compilada, incluindo dependências e configurações específicas. |
| `pre_dt_board.cmake` | Executado antes do Devicetree (`.dts`) ser processado, permitindo a configuração de variáveis para o compilador. |
| `Kconfig` | Define opções configuráveis no menuconfig (`west build -t menuconfig`). Pode incluir configurações específicas para a placa. |
| `Kconfig.board` | Define informações específicas da board que são integradas ao sistema Kconfig do Zephyr. Permite ativar/desativar features automaticamente. |
| `Kconfig.defconfig` | Define valores padrão para as configurações da board. Esses valores são carregados automaticamente se o usuário não sobrescrever. |
| `macrokeyboard_defconfig` | Arquivo de configuração específico da board, usado pelo Zephyr para definir parâmetros iniciais, como Bluetooth, GPIOs, NVS, etc. |
| `macrokeyboard.dts` | Devicetree Source (DTS): Define o hardware da board, incluindo GPIOs, pinos, periféricos e configurações de teclado (exemplo: `kscan`, `matrix-transform`). |
| `macrokeyboard.keymap` | Define o keymap da board no ZMK, especificando as teclas e suas funções em cada camada (`default_layer`, etc.). |
| `macrokeyboard.layout` | Define o layout físico do teclado, ou seja, como as teclas estão organizadas na matriz (`rows x cols`). |
| `macrokeyboard-pinctrl.dtsi` | Devicetree Include (DTSI): Define a configuração dos pinos (pinctrl), incluindo SPI, I2C, UART, etc. |
| `macrokeyboard.yaml` | Binding YAML usado pelo Devicetree para interpretar as definições da board. Especifica como os nós do DTS devem ser processados. |
| `macrokeyboard.zmk.yml` | Arquivo de configuração do ZMK que define parâmetros globais, como nome BLE (`bluetooth.name`) e outros ajustes. |

```
cd ~/git/zmk/app
rm -r ~/git/zmk/app/boards/arm/macrokeyboard
cp -r macrokeyboard ~/git/zmk/app/boards/arm/

west build -p always -b 'macrokeyboard'

# Colocar a placa em modo bootloader:
west flash

# Erase / Reset

Criar firmware para reset:
west build -p always -b 'macrokeyboard' -- -DSHIELD=settings_reset
```
