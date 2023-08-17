#include<bits/stdc++.h>
using namespace std;
//question link : https://leetcode.com/problems/lru-cache/description/

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};


//solution using list
class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> ht;
    list<int> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    void moveToFirst(int key){
        dll.erase(ht[key].first);
        dll.push_front(key);
        ht[key].first=dll.begin();
    }
    
    int get(int key) {
        if(ht.find(key)==ht.end()) return -1;
        
        moveToFirst(key);
        return ht[key].second;
    }
    
    void put(int key, int value) {
        if(ht.find(key)!=ht.end()){
            ht[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            ht[key]={dll.begin(), value};
            cap--;
        }
        
        if(cap<0){
            ht.erase(dll.back());
            dll.pop_back();
            cap++;
        }
        
    }
};

/*
Algorithm Outline:

LRUCache()
1. key -> (addr, value)
2. List, will contain keys
3. cap=capacity

Get
1. if found, movetofirst for key, return. Else -1

Put
1. if exist, update.
2. else add
3. move to first
4. if >capacity, remove last in list i.e. LRU

Move to first
1. erase element
2. add to first
3. store first addr in ht
 */
