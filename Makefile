#<-------------------------------|VARIABLES|---------------------------------->#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = Libft/libft.a

#<---------------------------------|FILES|------------------------------------>#

SRC_F = pipex.c command.c path.c make_pipe.c redirect.c execute.c
SRC_D = ./sources/

OBJ_F = ${SRC_F:.c=.o}
OBJ_D = ./objects/

DEP_F = ${SRC_F:.c=.d}
DEP_D = ./dependencies/

SRC = ${addprefix ${SRC_D}, ${SRC_F}}
OBJ = ${addprefix ${OBJ_D}, ${OBJ_F}}
DEP = ${addprefix ${DEP_D}, ${DEP_F}}

#<---------------------------------|COLORS|----------------------------------->#

DF = \033[0;39m#		Default
RED = \033[0;31m#		Red
BBLUE= \033[1;34m#		Bold Blue
BYELLOW = \033[1;33m#	Yellow
BCYAN = \033[1;36m#		Cyan
BIRED = \033[1;91m#		Red
BIGREEN = \033[1;92m#	Green
BIPURPLE = \033[1;95m#	Purple

#<---------------------------------|RULES|------------------------------------>#

all: ${NAME}

${NAME}: ${OBJ_D} ${DEP_D} ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}
	@echo "${RED}Compiling progam:${DF}"
	@echo "${BCYAN}${CC}${DF} ${BBLUE}${CFLAGS}${DF} ${BIGREEN}${OBJ_F}${DF} \
	${BIPURPLE}${LIBFT}${DF} ${BCYAN}-o${DF} ${RED}${NAME}${DF}"

${OBJ_D}%.o: ${SRC_D}%.c Makefile
	@${CC} ${CFLAGS} -MMD -c $< -o $@
	@echo "${BCYAN}${CC}${DF} ${BBLUE}${CFLAGS} -MMD${DF} ${BCYAN}-c${DF} \
	${BIRED}$<${DF} ${BCYAN}-o${DF} ${BIGREEN}$@${DF}"
	@mv ${@:.o=.d} ${DEP_D}
	@echo "${BCYAN}mv${DF} ${BYELLOW}${@:.o=.d}${DF} ${BCYAN}${DEP_D}${DF}"

${OBJ_D}:
	@mkdir ${OBJ_D}
	@echo "${BCYAN}mkdir${DF} ${BCYAN}${OBJ_D}${DF}"

${DEP_D}:
	@mkdir ${DEP_D}
	@echo "${BCYAN}mkdir${DF} ${BCYAN}${DEP_D}${DF}"

${LIBFT}:
	@echo
	@echo "${BCYAN}### LIBFT ###${DF}"
	@make -C Libft --no-print-directory
	@echo "${BCYAN}###${DF} ${BIPURPLE}libft.a${DF} ${BCYAN}made ---${DF}"
	@echo

lldb: ${LIBFT}
	${CC} -g ${CFLAGS} ${SRC} ${LIBFT}

#<---------------------------------|PHONY|------------------------------------>#

clean:
	@rm -rf ${OBJ_D} ${DEP_D}
	@echo "${RED}rm -rf${DF} ${BIGREEN}OBJECTS: ${OBJ_F}${DF}"
	@echo "${RED}rm -rf${DF} ${BYELLOW}DEPENDENCIES: ${DEP_F}${DF}"
	@echo
	@echo "${BCYAN}### LIBFT fclean ###${DF}"
	@make fclean -C Libft --no-print-directory
	@echo "${BCYAN}### LIBFT cleaned ---${DF}"
	@echo

fclean: clean
	@rm -rf ${NAME}
	@echo "${RED}rm -rf${DF} ${RED}PROGRAM: ${NAME}${DF}"

re : fclean all

-include ${DEP}

.PHONY: all clean fclean re
