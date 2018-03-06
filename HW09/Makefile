CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
DEB = -Ddebug1 -Ddebug2 -Ddebug3 -Ddebug4 -Ddebug5
GCC = gcc $(CFLAGS) #$(DEB)
SRCS = pa09.c main.c read_write.c
OBJFILES = obj/pe04.o
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: pa09 testcase

pa09:$(OBJS)
	$(GCC) $(OBJS) -o pa09

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testcase: test1 test2 test3 test4 test5

test1: pa09
	$(VALGRIND) ./pa09 smallDbBinary.bin -n sortSmallbyname.bin >output.txt
	diff output.txt expectedTxt/expectedSmallPivotName.txt

test2: pa09
	$(VALGRIND) ./pa09 smallDbBinary.bin -a sortSmallbyage.bin >output.txt
	diff output.txt expectedTxt/expectedSmallPivotAge.txt

test3: pa09
	$(VALGRIND) ./pa09 databaseBinary.bin -n sortbyname.bin >output.txt
	diff output.txt expectedTxt/expectedPivotName.txt

test4: pa09
	$(VALGRIND) ./pa09 databaseBinary.bin -a sortbyage.bin >output.txt
	diff output.txt expectedTxt/expectedPivotAge.txt

test5: pa09
	valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -n sortbyname.bin > output.txt
	#diff output.txt expectedTxt/memcheckage.txt
	
test6: pa09
	valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -a sortbyage.bin >output.txt
#	diff output.txt expectedTxt/memcheckage.txt
	
test7: pa09
  valgrind --tool=memcheck --log-file=memcheckage.txt --leak-check=full --verbose ./pa09 databaseBinary.bin -n sortbyname.bin
#	diff output.txt expectedTxt/memcheck.txt
		
test8: pa09
	$(VALGRIND) ./pa09 case.txt -I
	
clean:
	/bin/rm -f pa09.o pa09 main.o read_write.o
