builddir = build
srcdir = src
libdir = src/lib
CC = gcc
CFLAGS = -lm

srcfiles = $(notdir $(wildcard $(srcdir)/*.c))
outputs = $(basename $(srcfiles))

all: $(outputs)

$(outputs): %: $(srcdir)/%.c $(libdir)/*.c
	$(CC) $(CFLAGS) -o $(builddir)/$@ $^

clean:
	rm build/*
