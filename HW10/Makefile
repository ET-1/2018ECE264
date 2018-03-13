CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pe10.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pe10 testcase

pe10:$(OBJS)
	$(GCC) $(OBJS) -o pe10

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6

test1: pe10
	$(VALGRIND) ./pe10 10 3 1 > case1.txt
	diff case1.txt expected/case1.txt

test2: pe10
	$(VALGRIND) ./pe10 10 4 2 > case2.txt
	diff case2.txt expected/case2.txt

test3: pe10
	$(VALGRIND) ./pe10 8 5 3 > case3.txt
	diff case3.txt expected/case3.txt

test4: pe10
	$(VALGRIND) ./pe10 8 9 1 > case4.txt
	diff case4.txt expected/case4.txt

test5: pe10
	$(VALGRIND) ./pe10 41 3 1 > case5.txt
	diff case5.txt expected/case5.txt
	
test6: pe10
	$(VALGRIND) ./pe10 100 3 20 > case6.txt
	diff case6.txt expected/case6.txt
		
clean:
	/bin/rm -f pe10.o pe10 main.o
	/bin/rm -f case1.txt case2.txt case3.txt case4.txt case5.txt case6.txt
