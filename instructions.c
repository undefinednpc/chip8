#include "instructions.h"

void clear(Chip8* chip8) {
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
	for(int j = 0; i < SCREEN_WIDTH; j++) {
	    chip8->screen[i][j] = 0;
	}
    }
}

void jump(Chip8* chip8) {
    uint16_t nnn = chip8->current_op & 0x0FFF;
    chip8-pc_reg = nnn;
}
