CXXFLAGS  = -O3 -m64
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-vla
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

all:
	$(AS) ../src/fpu_const_windows.S -o asmfunc.o
	$(CXX) -c main.cpp -o main.o ${CXXFLAGS} -I../src
	$(CXX) main.o asmfunc.o -o main.exe ${CXXFLAGS}
