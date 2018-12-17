#include <iostream>
using namespace std;
#define N 100

// 2018/08/09

template <typename T> class Stack {
private:
  T* _data;
  size_t _size;
  size_t _top = 0; // aka. count
public:
  Stack(int size=10) : _size(size), _top(0) {
    _data = new T[size];
  }
  virtual ~Stack() { delete[] _data; }
  const void push(T val) {
    if (is_full()) overflow();
    _data[_top++] = val;
  }
  const T pop() {
    if (is_empty()) abort();
    return _data[--_top];
  }
  const T top() const { return _data[_top]; }
  const bool is_full() const { return _top+1 == _size; }
  const bool is_empty() const { return _top == 0; }
  const size_t count() const { return _top; }
private:
  const void overflow() {
    _size <<= 1;
    T* data = new T[_size];
    memcpy(data, _data, _top * sizeof(T));
    delete[] _data;
    _data = data;
  }
};

bool strsymmetry(char* str) {
  Stack<char> s;
  char* p = str;
  while (*p != '\0') s.push(*p++);
  p = str;
  while (*p != '\0')
    if (*p++ != s.pop()) return false;
  return true;
}

int main() {
  char* strs[N] = {
    "",
    "12345654321",
    "1345684612321648451556",
    "1345684612321648451556321146314865464314",
    "1345684612321648451556sdsvbjkdlkad;msdsvjkbnalkvn321146314865464314",
  };
  int r = 5;
  while (r--) cout << strsymmetry(strs[r]) << endl;
}