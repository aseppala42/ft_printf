#include "includes/ft_printf.h"
#include <time.h>
#include <stdio.h>
     
int	main()
{
	clock_t start, end;
	double time;
	char *print = "%s%s%s Kivaa %u aaaa\n%s";
	long d = 77;
	int a = 42;
	double f = -123.1234567891011;
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

	ft_printf("%lld\n", -9223372036854775808);
	printf("%lld\n", -9223372036854775808);
	ft_printf("%lx\n", 4294967296);
	printf("%lx\n", 4294967296);

	ft_printf("%*.*d\n", 0, 3, 0);
	printf("%*.*d\n", 0, 3, 0);

	ft_printf("%.0p, %.p\n", 0, 0);
	printf("%.0p, %.p\n", 0, 0);

  ft_printf("%x\n", -42);
  printf("%x\n", -42);

  ft_printf("%X\n", -42);
  printf("%X\n", -42);

  ft_printf("%x\n", 4294967296);
  printf("%x\n", 4294967296);

  ft_printf("%X\n", 4294967296);
  printf("%X\n", 4294967296);

  ft_printf("%lx\n", 4294967296);
  printf("%lx\n", 4294967296);

  ft_printf("%llX\n", 4294967296);
  printf("%llX\n", 4294967296);

  ft_printf("%llx\n", 9223372036854775807);
  printf("%llx\n", 9223372036854775807);

  ft_printf("%llx\n", 9223372036854775808);
  printf("%llx\n", 9223372036854775808);

  ft_printf("%#llx\n", 9223372036854775807);
  printf("%#llx\n", 9223372036854775807);

  ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
  printf("@moulitest: %#.x %#.0x\n", 0, 0);

  ft_printf("@moulitest: %.x %.0x\n", 0, 0);
  printf("@moulitest: %.x %.0x\n", 0, 0);

  ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
  printf("@moulitest: %5.x %5.0x\n", 0, 0);

  ft_printf("%.2c\n", NULL);
  printf("%.2c\n", NULL);

  ft_printf("@moulitest: %c\n", 0);
  printf("@moulitest: %c\n", 0);

  ft_printf("%2c\n", 0);
  printf("%2c\n", 0);

  ft_printf("null %c and text\n", 0);
  printf("null %c and text\n", 0);

  ft_printf("% c\n", 0);
  printf("% c\n", 0);

  ft_printf("@moulitest: %.o %.0o\n", 0, 0);
  printf("@moulitest: %.o %.0o\n", 0, 0);

  ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
  printf("@moulitest: %5.o %5.0o\n", 0, 0);

  ft_printf("%hd\n", 32767);
  printf("%hd\n", 32767);

  ft_printf("%hd\n", 32768);
  printf("%hd\n", 32768);

  ft_printf("%hhd\n", 128);
  printf("%hhd\n", 128);

  ft_printf("%hhd\n", -129);
  printf("%hhd\n", -129);

  ft_printf("%ld\n", 2147483647);
  printf("%ld\n", 2147483647);

  ft_printf("%ld\n", -2147483648);
  printf("%ld\n", -2147483648);

  ft_printf("%ld\n", 2147483648);
  printf("%ld\n", 2147483648);

  ft_printf("%ld\n", -2147483649);
  printf("%ld\n", -2147483649);

  ft_printf("%lld\n", 9223372036854775807);
  printf("%lld\n", 9223372036854775807);

  ft_printf("%lld\n", -9223372036854775808);
  printf("%lld\n", -9223372036854775808);

  ft_printf("@moulitest: %.d %.0d\n", 0, 0);
  printf("@moulitest: %.d %.0d\n", 0, 0);

  ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
  printf("@moulitest: %5.d %5.0d\n", 0, 0);

  ft_printf("%u\n", -1);
  printf("%u\n", -1);

  ft_printf("%u\n", 4294967296);
  printf("%u\n", 4294967296);

  ft_printf("% u\n", 4294967295);
  printf("% u\n", 4294967295);

  ft_printf("%lu\n", 4294967295);
  printf("%lu\n", 4294967295);

  ft_printf("%lu\n", 4294967296);
  printf("%lu\n", 4294967296);

  ft_printf("%lu\n", -42);
  printf("%lu\n", -42);

  ft_printf("%llu\n", 4999999999);
  printf("%llu\n", 4999999999);

	ft_printf("%*s\n", -32, "abc");
	printf("%*s\n", -32, "abc");

	ft_printf("%-32s\n", "abc");
	printf("%-32s\n", "abc");

	ft_printf("{%*3d}\n", 5, 0);
	printf("{%*3d}\n", 5, 0);

	ft_printf("{%.c}\n", 0);
	printf("{%.c}\n", 0);

	ft_printf("{%*c}\n", 0, 0);
	printf("{%*c}\n", 0, 0);

	ft_printf("%#c\n", 0);
	printf("%#c\n", 0);

	ft_printf("{%c}\n", 0);
	printf("{%c}\n", 0);

	ft_printf("{%3c}\n", 0);
	printf("{%3c}\n", 0);

	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);

	ft_printf("{%#c}\n", 0);
	printf("{%#c}\n", 0);

	ft_printf("%\n");
	printf("%\n");
	return (0);
}
