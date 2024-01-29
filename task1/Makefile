malloc_intercept.so:
	clang -fPIC -shared -o malloc_intercept.so malloc_intercept.c -D_GNU_SOURCE

task_1: malloc_intercept.so
	LD_PRELOAD=./malloc_intercept.so seq 1 5

clean:
	$(RM) *.so
