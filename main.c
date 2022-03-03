#include <stdio.h>
#include <string.h>

typedef enum PCAction {
    Step,
    Jump
} PCAction;

typedef struct CPU {
    int pc;
    int memory[4096];
    int acc;
    int overflow;
} CPU;

CPU new_cpu() {
    struct CPU cpu;
    cpu.pc = 0;
    cpu.acc = 0;
    cpu.overflow = 0;
    memset(cpu.memory, 0, sizeof(cpu.memory));
    return cpu;
}

PCAction set_value(CPU* cpu, int value) {
    printf("set_value\n");
    cpu->acc = value;
    return Step;
}

void jump(CPU* cpu, int addr) {
    cpu->pc = addr;
}

void step(CPU* cpu) {
    int current_address = cpu->pc * 2;
    int operation = (cpu->memory[current_address] & 0xF0) >> 4;
    int value = cpu->memory[current_address+1];
    int address = ((cpu->memory[current_address] & 0x0F) << 8) | value;
    /* printf("%i\n", cpu->memory[current_address]);
    printf("%i\n", current_address);
    printf("%i\n", operation);
    printf("%i\n", address);
    printf("%i\n", value); */
    switch(operation) {
        case 0x0:
            printf("hit 0x0");
            step(cpu);
    }
}

int main() {
    struct CPU cpu;
    cpu = new_cpu();
    step(&cpu);
}
