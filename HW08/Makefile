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

testcase: test1 test2 test3 test4 test5

test1: pa08
	$(VALGRIND) ./pa08 -D 0 1 4
	#diff output.txt expOutAll.txt

test2: pa08
	$(VALGRIND) ./pa08 testInt.txt -I >output.txt
	diff output.txt expOutInt.txt

test3: pa08
	$(VALGRIND) ./pa08 testDbl.txt -D >output.txt
	diff output.txt expOutDbl.txt

test4: pa08
	$(VALGRIND) ./pa08 testVID.txt -VID >output.txt
	diff output.txt expOutVID.txt

test5: pa08
	$(VALGRIND) ./pa08 cases.txt >OutCases.txt

test6: pa08
	$(VALGRIND) ./pa08
	
test7: pa08
	$(VALGRIND) ./pa08 cases.txt -I a
	
test8: pa08
	$(VALGRIND) ./pa08 case.txt -I
	
clean:
	/bin/rm -f pa08.o pa08 main.o
