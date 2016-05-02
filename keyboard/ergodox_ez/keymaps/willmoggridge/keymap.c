#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"


#define BASE 0
#define QWERTY 1
#define M_COLE 2
#define M_QWERT 3
#define MUMBLE 4
#define RAISE 5
#define LOWER 6
#define _MACROS 7
#define LAYOUTS 8


#define KC_DQOU S(KC_QUOT)
#define KC_GTHN S(KC_DOT)
#define KC_LTHN S(KC_COMM)
#define KC_QUES S(KC_SLSH)


#define UK_HASH KC_NONUS_HASH
#define UK_TILD S(KC_NONUS_HASH)
#define UK_POUN KC_HASH
#define UK_BSLS KC_NONUS_BSLASH
#define UK_PIPE S(KC_NONUS_BSLASH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layout picker
 *
 * (Following qwerty):
 * 1: Base / Colemak
 * 2: Qwerty Layout
 * 3: Toggle keys for VOIP
 *
 */
[LAYOUTS] = KEYMAP(
    // left hand
    KC_TRNS,    TG(QWERTY), TG(QWERTY), TG(MUMBLE), KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* Base
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Esc/Layt|   1  |   2  |   3  |   4  |   5  |   -  |           |  =   |   6  |   7  |   8  |   9  |   0  |Backspac|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  | Home |           | End  |   J  |   L  |   U  |   Y  |   ;  |    `   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------|  [{  |           |  ]}  |------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |    \   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt |Lower |Raise |Mirror| LGUI |                                       | Left | Down | Up   |Right |AltGr |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Macro |PrntSc|       | Vol- | Vol+ |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  F12 |       | Play |      |      |
 *                                 |Space |Enter |------|       |------|Raise |RShift|
 *                                 |      |      | Back |       | Del  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
    // left hand
    LT(LAYOUTS,KC_ESC), KC_1, KC_2,     KC_3,       KC_4,       KC_5,       KC_MINS,
    KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_HOME,
    KC_LSFT,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,
    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LBRC,
    KC_LALT,    MO(LOWER),  MO(RAISE),MO(M_COLE), KC_LGUI,
                                                    MO(_MACROS), KC_PSCR,
                                                                KC_F12,
                                        KC_SPC,     KC_ENTER,   KC_BSPC,
    // right hand
    KC_EQL,     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_END,     KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_GRV,
                KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
    KC_RBRC,    KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    UK_BSLS,
                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_RALT,
                KC_VOLD,    KC_VOLU,
                KC_MPLY,
                KC_DEL,     MO(RAISE),  KC_RSFT
),
/*
 * Mirrored Colemak
 */
[M_COLE] = KEYMAP(
    // left hand
    KC_TRNS,    KC_0,       KC_9,       KC_8,       KC_7,       KC_6,       KC_EQL,
    KC_TRNS,    KC_SCLN,    KC_Y,       KC_U,       KC_L,       KC_J,       KC_TRNS,
    KC_TRNS,    KC_O,       KC_I,       KC_E,       KC_N,       KC_H,
    KC_TRNS,    KC_SLSH,    KC_DOT,     KC_COMM,    KC_M,       KC_K,       KC_RBRC,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
/*
 * Qwerty
 */
[QWERTY] = KEYMAP(
    // left hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_TRNS,
    KC_TRNS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
    KC_TRNS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    MO(M_QWERT),KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
                KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_TRNS,
    KC_TRNS,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
/*
 * Mirrored Qwerty
 */
[M_QWERT] = KEYMAP(
    // left hand
    KC_TRNS,    KC_0,       KC_9,       KC_8,       KC_7,       KC_6,       KC_EQL,
    KC_TRNS,    KC_P,       KC_O,       KC_I,       KC_U,       KC_Y,       KC_TRNS,
    KC_TRNS,    KC_SCLN,    KC_L,       KC_K,       KC_J,       KC_H,
    KC_TRNS,    KC_SLSH,    KC_DOT,     KC_COMM,    KC_M,       KC_N,       KC_RBRC,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ~  |   {  |   [  |   (  |   <  |      |           |      |   >  |   )  |   ]  |   }  |   #  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   `  |   "  |   '  |   -  |   /  |------|           |------|   |  | Left | Down | Up   |Right |        |
 * |--------+------+------+------+------+------|   ^  |           |   %  |------+------+------+------+------+--------|
 * |        |   *  |   +  |   =  |   _  |   $  |      |           |      |   £  |   !  |   ?  |   @  |   &  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Home |PageDn|PageUp| End  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RAISE] = KEYMAP(
    // left hand
    KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,
    KC_TRNS,    UK_TILD,    KC_LCBR,    KC_LPRN,    KC_LBRC,    KC_LTHN,    KC_TRNS,
    KC_TRNS,    KC_GRV,     KC_DQOU,    KC_QUOT,    KC_MINS,    KC_SLASH,
    KC_TRNS,    KC_ASTR,    KC_PLUS,    KC_EQUAL,   KC_UNDS,    KC_DLR,     KC_CIRC,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_F12,     KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_TRNS,
    KC_TRNS,    KC_GTHN,    KC_RBRC,    KC_RPRN,    KC_RCBR,    UK_HASH,    KC_TRNS,
                UK_PIPE,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,
    KC_PERC,    UK_POUN,    KC_EXLM,    KC_QUES,    KC_AT,      KC_AMPR,    KC_TRNS,
                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* Lower
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |BrwsBk| MsUp |BrwsFd|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Back | Play | Next |------|           |------|MsWhUp|MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Vol- | Vol+ | Mute |      |           |      |MsWhDn|      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Lclk | Rclk |
 *                                 |      |      |      |       | Mclk |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWER] = KEYMAP(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_MPLY,    KC_MNXT,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_WBAK,    KC_MS_U,    KC_WFWD,    KC_TRNS,    KC_TRNS,
                KC_WH_U,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_WH_D,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_BTN3,    KC_BTN1,    KC_BTN2
),
/* Mumble
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | XXX    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | XXX  | XXX  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | XXX  |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MUMBLE] = KEYMAP(
    // left handars
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F20,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_F21,     KC_F22,
                KC_F23,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
[_MACROS] = KEYMAP(
    // left hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS
),
// [TEMPLATES] = KEYMAP(
//     // left hand
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//                                                     KC_TRNS,    KC_TRNS,
//                                                                 KC_TRNS,
//                                         KC_TRNS,    KC_TRNS,    KC_TRNS,
//     // right hand
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//                 KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//                             KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//                 KC_TRNS,    KC_TRNS,
//                 KC_TRNS,
//                 KC_TRNS,    KC_TRNS,    KC_TRNS
// ),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case QWERTY:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};
