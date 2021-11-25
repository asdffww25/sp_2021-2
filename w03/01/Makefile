#Makefile

CC=gcc
CFLAGS=
OBJS=main.o add.o sub.o mul.o
EXE=Calc.exe
LIBS=
all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

add.o: add.c
	$(CC) $(CFLAGS) -c add.c

sub.o: sub.c
	$(CC) $(CFLAGS) -c sub.c

mul.o: mul.c
	$(CC) $(CFLAGS) -c mul.c

clean:
	rm -f $(OBJS) $(EXE) core
