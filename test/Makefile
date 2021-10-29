COMP = gcc

COMP_FLAGS = -Wall -Wextra -Werror

LIBS = -lreadline ../src/libft/libft.a

TEST_SRCS = ./services/validate_input_test.c \
			./utils/ft_splitter_test.c \
			./utils/ft_append_test.c \
			./interpreter/extract_redirs_test.c \
			./interpreter/space_remover_test.c \
			./interpreter/var_subst_test.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

SRC_DIR = ../src

# LA FUNCIÓN main NO LA TESTEAMOS. ADEMÁS CREA CONFLICTO SI COMPILAMOS \
	MÁS DE UNA FUNCIÓN main EN UN PROGRAMA. Y EN ESTE CASO, \
	CADA ARCHIVO DE TEST TIENE SU PROPIO main.
SRCS = $(shell find $(SRC_DIR) -name '*.c' -not -path "$(SRC_DIR)/libft/*" \
	-not -path "$(SRC_DIR)/interpreter/wildcard_bonus/*" \
	-not -name 'main.c' -not -name 'parser_bonus.c')

SRC_OBJS = $(SRCS:.c=.o)

# NO SE PUEDE UTILIZAR ESTO EN LOS MACS DE LA ESCUELA: leaks -atExit --
PLATFORM = $(shell uname -s)
ifeq ($(PLATFORM),Darwin)
LEAK_CHECKER = leaks -atExit --
else
LEAK_CHECKER = valgrind --leak-check=yes
endif

all: $(TEST_OBJS)

%.o: %.c
	@$(COMP) $(COMP_FLAGS) -c $< -o $@ \
	&& $(COMP) $(COMP_FLAGS) $@ $(SRC_OBJS) $(LIBS) \
	&& $(LEAK_CHECKER) ./a.out ; rm a.out

clean:
	@rm -rf $(TEST_OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
		