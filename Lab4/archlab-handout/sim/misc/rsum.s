	.file	"rsum.c"
	.text
	.p2align 4,,15
	.globl	rsum_list
	.type	rsum_list, @function
rsum_list:
.LFB0:
	.cfi_startproc
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L4
	.p2align 4,,10
	.p2align 3
.L3:
	movq	(%rdi), %rdx
	movq	8(%rdi), %rdi
	addq	%rdx, %rax
	testq	%rdi, %rdi
	jne	.L3
	rep ret
.L4:
	rep ret
	.cfi_endproc
.LFE0:
	.size	rsum_list, .-rsum_list
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
