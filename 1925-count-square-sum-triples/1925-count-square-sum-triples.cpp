class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        int lmt = n* n;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int num = i*i + j*j;
                if(num > lmt) break;
                int root = sqrt(num);
                //cout << i << " " << j<<" "<<root<<endl;
                if(root*root==num)
                    ans+=2;
            }
        }
        return ans;
    }
};