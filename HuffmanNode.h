#ifndef HUFFNMANODE
#define HUFFNMANODE
namespace MSHIMA001{
class HuffmanNode
{
private: // private members
   char letter;
   int freq; // width and height of image stack
    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right; // data for each slice, in order
public: // public members
   HuffmanNode(); // default constructor - define in .cpp
   ~HuffmanNode(); // destructor - define in .cpp file
   //dont call delete at all in the HuffmanNode destructor.
   /* a default constructor, a move constructor, a copy
constructor, a destructor, an assignment operator and a move assignment operator
more details are provided below.*/
   
};
}
#endif