class Bank {
public:
    Bank(vector<long long>& balance) :acc(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        if(acc.size()<account1 || acc.size()<account2)
            return false;
        if(acc[account1-1] < money)
            return false;
        acc[account1-1]-=money;
        acc[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(acc.size()<account)
            return false;
        acc[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(acc.size()<account)
            return false;
        if(acc[account-1] < money)
            return false;
        acc[account-1]-=money;
        return true;
    }
    vector<long long> acc;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */