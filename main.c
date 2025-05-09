#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# define STRLEN(x)	printf("Input: '%s', Result: %d, Expected: %d\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)  printf("Input: '%s', '%s', Result: %d, Expected: %d\n", a, b, ft_strcmp(a,b), (int)strcmp(a, b));

int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
int		ft_write(int fd, const char *buffer, int bytes);
int		ft_read(int fd, char *buffer, int bytes);
char 	*ft_strdup(const char *src);

void	test_ft_strlen() {
	printf("Testing ft_strlen... \n");
	const char *str = "asier";

	int result = ft_strlen(str);
	int expected = strlen(str);

	STRLEN(str);
	if (result == expected)
		printf("ft_strlen: PASSED\n");
	else {
		printf("ft_strlen: FAILED\n");
		exit(EXIT_FAILURE);
	}
}

void	test_ft_strcmp() {
	printf("Testing ft_strcmp... \n");

	const char *s1 = "hola";
	const char *s2 = "hola";

	int result = ft_strcmp(s1, s2);
	int expected = strcmp(s1, s2);

	printf("Input: '%s', '%s', Result: %d, Expected: %d\n", s1, s2, result, expected);
	if (result == expected)
		printf("ft_strcmp: PASSED\n");
	else {
		printf("ft_strcmp: FAILED\n");
		exit(EXIT_FAILURE);
	}
}

void test_ft_strcpy() {
	printf("\nTesting ft_strcpy...\n");
	char dest[100];
	const char *src = NULL;
	ft_strcpy(dest, src);
	printf("Source: '%s', Destination: '%s'\n", src, dest);
	if (ft_strcmp(dest, src) == 0)
		printf("ft_strcpy: PASSED\n");
	else {
		printf("ft_strcpy: FAILED\n");
		exit(EXIT_FAILURE);
	}
}

void test_ft_write() {
	printf("\nTesting ft_write...\n");
	const char *msg = "Hello, ft_write!\n";
	//int fd = open("test_file.txt", O_WRONLY);
	//int bytes_written = ft_write(fd, msg, strlen(msg));
	int bytes_written = ft_write(1, msg, strlen(msg));
	printf("Bytes written: %d\n", bytes_written);
	if (bytes_written == (int)strlen(msg))
		printf("ft_write: PASSED\n");
	else {
		printf("ft_write: FAILED\n");
		exit(EXIT_FAILURE);
	}
}

void test_ft_read() {
	printf("\nTesting ft_read...\n");
	char buffer[100];

	int fd = open("test_file.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	int bytes_read = ft_read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1) {
		perror("Error reading file");
		close(fd);
		exit(EXIT_FAILURE);
		return;
	}
	buffer[bytes_read] = '\0';

	printf("Bytes read: %d, Content: '%s'\n", bytes_read, buffer);
	close(fd);
	if (bytes_read >= 0)
		printf("ft_read: PASSED\n");
	else {
		printf("ft_read: FAILED\n");
		exit(EXIT_FAILURE);
	}
}

void test_ft_strdup() {
	printf("\nTesting ft_strdup...\n");

	const char *src = "Duplicate this string!";
	char *dup = ft_strdup(src);

	if (dup == NULL) {
		perror("Error duplicating string");
		return;
	}
	printf("Source: '%s', Duplicate: '%s'\n", src, dup);

	if (dup && strcmp(dup, src) == 0)
		printf("ft_strdup: PASSED\n");
	else {
		printf("ft_strdup: FAILED\n");
		exit(EXIT_FAILURE);
	}
	free(dup);
}

int main(void) {
	int fd = open("test_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0) {
		perror("Error:");
		return 1;
	}
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}
