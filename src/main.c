#include <stdio.h>
#include "../includes/cub3d.h"

int main()
{
	if (!name_parser("..cub"))
		printf("ok\n");
	if (!name_parser("test.cub"))
		printf("ok\n");
	if (!name_parser(".cub"))
		printf("ko\n");
	if (!name_parser("caca.cu"))
		printf("ko\n");
	if (!name_parser("cu"))
		printf("ko\n");
	if (!name_parser("wqwqwqwqwwqwqw.cub.cub"))
		printf("ok\n");	
	return (0);
}