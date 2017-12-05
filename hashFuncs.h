#ifndef HASHFUNCS_H_
#define HASHFUNCS_H_

#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

inline string hash1(string key){
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

       for(std::size_t i = 0; i < key.length(); i++)
       {
          hash = hash * a + key[i];
          a    = a * b;
       }
       return to_string(hash);
}

inline string hash2(string key){
    unsigned int hash = 1315423911;

    for(std::size_t i = 0; i < key.length(); i++)
    {
      hash ^= ((hash << 5) + key[i] + (hash >> 2));
    }

    return to_string(hash);
}

inline string hash3(string key){
    unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
    unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
    unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash              = 0;
    unsigned int test              = 0;

    for(std::size_t i = 0; i < key.length(); i++)
    {
        hash = (hash << OneEighth) + key[i];

        if((test = hash & HighBits)  != 0)
        {
            hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }
    return to_string(hash);
}

inline string hash4(string key){
  int prime = 41;
  int big = 1543;
  char toHash[key.size() + 1];
  strcpy(toHash, key.c_str());
  int result = 0;
  for (auto v : toHash){
    result += (prime^v) % big;
  }
  result = (prime^result) % big;
  return to_string(result);
}

inline string hasher(string data, int selHash){
    
    if(selHash == 1){
    
        return hash1(data);
    
    } else if (selHash == 2){
    
        return hash2(data);
    
    } else if (selHash == 3){
    
        return hash3(data);
    
    } else if(selHash == 4){

        return hash4(data);
    
    } else {
      return data;
    }

}

#endif 