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

testcase: test1 test2 test3 test4 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17

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
	$(VALGRIND) ./pa09 database20.bin -n sortDB20name.bin >output.txt
	diff output.txt expectedTxt/expectedDB20Name.txt

test9: pa09
	$(VALGRIND) ./pa09 database20.bin -a sortDB20age.bin >output.txt
	diff output.txt expectedTxt/expectedDB20Age.txt

test10: pa09
	$(VALGRIND) ./pa09 database40.bin -n sortDB40name.bin >output.txt
	diff output.txt expectedTxt/expectedDB40Name.txt

test11: pa09
	$(VALGRIND) ./pa09 database40.bin -a sortDB40age.bin >output.txt
	diff output.txt expectedTxt/expectedDB40Age.txt


test12: pa09
	$(VALGRIND) ./pa09 database80.bin -n sortDB80name.bin >output.txt
	diff output.txt expectedTxt/expectedDB80Name.txt

test13: pa09
	$(VALGRIND) ./pa09 database80.bin -a sortDB80age.bin >output.txt
	diff output.txt expectedTxt/expectedDB80Age.txt
	
test14: pa09
	$(VALGRIND) ./pa09 database100.bin -n sortDB100name.bin >output.txt
	diff output.txt expectedTxt/expectedDB100Name.txt

test15: pa09
	$(VALGRIND) ./pa09 database100.bin -a sortDB100age.bin >output.txt
	diff output.txt expectedTxt/expectedDB100Age.txt

test16: pa09
	$(VALGRIND) ./pa09 database60.bin -n sortDB60name.bin >output.txt
	diff output.txt expectedTxt/expectedDB60Name.txt

test17: pa09
	$(VALGRIND) ./pa09 database60.bin -a sortDB60age.bin >output.txt
	diff output.txt expectedTxt/expectedDB60Age.txt

clean:
	/bin/rm -f pa09.o pa09 main.o read_write.o
	/bin/rm -f sortDB20name.bin sortDB20age.bin
	/bin/rm -f sortDB40name.bin sortDB40age.bin
	/bin/rm -f sortDB60name.bin sortDB60age.bin
	/bin/rm -f sortDB80name.bin sortDB80age.bin
	/bin/rm -f sortDB100name.bin sortDB100age.bin			
	/bin/rm -f sortbyage.bin sortbyname.bin		
	/bin/rm -f sortSmallbyage.bin sortSmallbyname.bin			
