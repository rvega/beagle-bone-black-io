all: bbb-io.c Makefile
	gcc -Wall -o bbb-io bbb-io.c /usr/local/lib/freebasic/fbrt0.o -lpruio -L"/usr/local/lib/freebasic/" -lfb -lpthread -lprussdrv -ltermcap -lsupc++ -Wno-unused-variable

remote:
	rsync -avu ./ root@192.168.7.2:~/bbb-io
	ssh root@192.168.7.2 "cd ~/bbb-io && make"
