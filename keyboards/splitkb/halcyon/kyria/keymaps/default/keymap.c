// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "keymap_uk.h"
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _GAMING,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define GAMING DF(_GAMING)

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

#define HOME_A MT(MOD_LCTL, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LGUI, KC_D)
#define HOME_F MT(MOD_LSFT, KC_F)

#define HOME_SCLN MT(MOD_RCTL, KC_SCLN)
#define HOME_L MT(MOD_RALT, KC_L)
#define HOME_K MT(MOD_RGUI, KC_K)
#define HOME_J MT(MOD_RSFT, KC_J)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * | / (    |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | / )    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_QWERTY] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,     KC_BSPC,
     CTL_ESC , KC_A, KC_S ,  KC_D  , KC_F , KC_G ,                                             KC_H,   KC_J,   KC_K ,   KC_L,   KC_SCLN,   CTL_QUOT,
     SC_LSPO , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH,  SC_RSPC,
                                ADJUST , KC_LGUI, KC_LALT, KC_SPC , NAV   ,     SYM    , KC_ENT ,KC_RALT, KC_RGUI, KC_APP,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     S(KC_NUBS) , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUNCTION] = LAYOUT_split_3x6_5_hlc(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |    Q   |   1  |   2  |  3   |  4   |  X   |                              |   6  |  7   |  8   |  9   |  0   |  BACK  |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |   TAB  |   A  |   W  |   E  |  R   |  T   |                              |      |      |      |      |      |  ENT   |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |   AMP  |   C  |   S  |   D  |  F   |  G   |  F1  |  F2  |  |      |      |      |      |      |      |      |  LSFT  |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        | ADJS | CTRL |   V  | SHFT | SPC  |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
     [_GAMING] = LAYOUT_split_3x6_5_hlc(
       KC_Q,  KC_1,    KC_2,    KC_3,    KC_4,    KC_X,                                        KC_6,    KC_7,    KC_8,    KC_I,    KC_O,   KC_ESC,
       KC_TAB, KC_A,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_H, KC_J, KC_K,    _______, _______, _______,
       UK_AMPR, KC_C,    KC_S,    KC_D,    KC_F,    KC_G, KC_F1, KC_F2, FKEYS, KC_B, _______, _______, _______, _______, _______, _______,
                        ADJUST, KC_LCTL, KC_V,  KC_LSFT, KC_SPC, KC_Z, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
     ),
/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |GAMING|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |Leader|      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
      _______, _______, _______, _______ , _______, _______,                                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, QWERTY , _______, _______,                                    RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
      _______, _______, _______, GAMING, _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                 _______, _______, _______,_______, _______, QK_LEAD, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                      _______, _______, _______, _______, _______
    ),
// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [5] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

// --- Danish characters (æ ø å) via leader key ---------------------------------
// Leader is on the Adjust layer (Sym thumb key). Tap it, release, then type the
// sequence on the base layer; hold Shift during the sequence for the capital.
// Output goes through the OS compose key: the OS maps Scroll Lock to Compose
// (hyprland kb_options = "compose:sclk") and the å/æ/ø rules are in the stock
// en_US.UTF-8 Compose table, so no custom ~/.XCompose is needed.
#ifdef LEADER_ENABLE
static void send_compose_pair(uint16_t first, uint16_t second) {
    // Compose must see the sequence without any held mods, except the shifts
    // baked into `first`/`second` for capitals.
    uint8_t mods = get_mods();
    clear_mods();
    send_keyboard_report();
    tap_code(KC_SCRL); // Compose
    tap_code16(first);
    tap_code16(second);
    set_mods(mods);
    send_keyboard_report();
}

// Fire the sequence the instant a complete 2-key match lands, instead of waiting
// for LEADER_TIMEOUT after the second key. All our sequences are exactly 2 keys,
// so once the buffer matches one there's nothing more to wait for. Returning true
// here makes leader.c call leader_end() immediately. (Runs on the 2nd key's
// keydown, so Shift is still held -> caps detection stays reliable.)
bool leader_add_user(uint16_t keycode) {
    return leader_sequence_two_keys(KC_A, KC_A)
        || leader_sequence_two_keys(KC_A, KC_E)
        || leader_sequence_two_keys(KC_O, KC_O);
}

