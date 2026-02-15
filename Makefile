NAME 		:= cube3D
NAME_BONUS	:= cube3D_bonus

SRC_DIR 	:= src/
SRC_BONUS_DIR	:= src_bonus/
VEC2_DIR 	:= vec2/
PARSING_DIR	:= parsing/
TEXTURE_DIR := textures/
GAME_DIR	:= game/
EVENT_DIR	:= event/

BUILD_DIR 		:= build/
BUILD_DIR_BONUS	:= build_bonus/

SRCS := main.c \
		$(EVENT_DIR)event.c \
		$(GAME_DIR)free_game.c \
		$(GAME_DIR)init.c \
		$(GAME_DIR)player.c \
		$(GAME_DIR)raycasting_utils.c \
		$(GAME_DIR)render.c \
		$(PARSING_DIR)check_map.c \
		$(PARSING_DIR)checker.c \
		$(PARSING_DIR)parsing.c \
		$(PARSING_DIR)parsing_free.c \
		$(PARSING_DIR)parsing_getter.c \
		$(PARSING_DIR)parsing_reader.c \
		$(TEXTURE_DIR)init_textures.c \
		$(TEXTURE_DIR)texture.c \
		$(VEC2_DIR)dvec2_utils1.c \
		$(VEC2_DIR)vec2_utils1.c \
		$(VEC2_DIR)vec2_utils2.c \
		$(VEC2_DIR)vec_convert.c \

SRCS_BONUS := main_bonus.c \
			  $(EVENT_DIR)event_bonus.c \
			  $(GAME_DIR)ceiling_floor_bonus.c \
			  $(GAME_DIR)free_game_bonus.c \
			  $(GAME_DIR)init_bonus.c \
			  $(GAME_DIR)minimap_bonus.c \
			  $(GAME_DIR)player_bonus.c \
			  $(GAME_DIR)player_init_bonus.c \
			  $(GAME_DIR)raycasting_utils_bonus.c \
			  $(GAME_DIR)render_bonus.c \
			  $(PARSING_DIR)check_map_bonus.c \
			  $(PARSING_DIR)checker_bonus.c \
			  $(PARSING_DIR)parsing_bonus.c \
			  $(PARSING_DIR)parsing_free_bonus.c \
			  $(PARSING_DIR)parsing_getter_bonus.c \
			  $(PARSING_DIR)parsing_reader_bonus.c \
			  $(TEXTURE_DIR)init_textures_bonus.c \
			  $(TEXTURE_DIR)texture_bonus.c \
			  $(VEC2_DIR)dvec2_utils1_bonus.c \
			  $(VEC2_DIR)vec2_utils1_bonus.c \
			  $(VEC2_DIR)vec2_utils2_bonus.c \
			  $(VEC2_DIR)vec_convert_bonus.c \

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
OBJ_BONUS := $(patsubst %.c, $(BUILD_DIR_BONUS)%.o, $(SRCS_BONUS))

HEADERS := includes/
HEADERS_BONUS := includes_bonus/

LIBS := lib/libft/libft.a \
		lib/MacroLibX/libmlx.so

CC := cc

FLAGS := -g -Wall -Werror -Wextra

all: ${NAME} header

header:
	@echo "\n"
	@echo "\033[38;5;51m"
	@echo "༺✧༒─────────────────────────────────────────────────────────────────────────────────────────────────────────────────༒✧༻\n"
	@echo "\033[0m"
	@echo "\033[38;5;46m"
	@echo "  ██████╗██╗   ██╗██████╗ ███████╗██████╗ ██████╗                                                                      "
	@echo " ██╔════╝██║   ██║██╔══██╗██╔════╝╚════██╗██╔══██╗\033[0m \033[38;5;34m                                                "
	@echo " ██║     ██║   ██║██████╔╝█████╗   █████╔╝██║  ██║                                                                     "
	@echo " ██║     ██║   ██║██╔══██╗██╔══╝   ╚═══██╗██║  ██║\033[0m \033[38;5;28m                                                "
	@echo " ╚██████╗╚██████╔╝██████╔╝███████╗██████╔╝██████╔╝                                                                     "
	@echo "  ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═════╝ ╚═════╝                                                                      "
	@echo "\033[0m \033[38;5;178m"
	@echo "\n - Move with WASD"
	@echo " - Exit with ESC"
	@echo "\n - Made by ntome and ccouton\n"
	@echo "\033[38;5;51m"
	@echo "༺✧༒─────────────────────────────────────────────────────────────────────────────────────────────────────────────────༒✧༻\n"
	@echo "\033[0m"

