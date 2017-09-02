CC=g++ -O2
INCLUDES=./include/Problema.hpp ./include/Solucion.hpp ./include/Algoritmo.hpp
OBJS=./obj/Problema.o ./obj/main.o ./obj/Solucion.o ./obj/Algoritmo.o


#BINARIOS:
./bin/recubrimiento: ${OBJS}
	${CC} $^ -o $@


#OBJS:
./obj/Problema.o: ./src/Problema.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@

./obj/Solucion.o: ./src/Solucion.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@

./obj/Algoritmo.o: ./src/Algoritmo.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@

./obj/main.o: ./src/main.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@


#REGLAS ADICIONALES
clean:
	rm -rf ./obj/*
	rm -rf ./bin/*
