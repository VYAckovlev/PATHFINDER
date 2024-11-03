
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBMX_DIR = libmx


LIBMX = $(LIBMX_DIR)/libmx.a
TARGET = pathfinder


SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(LIBMX) $(TARGET)


$(TARGET): $(OBJ_FILES) $(LIBMX)
	$(CC) $(CFLAGS) -o $@ $^ -I$(INC_DIR) -I$(LIBMX_DIR)/inc


$(LIBMX):
	$(MAKE) -C $(LIBMX_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBMX_DIR)/inc


clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	$(MAKE) -C $(LIBMX_DIR) clean


fclean: clean
	rm -f $(LIBMX)
	$(MAKE) -C $(LIBMX_DIR) fclean


re: fclean all


.PHONY: all clean fclean re



