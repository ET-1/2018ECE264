CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pa12.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa12 testout

pa12:$(OBJS)
	$(GCC) $(OBJS) -o pa12

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testout: test1 test2 test3 test4 test5 test6

test1: pa12
	$(VALGRIND) ./pa12 -J 10 3 1 > out1.txt
	diff out1.txt case1.txt

test2: pa12
	$(VALGRIND) ./pa12 -J 10 4 2 > out2.txt
	diff out2.txt case2.txt

test3: pa12
	$(VALGRIND) ./pa12 -J 8 5 3 > out3.txt
	diff out3.txt case3.txt

test4: pa12
	$(VALGRIND) ./pa12 -J 8 9 1 > out4.txt
	diff out4.txt case4.txt

test5: pa12
	$(VALGRIND) ./pa12 -J 41 3 1 > out5.txt
	diff out5.txt case5.txt	
	
test6: pa12
	$(VALGRIND) ./pa12 -J 100 3 20 > out6.txt
	diff out6.txt case6.txt			
			
clean:
	/bin/rm -f pa12.o pa12 main.o
	/bin/rm -f out1.txt out2.txt out3.txt out4.txt out5.txt out6.txt
