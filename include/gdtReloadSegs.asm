bits 32
section .text

[GLOBAL reloadRegs]
reloadRegs:
  mov ax, 0x08
  ; Triple fault located here:
  mov ds, ax
  jmp reload:0x08
reload:
  ret