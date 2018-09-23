/* Assignment: OLA1
 * Class: CSCI3130 - 001
 * Filename: asm_program.asm
 * Author: William Hampton
 * Date: 9/4/18
 * Description: this program calls a C function, c_function, to print a message to stdout
*/

.global main
.text

main:
		mov $haiku, %rdi		/* copy the haiku into rdi, which corresponds to the second argument of write() */
		call  c_function		/* call c_function, which passes haiku in as an argument */

.data
haiku:		.ascii		"Data moving in\nAnd data moving out too\nRegister Haiku\nAuthor: William Hampton\n"
