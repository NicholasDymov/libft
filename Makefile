NAME := libft.a
CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
LONG_BIT ?= 64

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

CFLAGS += -I$(INC_DIR) -DFT_LONG_BIT=$(LONG_BIT)

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) libft.so a.out

re: fclean all

debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -g3 -fsanitize=address,undefined
sanitize: re

fast: CFLAGS += -Ofast -fno-finite-math-only -flto -march=native -fomit-frame-pointer -DNDEBUG -DFT_SPEED
fast: re

so: CFLAGS += -fPIC
so: re
	@$(CC) -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re debug sanitize fast so
