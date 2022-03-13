P1_main: CicloDeLaVida.cc CellClass.o GridClass.o Functions.o StateEggClass.o StateLarvaClass.o StatePupaClass.o StateAdultClass.o StateDeadClass.o
	g++ -o CicloDeLaVida CicloDeLaVida.cc CellClass.o GridClass.o Functions.o StateEggClass.o StateLarvaClass.o StatePupaClass.o StateAdultClass.o StateDeadClass.o
P1_main.o: 
	g++ -c CellClass.o CellClass.cc GridClass.o GridClass.cc Functions.o Functions.cc StateEggClass.o StateEggClass.cc StateLarvaClass.o StateLarvaClass.cc StatePupaClass.o StatePupaClass.cc StateAdultClass.o StateAdultClass.cc StateDeadClass.o StateDeadClass.cc
clean: 
	rm *.o
	rm CicloDeLaVida