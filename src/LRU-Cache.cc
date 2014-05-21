/**
*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
*
*get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
*set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;
typedef list<pair<int, int>>::iterator KeyIter;

class LRUCache{
private:
  list<pair<int, int>> clist;
  unordered_map<int, KeyIter> cmap;
  int capacity;
public:
  LRUCache(int capacity): capacity(capacity) {

  }

  int get(int key) {
    unordered_map<int, KeyIter>::iterator iter = this->cmap.find(key);
    int value;
    if (iter == this->cmap.end()) {
      return -1;
    } else {
      value = iter->second->second;
      this->clist.erase(iter->second);
      this->clist.push_back(make_pair(key, value));
      return value;
    }
  }

  void set(int key, int value) {
    pair<int, int> *keyIter;
    if (this->clist.size() == capacity) {
      keyIter = &this->clist.front();
      
      this->cmap.erase(keyIter->first);
      clist.pop_front();
      
    }
    this->cmap[key] = this->clist.insert(this->clist.end(), make_pair(key, value));
  }
};

int main(int argc, char *argv[]) {
  /* unordered_map<int, int> m;
  m.insert(make_pair(1,10));
  m.insert(make_pair(2,20));
  m.insert(make_pair(3,30));
  m.insert(make_pair(4,40));

  cout<<(*m.find(10)).second<<endl;*/

  LRUCache l(2);
  l.set(2, 20);
  
  l.set(1, 10);

  cout<<l.get(2)<<endl;
  l.set(3, 30);

  cout<<l.get(2)<<endl;
  system("pause");
}