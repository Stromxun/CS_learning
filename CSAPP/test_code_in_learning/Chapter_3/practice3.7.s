	.file	"practice3.7.c"
	.text
	.globl	scale2
	.type	scale2, @function
scale2:
.LFB23:
	.cfi_startproc
	endbr64
	leaq	(%rdi,%rdi,4), %rax
	leaq	(%rax,%rsi,2), %rax
	leaq	(%rax,%rdx,8), %rax
	ret
	.cfi_endproc
.LFE23:
	.size	scale2, .-scale2
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
