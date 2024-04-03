# OS identification from: https://stackoverflow.com/questions/714100/os-detecting-makefile
OS := $(shell uname -s)

CC = gcc

ifeq ($(OS), Darwin) 
  INCLUDE_PATH := /opt/homebrew/include
  LIB_PATH := /opt/homebrew/lib
  CC = clang
endif
ifeq ($(OS), Linux) 
  INCLUDE_PATH := /util/criterion/include
  LIB_PATH := /util/criterion/lib/x86_64-linux-gnu
  CC = gcc
endif


OBJECTS = counts.o
EXE = counts
CFLAGS = -std=c11 -Wall -O0 -pg -fprofile-arcs -ftest-coverage

counts.o: counts.c counts.h
	$(CC) -c $(CFLAGS) counts.c

$(EXE): counts.o
	$(CC) $(CFLAGS) -L $(LIB_PATH) -I $(INCLUDE_PATH) -o $(EXE) $(OBJECTS) main.c

.PHONY: andRunPerformance
andRunPerformance:
	@make clean
	@make $(EXE)
	@./$(EXE) ../data/file00
	@gprof -b ./$(EXE) > analyze.txt
	@gcov ./$(EXE).c
	@echo "Look at analyze.txt for gprof timing data"
	@echo "Look at counts.c.gcov for gcov annotated source code with execution counts"

.PHONY: clean
clean: 
	rm -rf *~ $(EXE) $(OBJECTS) *.dSYM *.gc?? gmon.out analyze.txt

