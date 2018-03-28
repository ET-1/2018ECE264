CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pe11.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pe11 testcase

pe11:$(OBJS)
	$(GCC) $(OBJS) -o pe11

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3

test1: pe11
	$(VALGRIND) ./pe11 test1.txt > case1.txt
	diff case1.txt outTest1.txt

test2: pe11
	$(VALGRIND) ./pe11 test2.txt > case2.txt
	diff case2.txt outTest2.txt

test3: pe11
	$(VALGRIND) ./pe11 test3.txt > case3.txt
	diff case3.txt outTest3.txt

test4: pe11
	$(VALGRIND) ./pe11 test4.txt > case4.txt
#	diff case1.txt outText3.txt

test5: pe11
	$(VALGRIND) ./pe11 test5.txt > case5.txt
	
test6: pe11
	$(VALGRIND) ./pe11 test6.txt > case6.txt
			
clean:
	/bin/rm -f pe11.o pe11 main.o
	/bin/rm -f case1.txt case2.txt case3.txt case4.txt case5.txt case6.txt