void leader_end_user(void) {
    bool caps = get_mods() & MOD_MASK_SHIFT;
    if (leader_sequence_two_keys(KC_A, KC_A)) {
        send_compose_pair(caps ? S(KC_A) : KC_A, caps ? S(KC_A) : KC_A); // å Å
    } else if (leader_sequence_two_keys(KC_A, KC_E)) {
        send_compose_pair(caps ? S(KC_A) : KC_A, caps ? S(KC_E) : KC_E); // æ Æ
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        // Compose rule is <o> </> — the slash is never shifted.
        send_compose_pair(caps ? S(KC_O) : KC_O, KC_SLSH); // ø Ø
    }
}
#endif // LEADER_ENABLE

// --- kyra-companion RAW HID integration --------------------------------------
// Bidirectional channel with the desktop companion app. The message ids below
// MUST stay in sync with src/protocol.rs in the kyra-companion repo.
#ifdef RAW_ENABLE
#include "raw_hid.h"

#define KYRA_PROTOCOL_VERSION 1
#define KYRA_FW_MAJOR 0
#define KYRA_FW_MINOR 1
// RAW HID report size. Matches REPORT_SIZE in kyra-companion src/protocol.rs and
// QMK's RAW_EPSIZE (which isn't visible from the keymap translation unit).
#define KYRA_REPORT_SIZE 32

enum kyra_cmd {
    KYRA_CMD_PING              = 0x01, // host asks for state -> we reply PONG
    KYRA_CMD_SET_DEFAULT_LAYER = 0x02, // data[1] = layer index
    KYRA_CMD_OLED_TEXT         = 0x03, // data[1]=slot data[2]=len data[3..]=utf8
};

enum kyra_evt {
    KYRA_EVT_PONG   = 0x81,
    KYRA_EVT_LAYER  = 0x82,
    KYRA_EVT_ACTION = 0x83,
};

// Report the current layer stack to the host. Pass the *incoming* state from
// the layer hooks, since the globals aren't updated until after they return.
static void kyra_send_layer_state(layer_state_t active, layer_state_t base) {
    uint8_t buf[KYRA_REPORT_SIZE] = {0};
    buf[0] = KYRA_EVT_LAYER;
    buf[1] = get_highest_layer(active);
    buf[2] = get_highest_layer(base);
    raw_hid_send(buf, sizeof(buf));
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case KYRA_CMD_PING: {
            uint8_t buf[KYRA_REPORT_SIZE] = {0};
            buf[0] = KYRA_EVT_PONG;
            buf[1] = KYRA_PROTOCOL_VERSION;
            buf[2] = KYRA_FW_MAJOR;
            buf[3] = KYRA_FW_MINOR;
            buf[4] = get_highest_layer(layer_state);
            buf[5] = get_highest_layer(default_layer_state);
            raw_hid_send(buf, sizeof(buf));
            break;
        }
        case KYRA_CMD_SET_DEFAULT_LAYER:
            // set_single_default_layer() is the documented front-door API; takes a
            // layer *number* (no manual mask) and does NOT write EEPROM, so the
            // focus->layer feature can fire this rapidly without wearing flash.
            // (default_layer_set is flagged "avoid unless you know what you're doing".)
            set_single_default_layer(data[1]);
            break;
        case KYRA_CMD_OLED_TEXT:
            // TODO(milestone 2): forward slot/len/text to hlc_tft_display via
            // Quantum Painter. See PLAN.md "OLED push" for the open question.
            break;
        default:
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    kyra_send_layer_state(state, default_layer_state);
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    kyra_send_layer_state(layer_state, state);
    return state;
}
#endif // RAW_ENABLE
