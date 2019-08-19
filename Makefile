CC=gcc
CFLAGS=-O3 -Wall -std=gnu99
LDFLAGS=-lm

HEADERS = ohgodatool-common.h ohgodatool.h vbios-tables.h
SOURCES = ohgodatool-args.c ohgodatool-utils.c ohgodatool.c

all: ohgodatool

ohgodatool: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)

install: all
	cp -v ohgodatool /usr/local/bin/

clean:
	rm -f ohgodatool
