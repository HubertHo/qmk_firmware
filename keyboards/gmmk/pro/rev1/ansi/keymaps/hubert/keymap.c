/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 End
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       PgDn
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+Space. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INSERT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            RESET,                            _______, _______, _______, _______, _______, _______
    ),


};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif

#ifdef RGB_MATRIX_ENABLE

static void set_rgb_caps_leds(void);

void rgb_matrix_indicators_user() {
    // The only LEDs that I want to see are the panel LEDs
    rgb_matrix_set_color_all(0x00, 0x00, 0x00);
    if (host_keyboard_led_state().caps_lock) {
        set_rgb_caps_leds();
    }
}

static void set_rgb_caps_leds() {
    rgb_matrix_set_color(67, 0xE4, 0xA9, 0x15); // Left side LED 1
    rgb_matrix_set_color(68, 0xE4, 0xA9, 0x15); // Right side LED 1
    rgb_matrix_set_color(70, 0xE4, 0xA9, 0x15); // Left side LED 2
    rgb_matrix_set_color(71, 0xE4, 0xA9, 0x15); // Right side LED 2
    rgb_matrix_set_color(73, 0xE4, 0xA9, 0x15); // Left side LED 3
    rgb_matrix_set_color(74, 0xE4, 0xA9, 0x15); // Right side LED 3
    rgb_matrix_set_color(76, 0xE4, 0xA9, 0x15); // Left side LED 4
    rgb_matrix_set_color(77, 0xE4, 0xA9, 0x15); // Right side LED 4
    rgb_matrix_set_color(80, 0xE4, 0xA9, 0x15); // Left side LED 5
    rgb_matrix_set_color(81, 0xE4, 0xA9, 0x15); // Right side LED 5
    rgb_matrix_set_color(83, 0xE4, 0xA9, 0x15); // Left side LED 6
    rgb_matrix_set_color(84, 0xE4, 0xA9, 0x15); // Right side LED 6
    rgb_matrix_set_color(87, 0xE4, 0xA9, 0x15); // Left side LED 7
    rgb_matrix_set_color(88, 0xE4, 0xA9, 0x15); // Right side LED 7
    rgb_matrix_set_color(91, 0xE4, 0xA9, 0x15); // Left side LED 8
    rgb_matrix_set_color(92, 0xE4, 0xA9, 0x15); // Right side LED 8
    rgb_matrix_set_color(3, 0xE4, 0xA9, 0x15); // CAPS LED
}
#endif
