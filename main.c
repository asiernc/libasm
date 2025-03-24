#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

# define STRLEN(x)	printf("Str '%s' ==> %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)  printf("S1 '%s' S2 '%s' ==> %d (%d)\n", a, b, ft_strcmp(a,b), (int)strcmp(a, b));

int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, char *s2);
int		ft_write(int fd, char *buffer, int bytes);

int main(void) {
	char s1[100] = "Asier";
	char s2[100];

	STRLEN("Asier");
	STRCMP("Toni", "Toni");
	STRCMP("Asier", "Harry");
	ft_strcpy(s2, s1);
	printf("STRCPY -> %s\n", s2);

	int i = ft_write(-1, "Hello world\n", 10);
	printf("return del write : %d\n", i);
	return (0);
}