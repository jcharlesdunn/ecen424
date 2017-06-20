	.file	"sum.c"
	.text
	.globl	sum_list
	.type	sum_list, @function
sum_list:
.LFB0:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L4
	movl	$0, %eax
.L3:
	addq	(%rdi), %rax
	movq	8(%rdi), %rdi
	testq	%rdi, %rdi
	jne	.L3
	rep ret
.L4:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	sum_list, .-sum_list
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
