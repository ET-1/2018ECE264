CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -fprofile-arcs -ftest-coverage 
DEB = -Ddebug1 -Ddebug2 #-Ddebug3 -Ddebug4 -Ddebug5
DFI = -DTEST_STRUCT -DTEST_CONNECT -DTEST_CLOSE -DTEST_SEARCH
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pe04.c main.c
OBJFILES = obj/closest_centroid.o obj/dist2.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pe04 testcase

pe04:$(OBJS)
	$(GCC) $(OBJS) $(DFI) -o pe04

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6

test1: pe04
	./pe04 database.txt -a > result1.txt
	diff output1.txt result1.txt

test2: pe04
	./pe04 database.txt -s Remick
	#diff output2.txt result2.txt
	
test3: pe04
	./pe04 database.txt -s

test4: pe04
	./pe04 database.txt 1

test5: pe04 
	$(VALGRIND) ./pe04 data.txt -s Remick

clean:
	/bin/rm -f pe04.o pe04
