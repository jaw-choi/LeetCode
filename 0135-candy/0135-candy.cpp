class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i-1] < ratings[i])
            {
                if(candy[i-1] == candy[i])
                    candy[i]++;
                else if(candy[i-1] > candy[i])
                    candy[i] = candy[i-1] + 1;
            }
            else if(ratings[i-1] > ratings[i])
            {
                if(candy[i-1] == candy[i])
                    candy[i-1]++;
                else if(candy[i-1] < candy[i])
                    candy[i-1] = candy[i] + 1;
            }
        }
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i-1] < ratings[i])
            {
                if(candy[i-1] == candy[i])
                    candy[i]++;
                else if(candy[i-1] > candy[i])
                    candy[i] = candy[i-1] + 1;
            }
            else if(ratings[i-1] > ratings[i])
            {
                if(candy[i-1] == candy[i])
                    candy[i-1]++;
                else if(candy[i-1] < candy[i])
                    candy[i-1] = candy[i] + 1;
            }
        }
        return accumulate(candy.begin(),candy.end(),0);
    }
};
//1,1,1,1,1
//1,2,1,1,1
//1,2,3,1,1
//1,2,3,1,2,2,1
//1,2,3,1,3,2,1