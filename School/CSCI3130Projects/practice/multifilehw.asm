/* calls an assembly function to print a message to the screen */

.global main
.text

main:
		mov $message, %rdi		/* put message in rdi */
		mov $13, %rsi			/* number of bytes */
		call hwCFunction

.data
message:	.ascii		"Hello, World \n"
