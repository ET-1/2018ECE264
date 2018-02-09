CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pa06.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa06 testcase

pa06:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) -o pa06

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6 test7 test8

test1: pa06
	$(VALGRIND) ./pa06 SELECT name age WHERE age ">" 10 AND id = 1
#	diff age.txt expected/sortbyage.txt

test2: pa06
	$(VALGRIND) ./pa06 SELECT age name WHERE age ">" 10 AND id = 1
#	diff fail.txt expected/filefail.txt

test3: pa06
	$(VALGRIND) ./pa06 SELECT enrollment age major WHERE age "<" 22 OR id = 100
#	diff notconnect.txt expected/dbnotexist.txt	

test4: pa06
	$(VALGRIND) ./pa06 SELECT major enrollment major id WHERE major = CS AND enrollment = No AND year = Sophomore
#	diff name.txt expected/sortbyname.txt

test5: pa06
	$(VALGRIND) ./pa06 SELECT id WHERE enrollment = Yes
#	diff fail1.txt expected/filefail.txt

test6: pa06
	$(VALGRIND) ./pa06 SELECT id WHERE enrollment = Yes AND name = aa
#	diff notconnect1.txt expected/dbnotexist.txt	
		
test7: pa06
	$(VALGRIND) ./pa06 SELECT age enrollment year major name id WHERE enrollment = No
#	diff numargc.txt expected/argcnot4.txt
	
#test8: pa06
	$(VALGRIND) ./pa06 SELECT age name WHERE age ">" 10 AND id = 1
#	diff nor.txt expected/notaorn.txt



clean:
	/bin/rm -f pa06.o pa06 main.o
