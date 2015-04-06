#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>
#include "HuffmanNode.h"
#include "HuffmanTree.h"



using namespace std;
using namespace MSHIMA001;


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
   
  
   
  
   
  //priority queue now only has the root node.
  
   //create map for th character to codes.
   HuffmanTree tree;
   tree.buildTree(Map);
     
   unordered_map<char, string> map;
   
  
   
   const HuffmanNode& T = *(tree.root);
   
   tree.getCodes(T, "",map );
   
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
   
   
   int  N = output.size();
   int nbytes = (N/8) + (N%8 ? 1 : 0); 
   /*create bitstream
   


   unsigned char bitstream[nbytes];

   unsigned char ch;
   for (int i=0; i< nbytes; i++){
      string ch = output.substr(i*8, (i+1)*8);
      bitstream[i] = ch & 0xff;
      
   }
      
      
   //store bitstream to binary file
   string binaryfile = string(argv[2]) + ".bin" ;

  std::ofstream file(binaryfile, std::ios::binary);
  file.write(bitstream, nbytes);
  
  
  //create a method to extract file. */
  
  


    
}


      
