CPPFLAGS= -c -g -Iinc -Wall -fexceptions

__start__: uklad_rownan
        ./uklad_rownan

uklad_rownan: obj/LZespolona.o obj/main.o
        g++ -Wall -fexceptions -o uklad_rownan obj/LZespolona.o  obj/main.o

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
        g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/main.o: src/main.cpp src/LZespolona.cpp  inc/SUkladRownanLiniowych.hh inc/SMacierz.hh inc/SWektor.hh\
                inc/LZespolona.hh
        g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
        rm -f obj/*.o uklad_rownan
