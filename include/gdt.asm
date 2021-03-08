global load_gdt

jmp load_gdt ; Jump to the
; global descriptor table loading

gdt:

gdt_null: ; Null descriptor
    dq 0

gdt_code: ; Code descriptor
    dw 0FFFFh
    dw 0

gdt_data: ; Data descriptor
    dw 0FFFFh
    dw 0 
    db 0
    db 10010010b
    db 11001111b
    db 0
 
gdt_end:

gdt_desc:
    dw gdt_end - gdt - 1
    dd gdt

load_gdt:
    cli ; disable interrupts,
    ; we'll enable then later
    lgdt [gdt_desc]
    sti ; enable them