#include <unordered_map>
#include "helper.h"
#include "HuffmanTree.h"


#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace MSHIMA001;


TEST_CASE( "testing on one input file", "trial.txt") {
   //frequency counting
   unordered_map<char, int> freq;
   string input = getFreq("test1.txt", freq);

    REQUIRE(freq['o'] == 1);
    REQUIRE( freq['l'] == 2 );
    REQUIRE( freq['e'] == 2 );
    
   
    
    //build tree function.
    //tree node frequency = sum of frequencies.
    HuffmanTree tree;
    tree.buildTree(freq);
    
    REQUIRE((*(tree.root)).getFrequency() == input.size());
    
    
    unordered_map<char, string> table;
    
    tree.getCodes(*(tree.root), "", table);
    REQUIRE(table.size() == freq.size());
    
          //bit packing methods
    REQUIRE(toInt("101",3 )==5);
    
    REQUIRE(toString(5, 8)== "00000101");
    
    //unpacking test.
    string output = compress(input, table);
    bitPack(output, "out");

    REQUIRE(bitUnPack("out", output.size())== output);
    
   
}


TEST_CASE( "testing on second input file", "test2.txt") {
   //frequency counting
   unordered_map<char, int> freq;
   string input = getFreq("test2.txt", freq);

    REQUIRE(freq['f'] == 2);
    REQUIRE( freq['o'] == 1 );
    REQUIRE( freq['n'] == 3 );
    
   
    
    //build tree function.
    //tree node frequency = sum of frequencies.
    HuffmanTree tree;
    tree.buildTree(freq);
    
    REQUIRE((*(tree.root)).getFrequency() == input.size());
    
    
    unordered_map<char, string> table;
    
    tree.getCodes(*(tree.root), "", table);
    REQUIRE(table.size() == freq.size());
    
          //bit packing methods
    REQUIRE(toInt("101",3 )==5);
    
    REQUIRE(toString(5, 8)== "00000101");
    
    //unpacking test.
    string output = compress(input, table);
    bitPack(output, "out");

    REQUIRE(bitUnPack("out", output.size())== output);
    
   
}


