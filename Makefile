CFLAGS = -Wall -std=c99
LDFLAGS = -L -lgame

libgame.a: game.o game_io.o
	ar cr libgame.a game.o game_io.o

recolor_text: recolor_text.o libgame.a
	gcc $(CFLAGS) -o recolor_text recolor_text.o libgame.a $(LDFLAGS)

recolor_text.o: recolor_text.c game.h game_io.h
	gcc $(CFLAGS) -c recolor_text.c

.PHONY = clean
clean: 
	rm recolor_text recolor_text.o libgame.a