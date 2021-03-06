#include "hid.h"
#include "KeyboardioHID.h"

namespace kaleidoscope {
namespace hid {
void initializeKeyboard() {
  Keyboard.begin();
}

void pressRawKey(Key mappedKey) {
  Keyboard.press(mappedKey.keyCode);

}

void pressKey(Key mappedKey) {
  if (mappedKey.flags & SHIFT_HELD) {
    pressRawKey(Key_LeftShift);
  }
  if (mappedKey.flags & CTRL_HELD) {
    pressRawKey(Key_LeftControl);
  }
  if (mappedKey.flags & LALT_HELD) {
    pressRawKey(Key_LeftAlt);
  }
  if (mappedKey.flags & RALT_HELD) {
    pressRawKey(Key_RightAlt);
  }
  if (mappedKey.flags & GUI_HELD) {
    pressRawKey(Key_LeftGui);
  }

  pressRawKey(mappedKey);
}

void releaseRawKey(Key mappedKey) {
  Keyboard.release(mappedKey.keyCode);

}

void releaseAllKeys() {
  Keyboard.releaseAll();
}

void releaseKey(Key mappedKey) {
  if (mappedKey.flags & SHIFT_HELD) {
    releaseRawKey(Key_LeftShift);
  }
  if (mappedKey.flags & CTRL_HELD) {
    releaseRawKey(Key_LeftControl);
  }
  if (mappedKey.flags & LALT_HELD) {
    releaseRawKey(Key_LeftAlt);
  }
  if (mappedKey.flags & RALT_HELD) {
    releaseRawKey(Key_RightAlt);
  }
  if (mappedKey.flags & GUI_HELD) {
    releaseRawKey(Key_LeftGui);
  }
  releaseRawKey(mappedKey);
}

boolean isModifierKeyActive(Key mappedKey) {
  return Keyboard.isModifierActive(mappedKey.keyCode);
}

void sendKeyboardReport() {
  Keyboard.sendReport();
}

void initializeConsumerControl() {
  ConsumerControl.begin();
}

void pressConsumerControl(Key mappedKey) {
  ConsumerControl.press(mappedKey.keyCode);
}

void releaseConsumerControl(Key mappedKey) {
  ConsumerControl.release(mappedKey.keyCode);
}


void initializeSystemControl() {
  SystemControl.begin();
}

void pressSystemControl(Key mappedKey) {
  SystemControl.press(mappedKey.keyCode);
}

void releaseSystemControl(Key mappedKey) {
  SystemControl.release();
}


// Mouse events

void initializeMouse() {
  Mouse.begin();
}

void moveMouse(signed char x, signed char y, signed char wheel) {
  Mouse.move(x, y, wheel);
}

void clickMouseButtons(uint8_t buttons) {
  Mouse.click(buttons);
}

void pressMouseButtons(uint8_t buttons) {
  Mouse.press(buttons);
}

void releaseMouseButtons(uint8_t buttons) {
  Mouse.release(buttons);
}

/** Absolute mouse (grapahics tablet) events */

void initializeAbsoluteMouse() {
  AbsoluteMouse.begin();
}

void moveAbsoluteMouse(signed char x, signed char y, signed char wheel) {
  AbsoluteMouse.move(x, y, wheel);
}
void moveAbsoluteMouseTo(uint16_t x, uint16_t y, signed char wheel) {
  AbsoluteMouse.moveTo(x, y, wheel);
}

void clickAbsoluteMouseButtons(uint8_t buttons) {
  AbsoluteMouse.click(buttons);
}

void pressAbsoluteMouseButtons(uint8_t buttons) {
  AbsoluteMouse.press(buttons);
}

void releaseAbsoluteMouseButtons(uint8_t buttons) {
  AbsoluteMouse.release(buttons);
}

}
};
