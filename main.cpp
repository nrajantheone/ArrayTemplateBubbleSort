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

bool inputNumbers(Array<int>& num) {
  return num.size() > 0;
}

int main() {
  Array<BubbleSort> abs;
  Array<int> arr;
  BubbleSort bs;
  while(inputNumbers(bs)) {
    bs.sort();
    abs.push_back(bs);
    cout << bs;
    bs.clear();
    inputNumbers(arr);
    bs.swap(arr);
    bs.clear();
  }
}



//hw: implement input numbers
