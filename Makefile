program: src/main.c src/csv.c src/utils.c src/commands.c
	gcc -I./include -o program src/main.c src/csv.c src/utils.c src/commands.c

clean:
	rm -f program