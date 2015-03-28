#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>
#include "HuffmanNode.h"



using namespace std;
using namespace MSHIMA001;
int main(int argc, char** argv) {
   if(argc <3){
      cout<<"You should have at least 2 parameters, enter the name of of headerfile"<<endl;
      return 0;
   }
   
   unordered_map<char, int> Map;
   
   ifstream infile( argv[1], ios::in);
   if(infile.is_open()){
      
         
   
      char my_character ;
      string input;
   
      while (!infile.eof() ) {
      
         infile.get(my_character);
         cout << my_character;
         if (my_character != '\n'){ 
            if(Map.count(my_character)>0){
               input+=my_character;
               Map[my_character] = Map[my_character]+1;
            }
            else{
               Map[my_character] = 1;
            }
         }
         else{
            continue;
         }  
      
      }      
      infile.close();
   }
   else{
      cout<<"Could not open input file "<< argv[1]<<" provided"<<endl;
   }
   
   priority_queue<HuffmanNode, vector<HuffmanNode>,std::function<bool(HuffmanNode, HuffmanNode)>> pq(compare) > pq;
   
   for(  auto it = Map.begin(); it != Map.end(); ++it){
      HuffmanNode node(it->first,it->second);
      pq.push(node);
   }
 

  
   
   while(pq.size()>1){
      //build the huffman tree.
      HuffmanNode comb;
      comb.left = pq.pop();
      comb.right = pq.pop();
      
      comb.setFrequency();
      pq.push(comb);
      
      
      
      
   } 
   
   
  //priority queue now only has the root node.
  
   //create map for th character to codes.
     
    unordered_map<char, string> map;
   
   getCodes(pq.top(), "",map );
   
   //output table to outputfile.hdr;
   
   ofstream header(argv[2], ios::out);
   header<<map.size()<<"\n";
   for( auto i = map.begin(); i != map.end(); ++i){
      header<<i->first<<" "<<i->second<<"\n";
   }
   
   header.close()
   
   string output = "";
   
   for( int i =0; i< input.size(); i++){
      output+= map[input.at(i)];
      
   }  
   ofstream outfile( argv[2], ios::binary);
  
  outfile.write(output.c_str(), output.size());
  outfile.close();


    
}

bool compare(const HuffmanNode& a, const HuffmanNode& b)
{
   if(a < b) 
      return true; // or > if the algorithm requires that ordering
   else 
      return false;
      }
      
      void getCodes(HuffmanNode A, string prefix, unordered_map<string>& map){
         if(A.letter!=' '){
            map[A.letter] = prefix;
         }else{
            
            getCodes(A.left, prefix+"0", map);
            getCodes(B.right, prefix+"1", map);
            
         }
         
      }