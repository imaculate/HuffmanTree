#ifndef HELPER_H 
#define HELPER_H
#include <string>
#include <unordered_map>

using namespace std;
namespace MSHIMA001{
  string toString(int b, int num);
  int toInt(string bitString, int sLength);
  string getFreq(string file, unordered_map<char, int>& Map);
  string bitUnPack(string headerName, int size);
   void bitPack(string output, string outfile);
  string compress(string input, unordered_map<char, string>& map);
}

#endif