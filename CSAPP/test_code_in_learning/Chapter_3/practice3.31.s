	.file	"practice3.31.c"
	.text
	.globl	switcher
	.type	switcher, @function
switcher:
.LFB23:
	.cfi_startproc
	endbr64
	cmpq	$7, %rdi
	ja	.L2
	leaq	.L4(%rip), %r8
	movslq	(%r8,%rdi,4), %rax
	addq	%r8, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.text
.L6:
	movq	%rdi, %rsi
	jmp	.L2
.L5:
	movq	%rsi, %rdx
	xorq	$15, %rdx
.L7:
	leaq	112(%rdx), %rsi
.L2:
	movq	%rsi, (%rcx)
	ret
.L3:
	addq	%rdx, %rsi
	salq	$2, %rsi
	jmp	.L2
	.cfi_endproc
.LFE23:
	.size	switcher, .-switcher
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
