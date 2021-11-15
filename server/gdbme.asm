GLOBAL gdbme

gdbme:
    xor rax, rax
    mov rax, 20
    int 80h
    cmp eax, 0x12345678
    jz .iguales
    xor rax, rax
    ret
.iguales:
    mov rax, 1
    ret
