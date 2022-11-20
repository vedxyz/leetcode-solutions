class MyHashMap {
    typedef list<pair<int, int>> bucket;
    int tsize;
    vector<bucket> table;
    
    int i(int key) { return key % tsize; }
    struct matchkey {
        const int& key;
        matchkey(const int& key) : key(key) {}
        bool operator()(const pair<int, int>& kvpair) { return kvpair.first == key; }
    };
public:
    MyHashMap() : tsize(2069), table(tsize) {}
    
    void put(int key, int value) {
        table[i(key)].push_front({key, value});
    }
    
    int get(int key) {
        bucket& keyBucket = table[i(key)];
        bucket::iterator found = find_if(keyBucket.begin(), keyBucket.end(), matchkey(key));
        return found == keyBucket.end() ? -1 : found->second;
    }
    
    void remove(int key) {
        table[i(key)].remove_if(matchkey(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
