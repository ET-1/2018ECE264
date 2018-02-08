CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pe05.c main.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pe05 testcase

pe05:$(OBJS)
	$(GCC) $(OBJS) $(OBJFILES) -o pe05

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5 test6 test7 test8

test1: pe05
	./pe05 database.txt -a age.txt
	diff age.txt expected/sortbyage.txt

test2: pe05
	./pe05 database.txt -a bya.txt 
#	diff fail.txt expected/filefail.txt

test3: pe05
	./pe05 daabase.txt -a byage.txt 
#	diff notconnect.txt expected/dbnotexist.txt	

test4: pe05
	./pe05 database.txt -n name.txt
	diff name.txt expected/sortbyname.txt

test5: pe05
	./pe05 database.txt -n bya.txt 
#	diff fail1.txt expected/filefail.txt

test6: pe05
	./pe05 daabase.txt -n byname.txt 
#	diff notconnect1.txt expected/dbnotexist.txt	
		
test7: pe05
	./pe05 daabase.txt -n
#	diff numargc.txt expected/argcnot4.txt
	
test8: pe05
	./pe05 database.txt -s byname.txt
#	diff nor.txt expected/notaorn.txt



clean:
	/bin/rm -f pe05.o pe05 main.o
