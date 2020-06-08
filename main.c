#include "ft_printf.h"
#include <time.h>
#include <stdio.h>
     
int	main()
{
	clock_t start, end;
	double time;
	char *print = "%s%s%s Kivaa %X aaaa\n%s";
	long d = 77;
	int a = -42;
	double f = 123.1234567891011;
	char *s = "kalakukko123";
	char *n = 0;
	char *ns = "\0";
	char nc = 0;

	start = clock();
//	ft_printf("");
	ft_printf(print, "\x1B[1m", "ft_printf:", GRN, a,  RESET);
	end = clock();
	time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", time);

	start = clock();
//	printf("");
	printf(print, "\e[3m", "nr_printf:", GRN, a, RESET);
	end = clock();
	time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f\n", time);
/*	ft_printf("%#llx", 9223372036854775807);
	printf("\n");
	printf("%#llx", 9223372036854775807);
	printf("\n");
	ft_putstr(ft_uimaxtoa(4294967296, 16));
*/
	ft_printf("%");
	return (0);
}
