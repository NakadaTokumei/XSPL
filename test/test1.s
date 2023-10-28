	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"test1.cc"
	.text
	.section	.text.startup,"ax",%progbits
	.align	1
	.p2align 2,,3
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	.fnstart
.LFB7:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, .L3
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
	orr	r2, r2, #16
	str	r2, [r3]
	ldr	r2, [r3]
	bic	r2, r2, #24
	str	r2, [r3]
	ldr	r2, [r3]
	str	r2, [r3]
	ldr	r2, [r3, #12]
	orr	r2, r2, #1
	str	r2, [r3, #12]
	ldr	r2, [r3, #20]
	orr	r2, r2, #1
	movs	r0, #0
	str	r2, [r3, #20]
	bx	lr
.L4:
	.align	2
.L3:
	.word	1073813504
	.cantunwind
	.fnend
	.size	main, .-main
	.ident	"GCC: (Arm GNU Toolchain 12.3.Rel1 (Build arm-12.35)) 12.3.1 20230626"
