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

testcase: testDouble1 testDouble2 testDouble3 testDouble4 testDouble5 testDouble6 testDouble7 testDouble8 testDouble9 testDouble10 testcov


testDouble1: pa08
	$(VALGRIND) ./pa08 -D 0 2 3 | sort >testDouble1.txt
	diff testDouble1.txt outSortedDouble.txt 

testDouble2: pa08
	$(VALGRIND) ./pa08 -D 4 9 5 | sort >testDouble2.txt
	diff testDouble2.txt outSortedDouble2.txt

testDouble3: pa08
	$(VALGRIND) ./pa08 -D 3 6 4 | sort >testDouble3.txt
	diff testDouble3.txt outSortedDouble3.txt

testDouble4: pa08
	$(VALGRIND) ./pa08 -D 0 9 5 | sort >testDouble4.txt
	
testDouble5: pa08
	$(VALGRIND) ./pa08 -D 0 7 3 | sort >testDouble5.txt
	
testDouble6: pa08
	$(VALGRIND) ./pa08 -D 2 9 6 | sort >testDouble6.txt

testDouble7: pa08
	$(VALGRIND) ./pa08 -D 6 9 7 | sort >testDouble7.txt
	
testDouble8: pa08
	$(VALGRIND) ./pa08 -D 1 3 5 | sort >testDouble8.txt
	
testDouble9: pa08
	$(VALGRIND) ./pa08 -D 2 3 5 | sort >testDouble9.txt
	
testDouble10: pa08
	$(VALGRIND) ./pa08 -D 3 6 3 | sort >testDouble10.txt
		
#testDouble: pa08
#	$(VALGRIND) ./pa08 cases.txt -I a
	
#testDouble6: pa08
#	$(VALGRIND) ./pa08 case.txt -I
	
#testDouble7: 
#	$(VALGRIND) ./pa08 case.txt -I

testcov: pa08
	gcov main.c
	gcov pa08.c
	
	
clean:
	/bin/rm -f pa08.o pa08 main.o
	/bin/rm -f pa08.gcno main.gcno
	/bin/rm -f pa08.c.gcov main.c.gcov 
	/bin/rm -f pa08.gcda main.gcda
