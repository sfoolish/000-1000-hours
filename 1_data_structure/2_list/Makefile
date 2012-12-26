CC=gcc

CFLAGS+=-g

VPATH = ./

SOURCES = $(foreach dir,$(VPATH),$(wildcard $(dir)/*))

C_SRCS   = $(filter %.c, $(SOURCES))
CPP_SRCS = $(filter %.cpp,$(SOURCES))

C_OBJS   = $(C_SRCS:%.c=%)
CPP_OBJS = $(CPP_SRCS:%.cpp=%)

INCLUDE_DIR = -I./include/
INCLUDE_DIR += -I./include/hpr/

all: $(C_OBJS) $(CPP_OBJS)

%:%.c
	$(CC) $(CFLAGS) $(INC_DIR) $^ -o $@
	cp $@ /tftpboot/netra_rootfs
%:%.cpp
	$(COMPILE_TOOLS) $(CFLAGS) $(INC_DIR) $^ -o $@
	cp $@ /tftpboot/netra_rootfs

clean:
	rm -f $(LIB) $(C_OBJS) $(CPP_OBJS) *bak