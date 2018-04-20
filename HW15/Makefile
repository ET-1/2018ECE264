TARGET = pa15
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)
SRCS = pa15.c tree.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --leak-check=full

all: $(TARGET) testall

testall: test1 test2 test3 test4 test5 test6 test7

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test1: $(TARGET)
	$(VALGRIND) ./pa15 125 20 case1.bin
	diff case1.bin expected/expected1.bin

test2: $(TARGET)
	$(VALGRIND) ./pa15 125 100 case2.bin
	diff case2.bin expected/expected2.bin
	
test3: $(TARGET)
	$(VALGRIND) ./pa15 125 1000 case3.bin
	diff case3.bin expected/expected3.bin
	
test4: $(TARGET)
	$(VALGRIND) ./pa15 45 200 case4.bin
	diff case4.bin expected/expected4.bin
	
test5: $(TARGET)
	$(VALGRIND) ./pa15 79 1200 case5.bin
	diff case5.bin expected/expected5.bin
	
test6: $(TARGET)
	$(VALGRIND) ./pa15 67 1160 case6.bin
	diff case6.bin expected/expected6.bin
	
test7: $(TARGET)
	$(VALGRIND) ./pa15 23 50 case7.bin
	diff case7.bin expected/expected7.bin

test8: $(TARGET)
	$(VALGRIND) ./pa15 1 0 case8.bin
	
.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f case1.bin case2.bin case3.bin case4.bin case5.bin
	rm -f case6.bin case7.bin case8.bin 
