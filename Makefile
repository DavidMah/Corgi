corgi:
	gcc corgi.c -o corgi -lncurses -g

install: corgi
	mv corgi /usr/local/bin
	# lol cat -> dog
	echo "alias cat=\"/usr/local/bin/corgi\"" >> ~/.bash_profile
