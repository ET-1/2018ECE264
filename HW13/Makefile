TARGET = pe13
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)
SRCS = pe13.c frequency.c 
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: $(TARGET) testall

testall: test1 test2 test3 test4 test5 test6 test7

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test1: $(TARGET)
	$(VALGRIND) ./pe13 test/simple1.txt > test1.txt
	diff test1.txt expected/expectedSimple1.txt

test2: $(TARGET)
	$(VALGRIND) ./pe13 test/simple2.txt > test2.txt
	diff test2.txt expected/expectedSimple2.txt

test3: $(TARGET)
	$(VALGRIND) ./pe13 test/test1.txt > test3.txt
	diff test3.txt expected/expectedTest1.txt

test4: $(TARGET)
	$(VALGRIND) ./pe13 test/test2.txt > test4.txt
	diff test4.txt expected/expectedTest2.txt

test5: $(TARGET)
	$(VALGRIND) ./pe13 test/wiki1.txt > test5.txt
	diff test5.txt expected/expectedWiki1.txt

test6: $(TARGET)
	$(VALGRIND) ./pe13 test/wiki2.txt > test6.txt
	diff test6.txt expected/expectedWiki2.txt

test7: $(TARGET)
	$(VALGRIND) ./pe13 test/wiki3.txt > test7.txt
	diff test7.txt expected/expectedWiki3.txt

#valtest: $(TARGET)
#	$(VALGRIND)=expected/valgrind.log ./pe13 test/wiki1.txt > /dev/null

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f test1.txt test2.txt test3.txt test4.txt test5.txt
	rm -f test6.txt test7.txt  
