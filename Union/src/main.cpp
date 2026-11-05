#include <cstdint>
#include <cstdio>
#include <cstring>

struct RegisterFields {
    unsigned char control;
    unsigned char direction;
    unsigned char parity;
    unsigned char stopbits;
};

union HWRegister {
    RegisterFields fields;
    std::uint32_t reg;
};

int main() {
    // Read only the active member of the union.
    HWRegister value{};
    value.fields = {0x78, 0x56, 0x34, 0x12};
    std::printf("Control: %X\n", static_cast<unsigned>(value.fields.control));
    std::printf("Direction: %X\n", static_cast<unsigned>(value.fields.direction));
    std::printf("Parity: %X\n", static_cast<unsigned>(value.fields.parity));
    std::printf("Stop Bits: %X\n", static_cast<unsigned>(value.fields.stopbits));

    value.reg = UINT32_C(0x12345678); // reg is now the active member.
    unsigned char bytes[sizeof value.reg]{};
    std::memcpy(bytes, &value.reg, sizeof bytes);
    std::printf("Register: %08X\n", static_cast<unsigned>(value.reg));
    std::printf("Object bytes (native byte order):");
    for (unsigned char byte : bytes) {
        std::printf(" %02X", static_cast<unsigned>(byte));
    }
    std::printf("\n");
    return 0;
}
