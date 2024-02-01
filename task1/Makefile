malloc_intercept.so: malloc_intercept.c
	clang -fPIC -shared -o malloc_intercept.so malloc_intercept.c -D_GNU_SOURCE -ldl

task1: malloc_intercept.so
	LD_PRELOAD=./malloc_intercept.so seq 1 5

clean:
	$(RM) *.so

all: task1
