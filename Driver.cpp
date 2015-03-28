#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"


using namespace std;
int main(int argc, char** argv) {
   if(argc <3){
      cout<<"You should have at least 2 parameters, enter the name of of headerfile"<<endl;
      return 0;
   }
   
   unordered_map<char, int> Map;
   
   ifstream infile( argv[1], ios::in);
   if(infile.is_open()){
      
         
   
      char my_character ;
   
   
      while (!infile.eof() ) {
      
         infile.get(my_character);
         cout << my_character;
         if (my_character != '\n'){ 
            if(Map.count(my_character)>0){
               Map[my_character] = Map[my_character]+1;
            }else{
               Map.[my_character] = 1;
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
   
   priority_queue<HuffmanNode> pq;
   
   for(  auto it = Map.begin(); it != Map.end(); ++it){
      HuffmanNode node(it->first,it->second);
      pq.push(node);
   }
     
   
   
   
}