#include "cj_shell.h"

/**
 * cj_print - Custom print function that writes
 *            to standard output
 * @output: THe string to be printed
 */

void cj_print(const char *output)
{
	fputs(output, stdout);
}
