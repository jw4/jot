GIT_VERSION := "$(shell git describe --abbrev=4 --dirty --always --tags)"
CFLAGS += -DVERSION=\"$(GIT_VERSION)\"

jot: jot.o date_format.o options.o

.PHONY: run
run: jot
	@./$<

.PHONY: clean
clean:
	-rm jot *.o
