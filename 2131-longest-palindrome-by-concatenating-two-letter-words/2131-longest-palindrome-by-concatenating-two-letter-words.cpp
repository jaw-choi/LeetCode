class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int cnt = 0;
        bool flag = false;
        unordered_map<string,int> mmp;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]!=words[i][1])
                mmp[words[i]]++;
            else
                mp[words[i]]++;
        }
        for(auto mm : mmp)
        {
            string tmp = mm.first;
            string rtmp;
            rtmp+=tmp[1];
            rtmp+=tmp[0];
            ans += min(mmp[tmp],mmp[rtmp]);
            
        }
        ans*=2;
        cout <<ans;
        int oddCnt = 0;
        for(auto m :mp)
        {
            if(m.second %2==1)
                oddCnt = max(oddCnt,m.second);
        }
        int count = 0;
        for(auto m :mp)
        {
            if(m.second % 2 ==0)
                cnt+=m.second;
            else{
                if(m.second < oddCnt)
                    cnt+=(m.second-1);
                else{
                    if(count==0)
                        cnt+=(m.second);
                    else
                        cnt+=(m.second-1);
                    count++;
                }

            }
        }

        ans += cnt*2;
        cout<<endl<<ans;
        return ans;
    }
};
/*
c	num
ll	2
bb	3
xx	3  =>3

lb	4
bl	1 =>1

bx	3
xb	1 =>1

lx	2
xl	1=>1
*/
