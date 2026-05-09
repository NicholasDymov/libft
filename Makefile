NAME := minishell
CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror -lreadline

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -MP -c $< -o $@

-include $(DEPS)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -g3 -fsanitize=thread
sanitize: re

.PHONY: all clean fclean re debug
