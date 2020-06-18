##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME		= navy
CC			= @gcc
RM			= @rm -rf

SRC			= ./sources/main.c

SRC_BONUS   = ./sources/intelligence/main_ai.c \
			  ./sources/intelligence/map_gen.c \
			  ./sources/NCURSES/init_window_menu.c

SRC_CTX 	= ./sources/context/check_map.c \
			  ./sources/context/check_boats_intersection.c \
			  ./sources/context/main_error_gestion.c \
			  ./sources/context/open_and_read.c \
			  ./sources/context/input_players.c \
			  ./sources/context/get_boats_struct.c \
			  ./sources/context/game_loop.c \
			  ./sources/context/map_generator.c \
			  ./sources/context/check_args.c \
			  ./sources/context/print_map.c \
			  ./sources/context/error_message.c

SRC_CM 		= ./sources/communication/play_game.c \
			  ./sources/communication/get_ennemy_turn.c \
			  ./sources/communication/get_player_turn.c \
			  ./sources/communication/handshake.c \
			  ./sources/communication/send_msg.c

SRC_LIB	 	= ./sources/lib/clean_str.c \
		   	  ./sources/lib/copy_strings.c \
		   	  ./sources/lib/get_next_line.c \
		  	  ./sources/lib/list_toolbox.c \
		   	  ./sources/lib/malloc_toolbox.c \
		   	  ./sources/lib/misc.c \
		   	  ./sources/lib/number_toolbox.c \
		   	  ./sources/lib/string_toolbox.c \
		   	  ./sources/lib/string_toolbox2.c \
		   	  ./sources/lib/tabgen.c \
		   	  ./sources/lib/test_char_toolbox.c \
		   	  ./sources/lib/test_string_toolbox.c \
		   	  ./sources/lib/write_toolbox.c \
			  ./sources/lib/counter_functions.c \
			  ./sources/lib/my_get_nbr_base.c

TEST_SRC 	= ./tests/tests_lib.c 	\
		   	  ./tests/tests_gnl.c \
			  ./tests/tests_boats_struct.c \
			  ./tests/tests_open_a_map.c \
			  ./tests/tests_valid_map.c

CFLAGS 	= -I ./includes/ -g3

all: $(NAME)

$(NAME):
	 @$(CC) -c $(SRC) $(SRC_LIB) $(SRC_CTX) $(SRC_BONUS) $(SRC_CM) $(CFLAGS) -lncurses -lmenu
	 @$(CC) *.o -o $(NAME) $(CFLAGS) -lncurses -lmenu
	 @mkdir -p objects
	 @mv *.o objects
	 @echo "[*** COMPILATION SUCCESSFUL ***]"

clean:
	@$(RM) objects

fclean: clean
	@$(RM) $(NAME)
	@echo "[*** CLEAN ***]"

re: fclean all

tests_run:
	@$(CC) -c $(SRC_LIB) $(SRC_CTX) $(TEST_SRC) --coverage -g3 -I./includes
	@$(CC) -o unit_tests *.o -lcriterion --coverage -I./includes
	@mkdir -p objects
	@mv *.o objects
	@./unit_tests
	@echo "[*** TESTS OVER ***]"

tests_run_clean: tests_run
	@gcovr --exclude tests/
	@$(RM) unit_tests
	@$(RM) *.gc* unit_tests
	@$(RM) $(NAME)
	@$(RM) objects
	@echo "[*** CLEAN SUCCESSFUL ***]"

.PHONY: all clean fclean re tests_run tests_run_clean
