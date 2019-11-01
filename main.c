#include <stdio.h>
#include "header.h"

int main(int argc, char **argv)
{
	ASSERT_PRINTF("%d", 10);
	ASSERT_PRINTF("%   asdf");
	ASSERT_PRINTF("%fsdf", 5.3);

	return 0;
}
