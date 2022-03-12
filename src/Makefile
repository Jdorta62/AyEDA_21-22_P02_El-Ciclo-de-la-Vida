P1_main: prueba.cc CellClass.o GridClass.o StateEggClass.o StateLarvaClass.o StatePupaClass.o StateAdultClass.o StateDeadClass.o
	g++ -o prueba prueba.cc CellClass.o GridClass.o StateEggClass.o StateLarvaClass.o StatePupaClass.o StateAdultClass.o StateDeadClass.o
P1_main.o: 
	g++ -c CellClass.o CellClass.cc GridClass.o GridClass.cc StateEggClass.o StateEggClass.cc StateLarvaClass.o StateLarvaClass.cc StatePupaClass.o StatePupaClass.cc StateAdultClass.o StateAdultClass.cc StateDeadClass.o StateDeadClass.cc
clean: 
	rm *.o
	rm prueba