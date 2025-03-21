#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define STRLEN(x)	printf("Str '%s' ==> %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

// size_t
int	ft_strlen(const char *str);

int main(void) {
	STRLEN("Asier");
	return (0);
}