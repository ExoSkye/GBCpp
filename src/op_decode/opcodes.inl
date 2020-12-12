startOpcode(0xCE)
opCode(
        if ((uint16_t)regs->A + (extra8) > 0b11111111) {
            flags->carry = true;
        }
        regs->A += extra8;
)
endOpcode()
startOpcode(0x8E)
opCode(
        if (reg16->HL() + (uint16_t)regs->A > 0b11111111) {
            flags->carry = true;
        }
        regs->A += reg16->HL();
        )
endOpcode()
