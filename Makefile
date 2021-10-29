NAME = minishell

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

LIBS = -lreadline ./src/libft/libft.a

SRCS = ./src/main.c \
		./src/globvar/globvar.c \
		./src/globvar/heredoc/here_processor.c \
		./src/globvar/heredoc/heredoc.c \
		./src/globvar/heredoc/here_pipe.c \
		./src/globvar/redir/redir.c \
		./src/reader/reader.c \
		./src/reader/rdata.c \
		./src/reader/process_input.c \
		./src/reader/non_interactive/gnl.c \
		./src/reader/non_interactive/gnl_utils.c \
		./src/reader/non_interactive/non_int_reader.c \
		./src/reader/call_readline.c \
		./src/reader/get_input.c \
		./src/interpreter/divider.c \
		./src/interpreter/extract_redirs.c \
		./src/interpreter/extract_redirs_utils.c \
		./src/interpreter/input_output_redirs.c \
		./src/interpreter/space_remover.c \
		./src/interpreter/space_remover_utils.c \
		./src/interpreter/var_subst.c \
		./src/interpreter/var_subst_redirs.c \
		./src/interpreter/set_pipes.c \
		./src/interpreter/iter_args.c \
		./src/interpreter/waiter.c \
		./src/executor/executor.c \
		./src/executor/internal.c \
		./src/executor/internal_comms/echo.c \
		./src/executor/internal_comms/pwd.c \
		./src/executor/internal_comms/exit.c \
		./src/executor/internal_comms/export.c \
		./src/executor/internal_comms/export_utils.c \
		./src/executor/internal_comms/unset.c \
		./src/executor/internal_comms/cd.c \
		./src/executor/internal_comms/env.c \
		./src/executor/utils/internal_comms/get_fd.c \
		./src/executor/utils/internal_comms/check_valid_varname.c \
		./src/executor/external.c \
		./src/executor/external_exec.c \
		./src/controllers/crud/crud_utils.c \
		./src/controllers/crud/create.c \
		./src/controllers/crud/read.c \
		./src/controllers/crud/update.c \
		./src/controllers/crud/delete.c \
		./src/utils/ft_lib/ft_strcmp.c \
		./src/utils/ft_lib/ft_append.c \
		./src/utils/ft_lib/mod_strchr.c \
		./src/utils/ft_lib/ft_splitter.c \
		./src/utils/free_2dim_str.c \
		./src/utils/alpha_sort.c \
		./src/utils/get_path.c \
		./src/utils/check_path.c \
		./src/utils/custom_err_msg.c \
		./src/utils/cute_strchar.c \
		./src/utils/params.c \
		./src/services/quotes/quotes.c \
		./src/services/validate/validate_input.c \
		./src/services/validate/characters.c \
		./src/services/validate/pipe_validator.c \
		./src/services/validate/validate_redir_filenames.c

SRCS_BONUS = ./src/interpreter/wildcard_bonus/coincidences_bonus.c \
				./src/interpreter/wildcard_bonus/condition_bonus.c \
				./src/interpreter/wildcard_bonus/file_utils_bonus.c \
				./src/interpreter/wildcard_bonus/fill_args_again_bonus.c \
				./src/interpreter/wildcard_bonus/find_matches_bonus.c \
				./src/interpreter/wildcard_bonus/parser_utils_bonus.c \
				./src/interpreter/wildcard_bonus/wildcard_bonus.c

SRC_PARSER = ./src/interpreter/parser.o

SRC_PARSER_BONUS = ./src/interpreter/parser_bonus.o 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJ_PARSER = ./src/interpreter/parser.o

OBJ_PARSER_BONUS = ./src/interpreter/parser_bonus.o

all: $(NAME)

$(NAME): $(OBJS) $(OBJ_PARSER)
	make -sC ./src/libft/ bonus
	$(CC) $(CC_FLAGS) -D NO_BONUS -o $(NAME) $(OBJS) $(OBJ_PARSER) $(LIBS)

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS) $(OBJ_PARSER_BONUS)
	make -sC ./src/libft/ bonus
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(OBJS_BONUS) $(OBJ_PARSER_BONUS) $(LIBS)

unit_test:
	make -sC ./test/
	make -sC ./test/ fclean

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS) $(OBJ_PARSER) $(OBJ_PARSER_BONUS)
	make -sC ./src/libft/ clean

fclean: clean
	@rm -rf $(NAME)
	make -sC ./src/libft/ fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus unit_test clean fclean re re_bonus
