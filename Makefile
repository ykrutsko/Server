CC=g++
CFLAGS=-I.
DEPS = Server.h MouseInfo.h
OBJ = main.o Server.o MouseInfo.o
LIBS=-lws2_32

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o server