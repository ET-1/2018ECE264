CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pa08.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa08 testcase

pa08:$(OBJS)
	$(GCC) $(OBJS) -o pa08

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6

test1: pa08
	$(VALGRIND) ./pa08 -D 0 2 3 >output.txt
	diff output.txt outDouble.txt

test2: pa08
	$(VALGRIND) ./pa08 -D 0 2 3 | sort >output.txt
	diff output.txt outSortedDouble.txt 

test3: pa08
	$(VALGRIND) ./pa08 -D 4 9 5 >output.txt
	diff output.txt outDouble2.txt

test4: pa08
	$(VALGRIND) ../pa08 -D 4 9 5 | sort >output.txt
	diff output.txt outSortedDouble2.txt

test5: pa08
	$(VALGRIND) ./pa08 -D 3 6 4 >output.txt
	diff output.txt outDouble3.txt

test6: pa08
	$(VALGRIND) ./pa08 -D 3 6 4 | sort >output.txt
	diff output.txt outSortedDouble3.txt

test9: pa08
	$(VALGRIND) ./pa08 -D 0 2 4 >output.txt
	
test7: pa08
	$(VALGRIND) ./pa08 cases.txt -I a
	
test8: pa08
	$(VALGRIND) ./pa08 case.txt -I
	
clean:
	/bin/rm -f pa08.o pa08 main.o
