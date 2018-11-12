// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_dvorak.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DV 0
#define _RS 1
#define _LW 2

// NOTE: KC_ALT and KC_LCTL is opposite here, because it depends the order of my wiring.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  '       ,      .     p    y       ||        f     g     c     r    l
   *  a       o      e     u    i       ||        d     h     t     n    s
   *  ;       q      j     k    x       ||        b     m     w     v    z
   * lower  insert super shift bksp alt || ctrl space   L1    -     /   enter
   */
  [_DV] = LAYOUT( /* Dvorak */
    DV_QUOT, DV_COMM,  DV_DOT,   DV_P,    DV_Y,                       DV_F,    DV_G,    DV_C,    DV_R,    DV_L    ,
    DV_A,    DV_O,     DV_E,     DV_U,    DV_I,                       DV_D,    DV_H,    DV_T,    DV_N,    DV_S,
    DV_SCLN, DV_Q,     DV_J,     DV_K,    DV_X,                       DV_B,    DV_M,    DV_W,    DV_V,    DV_Z ,
    KC_ESC,  KC_TAB,   KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LALT, KC_LCTL, KC_SPC,  MO(_RS), DV_MINS, DV_SLSH, KC_ENT
  ),

  /*
   *  !       @     {      }    |       ||      pgup    7     8     9    *
   *  #       $     (      )    `       ||      pgdn    4     5     6    +
   *  %       ^     [      ]    ~       ||       `      1     2     3    \
   * lower  insert super shift bksp alt || ctrl space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    DV_EXLM, DV_AT,   DV_LCBR, DV_RCBR, DV_PIPE,                   KC_PGUP, DV_7,    DV_8,   DV_9, DV_ASTR ,
    DV_HASH, DV_DLR,  DV_LPRN, DV_RPRN, DV_GRV,                    KC_PGDN, DV_4,    DV_5,   DV_6, DV_PLUS ,
    DV_PERC, DV_CIRC, DV_LBRC, DV_RBRC, DV_TILD,                   DV_AMPR, DV_1,    DV_2,   DV_3, DV_BSLS ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTL, KC_SPC,  KC_TRNS, KC_DOT, DV_0, DV_EQL  ),
  /*
   * insert home   up  end    pgup      ||       up     F7    F8    F9   F10
   *  del   left  down right  pgdn      ||      down    F4    F5    F6   F11
   *       volup              reset     ||              F1    F2    F3   F12
   *       voldn  super shift bksp  alt || ctrl space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTL, KC_SPC,  TO(_DV), KC_PSCR, KC_SLCK, KC_PAUS )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
