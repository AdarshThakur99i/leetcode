class LRUCache {
public:
     list<int> dll;
     map<int,pair<list<int>::iterator,int>> mp;
     int n;
    LRUCache(int capacity) {
      n=capacity;
    }
    void makeUsed(int key) {
          dll.erase(mp[key].first);
          dll.push_front(key);
          mp[key].first=dll.begin();

    }
    int get(int key) {
         if(!mp.count(key)) return -1;
         makeUsed(key);
         return mp[key].second;
        
    }
    
    void put(int key, int value) {
         if(mp.count(key)) {
                makeUsed(key);
                mp[key]={dll.begin(),value};
         }
         else {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
         }

         if(n<0) {
            mp.erase(dll.back());
            dll.pop_back();
            n=0;
         }
         
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */