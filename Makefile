TARGET ?= jot

GIT_VERSION ?= "$(shell git describe --abbrev=4 --dirty --always --tags)"
INSTALL ?= install -s
prefix ?= ${HOME}
bindir ?= $(prefix)/bin

CFLAGS += -DVERSION=\"$(GIT_VERSION)\"

SRCS := $(wildcard *.c)
HDRS := $(wildcard *.h)
OBJS := $(SRCS:.c=.o)

$(TARGET): $(OBJS)

$(OBJS): $(SRCS) $(HDRS)

.PHONY: all
all: $(TARGET)

.PHONY: install
install: $(TARGET)
	$(INSTALL) $< $(bindir)/

.PHONY: run
run: $(TARGET)
	@./$<

.PHONY: clean
clean:
	-rm $(TARGET) $(OBJS)
