corgi:
	gcc corgi.c -o corgi -lncurses -g

clean:
	rm corgi

build: clean corgi
