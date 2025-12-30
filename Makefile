NAME := push_swap
BONUS_NAME := checker

LIBFT_DIR := libft/
LIBFT_NAME := libft.a

LIBFT_DIR     := libft/
LIBFT_INC_DIR := libft/include/
LIBFT_INCLUDE := -I $(LIBFT_INC_DIR)
INCLUDES      := -I . $(LIBFT_INCLUDE)

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

GREEN  := \033[32m
YELLOW := \033[33m
RED    := \033[31m
RESET  := \033[0m

COMMON_SRCS := stack_operations.c \
		stack_management.c \
		stack_utils.c \
		stack_utils2.c \
		sort.c \
        sort_small_cases.c \
		chunk_sort.c \
		sort_utils.c \
		advanced_operations.c \
		chunk_management.c \
        argument_management.c

MAIN_SRC := main.c

BONUS_SRCS := checker_bonus.c \
              execution_bonus.c \
			  checker_util_bonus.c \
			  get_next_line_bonus.c \
			  get_next_line_utils_bonus.c

OBJS := $(SRCS:.c=.o) $(MAIN_SRC:.c=.o)
BONUS_OBJS := $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
    SRCS    := $(COMMON_SRCS) $(BONUS_SRCS)
    TARGET  := $(BONUS_NAME)
else
    SRCS    := $(COMMON_SRCS) $(MAIN_SRC)
    TARGET  := $(NAME)
endif

OBJS := $(SRCS:.c=.o)
ALL_OBJS    := $(COMMON_SRCS:.c=.o) $(MAIN_SRC:.c=.o) $(BONUS_SRCS:.c=.o)




all: $(TARGET)

$(TARGET): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(TARGET)
	@echo "$(GREEN)Successfully built $(TARGET)!$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:
	@$(MAKE) WITH_BONUS=1 all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(ALL_OBJS)
	@echo "$(RED)Objects removed.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(RED)Executables removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
