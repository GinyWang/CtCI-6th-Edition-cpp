#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int getCharNumber(const char & c){
  if(c>='a' && c<='z'){
    return c-'a';
  }else if (c>='A' && c<='Z'){
    return c-'A';
  }else
    return -1;
}

bool isPermutationOfPallindrome3(string phrase){
  int bitVector = 0;
  for(char ch : phrase){
    int idx = getCharNumber(ch);
    if(idx < 0) continue;
    int mask = 1<<(idx);
    if((bitVector & mask) != 0){
      bitVector &= ~mask; //clear bit
    }else{
      bitVector |= mask; //set bit
    }
  }
  return (bitVector==0) || (bitVector & (bitVector-1))==0;
}

int main()
{
    std::string str("Tact Coa");
    std::cout << "Does \"" << str << "\"  has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    // std::cout << "Approach 1:" << isPermutationOfPallindrome( str ) << std::endl;
    // std::cout << "Approach 2:" << isPermutationOfPallindrome2( str ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str ) << std::endl;


    std::string str1("A big Cat");
    std::cout << "Does \"" << str1 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    //std::cout << "Approach 1:" << isPermutationOfPallindrome( str1 ) << std::endl;
    //std::cout << "Approach 2:" << isPermutationOfPallindrome2( str1 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str1 ) << std::endl;


    std::string str2("Aba cbc");
    std::cout << "Does \"" << str2 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    // std::cout << "Approach 1:" << isPermutationOfPallindrome1( str2 ) << std::endl;
    // std::cout << "Approach 2:" << isPermutationOfPallindrome2( str2 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPallindrome3( str2 ) << std::endl;
    return 0;
}