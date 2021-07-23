NAME := libft.a
CC := gcc
CFLAGS := $(INCLUDES) -g -Wall -Wextra -Werror
SRCS :=	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
B_SRCS=	ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstadd_back.c \
	 ft_lstdelone.c \
	 ft_lstclear.c \
	 ft_lstiter.c \
	 ft_lstmap.c

OBJS = ${SRCS:.c=.o}
B_OBJS := ${B_SRCS:.c=.o}

ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf libft.so a.out a.out.dSYM/

re: fclean all

test: bonus
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out | cat -e

bonus:
	make WITH_BONUS=1

so:
	gcc -shared $(SRCS) $(B_SRCS) -o libft.so

.PHONY: all clean fclean re test bonus so
