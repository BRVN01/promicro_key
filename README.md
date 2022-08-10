# Macro Keyboard using QMK Firmware

This guide provides a way to create a Keyboard or Macro Keyboard using an **Arduino Pro Micro** and **QMK Firmware**.

Access [the link](https://docs.qmk.fm/#/newbs_getting_started) to understand what QMK is and how to configure your environment.

```bash
# Using the method described by the qmk website, you may see a small error message that 
# you don't want to see, so I rather use the command line below.
$ git clone https://github.com/qmk/qmk_firmware.git && cd qmk_firmware && make git-submodule
```

> This process will take a long time!







2- http://www.keyboard-layout-editor.com/#/gists/deea4cf08014d7d683c95740520a8dd8

Crie o layout do teclado. Vá em **</> Raw Data.** Copie o código e cole no site abaixo.



3 - https://kbfirmware.com/

Cole o código informado e clique em import. Vá em **compile** e clique em **download .zip**. Descompacte o arquivo e edite o **keymap.c**. 



\> Voce pode apagar o que não importa, por exemplo:

Meu código - **[{a:7},"`","F13","F14"]**

![img](https://lh6.googleusercontent.com/WZ3W_cGnj67TFkIb8NItuvJoKpPzlnYGahP_Csea0YuJj-TVNiOSwokVi33LSw8yJ7qlF-mRCeLxjEKpFG24eMalt4j40gwR6fgSEoi7cxU51DNMjK_YWPcSPfy4VUM_UXYIyMUV_GSDqE7ixn_ygU4)



Meu código no arquivo keymap.c no meu ambiente do QMK:

**#include "kb.h"**

**const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {**

  **KEYMAP(**

​     **KC_GRV, KC_F13, KC_F14)**

**};**



Abra o arquivo de **config.h** e procure por **key matrix pins**.

Delete os 3 hashtags abaixo dele:

**#define MATRIX_ROW_PINS { B0 }**

**#define MATRIX_COL_PINS { B1, B2, B3 }**

**#define UNUSED_PINS**



e no lougar cole o código abaixo:

**#define DIRECT_PINS { \**

  **{B5, B4, E6} \**

**}**



A descrição acima é:

**{ \ {pin number here, seperate with comma, keep brackets} \ }**







Para saber qual Pino usar na placa, veja a foto abaixo:

![img](https://lh4.googleusercontent.com/JX6-EBc8eiiVxuK7dDcdCDR2fZ09zqWXZv8_McGfUMpdAAT_HjQB7DHc4C_vJgA04FP5gqUniEwN-aoG19XZ7cyaxtlzFq1cIysf3cy097uz8JhlTmzejhqu6w3m75CbGENcMJt0BplaBHVNiWDMq0Q)







Pode renomear a pasta para outro nome se quiser, a pasta se chama **kb**.



E depois mova a pasta para dentro de keyboards dentro do ambiente do QMK (~/qmk_firmware/keyboards/)



Usando o terminal, vá até onde está o ambiente do QMK, no meu caso é **~/qmk_firmware/keyboards/** e rode o comando abaixo para compilar:

**$ qmk compile -kb promicro_key/macrokeyboard -km default**



Se der erro de hora, entre na pasta e rode **$ touch \***





3 - Agora grave o firmware no arduino:

$ qmk flash -kb mc -km default





Para que funcione assim a linha de comando, no **rules.mk** vc deve ter essa linha:



**# Bootloader selection**

**BOOTLOADER = caterina**







https://docs.keeb.io/flashing-firmware

https://github.com/pithybuilds/MacroKeypad

https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

https://git.sijman.nl/_/qmk_firmware/src/commit/2b23072c3438ea2a8a8477f738d24be2bc9aacdc/docs/feature_macros.md

https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras

https://github.com/qmk/qmk_firmware/blob/master/docs/reference_keymap_extras.md



https://docs.qmk.fm/#/keycodes_basic

https://github.com/qmk/qmk_toolbox/releases/download/0.2.2/qmk_toolbox.exe



X - https://docs.qmk.fm/#/newbs_building_firmware

Agora com tudo funcionando vamos criar nosso próprio firmware



/home/bsilva/qmk/qmk_firmware/keyboards/macro3/keymaps/macrokeyboardlinux









\#https://github.com/pithybuilds/MacroKeypad/blob/main/vial-qmk/keyboards/_pb_l1v32a/keymaps/default/keymap.c