/* Assignment: OLA2
 * Class: CSCI3130 - 001
 * Filename: asm_program.asm
 * Author: William Hampton
 * Due: 9/20/18
 * Description - x86_64 assembly program that multiplies a sum and a difference. 
 *		 Of the form (W - X) + (Z + Y)
*/

.global main

.text
main:		
		mov $0, %r8			/* r8 will act as loop control */
		mov $arr, %rbx			/* rbx stores the array address */
		
loop:
		cmp $16, %r8			/* while r8 < 16 */
		je done				
		mov (%rbx), %r12		/* put 1st of current 4 nums in r12 */
		push %r8			/* push rdi (1st num in arr) to keep val after printf */
		mov $strf, %rdi			/* use printf to print the open paren */	
		mov $oparen, %rsi
		mov $0, %rax
		call printf		
		mov %r12, %rsi			/* print first number */
		mov $midint, %rdi		/* integer printf format with no newline */
		mov $0, %rax
		call printf
		add $8, %rbx			/* add # bytes to address of arr for 2nd num */
		mov (%rbx), %r13		/* 2nd of current 4 nums in r13 */
		mov $strf, %rdi			/* print minus sign using a call to printf */
		mov $minus, %rsi		
		mov $0, %rax
		call printf
		mov $midint, %rdi		/* print 2nd number of array */
		mov %r13, %rsi
		mov $0, %rax
		call printf
		add $8, %rbx			/* add # bytes to address of arr for 3rd num */
		mov $strf, %rdi			/* print closing parenthesis */
		mov $cparen, %rsi
		mov $0, %rax
		call printf
		mov $strf, %rdi			/* print multiplication operator */
		mov $times, %rsi
		mov $0, %rax
		call printf
                mov $strf, %rdi			/* print another open parenthesis */
                mov $oparen, %rsi
                mov $0, %rax
                call printf	
		mov (%rbx), %r14		/* 3rd of current 4 nums in r14 */
		mov %r14, %rsi                  /* print 3rd number */
                mov $midint, %rdi
                mov $0, %rax
		add $8, %rbx
                call printf
                mov $strf, %rdi                 /* print a plus sign */
                mov $plus, %rsi
                mov $0, %rax
                call printf
		mov (%rbx), %r15		/* 4th of current 4 nums in r15 */
                mov %r15, %rsi                  /* print 4th number */
                mov $midint, %rdi
                mov $0, %rax
                call printf
                mov $strf, %rdi			/* print a closed parenthesis */
                mov $cparen, %rsi
                mov $0, %rax
		call printf                 
                mov $strf, %rdi                 /* print the equals sign */
                mov $equals, %rsi
                mov $0, %rax
                call printf
		add $8, %rbx
		call function			/* calculate */
		mov %rax, %rsi			/* copy result of function evaluation to rsi */
		mov $intf, %rdi			/* print result of calculation */
		mov $0, %rax			
		call printf
		pop %r8		
		add $4, %r8
		jmp loop

function:
		sub %r12, %r13		/* r12 - r13 */
		add %r15, %r14		/* r15 + r14 */
		mov %r13, %rax		/* put result of r12 - r13 into rax in prep for mult */
		mul %r14		/* result of r14 * result is in rax */
		ret

done:
	ret



.data
count:	.quad	0		/* stores position of array */
oparen: .ascii  "(\0"		/* oparen through equals are for output */
cparen: .ascii  ")\0"
plus:   .ascii  " + \0"
minus:  .ascii  " - \0"
times:  .ascii  " * \0"
equals: .ascii  " = \0"
strf:   .ascii  "%s\0"		/* used to print the characters in output */
midint: .ascii  "%ld\0"		/* used to print a number without newline*/ 
intf:	.ascii  "%ld\n\0"
arr:	.quad	2, 3, 4, 5, 7, 6, 8, 1, 5, 4, 6, 3, 4, 6, 3, 7		/* declare an array of 16 64-bit integers*/
