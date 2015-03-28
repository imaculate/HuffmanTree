#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "HuffmanNode.h"

using namespace std;

//default constructor
MSHIMA001::HuffmanNode::HuffmanNode(){
   letter = '';
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
   N.letter='';
      
}
   
   //assignment operator
   
MSHIMA001::HuffmanNode::HuffmanNode& operator=(const HuffmanNode& N ){
   if(this == N)
      return *this;
      
      
   letter = N.letter;
   freq  = N.freq;
   left = N.left;
   right = N.right;
   
      
}
   //move assignment operator.
MSHIMA001::HuffmanNode::HuffmanNode& operator=(HuffmanNode&& N){
   if(this == N)
      return *this;
      
      
   letter = N.letter;
   freq  = N.freq;
   left = N.left;
   right = N.right;
      
   N.left = N.right = nullptr;
   N.letter = '';
   N.freq = 0;
      
   return *this;
      
} 
MSHIMA001::HuffmanNode::bool  operator<(HuffmanNode&& N){
   return freq<N.freq;
}
   
MSHIMA001::HuffmanNode::void setFrequency(){
   freq = left.getFrequency() + right.getFrequency();
}
   
MSHIMA001::HuffmanNode::int getFrequency(){
   return freq;
}
   
   

      
              
   
