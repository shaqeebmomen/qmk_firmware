/* Copyright 2022 Jose Pablo Ramirez <jp.ramangulo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                    LT(1,KC_MUTE),
      KC_ENT, KC_0, KC_BSPC,
      KC_7,   KC_8, KC_9,
      KC_4,   KC_5, KC_6,
      KC_1,   KC_2, KC_3
  ),
  [1] = LAYOUT(
                        _______,
      CK_TOGG, AU_TOGG, _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
  ),
  [2] = LAYOUT(
                        _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
  ),
  [3] = LAYOUT(
                        _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______,
      _______, _______, _______
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] = { ENCODER_CCW_CW(_______, _______) },
  [2] = { ENCODER_CCW_CW(_______, _______) },
  [3] = { ENCODER_CCW_CW(_______, _______) }
};
#endif


#ifdef OLED_ENABLE
static void render_qmk_logo(void) {
  static const char PROGMEM cinna_skate[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x07, 0x0F,
    0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0,
    0xE0, 0xC0, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xC0, 0xC0, 0xE0, 0xE0,
    0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x03, 0x03, 0x07, 0x0F, 0x0F, 0x1F,
    0x1F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC,
    0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE,
    0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF,
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE,
    0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0,
    0xF0, 0xE0, 0xE0, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0,
    0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0,
    0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE,
    0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0xC1, 0xE1, 0xF1,
    0xF9, 0xFD, 0xFC, 0xFE, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x3F,
    0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x9F, 0x07, 0x07,
    0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFD,
    0xFD, 0xF9, 0xC3, 0x03, 0x33, 0x73,
    0x73, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3,
    0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xE3,
    0xE3, 0xC3, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x83, 0x87, 0xC7, 0xCF,
    0xCF, 0xCF, 0xDF, 0xDF, 0x9F, 0x9F,
    0xBF, 0xBF, 0x3F, 0x3F, 0x2F, 0x6F,
    0x6F, 0x6F, 0x6F, 0x5F, 0x5F, 0xCF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xF0, 0xE0, 0xE0,
    0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x7F, 0x3F, 0x9F, 0x03, 0x00,
    0xCE, 0xC6, 0xE4, 0xE0, 0xF9, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
    0x7F, 0x3F, 0x3F, 0x1F, 0x06, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x03, 0x03, 0x03, 0x03, 0xC3, 0xF3,
    0xF3, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
    0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC,
    0xFC, 0xFC, 0xFD, 0xFD, 0xFD, 0xFD,
    0xFD, 0xFD, 0xFD, 0x7D, 0x3D, 0x3D,
    0x9C, 0xCC, 0xC6, 0xC2, 0xCF, 0xCF,
    0xC7, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF,
    0x7F, 0x3F, 0x1F, 0x1B, 0x0D, 0x05,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0,
    0xF8, 0xF8, 0xFC, 0xF0, 0x00, 0x0E,
    0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x3F, 0x1F, 0x1F, 0x1F, 0x9F, 0x9F,
    0x9F, 0x9F, 0x9F, 0x9F, 0xCF, 0xCF,
    0xCF, 0xEF, 0xE7, 0xE7, 0xF3, 0xF3,
    0xF3, 0xF9, 0xF9, 0xFC, 0xFC, 0xFE,
    0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F,
    0x1F, 0x0F, 0x07, 0x07, 0x03, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x06,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC,
    0xFC, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFC, 0xF8, 0xF1, 0xF3, 0xF3, 0xF1,
    0xF9, 0xF8, 0xFC, 0xFC, 0xFE, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x3F,
    0x1F, 0x1F, 0x0F, 0x07, 0x07, 0x03,
    0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(cinna_skate, sizeof(cinna_skate));
}

bool oled_task_user(void) {
  render_qmk_logo();
  return true;
}

#endif
