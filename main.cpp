#include <iostream>
#include <string.h>
#include "BubbleSort.h"
using namespace std;
#include "array.h"

istream& operator>>(istream& is, BubbleSort& bs) {
  char arr[BUFFER_SIZE] = {'\0'};
  is.getline(arr, sizeof(arr)/sizeof(char));
  printf("1: %s\n", arr); 
  bs.setNumbers(arr);     
  //BubbleSort::skipSpaces(arr);          
  return is;
}
ostream& operator<<(ostream& os, BubbleSort& b){
  os << b.output();
  return os;
}

int main() {
  array<BubbleSort> abs;
  BubbleSort bs;
  cout << "Enter Numbers: " << endl;
  cin >> bs;
  bs.sort();
  abs.push_back(bs);
  cout << bs;
}

//Comment out line 26 and put a while statement around lines 21-27 to sort as long as the user enters numbers.
