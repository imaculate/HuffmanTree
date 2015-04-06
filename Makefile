
CC=g++
CCFLAGS=-std=c++11

huffencode: Driver.o  HuffmanNode.o HuffmanTree.o
  $(CC) $(CCFLAGS) Driver.o HuffmanNode.o HuffmanTree.o -o huffencode
   
test: Tests.o 
   $(CC) Tests.o -o test

HuffmanNode.o : HuffmanNode.cpp HuffmanNode.h
   $(CC) $(CCFLAGS) -o HuffmanNode.o -c HuffmanNode.cpp
   
HuffmanTree.o : HuffmanTree.cpp HuffmanTree.h
	$(CC) $(CCFLAGS) -o HuffmanTree.o -c HuffmanTree.cpp

     
Driver.o : Driver.cpp
	$(CC) $(CCFLAGS) -o Driver.o -c Driver.cpp

Tests.o: Tests.cpp
   $(CC) $(CCFLAGS) -o Tests.o -c Tests.cpp

clean:
   rm -rf *.o