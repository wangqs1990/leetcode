/**
*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
*
*get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
*set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

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
      //this->clist.erase(iter->second);
      this->clist.splice(this->clist.begin(), this->clist, iter->second);
      this->cmap[key] = this->clist.begin();
      return value;
    }
  }

  void set(int key, int value) {
    pair<int, int> *keyIter;
    unordered_map<int, KeyIter>::iterator iter = this->cmap.find(key);

    if (iter != this->cmap.end()) {
      //update
      iter->second->second = value;
      this->clist.splice(this->clist.begin(), this->clist, iter->second);
    } else {
      if (this->clist.size() == capacity) {
        keyIter = &this->clist.back();
        this->cmap.erase(keyIter->first);
        clist.pop_back();
      }
      this->clist.push_front(make_pair(key, value));
    }
    this->cmap[key] = this->clist.begin();
  }
};