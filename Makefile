CC = gcc
NA_FLAGS = -f
ifeq ($(shell uname -m), arm64)
    CC += -ld_classic --target=x86_64-apple-darwin
	NA_FLAGS += macho64
else
	NA_FLAGS += elf64
endif

SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

NA			=	nasm
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	tester

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME) $(create_file)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				$(CC) $(FLAGS) -L. -o $(TEST) main.c -lasm

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				./$(TEST)

.PHONY:			clean fclean re test