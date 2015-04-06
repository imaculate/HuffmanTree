#include "helper.h"
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>
string MSHIMA001::toString(int b, int num){
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
int MSHIMA001::toInt(string bitString, int sLength){


   int tempInt;
   int num=0;
   for(int i=0; i<sLength; i++){
      tempInt = bitString[i]-'0';
      num += (1 << sLength-i-1) * tempInt;
   }
   cout<<num<<endl;

   return num;
}
string MSHIMA001::getFreq(string file, unordered_map<char, int>& Map){
   string input= "";
  
   ifstream infile( file, ios::in);
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
      }
          
      
           
      infile.close();
   }
   else{
      cout<<"Could not open input file "<< file<<" provided"<<endl;
   }
   return input;
}

string MSHIMA001::bitUnPack(string headerName, int size){
   //size is the initial length of string before bitpacking.
   
   //get nbytes from headerfile
   int  nbytes;//number of bytes
   string headerfile = headerName+".data";
   ifstream header(headerfile.c_str() , ios::in);
   string line;
   
   if (header.is_open()) {
      getline (header,line);
      istringstream iss(line);
     	
      iss >> nbytes;
      
      header.close();
   }
   else{
      cout<<"Unable to open headerfile"<<endl;
   }
   unsigned char* bits = new unsigned char[nbytes];
   string binaryfile = headerName + ".bin";
   ifstream bin(binaryfile, ios::binary);
   
   string comp;
   bin.read((char*)bits, nbytes);
   
   int fill;
   for (int i=0; i< nbytes; i++){
      fill = (size>8)?8:size;
      comp += toString(bits[i],fill);
      cout<<comp<<endl;
      size-=8;
      
   }
   bin.close();
   delete[] bits;
   return comp;
    
}

string MSHIMA001::compress(string input, unordered_map<char, string>& map){
   string output = "";

   for( int i =0; i< input.size(); i++){
      output+= map[input.at(i)];
      
   }  
   
   
   
      
   return output;
   
}

void MSHIMA001::bitPack(string output, string outfile ){
   int N = output.size();
   int nbytes =(N/8) + (N%8 ? 1 : 0); 
   char* bitstream = new char[nbytes];

  
   for (int i=0; i< nbytes; i++){
      string ch = output.substr(i*8, 8);
      cout<<ch<<endl;
      
      bitstream[i] = toInt(ch, ch.size()) ;
      
   }
   
   string binheader = outfile + ".data";
   ofstream head(binheader.c_str(), ios::out);
   if(head.is_open()){
      head<< nbytes<< endl;
      head.close();
   }
   else{
      cout<<"Unable to open file"<<binheader<<endl;
   }

      
   //store bitstream to binary file
   string binaryfile = outfile + ".bin" ;
   

   ofstream binfile(binaryfile, ios::binary);
   binfile.write((char*)bitstream, nbytes);
   binfile.close();
   delete [] bitstream;
}
   //extract



