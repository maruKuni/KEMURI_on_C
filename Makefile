CC:=clang
CFLAGS+=-g

INCLUDE:=-Iinclude

SRCS:=$(wildcard src/*.c)
OBJS:=$(SRCS:src/%.c=obj/%.o)

.PHONY:all clean

all:bin/kemuri.exe

$(OBJS):obj/%.o:src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
bin/kemuri.exe:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm obj/*.o
	-rm bin/*.exe
