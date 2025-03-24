#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# define STRLEN(x)	printf("Str '%s' ==> %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)  printf("S1 '%s' S2 '%s' ==> %d (%d)\n", a, b, ft_strcmp(a,b), (int)strcmp(a, b));

int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, char *s2);
int		ft_write(int fd, char *buffer, int bytes);
int		ft_read(int fd, char *buffer, int bytes);
char 	*ft_strdup(const char *src);

int main(void) {
	char s1[100] = "Asier";
	char s2[100];
	char buffer[100];

	STRLEN("Asier");
	STRCMP("Toni", "Toni");
	STRCMP("Asier", "Harry");
	ft_strcpy(s2, s1);
	printf("STRCPY -> %s\n", s2);
	//close(1);
	int i = ft_write(1, "Hello world\n", 13);
	printf("return del write : %d\n", i);
	perror("Detected error:");

	int fd = open("/home/anovio-c/Desktop/libasm/hola.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	int bytes_read = ft_read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1) {
		perror("Error reading file.");
		close(fd);
		return 1;
	}
	buffer[bytes_read] = '\0';
	printf("Buffer: \n%s\n", buffer);
	close(fd);
	const char *dup = "dupeaesto";
	char *str = ft_strdup(dup);
	if (str == NULL) {
		perror("Error duplicating string");
		return 1;
	}
	printf("Dupeador = %s\n", str);
	free(str);	
	return (0);
}