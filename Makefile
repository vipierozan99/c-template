TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
INCL_DIRS ?= ./include

# EXE_SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name *.c )
LIB_SRCS := $(shell find $(SRC_DIRS) -mindepth 2 -name *.c )
OBJS := $(LIB_SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) $(shell find $(INCL_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

# see the pattern here? just copy paste for each new executable
# they _must_ be in src/.
$(BUILD_DIR)/src/exec_1: $(OBJS) $(BUILD_DIR)/src/exec_1.c.o
	$(CC) $(OBJS) $@.c.o -o $@ $(LDFLAGS)

$(BUILD_DIR)/src/exec_2: $(OBJS) $(BUILD_DIR)/src/exec_2.c.o
	$(CC) $(OBJS) $@.c.o -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: clean debug

clean:
	$(RM) -r $(BUILD_DIR)

debug:
	echo $(LIB_SRCS)
	echo $(OBJS)
	echo $(INC_FLAGS)
	echo $(INC_DIRS)
	echo $(SRC_DIRS)
	echo $(DEPS)

-include $(DEPS)

MKDIR_P ?= mkdir -p