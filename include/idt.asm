global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15
 
global load_idt
 
global _irq0_handler
global _irq1_handler
global _irq2_handler
global _irq3_handler
global _irq4_handler
global _irq5_handler
global _irq6_handler
global _irq7_handler
global _irq8_handler
global _irq9_handler
global _irq10_handler
global _irq11_handler
global _irq12_handler
global _irq13_handler
global _irq14_handler
global _irq15_handler
 
extern _irq0_handler
extern _irq1_handler
extern _irq2_handler
extern _irq3_handler
extern _irq4_handler
extern _irq5_handler
extern _irq6_handler
extern _irq7_handler
extern _irq8_handler
extern _irq9_handler
extern _irq10_handler
extern _irq11_handler
extern _irq12_handler
extern _irq13_handler
extern _irq14_handler
extern _irq15_handler
 
irq0:
  pusha
  call _irq0_handler
  popa
  iret
 
irq1:
  pusha
  call _irq1_handler
  popa
  iret
 
irq2:
  pusha
  call _irq2_handler
  popa
  iret
 
irq3:
  pusha
  call _irq3_handler
  popa
  iret
 
irq4:
  pusha
  call _irq4_handler
  popa
  iret
 
irq5:
  pusha
  call _irq5_handler
  popa
  iret
 
irq6:
  pusha
  call _irq6_handler
  popa
  iret
 
irq7:
  pusha
  call _irq7_handler
  popa
  iret
 
irq8:
  pusha
  call _irq8_handler
  popa
  iret
 
irq9:
  pusha
  call _irq9_handler
  popa
  iret
 
irq10:
  pusha
  call _irq10_handler
  popa
  iret
 
irq11:
  pusha
  call _irq11_handler
  popa
  iret
 
irq12:
  pusha
  call _irq12_handler
  popa
  iret
 
irq13:
  pusha
  call _irq13_handler
  popa
  iret
 
irq14:
  pusha
  call _irq14_handler
  popa
  iret
 
irq15:
  pusha
  call _irq15_handler
  popa
  iret
 
load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret