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

string toString(int b, int num){
   string temp;
   cout<<b<<endl;
   while(b>0){
      int rem = b%2;
    
      string s;
      std::stringstream ss;
      ss << rem;
      s = ss.str();
      
      temp=s +temp;
      b=b/2;
   }
   int n =temp.size();
   for(int j= 0; j<(num - n);j++){
      temp = "0"+temp;
   }
   return temp;
}
int toInt(string bitString, int sLength){


   int tempInt;
   int num=0;
   for(int i=0; i<sLength; i++){
      tempInt = bitString[i]-'0';
      num += (1 << sLength-i-1) * tempInt;
   }
   cout<<num<<endl;

   return num;
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
            }
            else{
            
               Map[my_character] = 1;
            }
            input+=my_character;
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
   cout<<"nbytes "<<nbytes<<endl;
   //create bitstream
   


   char* bitstream = new char[nbytes];

  
   for (int i=0; i< nbytes; i++){
      string ch = output.substr(i*8, 8);
      cout<<ch<<endl;
      
      bitstream[i] = toInt(ch, ch.size()) ;
      
   }
   
      
      
   //store bitstream to binary file
   string binaryfile = string(argv[2]) + ".bin" ;

   ofstream file(binaryfile, ios::binary);
   file.write((char*)bitstream, nbytes);
  file.close();
   delete [] bitstream;
   //extract
  
    unsigned char* bits = new unsigned char[nbytes];
   
   ifstream bin(binaryfile, ios::binary);
   
    string comp;
    bin.read((char*)bits, nbytes);
    int size = output.size(); 
    int fill;
     for (int i=0; i< nbytes; i++){
      fill = (size>8)?8:size;
      comp += toString(bits[i],fill);
      cout<<comp<<endl;
      size-=8;
      
   }
   bin.close();
   delete[] bits;
   cout<<"extracted stuff "<<comp<<endl;
    
  
  
  //create a method to extract file. 
  
  
  
  
  


    
}


      
