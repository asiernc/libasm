SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s
OBJS		=	$(SRCS:.s=.o)


NA			=	nasm
NA_FLAGS	=	-f elf64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	tester

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				gcc $(FLAGS) -L. -o $(TEST) main.c -lasm

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				./$(TEST)


.PHONY:			clean fclean re test