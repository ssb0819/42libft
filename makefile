RM = rm -rf
CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

NAME = libft.a
HEADER = libft.h

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

GNL_HEADER = get_next_line.h
GNL_DIR = get_next_line
GNL_SRCS = get_next_line.c get_next_line2.c get_next_line_bonus.c get_next_line_utils.c
GNL_SRCS_FILES = $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
GNL_OBJS = $(GNL_SRCS_FILES:.c=.o)

OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJS))

.PHONY: all bonus clean fclean re

all : libft_mandatory

bonus : libft_bonus

clean :
	$(RM) $(OBJ_DIR) $(GNL_OBJS)
	$(RM) libft_mandatory libft_bonus

fclean: 
	$(RM) $(BONUS_OBJ_FILES) $(OBJ_DIR) $(GNL_OBJS) $(NAME)
	$(RM) libft_mandatory libft_bonus

re: 
	$(MAKE) fclean
	$(MAKE) all

libft_mandatory : $(OBJ_FILES) $(GNL_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

libft_bonus : $(OBJ_FILES) $(BONUS_OBJ_FILES) $(GNL_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@