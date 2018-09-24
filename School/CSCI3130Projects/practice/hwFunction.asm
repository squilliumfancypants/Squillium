/* A hello world program that uses a function call */

.global main
.text

main:
		mov $message, %rdi		/* put the string in rdi */
		mov $13, %rsi			/* number of bytes */
		call hwFunction
		syscall

hwFunction:
		mov %rsi, %rdx			/* copy # bytes into rdx */
		mov %rdi, %rsi			/* copy string into rsi */
		mov $1, %rax			/* syscall 1 is write */
		mov $1, %rdi			/* file handle 1 is stdout */
		ret

.data
message:	.ascii "Hello, World\n"
