NAME		:= 	cube3D

DIR		:=	srcs/
VEC2	:=	vec2/

BUILD_DIR	:=	build/

SRCS		:= 	${DIR}main.c \
				${DIR}${VEC2}vec2_utils1.c \
				${DIR}${VEC2}vec2_utils2.c \

OBJS		:=	$(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))


CC			:= cc

FLAGS 		:= -Wall -Werror -Wextra -I ./includes

TPUT 					= tput -T xterm-256color
_RESET 					:= $(shell $(TPUT) sgr0)
_BOLD 					:= $(shell $(TPUT) bold)
_ITALIC 				:= $(shell $(TPUT) sitm)
_UNDER 					:= $(shell $(TPUT) smul)
_GREEN 					:= $(shell $(TPUT) setaf 2)
_YELLOW 				:= $(shell $(TPUT) setaf 3)
_RED 					:= $(shell $(TPUT) setaf 1)
_GRAY 					:= $(shell $(TPUT) setaf 8)
_PURPLE 				:= $(shell $(TPUT) setaf 5)

OBJS_TOTAL	= $(words $(OBJS))
N_OBJS		:= $(shell find $(DIR) -type f -name $(OBJS) 2>/dev/null | wc -l)
OBJS_TOTAL	:= $(shell echo $$(( $(OBJS_TOTAL) - $(N_OBJS) )))
CURR_OBJ	= 0

all: ${NAME}

${LIBS}:
	@make -C lib/libft
	@make -C lib/MacroLibX -j16

${NAME}: ${LIBS} ${OBJS}
	@${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBS} -lm -lSDL2
	@printf "$(_BOLD)$(NAME)$(_RESET) compiled $(_GREEN)$(_BOLD)successfully$(_RESET)\n\n"

${BUILD_DIR}%.o: ${DIR}%.c
	@mkdir -p ${BUILD_DIR}$(dir $@)
	@${CC} -o $@ -c $< $(FLAGS)
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"
	
clean:
	@rm -rf ${OBJS}
	@make -C lib/MacroLibX clean
	@make -C lib/libft clean
	@printf "\n$(_BOLD)All objects are $(_GREEN)cleaned $(_RESET)! 🎉\n\n"

fclean: clean
	@rm -f ${NAME}
	@rm -f ${LIBS}
	@printf "Cleaned $(_BOLD)$(NAME)$(_RESET) !\n\n"

re: fclean all

.PHONY: clean fclean re all
