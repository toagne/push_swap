#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
char	**split_for_argc_2(char **str,char **new_str, int argc)
{
	int		c;
	char	**temp;

	temp = NULL;
	c = 0;
    if (argc == 2)
	{
        temp = ft_split(str[1], ' ');
		while (temp[c])
			c++;
		new_str = (char **)malloc(sizeof(char *) * (c + 2));
		new_str[0] = NULL;
		new_str[c + 1] = NULL;
		while (c--)
			new_str[c + 1] = temp[c];
	}
    else
        new_str = str;
	free(temp);
	return (new_str);
}

int main(void)
{
	char *str[2];
	int n = 2;
	char **new_str;
	int c = 1;

	new_str = NULL;
	str[0] = "a.out";
	str[1] = "1 5 4 6 8";
	new_str = split_for_argc_2(str, new_str, n);
	while (new_str[c])
	{
		printf("%s\n", new_str[c]);
		c++;
	}
}
