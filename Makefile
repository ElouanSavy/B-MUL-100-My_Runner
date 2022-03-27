##
## EPITECH PROJECT, 2021
## B-MUL-100-BDX-1-1-myhunter-elouan.savy-camaret
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/window/window_handler.c	\
		src/player/create_player.c	\
		src/player/move_player.c	\
		src/texture_handler.c	\
		src/gameplay/game_handler.c	\
		src/display/display_player.c	\
		src/display/display_tutorial.c	\
		src/display/display_score.c	\
		src/display/display_background.c	\
		src/display/display_game_obj.c	\
		src/display/display_best_score.c	\
		src/events/events_handler.c	\
		src/background/create_background.c	\
		src/background/anim_background.c	\
		src/collision/action.c	\
		src/collision/check_collision.c	\
		src/game_object/create_game_object.c	\
		src/game_object/move_game_obj.c	\
		src/game_object/destroy_game_obj.c	\
		src/menu/menu_handler.c	\
		src/menu/menu_interaction.c	\
		src/map/map_handler.c	\
		src/map/map_to_obj.c	\
		src/clock/clock_handler.c	\
		src/score/score_handler.c	\
		src/over/over_handler.c	\
		src/over/over_interaction.c	\
		src/pause/pause_handler.c	\
		src/pause/pause_interaction.c	\
		src/music_handler/music_handler.c	\
		src/music_handler/play_sound.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME	=	my_runner

CPPFLAGS	=	-I./include

LIB     =       -L./lib/ -lmy

LIBMYPATH =	./lib/libmy.a

all:	$(NAME)

$(NAME):	$(LIBMYPATH) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*

fclean : clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

debug: fclean
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LIB) -lcsfml-graphics -lcsfml-system \
	-lcsfml-window -lcsfml-audio -W -Wall -Wextra -ggdb3

$(LIBMYPATH):
	make -C ./lib/my
