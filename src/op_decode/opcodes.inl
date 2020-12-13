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
startOpcode(0x3B)
opCode(
        reg16->SP-= 1;
)
endOpcode()
//TODO: Implement system clock
/*
startOpcode(0x76) //HALT
opCode(

)
endOpcode()
*/
startOpcode(0x34)
opCode (
       reg16->HL+= 1;
)
endOpcode()
startOpcode(0x3C)
opCode (
       regs->A+= 1;
)
endOpcode()
startOpcode(0x04)
opCode (
       regs->B+= 1;
)
endOpcode()
startOpcode(0x04)
opCode (
       regs->B+= 1;
)
endOpcode()
startOpcode(0x03)
opCode (
       reg16->BC+= 1;
)
endOpcode()
startOpcode(0x0C)
opCode (
        regs->C+= 1;
)
endOpcode()
startOpcode(0x14)
opCode (
        regs->D+= 1;
)
endOpcode()
startOpcode(0x13)
opCode (
        reg16->DE+= 1;
)
endOpcode()
startOpcode(0x1C)
opCode (
        regs->E+= 1;
)
endOpcode()
startOpcode(0x24)
opCode (
        regs->H+= 1;
)
endOpcode()
startOpcode(0x23)
opCode (
        reg16->HL+= 1;
)
endOpcode()
startOpcode(0x2C)
opCode (
        regs->L+= 1;
)
endOpcode()
startOpcode(0x33)
opCode (
        reg16->SP+= 1;
)
endOpcode()