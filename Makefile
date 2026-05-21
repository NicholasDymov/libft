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

speed: CFLAGS += -DSPEED
speed: re

o1: CFLAGS += -O1
o1: re

o2: CFLAGS += -O2
o2: re

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRC_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJ_BONUS)
	
.PHONY: all clean fclean re debug
