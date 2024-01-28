malloc_intercept.so:
	gcc -fPIC -shared -o malloc_intercept.so malloc_intercept.c -ldl

