class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        //1,-3,4,x
        //1 = b-a
        //-3 = c-b
        //4 = d-c
        //lower <= a,b,c,d<=upper
        //c-a = -2
        //d-b = 1
        //a->2, b->3, c->3, d->2
        //x,x+1,x-2,x+2 (for 1 to 6) => upper - max, lower - min(if(min<0))
        //3to4
        long long ans = 0;
        long long diffMax = 0;
        long long diffMin = 0;
        long long curr = 0;
        int diff = upper-lower;
        for(int i=0;i<differences.size();i++)
        {
            //1,1,0  / -2,1,-2   / 2,2,-2
            curr += differences[i];
            diffMax = max(diffMax,curr);
            diffMin = min(diffMin,curr);
            if(abs(curr) > diff)
                return 0;
        }
        upper-=diffMax;
        lower-=diffMin;
        ans = upper - lower + 1;
        return ans > 0 ? ans : 0;
    }
};