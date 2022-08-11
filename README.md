## Macro Keyboard using QMK Firmware

This guide provides a way to create a Keyboard or Macro Keyboard using an **Arduino Pro Micro** and **QMK Firmware**. The only things you will need initially are **Arduino Pro Micro**, a **PC** to build a firmware and a **basic knowledge of electronics**.

> It's nice to have some buttons!



## Configure QMK environment

Go to [the link](https://docs.qmk.fm/#/newbs_getting_started) to understand what QMK is and how to configure your environment.

```bash
# Using the method described by the QMK website, you may see a small error message that 
# you don't want to see, so I rather use the command line below.
$ git clone https://github.com/qmk/qmk_firmware.git && cd qmk_firmware && make git-submodule
```

> This process will take a long time!



## Create keyboard layout

Go to [the link](http://www.keyboard-layout-editor.com/#/gists/deea4cf08014d7d683c95740520a8dd8) (this link is an example used by me) and create your own layout.

![img](https://lh6.googleusercontent.com/WZ3W_cGnj67TFkIb8NItuvJoKpPzlnYGahP_Csea0YuJj-TVNiOSwokVi33LSw8yJ7qlF-mRCeLxjEKpFG24eMalt4j40gwR6fgSEoi7cxU51DNMjK_YWPcSPfy4VUM_UXYIyMUV_GSDqE7ixn_ygU4)

This image is the layout I'm using.

After you create the layout, go to `</> Raw Data` and copy the code shown below.

> My code is `[{a:7},".","F13","F14"]`.



## Prepare your firmware

Go to [the link](https://kbfirmware.com/) and paste the code that you copied in the last step, after that click in `import`, `compile`, and `download.zip`. Now extract the files, the only important folder is inside `layout/qmk_firmware/keyboards` and its name is `kb`.

If you rename this folder will be necessary rename two the files inside it, the files are `kb.c` and `kb.h`, besides that is extremely necessary to edit `kb.c` and change the *include* to the new name.

> So in my case I change the name of the folder to `macrokeyboard` and the files inside it are `macrokeyboard.c` and `macrokeyboard.h`.
>
> Don't forget to change the `include` inside `macrokeyboard.c`.



Now edit the `keymap.c` file, it's in `macrokeyboard/keymaps/default/`. In this file you must keep only the first 4 lines. Follow example below.

```bash
#include "kb.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
     KC_GRV, KC_F13, KC_F14)
};
```

> If you take a look at my `keymap.c` which is on github you will notice a little difference, the above example is just for your understanding.



Open the `config.h` file and find `key matrix pins`, then delete the 3 hashtags below it, follow the hashtags you should:

```
#define MATRIX_ROW_PINS { B0 }
#define MATRIX_COL_PINS { B1, B2, B3 }
#define UNUSED_PINS
```



After deleting you need to put the code below:

```
#define DIRECT_PINS { \
  {B5, B4, E6} \
}
```

> The code description above is: `{ \ {pin number here, seperate with comma, keep brackets} \ }`



The image below describes the pin names.

![img](https://lh4.googleusercontent.com/JX6-EBc8eiiVxuK7dDcdCDR2fZ09zqWXZv8_McGfUMpdAAT_HjQB7DHc4C_vJgA04FP5gqUniEwN-aoG19XZ7cyaxtlzFq1cIysf3cy097uz8JhlTmzejhqu6w3m75CbGENcMJt0BplaBHVNiWDMq0Q)





## Build your firmware

Move your folder into the QMK environment, the location is usually `~/qmk_firmware/keyboards/`.

```bash
# I moved my folder like this:
mv macrokeyboard ~/qmk_firmware/keyboards/
```



Flash firmware in a Linux environment requires an extra step, for that edit the `rules.mk` file and add the line below:

```
# Bootloader selection
BOOTLOADER = caterina
```



Enter the QMK environment and compile the firmware, usually you don't need to do this because when you update your firmware this build process will always be done.

Following the command to compile your firmware:

```bash
qmk compile -kb macrokeyboard -km default
```

> If you see a date/time error message, run the command `touch ~/qmk_firmware/keyboards/macrokeyboard/*`, this command will update the date/time.



So let's flash the firmware on the Arduino, during this process you will need to do a reset on the Arduino. Connect the Arduino to the PC and then run the command below, while the command is running you must do a reset, for this you need to connect the **RST** Pin with the **GND** Pin.

```bash
qmk flash -kb macrokeyboard -km default
```

> As soon as the system identifies the Arduino the flash firmware will start and finish in a few seconds.



Now you can finally use your Macro Keyboard!!!!



# Links

https://docs.keeb.io/flashing-firmware

https://github.com/pithybuilds/MacroKeypad

https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

https://git.sijman.nl/_/qmk_firmware/src/commit/2b23072c3438ea2a8a8477f738d24be2bc9aacdc/docs/feature_macros.md

https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras

https://github.com/qmk/qmk_firmware/blob/master/docs/reference_keymap_extras.md

https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md


https://docs.qmk.fm/#/keycodes_basic

https://github.com/qmk/qmk_toolbox/releases/download/0.2.2/qmk_toolbox.exe

https://docs.qmk.fm/#/newbs_building_firmware

https://github.com/pithybuilds/MacroKeypad/blob/main/vial-qmk/keyboards/_pb_l1v32a/keymaps/default/keymap.c

https://github.com/qmk/qmk_firmware/blob/master/docs/feature_programmable_button.md