compile : random.c
	gcc -o random random.c
run : compile
	./random
clean :
	rm *.o
	rm *~
