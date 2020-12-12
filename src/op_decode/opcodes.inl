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
        reg16->SP--;
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
opCode {
       reg16->HL++;
}
endOpcode()
startOpcode(0x3C)
opCode {
       regs->A++;
}
endOpcode()
startOpcode(0x04)
opCode {
       regs->B++;
}
endOpcode()
startOpcode(0x04)
opCode {
       regs->B++;
}
endOpcode()
startOpcode(0x04)
opCode {
       regs->B++;
}
endOpcode()
startOpcode(0x03)
opCode {
       reg16->BC++;
}
endOpcode()
