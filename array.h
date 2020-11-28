#if !defined __Array_h__
#define __Array_h__ 1
const int ARRAYSIZE = 1024;
const int OUT_OF_BOUNDS = 2354978;
#include <stdio.h>

template<class T>
class Array{
  public:

  Array() : _store(NULL), _size(0){
    _store = new T[ARRAYSIZE];
    _capacity = ARRAYSIZE;
  }
  ~Array() {
    if(_store != NULL) {
      delete [] _store;
      _store = NULL;
    }
  }

bool empty() const{
  return _size == 0 || _store == NULL;
}

  unsigned long size() const {
    return _size;
  }
  const T& operator[](const int i) const {
    return ( const_cast <Array<T>*> (this) )->item(i);
  }

  T& operator[](const int i) {
    return item(i);
  }

  T& pop() {
    if(_store != NULL && _size > 0) {
      return item(_size-- -1);
    }
    throw OUT_OF_BOUNDS;
    return _store[0];
  }

  bool insert(const T& it, const int index) {
    if(index >= 0 && index <= _size) {
      if(index == _size) {
        return push_back(it) >= 0;
      }
      moveItemsUp(index);
      (*this)[index] = it;
      return true;
    }
    return false;
  }

  void clear() {
    int i = size();
    while(remove(--i))printf("i = %d\n", i);
  }

  bool remove(const int index) {
    if(_size > 0 && _store != NULL && index >= 0 && index <= _size) {
      moveItemsDown(index);
      _size--;
      return true;
    }
    return false;
  }

  const int push_back(const T& item) {
    if(_capacity > _size) {
      int   length = (int)_size;
      _store[_size++] = item;
      return length;
    }
    return _reAllocatePushBack(item);
  }

  protected:
  
  static void swapElement(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
  }

  public: 
    int swap(Array<T>& rhs) {
    int i = 0;
    if(_size <= rhs._size)
      return rhs.swap(*this);
    for(;i < rhs._size; i++) {
      swapElement(item(i), rhs[i]);
    }
    for(; i < _size; i++) {
      rhs.push_back(item(i));
      remove(i);
    }
    return _size;
  } 
  protected:


  //friend char* X::foo(int);
  //lets other classe X use this funct

  /*void swap(arr) {
    int temp, i;
    for(i = 0; i < arr.length; i++) {
      if(arr[i] > arr[i+1]) {
        temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
      }
    }
    return arr;
  }*/

  void moveItemsDown(const int i){
    int cs = _size;
    for(int c = i; c < cs - 1; c++) {
      (*this)[c-1] = (*this)[c];
    }
  }

  void moveItemsUp(const int i){
    int cs = _size;
    push_back(*this[_size-1]);
    for(int j = cs - 1; j > i; j--) {
      (*this)[j] = (*this)[j-1];
    }
  }

  T& item(const int i) {
    if(i < _size && _store != NULL) {
      return _store[i];
    }
    throw OUT_OF_BOUNDS;
    return _store[0];
  }

  protected:
    const int _reAllocatePushBack(const T& item) {
      T*  newMem = reallocate();
      if(newMem != NULL) {
        copyTo(newMem);
        delete _store;
        _store = newMem;
        return push_back(item);
      }
      throw "no more mem remaining :(";
      return -1;
    }

    T* reallocate() {
      T*  mem = new T[_capacity + ARRAYSIZE];
      if(mem != NULL) {
        _capacity += ARRAYSIZE;
        return mem;
      }
      return NULL;
    }

    void copyTo(T* newMem) {
      if(newMem != NULL) {
        for(int i = 0; i < _size; i++) {
          newMem[i] = _store[i];
        }
      }
    }

  protected:
    T* _store;
    unsigned long _capacity;
    unsigned long _size;
};

template<typename T>
void swap(Array<T>& left, Array<T>& right) {
  left.swap(right);
}

#endif //__Array_h__
