#include <stdio.h>

int	printnum(char *name, int num)
{
	int	ret;

	ret = 0;
	if trlen(name) > 0)
		ret = printf("%-20s", name);
	ret += printf("%d\n", num);
	return (ret);
}

int	printfloat(char *name, float num)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret += printf("%f\n", num);
	return (ret);
}

int	printstr(char *name, char *str)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret += printf("%s\n", str);
	return (ret);
}

int	printchar(char *name, char c)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret += printf("%c\n", c);
	return (ret);
}

int	printco(char *name, int x, int y)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret = printf("( %d, %d )\n", x, y);
	return (ret);
}

int	printflco(char *name, double x, double y)
{
	int	ret;

	ret = 0;
	if (strlen(name) > 0)
		ret = printf("%-20s", name);
	ret = printf("( %f, %f )\n", x, y);
	return (ret);
}