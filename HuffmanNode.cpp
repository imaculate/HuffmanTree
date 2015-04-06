#include "HuffmanNode.h"
#include <vector>
#include <string>


using namespace std;
using namespace MSHIMA001;
//default constructor
MSHIMA001::HuffmanNode::HuffmanNode(){
  	letter = '\0';
   freq = 0;
  
 
} 

MSHIMA001::HuffmanNode::HuffmanNode(char c, int f):letter(c),freq(f){
}
//destructor
MSHIMA001::HuffmanNode::~HuffmanNode(){
   left = right = nullptr;
   
} 
//copy constructor
MSHIMA001::HuffmanNode::HuffmanNode(const HuffmanNode& N): letter(N.getLetter()), freq(N.getFrequency()), left(N.left), right(N.right){
   
   
}
   
   //move constructor
MSHIMA001::HuffmanNode::HuffmanNode(HuffmanNode&& N): letter(N.getLetter()), freq(N.getFrequency()), left(N.left), right(N.right){
      
   N.left= N.right = nullptr;
   N.freq = 0;
   
      
}
   
   //assignment operator
HuffmanNode& MSHIMA001::HuffmanNode::operator=( const HuffmanNode& N ){
   if(this == &N)
      return *this;
      
      
   letter = N.getLetter();
   freq  = N.getFrequency();
   left = N.left;
   right = N.right;
   return *this;

      
}
   //move assignment operator.
HuffmanNode& MSHIMA001::HuffmanNode::operator=(HuffmanNode&& N){
   if(this == &N)
      return *this;
      
      
   letter = N.getLetter();
   freq  = N.getFrequency();
   left = N.left;
   right = N.right;
      
   N.left = N.right = nullptr;

   N.freq = 0;
      
   return *this;
      
}
bool MSHIMA001::HuffmanNode::operator<(const HuffmanNode& N) const{
   return (N.getFrequency()<freq);
}
   
void MSHIMA001::HuffmanNode::setFrequency(){
	
   freq = (*left).getFrequency() + (*right).getFrequency();
}
   
int MSHIMA001::HuffmanNode::getFrequency() const{
   return freq;
} 
  
  
char MSHIMA001::HuffmanNode::getLetter() const{
   return letter;
} 
   

      
              
   
