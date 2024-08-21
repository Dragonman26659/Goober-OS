org 0x7c00
bits 16

%define ENDL 0x0d, 0x0A


; Entry point
start:
    jmp main


;
;   Print a string to the screen.
;   Params:
;       - ds:si points to a string
;
puts:
    ; save registers we will modify
    push si
    push ax

.loop:
    lodsb          ; loads next charater in al
    or al, al       ; verify if next charater is null
    jz .done

    mov ah, 0x0e
    mov bh, 0
    int 0x10

    jmp .loop

.done:
    pop ax
    pop si
    ret



main:
    ; Setup data segments
    mov ax, 0           ; cant write to ds/es directly
    mov ds, ax
    mov es, ax

    ; setup stack
    mov ss, ax
    mov sp, 0x7C00      ; Stack grows downwards from where we are located in memory
    
    ; print message
    mov si, msg_hello
    call puts

    hlt

.halt:
    jmp .halt


msg_hello: db 'Hello world!', ENDL, 0

times 510-($-$$) db 0
dw 0AA55h