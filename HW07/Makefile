CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pe07.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pe07 testcase

pe07:$(OBJS)
	$(GCC) $(OBJS) -o pe07

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5

test1: pe07
	$(VALGRIND) ./pe07 testAll.txt >output.txt
	diff output.txt expOutAll.txt

test2: pe07
	$(VALGRIND) ./pe07 testInt.txt -I >output.txt
	diff output.txt expOutInt.txt

test3: pe07
	$(VALGRIND) ./pe07 testDbl.txt -D >output.txt
	diff output.txt expOutDbl.txt

test4: pe07
	$(VALGRIND) ./pe07 testVID.txt -VID >output.txt
	diff output.txt expOutVID.txt

test5: pe07
	$(VALGRIND) ./pe07 cases.txt >OutCases.txt

test6: pe07
	$(VALGRIND) ./pe07
	
test7: pe07
	$(VALGRIND) ./pe07 cases.txt -I a
	
test8: pe07
	$(VALGRIND) ./pe07 case.txt -I
	
clean:
	/bin/rm -f pe07.o pe07 main.o
