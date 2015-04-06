#include "HuffmanNode.h"
#include "HuffmanTree.h"

#include <iostream>


using namespace std;
typedef bool(*fptr)(const MSHIMA001::HuffmanNode&,const MSHIMA001::HuffmanNode&);

bool compare(const MSHIMA001::HuffmanNode& a, const MSHIMA001::HuffmanNode& b)
{
   if(a < b) 
      return true; // or > if the algorithm requires that ordering
   else 
      return false;
}



MSHIMA001::HuffmanTree::~HuffmanTree(){
   root = nullptr;
   
} 
void MSHIMA001::HuffmanTree::buildTree(unordered_map<char, int>& Map){

   priority_queue<HuffmanNode, vector<HuffmanNode>,fptr> pq(compare);
   
   for(  auto it = Map.begin(); it != Map.end(); ++it){
		cout<<(it->first)<<" "<<(it->second)<<endl;
      HuffmanNode node(it->first,it->second);
		
      pq.push(node);
   }
 

   while(pq.size()>1){
      
      HuffmanNode comb;
      comb.left = make_shared<HuffmanNode>(pq.top());
       pq.pop();
      comb.right = make_shared<HuffmanNode>(pq.top());
       pq.pop();
    
      
      comb.setFrequency();
      pq.push(comb);
      
      
      
      
   } 
   root = make_shared<HuffmanNode>(pq.top());
   pq.pop();

   
}

      
void MSHIMA001::HuffmanTree::getCodes(const MSHIMA001::HuffmanNode& A, string prefix, unordered_map<char,string>& map){
   if(A.getLetter()!='\0'){
      map[A.getLetter()] = prefix;
   }
   else{
   
            
      getCodes(*(A.left), prefix+"0", map);
      getCodes(*(A.right), prefix+"1", map);
            
   }



   
}