header_bonus:
	@echo "\n"
	@echo "\033[38;5;51m"
	@echo "༺✧༒─────────────────────────────────────────────────────────────────────────────────────────────────────────────────༒✧༻\n"
	@echo "\033[0m"
	@echo "\033[38;5;46m"
	@echo "  ██████╗██╗   ██╗██████╗ ███████╗██████╗ ██████╗                                                                      "
	@echo " ██╔════╝██║   ██║██╔══██╗██╔════╝╚════██╗██╔══██╗\033[0m \033[38;5;34m                                                "
	@echo " ██║     ██║   ██║██████╔╝█████╗   █████╔╝██║  ██║                                                                     "
	@echo " ██║     ██║   ██║██╔══██╗██╔══╝   ╚═══██╗██║  ██║\033[0m \033[38;5;28m                                                "
	@echo " ╚██████╗╚██████╔╝██████╔╝███████╗██████╔╝██████╔╝                                                                     "
	@echo "  ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═════╝ ╚═════╝     bonus                                                            "
	@echo "\033[0m \033[38;5;178m"
	@echo "\n - Move with WASD"
	@echo " - Open and close door with E"
	@echo " - Exit with ESC"
	@echo "\n - Made by ntome and ccouton\n"
	@echo "\033[38;5;51m"
	@echo "༺✧༒─────────────────────────────────────────────────────────────────────────────────────────────────────────────────༒✧༻\n"
	@echo "\033[0m"

${LIBS}:
	@make --no-print-directory -C lib/MacroLibX -j16
	@make --no-print-directory -C lib/libft
	@echo "\033[38;5;46m✅ Libft Compiled !\033[0m"

$(NAME): ${LIBS} ${OBJ}
	@echo "\033[38;5;46m✅ Cube3D Compiled !\033[0m"
	@${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${LIBS} ${FLAGS} -no-pie -lm -lSDL2

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR_BONUS}%.o: ${SRC_BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	@${CC} -o $@ -I ${HEADERS_BONUS} -c $< ${FLAGS}

bonus: ${NAME_BONUS} header_bonus

${NAME_BONUS}: ${LIBS} ${OBJ_BONUS}
	@echo "\033[38;5;46m✅ Cube3D bonus compiled !\033[0m"
	@${CC} -o ${NAME_BONUS} -I ${HEADERS_BONUS} ${OBJ_BONUS} ${LIBS} ${FLAGS} -no-pie -lm -lSDL2

clean:
	@make --no-print-directory -C lib/MacroLibX clean
	@echo "\033[38;5;196m🧹 Macro deleted !\033[0m"
	@rm -f ${OBJ}
	@echo "\033[38;5;196m🧹 Objects deleted !\033[0m"
	@rm -f ${OBJ_BONUS}
	@echo "\033[38;5;196m🧹 Objects bonus deleted !\033[0m"
	@make --no-print-directory -C lib/libft clean
	@echo "\033[38;5;196m🧹 Libft deleted !\033[0m"

fclean: clean
	@rm -f ${LIBS}
	@rm -f ${NAME}
	@echo "\033[38;5;196m🧹 Cube3D deleted !\033[0m"
	@rm -f ${NAME_BONUS}
	@echo "\033[38;5;196m🧹 Cube3D_bonus deleted !\033[0m"

re: fclean all

.PHONY: clean fclean re all
