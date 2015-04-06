#ifndef HUFFNMANTREE_H
#define HUFFNMANTREE_H
#include <memory>
#include <queue>
#include <unordered_map>
using namespace std;
namespace MSHIMA001{
   class HuffmanTree
   
   {
  
      
   public:
      shared_ptr<HuffmanNode> root;
      ~HuffmanTree();
      void buildTree(unordered_map<char,int>& Map);
      void getCodes(const HuffmanNode& A, string prefix, unordered_map<char,string>& map);
      
      
   
      
   };
}
#endif