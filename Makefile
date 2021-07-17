APP_NAME = uniq
LIB_NAME = lib$(APP_NAME)

.PHONY: all format test clean run prereq
.SUFFIXES: .cpp .o

# ====== main app ============

BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
APPS_DIR = apps

LIB_PATH = $(LIB_DIR)/$(LIB_NAME).so

TEST_PATH=$(BIN_DIR)/$(APP_NAME)-test

LIB_SRC = $(shell find $(SRC_DIR)/ -name "*.cpp")
LIB_OBJ = $(LIB_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# FILE can be set from arguments
# use: ` make FILE=<filename>.cpp `
FILE ?= main.cpp
MAIN_SRC := ./$(FILE)
MAIN_OBJ := $(shell find $(MAIN_SRC) -type f -printf "%f" 2>/dev/null)
MAIN_OBJ := $(MAIN_OBJ:%.cpp=$(OBJ_DIR)/%.o)

# executable always `./bin/app`
MAIN_EXE := $(BIN_DIR)/app

DEPS :=  $(LIB_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) 

# ====== google test lib ======

GTEST_LIB = libgtest.so
GTEST_PATH = lib/$(GTEST_LIB)
GTEST_SRC_PATH = build/googletest

CLANG_FORMAT = clang-format
CLANG_FORMAT_FLAGS = -i

ifeq (${GITHUB_ACTIONS},true)
	CLANG_FORMAT = clang-format-12
	CLANG_FORMAT_FLAGS := -Wno-error=unknown $(CLANG_FORMAT_FLAGS)
endif

# ===== flags and libraries ======

CC = g++ -fPIC
LIBS = -luniq
LIBS_TEST = -pthread -lgtest 
CFLAGS = -std=gnu++11 -MD -MP
LDFLAGS = -I $(INCLUDE_DIR) -L $(LIB_DIR) -Wl,-rpath=$(LIB_DIR)
TEST_FLAGS = -I $(GTEST_SRC_PATH)/googletest/include/

# ===== recipes ===========================

# remove executable; check if sources exist
prereq:
	@test -e $(MAIN_SRC) || { echo "File '$(MAIN_SRC)' doesn't exist!" ; exit 1; }
	@$(RM) $(MAIN_EXE)

all: prereq $(LIB_PATH) $(MAIN_EXE)

run: all
	./$(MAIN_EXE)

$(MAIN_EXE): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

$(LIB_PATH): $(LIB_OBJ)
	@echo Creating shared library...
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

format: .clang-format
	find $(SRD_DIR) test -name "*.[ch]pp" | xargs $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS)
	find $(INCLUDE_DIR) test -name "*.[ch]pp" | xargs $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS)
	find $(APPS_DIR) test -name "*.[ch]pp" | xargs $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS)
	$(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) main.cpp
	@echo Done!

.clang-format:
	wget https://gist.githubusercontent.com/remortalite/5a19717025837ea5a1ddcaaa228ee1a9/raw/0f7661accb30863ca7f620d00a0c07ca66c0ab68/.clang-format -O $@

test: $(TEST_PATH)

$(TEST_PATH): $(GTEST_PATH) $(LIB_PATH)
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_FLAGS) $(TEST_DIR)/main.cpp -I $(TEST_DIR) -o $@ $(LIBS) $(LIBS_TEST)

$(GTEST_PATH): $(GTEST_SRC_PATH)
	@cd $(GTEST_SRC_PATH) &&\
		mkdir -p build &&\
		cd build &&\
	   	cmake .. -DBUILD_SHARED_LIBS=ON -DBUILD_GMOCK=OFF &&\
		make 
	cp $(GTEST_SRC_PATH)/build/lib/*.so $(GTEST_SRC_PATH)/build/lib/*.so.* lib/

$(GTEST_SRC_PATH):
	git clone https://github.com/google/googletest.git $@

clean:
	@find . -name '*.[od]' -exec $(RM) '{}' \;
	@find . -name '*.gch' -exec $(RM) '{}' \;
	@$(RM) $(LIB_PATH)
	@$(RM) $(TEST_PATH)
	@$(RM) $(MAIN_EXE)
	@echo Cleaned!

clean-full: clean
	@$(RM) $(LIB_DIR)/*
	@$(RM) $(GTEST_PATH)
	@$(RM) -R $(GTEST_SRC_PATH)
	@echo All libs and gtest sources deleted!

-include $(DEPS)
