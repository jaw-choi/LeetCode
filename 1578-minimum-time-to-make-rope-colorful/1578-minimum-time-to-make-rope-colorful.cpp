class Solution {
public:
    int helper(int left, int right, const vector<int>& t)
    {
        cout << left << " " << right << " " << accumulate(t.begin()+left,t.begin()+right,0) - *max_element(t.begin()+left,t.begin()+right)<<endl;
        return accumulate(t.begin()+left,t.begin()+right,0) - *max_element(t.begin()+left,t.begin()+right);
    }
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int left = 0;
        for(int i=0;i<colors.size();i++)
        {
            while(colors[i]==colors[left])
                i++;
                
            if(i-left>1){
                ans += helper(left,i,neededTime);
            }
            left = i;

        }
        return ans;
    }
};