/* Practice with static memory allocation */

.global main
.text

main:
		mov	$str, %rdi		/* copy 1st val of str to rdi */
		mov	$14, %rsi		/* # of bytes */
		call	function		/* give control to function */
		ret

function:
		mov	%rsi, %rdx		/* copy # bytes to rdx */
		mov	%rdi, %rsi		/* copy 1st val of str to rsi*/
		mov	$str+14, %rsi	 	/* copy 2nd val of str to 1st*/
		mov	$1, %rax		/* syscall 1 is write */
		mov	$1, %rdi		/* file handle 1 is stdout */
		syscall				/* invoke os for write */
		ret				/* return control to main */

.data
str:	.ascii	"Hello, World\n\0", "Hi, Register\n\0"
