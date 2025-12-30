# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmorita <hmorita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 22:39:31 by hmorita           #+#    #+#              #
#    Updated: 2025/12/11 18:58:25 by hmorita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

AR := ar
ARFLAGS := rcs
CC := cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))

SRCDIR := src
OBJDIR := obj
INCDIR := include

SRCFILES := $(notdir $(wildcard $(SRCDIR)/*.c))

SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCLUDES := $(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
