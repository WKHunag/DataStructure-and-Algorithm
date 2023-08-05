SHELL = /usr/bin/bash
CFLAGS = -O3 -std=c++11 -Wall
OBJS = main.o Deque_Arr.o Deque.o Node.o

.SUFFIXS: .cpp .o
main: ${OBJS}
	g++ ${OBJS} ${CFLAGS} -o main.exe   
%.o: %.cpp 
	g++ $< -c ${CFLAGS}
.PHONY: clean
clean: 
	@rm -rf *.o main.exe
