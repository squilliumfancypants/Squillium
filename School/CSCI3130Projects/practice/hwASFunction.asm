/* A function that prints a message to stdout */

.global hwASFunction
.text

hwASFunction:
		mov %rsi, %rdx		/* move the message into rdx */
		mov %rdi, %rsi		/* move the string length into rsi */
		mov $1, %rax		/* syscall 1 is write */
		mov $1, %rdi		/* file handle 1 is stdout */
		syscall			/* write to stdout */
		ret

