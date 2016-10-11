test: list.c
	gcc list.c -o test
clean:
	rm *~
run: test
	./test
