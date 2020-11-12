#include <iostream>
#include <string.h>
#include "BubbleSort.h"
using namespace std;
#include "array.h"

istream& operator>>(istream& is, BubbleSort& bs) {
  char arr[BUFFER_SIZE] = {'\0'};
  is.getline(arr, sizeof(arr)/sizeof(char));
  printf("%s\n", arr); 
  bs.setNumbers(arr);     
  //BubbleSort::skipSpaces(arr);          
  return is;
}
ostream& operator<<(ostream& os, BubbleSort& b){
  os << b.output() << endl;
  return os;
}



bool inputNumbers(BubbleSort& bs) {
  cout << "Enter Numbers: " << endl;
  cin >> bs;
  return bs.isValid();
}

int main() {
  Array<BubbleSort> abs;
  BubbleSort bs;
  while(inputNumbers(bs)) {
    bs.sort();
    abs.push_back(bs);
    cout << bs;
    bs.clear();
  }
}

//hw: Use remove to remove all items. 

//Comment out line 26 and put a while statement around lines 21-27 to sort as long as the user enters numbers.
