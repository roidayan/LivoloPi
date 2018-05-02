CC=g++
CFLAGS=-std=gnu++11
LDFLAGS=-lwiringPi

all: prog

.PHONY: LivoloTx
LivoloTx:
	$(CC) -c -o LivoloTx.o LivoloTx.cpp $(CFLAGS)

.PHONY: livolo
livolo:
	$(CC) -c -o livolo.o livolo.cpp $(CFLAGS)

prog: livolo LivoloTx
	$(CC) -o livolo livolo.o LivoloTx.o $(LDFLAGS)

clean:
	rm -fr livolo livolo.o LivoloTx.o
