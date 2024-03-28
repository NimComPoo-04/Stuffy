CC = gcc
CFLAGS = -Wall -Wextra -ggdb -std=c11 -O2

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))

all: build sgol

build:
	mkdir -p obj

sgol: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf obj sgol

genvid: sgol 
	./sgol | ffmpeg -y -f rawvideo -pixel_format rgb32 -video_size 512x512\
		-framerate 30 -i - -c:v libx264 -profile:v baseline -level 3.0 -pix_fmt yuv420p\
		video.mp4; ffplay video.mp4
