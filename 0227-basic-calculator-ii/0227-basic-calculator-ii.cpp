class Solution {
public:
    int calculate(string s) {
        stringstream ss("+"+s);
        char op;
        int n=0,last=0,ans=0;
        while(ss>>op>>n){
            if(op=='+'||op=='-'){
                n = op == '+' ? n : -n;
                ans += n;
            }
            else{
                n = op == '*'? last*n : last/n;
                ans = ans - last + n;
            }
            last = n;
        }
        return ans;
    }
};