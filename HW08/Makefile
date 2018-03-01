CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror $(COV)
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
COV = -fprofile-arcs -ftest-coverage
SRCS = pa08.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa08 testcase

pa08:$(OBJS)
	$(GCC) $(OBJS) -o pa08

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 testcov


test1: pa08
	$(VALGRIND) ./pa08 -D 0 2 3 | sort >output.txt
	diff output.txt outSortedDouble.txt 

test2: pa08
	$(VALGRIND) ./pa08 -D 4 9 5 | sort >output.txt
	diff output.txt outSortedDouble2.txt

test3: pa08
	$(VALGRIND) ./pa08 -D 3 6 4 | sort >output.txt
	diff output.txt outSortedDouble3.txt

test4: pa08
	$(VALGRIND) ./pa08 -D 0 9 5 | sort >output.txt
	
test5: pa08
	$(VALGRIND) ./pa08 -D 0 7 3 | sort >output.txt
	
test6: pa08
	$(VALGRIND) ./pa08 -D 2 9 7 | sort >output.txt

test7: pa08
	$(VALGRIND) ./pa08 -D 6 9 7 | sort >output.txt
	
test8: pa08
	$(VALGRIND) ./pa08 -D 1 3 5 | sort >output.txt
	
test9: pa08
	$(VALGRIND) ./pa08 -D 2 3 5 | sort >output.txt
	
test10: pa08
	$(VALGRIND) ./pa08 -D 3 6 3 | sort >output.txt
		
test: pa08
	$(VALGRIND) ./pa08 cases.txt -I a
	
test6: pa08
	$(VALGRIND) ./pa08 case.txt -I
	
test7: 
	$(VALGRIND) ./pa08 case.txt -I

testcov: pa08
	gcov main.c
	gcov pa08.c
	
	
clean:
	/bin/rm -f pa08.o pa08 main.o
	/bin/rm -f pa08.gcno main.gcno
	/bin/rm -f pa08.c.gcov main.c.gcov 
	/bin/rm -f pa08.gcda main.gcda
