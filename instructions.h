#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "chip8.h"

void clear(Chip8* chip8);
void jump(Chip8* chip8);
void set_vx(Chip8* chip8);
void add_val_vx(Chip8* chip8);
void set_i_reg(Chip8* chip8);
void draw(Chip8* chip8);
