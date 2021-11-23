CC = nvc++
CFLAGS = -acc -gpu=cc61 -Minfo=accel
LIBS = -lm

DEPS = *.h
OBJ = main.o Ray.o primitive.o bitmap.o btree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CLIBS)

profile: main.out
	rm -f main_nsys.*
	nsys profile -o main_nsys --trace openacc,cuda,openmp ./main.out
	/home/quin/nsight-systems-2021.5.1/bin/nsys-ui ./main_nsys.qdrep

clean:
	rm -rf *.o
	rm -f *.out
	rm -rf Output
	rm -f main_nsys.*
