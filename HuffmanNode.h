#ifndef HUFFNMANODE_H
#define HUFFNMANODE_H
#include <memory>
using namespace std;
namespace MSHIMA001{
class HuffmanNode

{
private: // private members
   char letter;
   int freq; // width and height of image stack
   // data for each slice, in order
public: // public members
   shared_ptr<HuffmanNode> left;
   shared_ptr<HuffmanNode> right;
   HuffmanNode(); // default constructor - define in .cpp
   HuffmanNode(char c, int f);
   ~HuffmanNode(); // destructor - define in .cpp file
  
   //copy constructor
   HuffmanNode(const HuffmanNode& N);
   
   //move constructor
   HuffmanNode(HuffmanNode&& N); 
   
   //assignment operator
   
   HuffmanNode& operator=(const HuffmanNode& N );
   //move assignment operator.
   HuffmanNode& operator=(HuffmanNode&& N); 
   
   //less that operator
   bool operator<(HuffmanNode&& N); 
   
   void setFrequency();
   
   int getFrequency();
   
   
};
}
#endif