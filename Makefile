all:
	gcc src/load.c src/libloader/load.c -o loader
	gcc hello.c -o hello.elf
