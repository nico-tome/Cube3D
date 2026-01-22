NAME := cube3D

SRC_DIR := src/
VEC2_DIR := vec2/
PARSING_DIR	:= parsing/
TEXTURE_DIR := textures/

BUILD_DIR := build/

SRCS := $(GAME_DIR)main.c \
		$(PARSING_DIR)parsing.c \
		$(PARSING_DIR)check_map.c \
		$(PARSING_DIR)checker.c \
		$(PARSING_DIR)parsing_free.c \
		$(PARSING_DIR)parsing_getter.c \
		$(PARSING_DIR)parsing_reader.c \
		$(TEXTURE_DIR)texture.c \
		$(VEC2_DIR)vec2_utils1.c \
		$(VEC2_DIR)vec2_utils2.c \

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

HEADERS := includes/
HEADERS_BONUS := includes_bonus/

LIBS := lib/libft/libft.a \
		lib/MacroLibX/libmlx.so

CC := cc

FLAGS := -g -Wall -Werror -Wextra

all: ${NAME}

${LIBS}:
	@make -C lib/libft
	@make -C lib/MacroLibX -j16

$(NAME): ${LIBS} ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${LIBS} ${FLAGS} -no-pie -lm -lSDL2

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR_BONUS}%.o: ${SRC_BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS_BONUS} -c $< ${FLAGS}

bonus: ${LIBS} ${OBJ_BONUS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS_BONUS} ${OBJ_BONUS} ${LIBS} ${FLAGS} -lm -lSDL2

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}
	@make -C lib/MacroLibX clean
	@make -C lib/libft clean

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: clean fclean re all
