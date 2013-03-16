corgi:
	gcc corgi.c -o corgi -lncurses -g

install: corgi
	mv corgi /usr/local/bin
