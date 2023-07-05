# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/04 22:00:29 by fras          #+#    #+#                  #
#    Updated: 2023/07/05 21:47:31 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = server client
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
SERVER_SOURCES = $(addprefix $(SRC_DIR)/server/, server.c)
SERVER_OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SERVER_SOURCES:%.c=%.o))
# CLIENT_SOURCES = $(addprefix $(SRC_DIR)/client/, client.c)
CLIENT_SOURCES = $(shell find $(SRC_DIR)/client -type f -name "*.c")
CLIENT_OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(CLIENT_SOURCES:%.c=%.o))
RM = rm -f

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

server:	$(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(SERVER_OBJECTS)
	@$(MAKE) message EXECUTABLE=$@

client: $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(CLIENT_OBJECTS)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

mandatory: $(NAME)

bonus: $(BONUS)

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) $(OBJECTS)
	$(RM) -r obj

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CLIENT)

re: fclean all

# Debugging
debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"