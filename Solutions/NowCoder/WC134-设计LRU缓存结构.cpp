// 2021/10/02 
// Note: LRU = linklist (update/delete) + hashmap (query)

#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

class MyLRU {
private:
  int size = 0;
  int count = 0;
  map<int, int> ht;   // <key> <value>
  list<int> ll;       // <key>
public:
  MyLRU(int size) : size(size) { }
  void put(int key, int val) {
    if (get(key) != -1) {
      ht[key] = val;  // just update
      return;
    }

    if (count >= size) {
      int k = ll.back();
      ll.pop_back();
      ht.erase(k);
    } else count++;
    ll.push_front(key);
    ht[key] = val;
  }
  int get(int key) {
    auto it = ht.find(key);
    if (it == ht.end()) return -1;
    
    for (auto jt=ll.begin(); jt!=ll.end(); jt++) {
      if (*jt == key) {
        ll.erase(jt);
        ll.push_front(key);
        break;
      }
    }
    return it->second;
  }
};

class Solution {
public:
  vector<int> LRU(vector<vector<int>>& operators, int k) {
    vector<int> r;
    MyLRU lru = MyLRU(k);
    for (auto it=operators.begin(); it!=operators.end(); it++) {
      if ((*it)[0] == 1) {
        cout << "put: " << (*it)[1] << ' ' << (*it)[2] << endl;
        lru.put((*it)[1], (*it)[2]);
      } else {
        cout << "get: " << (*it)[1] << endl;
        r.push_back(lru.get((*it)[1]));
      }
    }
    return r;
  }
};

int main() {
  cin.sync_with_stdio(false);
  vector<vector<int>> operators;
  vector<int> op1 = {1,1,1};
  vector<int> op2 = {1,2,2};
  vector<int> op3 = {1,3,2};
  vector<int> op4 = {2,1};
  vector<int> op5 = {1,4,4};
  vector<int> op6 = {2,2};
  operators.push_back(op1);
  operators.push_back(op2);
  operators.push_back(op3);
  operators.push_back(op4);
  operators.push_back(op5);
  operators.push_back(op6);

  vector<int> r = Solution().LRU(operators, 3);
  for (auto it=r.begin(); it!=r.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
 
