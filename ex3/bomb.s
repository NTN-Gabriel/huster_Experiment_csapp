	.file	"bomb.c"
	.text
	.globl	infile
	.bss
	.align 8
	.type	infile, @object
	.size	infile, 8
infile:
	.zero	8
	.globl	studentid
	.align 8
	.type	studentid, @object
	.size	studentid, 11
studentid:
	.zero	11
	.section	.rodata
	.align 8
.LC0:
	.string	"The student number has 10 characters, such as U202315001 "
.LC1:
	.string	"welcome  %s \n"
	.align 8
.LC2:
	.string	" gcc  -g -o binarybomb -D U* bomb.c  support.c  phase.o"
	.align 8
.LC3:
	.string	" U* : * is the last number of your Student Id . "
	.align 8
.LC4:
	.string	" example :  U202315001  ->   -D U1 . "
	.text
	.globl	initialize_bomb
	.type	initialize_bomb, @function
initialize_bomb:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$1, -28(%rbp)
	movl	$2, -24(%rbp)
	movl	$3, -20(%rbp)
	movl	$4, -16(%rbp)
	movl	$5, -12(%rbp)
	movl	$6, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -4(%rbp)
	cmpl	$10, -4(%rbp)
	je	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %edi
	call	exit@PLT
.L2:
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	studentid(%rip), %rax
	movq	%rax, %rdi
	call	strcpy@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	initialize_bomb, .-initialize_bomb
	.section	.rodata
.LC5:
	.string	"r"
.LC6:
	.string	"%s: Error: Couldn't open %s\n"
.LC7:
	.string	"Usage: %s [<input_file>]\n"
.LC8:
	.string	"Input your Student ID : "
.LC9:
	.string	"You have 6 bombs to defuse! "
	.align 8
.LC10:
	.string	"Gate 1 :  input a string that meets the requirements. "
.LC11:
	.string	"Phase 1 passed! "
	.align 8
.LC12:
	.string	"Gate 2 :  input six intergers that meets the requirements. "
.LC13:
	.string	"Phase 2 passed! "
.LC14:
	.string	"Gate 3 :  input 2 intergers. "
.LC15:
	.string	"Phase 3 passed! "
	.align 8
.LC16:
	.string	"Gate 4 :  input 2 intergers and a string. "
.LC17:
	.string	"Phase 4 passed! "
.LC18:
	.string	"Gate 5 :  input  a string. "
.LC19:
	.string	"Phase 5 passed! "
.LC20:
	.string	"Gate 6 :  input 6 intergers. "
.LC21:
	.string	"Phase 6 passed! "
	.align 8
.LC22:
	.string	"Congratulations! You have passed all the tests! "
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L4
	movq	stdin(%rip), %rax
	movq	%rax, infile(%rip)
	jmp	.L5
.L4:
	cmpl	$2, -20(%rbp)
	jne	.L6
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC5(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, infile(%rip)
	movq	infile(%rip), %rax
	testq	%rax, %rax
	jne	.L5
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$8, %edi
	call	exit@PLT
.L6:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$8, %edi
	call	exit@PLT
.L5:
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	initialize_bomb
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_1@PLT
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_2@PLT
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_3@PLT
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_4@PLT
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_5@PLT
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	call	read_line@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	phase_6@PLT
	leaq	.LC21(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC22(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
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
