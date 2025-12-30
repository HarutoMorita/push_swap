PUSH_SWAP_NAME := push_swap
CHECKER_NAME := checker

LIBFT_DIR := libft/
LIBFT_NAME := libft.a
LIBFT_INC_DIR := libft/include/

INCLUDE_DIR := include/
INCLUDE := -I $(INCLUDE_DIR) -I $(LIBFT_INC_DIR)

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

GREEN  := \033[32m
YELLOW := \033[33m
RED    := \033[31m
RESET  := \033[0m

SRC_DIR := src/
OBJ_DIR := obj/

STACK_SRC := stack/stack_operations.c \
             stack/stack_management.c \
             stack/stack_utils.c \
             stack/stack_utils2.c

SORT_SRC := sort/sort.c \
            sort/sort_small_cases.c \
            sort/chunk_sort.c \
            sort/sort_utils.c \
            sort/advanced_operations.c \
            sort/chunk_management.c

MAIN_SRC := main/main.c

UTILS_SRC := utils/argument_management.c

CHECK_SRC := checker/checker.c \
             checker/execution.c \
             checker/checker_utils.c \
             checker/get_next_line_bonus.c \
             checker/get_next_line_utils_bonus.c

COMMON_SRCS := $(addprefix $(SRC_DIR), $(STACK_SRC) $(SORT_SRC) $(UTILS_SRC))

PUSH_SWAP_SRCS := $(COMMON_SRCS) $(addprefix $(SRC_DIR), $(MAIN_SRC))
CHECKER_SRCS   := $(COMMON_SRCS) $(addprefix $(SRC_DIR), $(CHECK_SRC))

PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CHECKER_OBJS   := $(CHECKER_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -L$(LIBFT_DIR) -lft -o $(PUSH_SWAP_NAME)
	@echo "$(GREEN)Successfully built $(PUSH_SWAP_NAME)!$(RESET)"

checker: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -L$(LIBFT_DIR) -lft -o $(CHECKER_NAME)
	@echo "$(GREEN)Successfully built $(CHECKER_NAME)!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	@echo "$(RED)Objects removed.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(PUSH_SWAP_NAME) $(CHECKER_NAME)
	@echo "$(RED)Executables removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re checker
