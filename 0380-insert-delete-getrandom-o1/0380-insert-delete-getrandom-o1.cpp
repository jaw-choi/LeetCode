class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        mp[val]=1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {

        auto it = mp.begin();
        int r = rand() % mp.size();
        advance(it,r);
        return it->first;
    }
private:
    unordered_map<int,int> mp;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */