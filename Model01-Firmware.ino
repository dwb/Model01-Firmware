// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "built by dwb"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include <Kaleidoscope.h>

// Support for keys that move the mouse
#include <Kaleidoscope-MouseKeys.h>

// Support for macros
#include <Kaleidoscope-Macros.h>

// Support for controlling the keyboard's LEDs
#include <Kaleidoscope-LEDControl.h>

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
// #include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
// #include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include <Kaleidoscope-LEDEffect-BootGreeting.h>

// Support for LED modes that set all LEDs to a single color
/* #include <Kaleidoscope-LEDEffect-SolidColor.h> */

// Support for an LED mode that makes all the LEDs 'breathe'
/* #include <Kaleidoscope-LEDEffect-Breathe.h> */

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
/* #include <Kaleidoscope-LEDEffect-Chase.h> */

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include <Kaleidoscope-LEDEffect-Rainbow.h>

// Support for an LED mode that lights up the keys as you press them
/* #include <Kaleidoscope-LED-Stalker.h> */

// Support for an LED mode that prints the keys you press in letters 4px high
/* #include <Kaleidoscope-LED-AlphaSquare.h> */

// Support for Keyboardio's internal keyboard testing mode
// Support for host power management (suspend & wakeup)
#include <Kaleidoscope-HostPowerManagement.h>

// For holding-backspace-is-CapsLock (to emulate Fn)
#include <Kaleidoscope-Qukeys.h>

// this doesn't work yet :(
// #define Key_Apple_Fn CONSUMER_KEY(0x029D, HID_TYPE_OOC)


/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       MACRO_ANY
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/tree/master/src/kaleidoscope/key_defs
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { QWERTY, NUMBERS, OTHERCOMMON, FKEYS, NUMPAD }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

// HYPER(Key_I) : Siri
// HYPER(Key_S) : Search for UI element to click
// HYPER(Key_L) : Scroll UI element

// Keycodes list here:
// https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/keyboard.h
KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,             Key_F1,        Key_F2,      Key_F3,        Key_F4, Key_F5, LGUI(Key_H),
   Key_Tab,         Key_Q,         Key_W,       Key_E,         Key_R,  Key_T,  Key_Tab,
   Key_PageUp,      Key_A,         Key_S,       Key_D,         Key_F,  Key_G,
   Key_PageDown,    Key_Z,         Key_X,       Key_C,         Key_V,  Key_B,  Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(NUMBERS),

   Key_F19,                    Key_F6,         Key_F7,       Key_F8,           Key_F9,        Key_F10,       LGUI(Key_H),
   Key_Enter,                  Key_Y,          Key_U,        Key_I,            Key_O,         Key_P,         Key_Minus,
                               Key_H,          Key_J,        Key_K,            Key_L,         Key_Semicolon, Key_Quote,
   Key_RightAlt,               Key_N,          Key_M,        Key_Comma,        Key_Period,    Key_Slash,     Key_Backslash,
   Key_LeftAlt,                Key_RightShift, Key_Spacebar, Key_RightControl,
   ShiftToLayer(OTHERCOMMON)),

  [NUMBERS] =  KEYMAP_STACKED
  (XXX,                      HYPER(Key_1),               HYPER(Key_2),           HYPER(Key_3),                  HYPER(Key_4),                   HYPER(Key_5), Key_LEDEffectNext,
   Consumer_VolumeIncrement, XXX,                        Key_PageUp,             XXX,                           Key_Enter,                      XXX,          Key_Backtick,
   Consumer_VolumeDecrement, Key_Home,                   Key_PageDown,           Key_End,                       Key_Spacebar,                   XXX,
   Consumer_PlaySlashPause,  Consumer_ScanPreviousTrack, Consumer_ScanNextTrack, LSHIFT(LGUI(Key_LeftBracket)), LSHIFT(LGUI(Key_RightBracket)), XXX, ShiftToLayer(NUMPAD),
   ___,                      ___,                        ___,                    ___,
   XXX,

   M(MACRO_VERSION_INFO),       XXX,          XXX,   XXX,   XXX,        XXX,           ___,
   ___,                         Key_Backtick, Key_7, Key_8, Key_9,      XXX,           Key_Minus,
                           XXX, Key_4,        Key_5, Key_6, Key_Equals, XXX,
   ___,                         RALT(Key_3),  Key_1, Key_2, Key_3,      Key_Period, XXX,
   ___,                         ___,          ___,   Key_0,
   ShiftToLayer(FKEYS)),

  [OTHERCOMMON] =  KEYMAP_STACKED
  (XXX, XXX,             XXX,          XXX,          XXX, XXX, XXX,
   XXX, XXX,             Key_PageUp,   Key_Enter,    XXX, XXX, XXX,
   XXX, Key_Home,        Key_PageDown, Key_End,      XXX, XXX,
   XXX, Key_PrintScreen, Key_Insert,   Key_Spacebar, XXX, XXX, XXX,
   ___, Key_Delete,      ___,          ___,
   ShiftToLayer(FKEYS),

   Consumer_VolumeIncrement,                HYPER(Key_6),    HYPER(Key_7),     HYPER(Key_8),     HYPER(Key_9),  HYPER(Key_0),   XXX,
   Consumer_VolumeDecrement,                HYPER(Key_Y),    Key_LeftBracket,  Key_RightBracket, Key_LeftParen, Key_RightParen, HYPER(Key_Minus),
                             Key_LeftArrow, Key_DownArrow, Key_UpArrow,     Key_RightArrow,   XXX,           XXX,
   Consumer_PlaySlashPause,                 ___,           LSHIFT(Key_9),   LSHIFT(Key_0),    XXX,           HYPER(Key_I),            LGUI(LCTRL(Key_F)),
   ___,                                     ___,           Key_Enter,       ___,
   XXX),

  [FKEYS] =  KEYMAP_STACKED
  (XXX,     XXX,      XXX,     XXX,     XXX,     XXX,     XXX,
   XXX,     XXX,      XXX,     XXX,     XXX,     XXX,     XXX,
   XXX, Key_F13, Key_F14,  Key_F15, Key_F16, Key_F17,
   XXX, LGUI(Key_F13), LGUI(Key_F14),  LGUI(Key_F15), LGUI(Key_F16), LGUI(Key_F17), XXX,
   ___, ___,      XXX,          ___,
   XXX,

   M(MACRO_VERSION_INFO),  XXX, XXX, XXX, XXX,     XXX, XXX,
   XXX,                    Consumer_VolumeIncrement, Key_F7, Key_F8, Key_F9,     Key_F12, XXX,
                           Consumer_VolumeDecrement, Key_F4, Key_F5, Key_F6,     Key_F11, XXX,
   HYPER(Key_S),           HYPER(Key_L),             Key_F1, Key_F2, Key_F3,     Key_F10, XXX,
   ___,                         ___,   HYPER(Key_Spacebar),   Key_RightControl,
   XXX),

  [NUMPAD] =  KEYMAP_STACKED
  (XXX,                      XXX,               XXX,           XXX,                  XXX,                   XXX, XXX,
   XXX, XXX,                        XXX,             XXX,                           XXX,                      XXX,          XXX,
   XXX, XXX,                   XXX,           XXX,                       XXX,                   XXX,
   XXX,  XXX, XXX, XXX, XXX, XXX, XXX,
   ___,                      ___,                        ___,                    ___,
   XXX,

   XXX,                     XXX, XXX,         Key_KeypadDivide, Key_KeypadMultiply, Key_KeypadSubtract, XXX,
   XXX,                     XXX, Key_Keypad7, Key_Keypad8,      Key_Keypad9,        Key_KeypadAdd,      XXX,
                            XXX, Key_Keypad4, Key_Keypad5,      Key_Keypad6,        Key_KeypadEnter,    XXX,
   XXX,                     XXX, Key_Keypad1, Key_Keypad2,      Key_Keypad3,        Key_KeypadDot,      XXX,
   ___,                     ___, XXX,   Key_Keypad0,
   XXX)

	) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    event.key.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
    event.key.setFlags(0);
  }
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  switch (macro_id) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(event.state);
    break;

  case MACRO_ANY:
    anyKeyMacro(event);
    break;
  }
  return MACRO_NONE;
}


// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


/* static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
 * static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
 * static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
 * static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
 * static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
 * static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
 * static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120); */

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
  BootGreetingEffect,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  LEDRainbowWaveEffect,

  // For holding-backspace-is-CapsLock (to emulate Apple Fn)
  Qukeys,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  // NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  //NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  /* AlphaSquare.color = CRGB(255, 0, 0); */

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  /* StalkerEffect.variant = STALKER(BlazingTrail); */

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // LEDRainbowWaveEffect.activate();

  MouseKeys.accelDelay = 100; // ms

  // very annoying
  Qukeys.setMaxIntervalForTapRepeat(0);

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 7), Key_CapsLock),
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 7), Key_CapsLock),
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 7), Key_CapsLock),
    kaleidoscope::plugin::Qukey(3, KeyAddr(1, 7), Key_CapsLock),
  );
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
