
CC=g++
CCFLAGS=-std=c++11

Driver: Driver.o  HuffmanNode.o
	$(CC) $(CCFLAGS) Driver.o HuffmanNode.o -o Driver

  
Driver.o : Driver.cpp
	$(CC) $(CCFLAGS) -o Driver.o -c Driver.cpp
  
HuffmanNode.o : HuffmanNode.cpp HuffmanNode.h
	$(CC) $(CCFLAGS) -o HuffmanNode.o -c HuffmanNode.cpp
   



   
      
clean:
	rm -f *.o
