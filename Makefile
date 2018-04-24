# Makefile for problem3 in problemect 3
#
# DO NOT modify this file

OBJS := level_0.o level_1.o level_2.o level_3.o
CC		= gcc
CFLAGS := -g -Og

all: $(OBJS) problem3

problem3: problem3.h problem3.o $(OBJS)
	$(CC) $(CFLAGS) -o problem3  problem3.o $(OBJS)


level_0.o: level_0.c problem3.h
	$(CC) $(CFLAGS) -c level_0.c
level_1.o: level_1.c problem3.h
	$(CC) $(CFLAGS) -c level_1.c
level_2.o: level_2.c problem3.h
	$(CC) $(CFLAGS) -c level_2.c
level_3.o: level_3.c problem3.h
	$(CC) $(CFLAGS) -c level_3.c
level_4.o: level_4.c problem3.h
	$(CC) $(CFLAGS) -c level_4.c
problem3.o: problem3.c problem3.h
	$(CC) $(CFLAGS) -c problem3.c

clean:
	rm -f *~ problem3 problem3.o level*.o a.out core cache.trace valgrind.log

run:
	valgrind --tool=cachegrind --D1=1024,2,128 --cachegrind-out-file=cache.trace ./problem3 > valgrind.log 2>&1

results:
	cg_annotate --threshold=0.001 --show=D1mr,D1mw  --sort=D1mr,D1mw cache.trace  |grep level_[0-3]

run_test:
	make clean
	make all
	./problem3
	make run
	make results
