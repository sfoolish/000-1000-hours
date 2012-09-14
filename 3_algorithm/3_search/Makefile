CC=gcc

CFLAGS+=-g

VPATH = ./

SOURCES = $(foreach dir,$(VPATH),$(wildcard $(dir)/*))

C_SRCS   = $(filter %.c, $(SOURCES))
CPP_SRCS = $(filter %.cpp,$(SOURCES))

C_TARGETS  = $(C_SRCS:%.c=%)
CPP_TARGETS = $(CPP_SRCS:%.cpp=%)

INCLUDE_DIR = -I./

all: $(C_TARGETS) $(CPP_TARGETS)

%:%.c
	$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@

%:%.cpp
	$(COMPILE_TOOLS) $(CFLAGS) $(INC_DIR) $^ -o $@

clean:
	rm -rf $(LIB) $(C_TARGETS) $(CPP_TARGETS) *bak *.dSYM
