#define NUM_KEYS 16
#define NUM_V_REGISTERS 16
#define RAM 4096
#define STACK_SIZE 16
#define PC_START 0x200
#define TIMER_MAX 255

#define CHIP8_RAM_START_ADDR 0x000
#define CHIP8_RAM_END_ADDR 0x1FF
#define PROGRAM_START_ADDR 0x200
#define PROGRAM_END_ADDR 0xFFF

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

#define TRUE 1
#define FALSE 0

typedef struct Chip8_t Chip8;

struct Chip8_t {
    uint8_t ram[RAM];
    uint16_t stack[STACK_SIZE];

    // screen
    uint8_t screen[SCREEN_WIDTH][SCREEN_HEIGHT];

    // registers
    uint16_t pc_reg;
    uint16_t I_reg;
    uint16_t sp_reg;
    

    // timers
    uint8_t delay_timer;
    uint8_t sound_timer;

    uint16_t current_op;

    // keys
    uint8_t keyboard[NUM_KEYS];
    uint8_t was_key_pressed;

    // status
    uint8_t is_running;
    uint8_t draw_screen;
    uint8_t is_paused;
}
