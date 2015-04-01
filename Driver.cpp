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
typedef bool(*fptr)(const HuffmanNode&,const HuffmanNode&);

bool compare(const HuffmanNode& a, const HuffmanNode& b)
{
   if(a < b) 
      return true; // or > if the algorithm requires that ordering
   else 
      return false;
}

void getCodes(const HuffmanNode& A, string prefix, unordered_map<char,string>& map){
   if(A.getLetter()!='\0'){
      map[A.getLetter()] = prefix;
   }
   else{
   
            
      getCodes(*(A.left), "0"+prefix, map);
      getCodes(*(A.right), "1"+prefix, map);
            
   }
         
}
int main(int argc, char** argv) {
   if(argc <3){
      cout<<"You should have at least 2 parameters, enter the name of of headerfile"<<endl;
      return 0;
   }
  
   unordered_map<char, int> Map;
   string input= "";
   ifstream infile( argv[1], ios::in);
   if(infile.is_open()){
      
         
   
      char my_character ;
      
   
      while (!infile.eof() ) {
      
         infile.get(my_character);
      		if(my_character!='\n'){
      
            if(Map.count(my_character)>0){
              
               Map[my_character]+=1;
            }else{
		
               Map[my_character] = 1;
            }
			 input+=my_character;
			}else{
				continue;
			}
         }
          
      
           
      infile.close();
   }
   else{
      cout<<"Could not open input file "<< argv[1]<<" provided"<<endl;
   }
   
   cout<<"I reached this point!"<<endl;
   priority_queue<HuffmanNode, vector<HuffmanNode>,fptr> pq(compare);
   cout<<Map.size()<<endl;
   for(  auto it = Map.begin(); it != Map.end(); ++it){
		cout<<(it->first)<<" "<<(it->second)<<endl;
      HuffmanNode node(it->first,it->second);
		
      pq.push(node);
   }
 

  
   
   while(pq.size()>1){
      //build the huffman tree.
      HuffmanNode comb;
      comb.left = make_shared<HuffmanNode>(pq.top());
       pq.pop();
      comb.right = make_shared<HuffmanNode>(pq.top());
       pq.pop();
    
      
      comb.setFrequency();
      pq.push(comb);
      
      
      
      
   } 
   cout<<"pq size is"<<pq.size()<<endl;
   
  //priority queue now only has the root node.
  
   //create map for th character to codes.
     
   unordered_map<char, string> map;
   
   const HuffmanNode& T = pq.top();
   
   getCodes(T, "",map );
   
   //output table to outputfile.hdr;
   string headerfile = string(argv[2]) + ".hdr" ;
	//cout<<"header "<<headerfile<<endl;
   ofstream header(headerfile, ios::out);
	cout<<map.size()<<endl;
   header<<map.size()<<"\n";
   for( auto i = map.begin(); i != map.end(); ++i){
		cout<<(i->first)<<" "<<(i->second)<<endl;
      header<<(i->first)<<" "<<(i->second)<<"\n";
   }
   
   header.close();
      
      string output = "";
   cout<<input<<endl;
   for( int i =0; i< input.size(); i++){
      output+= map[input.at(i)];
      
   }  
	string opfile = string(argv[2]) + ".txt" ;
   ofstream outfile( opfile, ios::binary);
  
   outfile.write(output.c_str(), output.size());
   outfile.close();


    
}


      
