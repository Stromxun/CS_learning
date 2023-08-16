	.file	"practice3.26.c"
	.text
	.globl	fun_a
	.type	fun_a, @function
fun_a:
.LFB23:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	jmp	.L2
.L3:
	xorq	%rdi, %rax
	shrq	%rdi
.L2:
	testq	%rdi, %rdi
	jne	.L3
	andl	$1, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	fun_a, .-fun_a
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
