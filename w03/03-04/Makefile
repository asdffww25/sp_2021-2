#Makefile

CC=gcc
CFLAGS=
OBJS=main-2.c
release=release
EXE=out.exe
LIBS=
DEBUG=-DDEBUG

all: $(release)

release: main-2.c
	$(CC) $(CFLAGS) -o $(EXE) main-2.c $(LIBS)
debug: main-2.c
	$(CC) $(CFLAGS) $(DEBUG) -o $(EXE) main-2.c $(LIBS)
clean:
	rm -f $(OBJS) $(EXE) core

