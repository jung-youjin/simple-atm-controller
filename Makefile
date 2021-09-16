Bank.o: lib/Bank.h include/Bank.cpp
		g++ -c include/Bank.cpp

ATM.o: lib/ATM.h include/ATM.cpp
		g++ -c include/ATM.cpp

main.o: src/main.cpp lib/Bank.h lib/ATM.h
		g++ -c src/main.cpp

main: Bank.o ATM.o main.o
		g++ Bank.o ATM.o main.o -o simple-atm-controller