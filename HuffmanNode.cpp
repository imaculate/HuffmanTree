#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "HuffmanNode.h"
#include <memory>
using namespace std;

//default constructor
MSHIMA001::HuffmanNode::HuffmanNode(){
  
   freq = 0;
  
 
} 

MSHIMA001::HuffmanNode::HuffmanNode(char c, int f):letter(c),freq(f){
}
//destructor
MSHIMA001::HuffmanNode::~HuffmanNode(){
   left = right = nullptr;
   
} 
//copy constructor
MSHIMA001::HuffmanNode::HuffmanNode(const HuffmanNode& N): letter(N.letter), freq(N.freq), left(N.left), right(N.right){
   
   
}
   
   //move constructor
MSHIMA001::HuffmanNode::HuffmanNode(HuffmanNode&& N): letter(N.letter), freq(N.freq), left(N.left), right(N.right){
      
   N.left= N.right = nullptr;
   N.freq = 0;
   
      
}
   
   //assignment operator
   
/*HuffmanNode& MSHIMA001::HuffmanNode::operator=(const HuffmanNode& N ){
   if(this == N)
      return *this;
      
      
   letter = N.letter;
   freq  = N.freq;
   left = N.left;
   right = N.right;
   return *this;

      
}
   //move assignment operator.
HuffmanNode& MSHIMA001::HuffmanNode::operator=(HuffmanNode&& N){
   if(this == N)
      return *this;
      
      
   letter = N.letter;
   freq  = N.freq;
   left = N.left;
   right = N.right;
      
   N.left = N.right = nullptr;

   N.freq = 0;
      
   return *this;
      
}*/ 
bool MSHIMA001::HuffmanNode::  operator<(HuffmanNode&& N){
   return (freq<N.freq);
}
   
void MSHIMA001::HuffmanNode::setFrequency(){
   freq = left->freq + right->freq;
}
   
int MSHIMA001::HuffmanNode::getFrequency(){
   return freq;
} 
   
   

      
              
   
