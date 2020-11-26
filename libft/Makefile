FLAGS 		= -Wall -Wextra -Werror -fpic -O2 
CC 			= gcc
NAME 		= libft.a
HEADER		= libft.h
HEADER_OBJ	= $(HEADER:.h=.h.gch)
SRC			= 	ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strmapi.c ft_itoa.c \
				ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				ft_tolower.c ft_toupper.c ft_match.c ft_numlen.c ft_strcmp.c ft_arrinit.c
SRC_OBJ		= $(SRC:.c=.o)
BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ) $(HEADER_OBJ)
	ar rcs $(NAME) *.o $(HEADER_OBJ)


bonus: $(BONUS_OBJ) $(SRC_OBJ) $(HEADER_OBJ) $(NAME)

clean:
	rm -f *.o $(HEADER_OBJ)

fclean: clean
	rm -f $(NAME) libft.so 

re: fclean all

so: $(SRC_OBJ) $(HEADER_OBJ) $(BONUS_OBJ)
	gcc -shared -o libft.so *.o

$(HEADER_OBJ):$(HEADER)
	$(CC) $(FLAGS) -c $(HEADER) $<
	ar rcs $(NAME) $@

.c.o:
	$(CC) $(FLAGS) -c $<
	ar rcs $(NAME) $@
