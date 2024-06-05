RM = rm -rf
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

INC_DIR = include

SRCS = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
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

BONUS_OBJS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

GNL_DIR = get_next_line
GNL_SRCS = get_next_line.c get_next_line2.c get_next_line_bonus.c get_next_line_utils.c
GNL_SRCS_FILES = $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
GNL_OBJS = $(GNL_SRCS_FILES:.c=.o)

NAME = libft.a

SRC_DIR = libft_src
SRCS_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS_FILES:.c=.o)
BONUS_SRCS_FILES = $(addprefix $(SRC_DIR)/, $(BONUS_SRCS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all : libft_mandatory

bonus : libft_bonus

clean :
	$(RM) $(OBJS) $(GNL_OBJS)
	$(RM) libft_mandatory libft_bonus

fclean: 
	$(RM) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(NAME)
	$(RM) libft_mandatory libft_bonus

re: 
	$(MAKE) fclean
	$(MAKE) all

libft_mandatory : $(OBJS) $(GNL_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

libft_bonus : $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@