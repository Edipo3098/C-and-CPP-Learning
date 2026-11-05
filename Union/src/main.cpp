#include <stdio.h>
union HWRegister{
    struct{
        unsigned char control;
        unsigned char direction;
        unsigned char parity;
        unsigned char stopbits;
    };
    unsigned int reg;
};

int main()
{
    union HWRegister reg;
    reg.reg = 0x12345678;
    printf("Control: %X\n", reg.control);
    printf("Direction: %X\n", reg.direction);
    printf("Parity: %X\n", reg.parity);
    printf("Stop Bits: %X\n", reg.stopbits);
    return 0;
}