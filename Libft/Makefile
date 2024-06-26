NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_F = length.c search.c malloc.c join.c split.c split_char.c printf.c printf_utils.c putfd.c get_next_line.c get_next_line_utils.c
SRC_D = ./sources/

OBJ_F = ${SRC_F:.c=.o}
OBJ_D = ./objects/

DEP_F = ${SRC_F:.c=.d}
DEP_D = ./dependencies/

SRC = ${addprefix ${SRC_D}, ${SRC_F}}
OBJ = ${addprefix ${OBJ_D}, ${OBJ_F}}
DEP = ${addprefix ${DEP_D}, ${DEP_F}}

# COLORS

DF = \033[0;39m#		Default
RED= \033[0;31m#		Red
BRED= \033[1;31m#		Bold Red
BBLUE= \033[1;34m#		Bold Blue
BYELLOW= \033[1;33m#	Bold Yellow
BIPURPLE = \033[1;95m#	Purple
BCYAN= \033[1;36m#		Bold Cyan
BIRED= \033[1;91m#		Bold Intense Red
BIGREEN= \033[1;92m#	Bold Intense Green
BBLACK=\033[1;30m#		Bold Black

all: ${NAME}

${NAME}: ${OBJ_D} ${DEP_D} ${OBJ}
	@ar -rc ${NAME} ${OBJ}
	@echo "${BCYAN}ar -rc${DF} ${BIPURPLE}${NAME}${DF} ${BIGREEN}${OBJ_F}${DF}"

${OBJ_D}%.o: ${SRC_D}%.c Makefile
	@${CC} ${CFLAGS} -MMD -c $< -o $@
	@echo "${BCYAN}${CC}${DF} ${BBLUE}${CFLAGS} -MMD${DF} ${BCYAN}-c${DF} ${BIRED}$<${DF} ${BCYAN}-o${DF} ${BIGREEN}$@${DF}"
	@mv ${@:.o=.d} ${DEP_D}
	@echo "${BCYAN}mv${DF} ${BYELLOW}${@:.o=.d}${DF} ${BCYAN}${DEP_D}${DF}"

${OBJ_D}:
	@mkdir ${OBJ_D}
	@echo "${BCYAN}mkdir${DF} ${BCYAN}${OBJ_D}${DF}"

${DEP_D}:
	@mkdir ${DEP_D}
	@echo "${BCYAN}mkdir${DF} ${BCYAN}${DEP_D}${DF}"

clean:
	@rm -rf ${OBJ_D} ${DEP_D}
	@echo "${RED}rm -rf${DF} ${BIGREEN}OBJECTS: ${OBJ_F}${DF}"
	@echo "${RED}rm -rf${DF} ${BYELLOW}DEPENDENCIES: ${DEP_F}${DF}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}rm -rf${DF} ${BIPURPLE}LIBRARY: ${NAME}${DF}"

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re
