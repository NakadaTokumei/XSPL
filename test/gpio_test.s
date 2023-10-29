	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 1
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"gpio_test.cc"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	.fnstart
.LFB8:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L4
	ldr	r2, [r3]
	bic	r2, r2, #12
	str	r2, [r3]
	ldr	r2, [r3]
	orr	r2, r2, #12
	str	r2, [r3]
	ldr	r2, [r3]
	bic	r2, r2, #24
	str	r2, [r3]
	ldr	r2, [r3]
	str	r2, [r3]
	ldr	r2, [r3]
	bic	r2, r2, #48
	str	r2, [r3]
	ldr	r2, [r3]
	str	r2, [r3]
	ldr	r2, [r3]
	bic	r2, r2, #24
	str	r2, [r3]
	ldr	r2, [r3]
	str	r2, [r3]
	ldr	r3, [r3, #8]
	tst	r3, #4
	beq	.L2
	ldr	r2, .L4
	ldr	r3, [r2, #12]
	orr	r3, r3, #1
	str	r3, [r2, #12]
.L3:
	movs	r0, #0
	bx	lr
.L2:
	ldr	r2, .L4
	ldr	r3, [r2, #20]
	orr	r3, r3, #1
	str	r3, [r2, #20]
	b	.L3
.L5:
	.align	2
.L4:
	.word	1073813504
	.cantunwind
	.fnend
	.size	main, .-main
	.ident	"GCC: (Arm GNU Toolchain 12.3.Rel1 (Build arm-12.35)) 12.3.1 20230626"
