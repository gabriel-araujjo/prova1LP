MKDIR_P = mkdir -p
RMDIR = rm -r

BUILD_DIR=build
BIN_DIR=bin

# codigos
SOURCE_DIR=src
INCLUDE_DIR=include

CFLAGS=-g -O0 -std=c++11 -I./$(INCLUDE_DIR)

SOURCES := $(shell find $(SOURCE_DIR) -name '*.cc')
OBJECTS := $(addprefix $(BUILD_DIR)/,$(SOURCES:%.cc=%.o))


# teste 
TEST_SOURCE_DIR=test/src
TEST_INCLUDE_DIR=test/include

TEST_CFLAGS=$(CFLAGS) -I./$(TEST_INCLUDE_DIR)

TEST_SOURCES := $(shell find $(TEST_SOURCE_DIR) -name '*_teste.cc')
TEST_OBJECTS := $(addprefix $(BUILD_DIR)/,$(TEST_SOURCES:%.cc=%.o))
TEST_BINARIES := $(addprefix $(BIN_DIR)/,$(TEST_SOURCES:$(TEST_SOURCE_DIR)/%.cc=%))

run_tests: compile_tests
	@$(foreach bin,$(TEST_BINARIES),echo Executing $(bin);echo;./$(bin);echo;echo;)

compile_tests: directories $(TEST_BINARIES)

clean:
	@$(RMDIR) $(BUILD_DIR)
	@$(RMDIR) $(BIN_DIR)
	@echo Cleaned!

directories:
	@$(MKDIR_P) $(BUILD_DIR)/$(SOURCE_DIR)
	@$(MKDIR_P) $(BUILD_DIR)/$(TEST_SOURCE_DIR)
	@$(MKDIR_P) $(BIN_DIR)

$(BIN_DIR)/%_teste: $(BUILD_DIR)/$(TEST_SOURCE_DIR)/%_teste.o $(BUILD_DIR)/$(SOURCE_DIR)/%.o
	$(CXX) $^ $(TEST_CFLAGS) -o $@

$(BUILD_DIR)/$(TEST_SOURCE_DIR)/%.o: $(TEST_SOURCE_DIR)/%.cc
	$(CXX) -c $< $(TEST_CFLAGS) -o $@

$(BUILD_DIR)/$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cc $(INCLUDE_DIR)/%.h
	$(CXX) -c $< $(CFLAGS) -o $@

.SECONDARY: $(TEST_OBJECTS) $(OBJECTS)
.PHONY: run_tests compile_tests clean

