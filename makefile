all: shell-remind

shell-remind: ShellRemind.o
	g++ -o shell-remind ShellRemind.o -lsfml-audio

ShellRemind.o:
	g++ -c ShellRemind.c++

clean:
	rm shell-remind ShellRemind.o
