[GLOBAL reloadRegs]
reloadRegs:
  mov ax, 0x08
  mov ds, ax
  jmp reload:0x08
reload:
  ret