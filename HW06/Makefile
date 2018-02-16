CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pa06.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa06 testcase

pa06:$(OBJS)
	$(GCC) $(OBJS) -o pa06

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6 test7

test1: pa06
	$(VALGRIND) ./pa06 SELECT name age WHERE age ">" 10 AND id = 1
	diff output.txt expected/test1.txt

test2: pa06
	$(VALGRIND) ./pa06 SELECT age name WHERE age ">" 10 AND id = 1
	diff output.txt expected/test2.txt

test3: pa06
	$(VALGRIND) ./pa06 SELECT enrollment age major WHERE age "<" 22 OR id = 100
	diff output.txt expected/test3.txt

test4: pa06
	$(VALGRIND) ./pa06 SELECT id major enrollment WHERE major = CS AND enrollment = No AND year = Sophomore
	diff output.txt expected/test4.txt

test5: pa06
	$(VALGRIND) ./pa06 SELECT id WHERE enrollment = Yes
	diff output.txt expected/test5.txt

test6: pa06
	$(VALGRIND) ./pa06 SELECT id WHERE enrollment = Yes AND name = aa
	diff output.txt expected/test6.txt	
		
test7: pa06
	$(VALGRIND) ./pa06 SELECT age enrollment year major name id WHERE enrollment = No
	diff output.txt expected/test7.txt

test8: pa06
	$(VALGRIND) ./pa06 SELECT ag enrolment yar major name id WHERE enrollment = No	
	
test9: pa06
	$(VALGRIND) ./pa06 SELECT age enrollment year major name id WHERE id "<" 50
test10: pa06
	$(VALGRIND) ./pa06 SELECT age name enrollment year major id WHERE name = Lynox
#	diff nor.txt expected/notaorn.txt



clean:
	/bin/rm -f pa06.o pa06 main.o
