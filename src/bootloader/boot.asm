org 0x7c00

;
; FAT12 HEADERS
;
jmp short start
nop

bdb_oem:                    db 'MSWIN4.1'           ; 8 bytes
bdb_bytes_per_sector:       dw 512
bdb_sectors_per_cluster:    db 1
bdb_reserved_sectors:       dw 1
bdb_fat_count:              db 2
bdb_dir_entries_count:      dw 0E0h
bdb_total_sectors:          dw 2880                 ; 1.44MB
bdb_media_descriptor_type:  db 0F0h                 ; F0 = 3.5" floppy disk
bdb_sectors_per_fat:        dw 9
bdb_sectors_per_track:      dw 18
bdb_heads:                  dw 2
bdb_hidden_sectors:         dd 0 
bdb_large_sector_count:     dd 0 

; extended boot record
ebr_drive_number:           db 0                    ; Useless
                            db 0                    ; Reserved
ebr_signature:              db 29h
ebr_volume_id:              db 12h, 34h, 56h, 78h   ; serial number, value dosent matter
ebr_volume_label:           db 'GOOBER OS  '        ; 11 bytes padded w spaces
ebr_system_id:              db 'FAT12   '           ; 8bytes




start:
    KERNEL_LOCATION equ 0x1000


    BOOT_DISK: db 0

    mov al, dl
    mov [BOOT_DISK], al

    ; setting up the stack

    xor ax, ax                          
    mov es, ax
    mov ds, ax
    mov bp, 0x8000
    mov sp, bp

    mov bx, KERNEL_LOCATION

    ; reading the disk

    mov ah, 2
    mov al, 1
    mov ch, 0
    mov dh, 0
    mov cl, 2
    mov dl, [BOOT_DISK]
    int 0x13


    mov ah, 0x0
    mov al, 0x3
    int 0x10


    CODE_SEG equ GDT_code - GDT_start
    DATA_SEG equ GDT_data - GDT_start

    cli
    lgdt [GDT_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:start_protected_mode

    jmp $
                                    
;   global discriptor table                   
GDT_start:                          ; must be at the end of real mode code
    GDT_null:
        dd 0x0
        dd 0x0

    GDT_code:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10011010
        db 0b11001111
        db 0x0

    GDT_data:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0

GDT_end:

GDT_descriptor:
    dw GDT_end - GDT_start - 1
    dd GDT_start


[bits 32]
start_protected_mode:
    ; Setup stack
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
    
    jmp KERNEL_LOCATION


times 510-($-$$) db 0
dw 0AA55h