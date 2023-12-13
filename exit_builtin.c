#include "cj_shell.h"

/**
 * cj_exit - Exits the shell
 */

void cj_exit(void)
{
	cj_print("Exiting shell.\n");
	exit(EXIT_SUCCESS);
}
