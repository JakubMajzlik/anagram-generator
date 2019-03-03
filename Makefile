# Makefile for program
# Author: Jakub Majjzlik
# Version: 1.0

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
BIN = anagramgenerator

all:init bin

obj/generator.o: src/generator.c
	$(CC) $(CFLAGS) -c src/generator.c -o obj/generator.o

obj/list.o: src/list.c
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

bin: obj/main.o obj/list.o obj/generator.o
	$(CC) $(CFLAGS) obj/main.o obj/list.o obj/generator.o -o bin/$(BIN)


run:
	./bin/$(BIN)

init:
	@if [ ! -d "src" ]; then\
		mkdir -p src;\
	fi;
	@if [ ! -d "bin" ]; then\
		mkdir -p bin;\
	fi;
	@if [ ! -d "obj" ]; then\
		mkdir -p obj;\
	fi;
	@if [ ! -d "doc" ]; then\
		mkdir -p doc;\
	fi;
	@if [ ! -d ".git" ]; then\
		git init;\
	fi;
	@if [ ! -f ".gitignore" ]; \
	then \
		printf 'bin/* \nobj/* \n.vscode/* \n '> .gitignore;\
	fi

clear:
	rm -f obj/* bin/*
