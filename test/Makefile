CXXFLAGS  = -O3 -m64
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-vla
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

all:
	$(AS) fpu_const_windows.S ${ASFLAGS64} -o fpu_const_windows.o
	$(CXX) -c main.cpp -o main.o ${CXXFLAGS} -I../src
	$(CXX) main.o fpu_const_windows.o -o main.exe ${CXXFLAGS}
