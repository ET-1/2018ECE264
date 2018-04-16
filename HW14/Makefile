TARGET = pa14
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)
SRCS = pa14.c frequency.c list_node.c tree.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: $(TARGET) testall

testall: test1 test2 test3 test4 test5 test6 test7

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test1: $(TARGET)
	$(VALGRIND) ./pa14 input/simple1.txt > case1.txt
	diff case1.txt expected/expectedSimple1.txt

test2: $(TARGET)
	$(VALGRIND) ./pa14 input/simple2.txt > case2.txt
	diff case2.txt expected/expectedSimple2.txt

test3: $(TARGET)
	$(VALGRIND) ./pa14 input/test1.txt > case3.txt
	diff case3.txt expected/expectedTest1.txt

test4: $(TARGET)
	$(VALGRIND) ./pa14 input/test2.txt > case4.txt
	diff case4.txt expected/expectedTest2.txt

test5: $(TARGET)
	$(VALGRIND) ./pa14 input/wiki1.txt > case5.txt
	diff case5.txt expected/expectedWiki1.txt

test6: $(TARGET)
	$(VALGRIND) ./pa14 input/wiki2.txt > case6.txt
	diff case6.txt expected/expectedWiki2.txt

test7: $(TARGET)
	$(VALGRIND) ./pa14 input/wiki3.txt > case7.txt
	diff case7.txt expected/expectedWiki3.txt

#valtest: $(TARGET)
#	$(VALGRIND)=expected/valgrind.log ./pa14 test/wiki1.txt > /dev/null

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f case1.txt case2.txt case3.txt case4.txt case5.txt
	rm -f case6.txt case7.txt  
