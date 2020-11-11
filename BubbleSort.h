#if !defined __bubblesort__
#define __bubblesort__ 1
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include "array.h"

using namespace std;
const int BUFFER_SIZE = 40;

class BubbleSort {
public:
  BubbleSort(){
    //cout << "bs" << endl;
  }

  ostream& operator<<(ostream& out) {
    out << output();
    return out;
  }

  static const char* skipSpaces(const char* arr) {
    if(arr != NULL) {
      const char* p = arr;
      for(; isspace(*p); p++);
      return p;
    }
    return NULL;
  }

  static const char* nextNumber(const char* pn) {
    if(pn != NULL) {
      /*const char* p = skipSpaces(pn);
      for(; isdigit(*pn) || *pn == '.'; pn++);
      return pn;*/
      const char* p = skipSpaces(pn);
      for(; isdigit(*p) || *p == '.'; p++);
      return p;
    }
    return NULL;
  }
public:
  string output() const {
    char buffer[BUFFER_SIZE] = {'\0'};
    string out("Sorted Output: ");
    string num;
    for(int a = 0; a < _numbers.size(); a++){
      sprintf(buffer, "%d ", _numbers[a]);
      printf("%s", buffer);
      out += buffer;
    }
    return out;
  }

  int setNumbers(const char* arr){
    int n = 0;
    int no = 0;
    cout << arr << endl;
    const char* p = skipSpaces(arr);
    for(;p != NULL && sscanf(p, "%d", &no) > 0; n++, p = nextNumber(p)){
      _numbers.push_back(no);                       
    }
    return n;
  }
  
  const BubbleSort& operator=(const BubbleSort& rhs) {
    copyNumbers(rhs._numbers);
    return rhs;
  }

private:

  void copyNumbers(const array<int> numbers) {
    //cout << "copyNumbers" << endl;
    for(int i = 0; i < numbers.size(); i++) {
      //printf("i: %d\tn: %d\n", i, numbers[i]);
      _numbers.push_back(numbers[i]);
    }
  }
  
  void swap(int i){
    int a = _numbers[i+1];
    _numbers[i+1] = _numbers[i];
    _numbers[i] = a;
  }
  int moveBiggestToEnd() {
    int n = 0;
    int i = 0;
    for(; i < _numbers.size() -1; i++){
      if(_numbers[i] > _numbers[i+1]){
        swap(i);
        n++;
      }
    }
    return n;
  }
  public:
  void sort(){
    int n;
    while((n = moveBiggestToEnd()) > 0);
  }
  private:
  array<int> _numbers;
};
#endif //__bubblesort__