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

testcase: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10  test11

test1: pa06
	$(VALGRIND) ./pa06 SELECT major enrollment WHERE id ">" 199
	diff output.txt grading/test1.txt

test2: pa06
	$(VALGRIND) ./pa06 SELECT enrollment major WHERE id ">" 199
	diff output.txt grading/test2.txt

test3: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20
	diff output.txt grading/test3.txt

test4: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100	
	diff output.txt grading/test4.txt

test5: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes
	diff output.txt grading/test5.txt

test6: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100 AND enrollment "=" Yes AND major "=" ECE
	diff output.txt grading/test6.txt	
		
test7: pa06
	$(VALGRIND) ./pa06 SELECT id enrollment age major name year WHERE id "<" 10
	diff output.txt grading/test7.txt

test8: pa06
	$(VALGRIND) ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE
	diff output.txt grading/test8.txt
	
test9: pa06
	$(VALGRIND) ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19
	diff output.txt grading/test9.txt

test10: pa06
	$(VALGRIND) ./pa06 SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes
	diff output.txt grading/test10.txt

test11: pa06
	$(VALGRIND) ./pa06  SELECT id enrollment age major name year WHERE id "<" 10 OR major "=" ECE OR age ">=" 19 OR enrollment "=" Yes OR name = ECE264
		diff output.txt grading/test11.txt

test12: pa06
	$(VALGRIND) ./pa06 SELECT age name enrollment year major id name = Lynox
	
test15: pa06
	$(VALGRIND) ./pa06 SELECT major enrollment WHERE id ">" 199
	
test16: pa06
	$(VALGRIND) ./pa06 SELECT enrollment major WHERE id ">" 199

test17: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20

test18: pa06
	$(VALGRIND) ./pa06 SELECT name WHERE age ">" 20 AND id "<=" 100
clean:
	/bin/rm -f pa06.o pa06 main.o
