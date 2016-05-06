.thumb @make the assembler assemble it in thumb
.global load_icons @make it a global function
.thumb_func @make the assembler know that the function is in thumb
load_icons:
push {r4-r7,lr}
sub sp, sp, #0x8
ldr r4, =pal_graphics
mov r0, r4
ldr r3, =0x8008929
bl bx_r3
add r4, #8
mov r0, r4
ldr r3, =0x8008929
bl bx_r3
add r4, #8
mov r0, r4
ldr r3, =0x8008929
bl bx_r3
mov r4, sp
ldr r0, =0x83CE7F0
str r0, [r4]
ldr r0, =0x1303
str r0, [r4, #4]
mov r0, sp
ldr r3, =0x8008929
bl bx_r3
ldr r0, =0x83D2BEC
str r0, [r4]
ldr r0, =0x1406
strh r0, [r4, #6]
ldr r0, =0x400
strh r0, [r4, #4]
mov r0, sp
ldr r3, =0x80086DD
bl bx_r3

check_start:
ldr r0, =0x2024029
ldrb r4, [r0] @pokemon_quanitity
mov r5, #0

loop:
ldr r0, =0x2024284
mov r1, #0x64
mul r1, r5
add r0, r1, r0
bl egg_check
cmp r0, #1
beq load_icon_egg
ldr r0, =0x2024284
mov r1, #0x64
mul r1, r5
add r0, r1, r0
bl get_species
cmp r0, #0
beq back

load_icon_image:
mov r7, r0
ldr r1, =0x83D37A0
lsl r0, r0, #2
add r0, r1, r0
ldr r0, [r0]
str r0, [sp]
ldr r0, =0x400
mov r1, sp
strh r0, [sp, #4]
ldr r0, =0x1400
add r0, r5, r0
strh r0, [r1, #6]
mov r0, sp
ldr r3, =0x80086DD
bl bx_r3
bl obj_spawn
add r5, #1
cmp r5, r4
bne loop
b back

load_icon_egg:
ldr r0, =0x8E7BB88
str r0, [sp]
ldr r0, =0x400
mov r1, sp
strh r0, [sp, #4]
ldr r0, =0x1400
add r0, r5, r0
strh r0, [r1, #6]
mov r0, sp
ldr r3, =0x80086DD
bl bx_r3
mov r7, #0xFF
bl obj_spawn
add r5, #1
cmp r5, r4
bne loop

back:
bl load_hand
add sp, sp, #0x8
pop {r4-r7,pc}
.ltorg @same as .pool?

get_species:
push {lr}
mov r1, #0xB
ldr r3, =0x803FBE9
bl bx_r3
pop {pc}
.ltorg

egg_check:
push {lr}
mov r1, #0x2D
ldr r3, =0x803FBE9
bl bx_r3
pop {pc}
.ltorg

obj_spawn:
push {r4,lr}
sub sp, sp, #0x18
mov r1, sp
ldr r0, =0x1400
add r0, r5
strh r0, [r1]
cmp r7, #0xFF
beq spawn_egg
ldr r0, =0x83D3E80
add r0, r7, r0
ldrb r0, [r0]
b spawn_back

spawn_egg:
mov r0, #1

spawn_back:
ldr r2, =0x1300
add r0, r2, r0
strh r0, [r1, #2]
ldr r0, =image_anims
str r0, [r1, #8]
ldr r0, =oam
str r0, [r1, #4]
mov r0, #0
str r0, [r1, #12]
ldr r0, =0x800760D
str r0, [r1, #0x14]
ldr r0, =rotscale
str r0, [r1, #0x10]
bl load_coords
mov r0, sp
mov r3, #0
ldr r4, =0x8006F8D
bl bx_r4
add sp, sp, #0x18
pop {r4, pc}
.ltorg

load_coords:
cmp r5, #3
blt upper
mov r0, #32
sub r1, r5, #3
mul r0, r1
mov r1, #0x98
add r1, r0, r1
mov r2, #0x68
b coo_back

upper:
mov r0,#32
mul r0, r5
mov r1, #0x98
add r1, r0, r1
mov r2, #0x48

coo_back:
bx lr

load_hand:
push {r4, lr}
sub sp, sp, #0x18
mov r4, sp
ldr r0, =0x1406
strh r0, [sp]
ldrh r0, =0x1303
strh r0, [r4, #2]
ldr r0, =image_anims
str r0, [r4, #8]
ldr r0, =oam2
str r0, [r4, #4]
mov r0, #0
str r0, [r4, #12]
ldr r0, =0x800760D
str r0, [r4, #0x14]
ldr r0, =rotscale
str r0, [r4, #0x10]
mov r0, sp
mov r1, #0x9A
mov r2, #0x48
mov r3, #0
ldr r4, =0x8006F8D
bl bx_r4
ldr r4, =0x2039990
strb r0, [r4]
add sp, sp, #0x18
pop {r4, pc}
.ltorg

bx_r3:
bx r3

bx_r4:
bx r4

.align 2
pal_graphics:
.word 0x83D3740
.word 0x1300
.word 0x83D3760
.word 0x1301
.word 0x83D3780
.word 0x1302

image_anims:
.word img_anim

img_anim:
.hword 0,8,0x10,8,0xFFFE,0

oam:
.hword 0,0x8000,0x400,0

oam2:
.hword 0,0x8000,0,0

rotscale:
.word rot_null

rot_null:
.hword 0x100
.hword 0x100
.word 0x0
.hword 0x7FFF
.hword 0x0
.word 0x0