CPPC            = g++
CFLAGS          = -I src -Wall
AR              = ar
ARFLAGES        = -crv
LIB_TARGET      = libton.a
TEST_TARGET     = test.out
LIB_CPPFILE     = $(notdir $(wildcard ./src/*.cpp))
TEST_CPPFILE    = $(notdir $(wildcard ./test/.cpp))
LIB_OBJS       := $(patsubst %.c, %.o, $(LIB_CPPFILE))
TEST_OBJS      := $(patsubst %.c, %.o, $(TEST_CPPFILE))
HEADER_FILLE    = $(wildcard ./src/*.h)
LIB_DIR         = /usr/local/lib
INCLUDE_DIR     = /usr/local/include/ton

VPATH           = src:test

$(LIB_TARGET): $(LIB_OBJS)
	@echo compile archive target
	$(AR) $(ARFLAGES) $@ $?
    
.PHONY: test
test: $(TEST_OBJS) $(LIB_TARGET)
	@echo compile test target
	$(CPPC) $(CFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)
    
.PHONY: install
install: $(LIB_TARGET) $(HEADER_FILLE)
	@echo install ...
	mkdir -p $(INCLUDE_DIR)
	cp -r $(HEADER_FILLE) $(INCLUDE_DIR)
	cp $(LIB_TARGET) $(LIB_DIR)
    
$(LIB_OBJS):  $(LIB_CPPFILE)
$(TEST_OBJS): $(TEST_CPPFILE)

.PHONY: clean
clean:
	@echo clean ...
	-rm -rf $(LIB_OBJS) $(TEST_OBJS) $(LIB_TARGET) $(TEST_TARGET)