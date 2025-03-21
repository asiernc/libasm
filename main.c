#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define STRLEN(x)	printf("Str '%s' ==> %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)  printf("S1 '%s' S2 '%s' ==> %d (%d)\n", a, b, ft_strcmp(a,b), (int)strcmp(a, b));
//# define STRCPY(a, b)  printf("S1 '%s' S2 '%s' ==> %s (%s)\n", a, b, ft_strcpy(a,b), strcpy(a, b));



// size_t
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, char *s2);

int main(void) {
	char s1[100] = "Asier";
	char s2[100];

	STRLEN("Asier");
	STRCMP("Toni", "Toni");
	STRCMP("Asier", "Alejandro");
	ft_strcpy(s2, s1);
	printf("STRCPY -> %s\n", s2);
	//STRCPY(s2, s1);
	//printf("STR1 %s\n", s1);
	return (0);
}