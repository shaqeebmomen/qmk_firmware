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
#include "images.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(LT(1, KC_MUTE), KC_ENT, KC_0, KC_BSPC, KC_7, KC_8, KC_9, KC_4, KC_5, KC_6, KC_1, KC_2, KC_3),
    [1] = LAYOUT(_______, CK_TOGG, AU_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [1] = {ENCODER_CCW_CW(_______, _______)}, [2] = {ENCODER_CCW_CW(_______, _______)}, [3] = {ENCODER_CCW_CW(_______, _______)}};
#endif

#ifdef OLED_ENABLE
static void render_anim(void) {
    static uint16_t anim_timer       = 0;
    static uint8_t  anim_frame_index = 0;

    static char const(*active_anim)[IMG_FRAME_SIZE] = anim_0;
    static size_t active_anim_size                  = (sizeof(anim_0) / IMG_FRAME_SIZE);

    if (timer_elapsed(anim_timer) > 50) {
        if (IS_LAYER_ON(0) && (active_anim != anim_0)) {
            active_anim      = anim_0;
            active_anim_size = (sizeof(anim_0) / IMG_FRAME_SIZE);
            anim_frame_index = 0;
        } else if (IS_LAYER_ON(1) && (active_anim != anim_1)) {
            active_anim      = anim_1;
            active_anim_size = (sizeof(anim_1) / IMG_FRAME_SIZE);
            anim_frame_index = 0;
        } else if (IS_LAYER_ON(2) && (active_anim != anim_2)) {
            active_anim      = anim_2;
            active_anim_size = (sizeof(anim_2) / IMG_FRAME_SIZE);
            anim_frame_index = 0;
        } else if (IS_LAYER_ON(3) && (active_anim != anim_3)) {
            active_anim      = anim_3;
            active_anim_size = (sizeof(anim_3) / IMG_FRAME_SIZE);
            anim_frame_index = 0;
        }

        anim_frame_index = (anim_frame_index + 1) % active_anim_size;
        anim_timer       = timer_read();
    }

    oled_write_raw(active_anim[anim_frame_index], IMG_FRAME_SIZE);
}

bool oled_task_user(void) {
    render_anim();
    return false;
}

#endif
