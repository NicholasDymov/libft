NAME := libft.a
CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
LONG_BIT ?= 64

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

CFLAGS += -I$(INC_DIR)

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
	@rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -g3 -fsanitize=address,undefined
sanitize: re

fast: CFLAGS += -Ofast -flto -march=native -fomit-frame-pointer -DNDEBUG -DSPEED
fast: re

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re debug sanitize fast
