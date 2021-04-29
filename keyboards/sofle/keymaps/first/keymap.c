#include QMK_KEYBOARD_H
#include <stdio.h>

#include "encoder.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
};
#include "oled.c"

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
};

/*
 *  --- Layers ---
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(KC_MINS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_GESC, LALT_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G, KC_H, RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), KC_QUOT, LSFT_T(KC_LBRC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT(KC_RBRC), KC_MPLY, KC_MFFD, OSM(MOD_HYPR), KC_SPC, LT(1, KC_ENT), KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
                                                              [1] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_TRNS, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT)};

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
    }
    return true;
}
