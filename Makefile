program: src/main.c src/csv.c src/utils.c
	gcc -I./include -o program src/main.c src/csv.c src/utils.c

clean:
	rm -f program