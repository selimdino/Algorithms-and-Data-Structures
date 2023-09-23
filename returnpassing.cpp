#include <iostream>
#include <vector>
 
using namespace std;
 

LargeType randomItem1 (const vector<LargeType> & arr){
    return arr[ randomInt(0 , arr.size() - 1)];
}

const LargeType & randomItem2 ( const vector<LargeType> & arr){
    return arr[ randomInt(0 , arr.size() - 1)];
}

    vector<LargeType> vec;
    LargeType item1 = 
