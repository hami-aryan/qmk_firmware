//I borrowed from atlacat...		

#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * using space cadet: https://docs.qmk.fm/features/space-cadet
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |( or Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| ) or Shift |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO2 |Ctrl |
   * `-----------------------------------------------------------'
   */

  LAYOUT(
      F(0), KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
      KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
      LT(MO(1), KC_CAPS),KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
      KC_LSPO, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC,          XXXXXXX,
      KC_LCTL,          KC_LGUI, KC_LALT, KC_SPC ,          KC_SPC ,          KC_SPC , KC_RALT, KC_RGUI, XXXXXXX, MO(2)  ,          KC_RCTL),


	 /* Keymap : Second Layer (WASD and Media)
	* ,-----------------------------------------------------------------------------------------.
	* | ` | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |      Del    |
	* |-----------------------------------------------------------------------------------------+
	* |       |Home |  Up |  End | PgUp |     |     |     |     |     |     |     |     |       | 
	* |-----------------------------------------------------------------------------------------+
	* |         | Left| Down| Right| PgDn |     |     |     |     |     |     |     |           |
	* |-----------------------------------------------------------------------------------------+
	* |           |     |     |     |     |     |     |     |     |     |           |           |
	* |-----------------------------------------------------------------------------------------+
	* |      |      |      |                                     |      |     |     |     |     |
	* `-----------------------------------------------------------------------------------------'
	*/

  LAYOUT(
      KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL ,
      _______,          KC_HOME,  KC_UP,  KC_END, KC_PGUP, _______, _______, _______, _______, _______, _______,_______, _______, _______,
      _______,          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, _______ , _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,          _______,
      _______,          _______, _______, _______,          _______,          _______, _______, _______, _______, _______,          _______),



   /* Keymap : Third Layer (RGB / Reset)
	* ,-----------------------------------------------------------------------------------------.
	* | ` | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   Sleep     |
	* |-----------------------------------------------------------------------------------------+
	* |       |     |     |      |      |     |     |     |     |     |     |     |     | RESET | 
	* |-----------------------------------------------------------------------------------------+
	* |         |     |     |      |      |     |     |     |   | Prev | Play | Next  |         |
	* |-----------------------------------------------------------------------------------------+
	* |           |     |     |     |     |     |     |     | Vol-  | Vol+  |  Mute   |         |
	* |-----------------------------------------------------------------------------------------+
	* |      |      |      |                                     |      |     |     |     |     |
	* `-----------------------------------------------------------------------------------------'
	*/  LAYOUT(
      KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_SLEP,
      _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET  ,
      _______,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, _______, KC_MPRV, KC_MPLY, KC_MNXT,          _______,
      _______, _______, BL_DEC , BL_TOGG, BL_INC , BL_STEP, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,          _______,
      _______,          _______, _______, _______,          _______,          _______, _______, _______, _______, _______,          _______),

};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}
