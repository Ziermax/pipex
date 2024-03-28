NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_F = length.c calloc.c split.c split_char.c join.c
SRC_D = ./src/

OBJ_F = ${SRC_F:.c=.o}
OBJ_D = ./obj/

DEP_F = ${SRC_F:.c=.d}
DEP_D = ./dep/

SRC = ${addprefix ${SRC_D}, ${SRC_F}}
OBJ = ${addprefix ${OBJ_D}, ${OBJ_F}}
DEP = ${addprefix ${DEP_D}, ${DEP_F}}

# COLORS

DF = \033[0;39m#		Default
RED= \033[0;31m#		Red
PURPLE= \033[0;35m#		Purple
BRED= \033[1;31m#		Bold Red
BBLUE= \033[1;34m#		Bold Blue
BYELLOW= \033[1;33m#	Bold Yellow
BPURPLE= \033[1;35m#	Bold Purple
BCYAN= \033[1;36m#		Bold Cyan
BIRED= \033[1;91m#		Bold Intense Red
BIGREEN= \033[1;92m#	Bold Intense Green

all: ${NAME}

${NAME}: ${OBJ_F}
	@ar -rc ${NAME} ${OBJ_F}
	@echo "${BCYAN}ar -rc${DF} ${PURPLE}${NAME}${DF} ${BIGREEN}${OBJ_F}${DF}"

%.o: %.c Makefile
	@${CC} ${CFLAGS} -MMD -c $<
	@echo "${BBLUE}${CC}${DF} ${BCYAN}${CFLAGS} -MMD${DF} ${BBLUE}-c${DF} ${BIRED}$<${DF}"

clean:
	@rm -f ${OBJ_F} ${DEP_F}
	@echo "${RED}rm -f${DF} ${BIGREEN}${OBJ_F}${DF}"
	@echo "${RED}rm -f${DF} ${BYELLOW}${DEP_F}${DF}"

fclean: clean
	@rm -f ${NAME}
	@echo "${RED}rm -f${DF} ${PURPLE}${NAME}${DF}"

re: fclean all

-include ${DEP_F}

.PHONY: all clean fclean re
