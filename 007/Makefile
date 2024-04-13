target = hello_world
sources = hello_world.c

$(target):hello_world.o
	gcc    hello_world.o -o hello_world

hello_world.o : hello_world.s
	gcc -c hello_world.s -o hello_world.o

hello_world.s : hello_world.i
	gcc -S hello_world.i -o hello_world.s

hello_world.i : $(sources)
	gcc -E hello_world.c -o hello_world.i
    
clean:
	rm hello_world.i hello_world.s hello_world.o hello_world