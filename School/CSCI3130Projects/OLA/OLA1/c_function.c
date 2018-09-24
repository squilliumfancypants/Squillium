/* Assignment: OLA1
 * Class: CSCI3130 - 001
 * Author: William Hampton
 * Date: 9/04/18
 * Description: This function is called in the x86_64 assembly program asm_program.asm
 */

#include <unistd.h>
#include <string.h>

/* pre - an array of characters of size count */
/* prints a haiku to stdout using the write() function from unistd.h library */
void c_function( const char *haiku )
{
	write( 1, haiku, strlen() );
	return;
}
