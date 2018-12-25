main.out: *.cpp *.h
	g++ social.cpp main.cpp shelfman.cpp bookman.cpp accounting.cpp  basic.cpp -o  main.o -l sqlite3

clean:
	rm -f main.out

.PHONY: clean