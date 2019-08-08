CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

ASFLAGS64  = --64

CPPASM_INC = ../../cppasm/src
CPPASM_OBJ = ../../cppasm/src/obj/*.o

.PHONY: compile
.PHONY: link
.PHONY: generate
.PHONY: check

all: compile link generate check
	@echo "No errors"

compile:
	$(CXX) -c generate.cpp -o generate.o -I$(CPPASM_INC) $(CXXFLAGS)

link:
	$(CXX) generate.o $(CPPASM_OBJ) -o generate.exe $(CXXFLAGS)

generate:
	generate.exe windows > result/fpu_const_windows.S
	generate.exe linux > result/fpu_const_linux.S

check:
	$(AS) result/fpu_const_windows.S ${ASFLAGS64} -o fpu_const_windows.o
	$(AS) result/fpu_const_linux.S ${ASFLAGS64} -o fpu_const_linux.o
