class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.begin(),cards.end());
        return dfs(v);
    }
private:
static constexpr double EPS = 1e-6;
    bool dfs(vector<double>& v)
    {
        int n = (int)v.size();
        if (n == 1) return fabs(v[0] - 24.0) < EPS;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double x = v[i];
                double y = v[j];
                vector<double> rest;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j)
                        rest.push_back(v[k]);
                }
                rest.push_back(x+y);
                if(dfs(rest)) return true;

                rest.back() = x*y;
                if(dfs(rest)) return true;

                rest.back() = x-y;
                if(dfs(rest)) return true;

                rest.back() = y-x;
                if(dfs(rest)) return true;
                if(fabs(y) > EPS){
                    rest.back() = x/y;
                    if(dfs(rest)) return true;
                }
                if(fabs(x) > EPS){
                    rest.back() = y/x;
                    if(dfs(rest)) return true;
                }
            }
        }
        return false;
    }
};
//3,8
//4,6