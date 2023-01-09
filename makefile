CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: txtfind isort


isort: mainSORT.o for_isort.o
	$(CC) $(FLAGS) -o isort mainSORT.o for_isort.o

txtfind: mainTXT.o for_txtfind.o
	$(CC) $(FLAGS) -o txtfind mainTXT.o for_txtfind.o	

mainSORT.o: mainSORT.c for_isort.h
	$(CC) $(FLAGS) -c mainSORT.c	

mainTXT.o: mainTXT.c for_isort.h
	$(CC) $(FLAGS) -c mainTXT.c	

for_isort.o: for_isort.c for_isort.h
	$(CC) $(FLAGS) -c for_isort.c

for_txtfind.o: for_txtfind.c for_txtfind.h
	$(CC) $(FLAGS) -c for_txtfind.c	


clean:
	rm -f txtfind isort *.o
