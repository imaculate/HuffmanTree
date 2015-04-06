
CC=g++
CCFLAGS=-std=c++11

huffencode: Driver.o  HuffmanNode.o HuffmanTree.o
	$(CC) $(CCFLAGS) Driver.o HuffmanNode.o HuffmanTree.o -o huffencode

HuffmanNode.o : HuffmanNode.cpp HuffmanNode.h
	$(CC) $(CCFLAGS) -o HuffmanNode.o -c HuffmanNode.cpp
   
HuffmanTree.o : HuffmanTree.cpp HuffmanTree.h
	$(CC) $(CCFLAGS) -o HuffmanTree.o -c HuffmanTree.cpp

     
Driver.o : Driver.cpp
	$(CC) $(CCFLAGS) -o Driver.o -c Driver.cpp
  
      

