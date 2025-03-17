class Solution {
public:
    bool timeStuff(int cars, const vector<int>& ranks, long long time)
    {
        long long carDone = 0;
        for(auto r : ranks)
        {
            long long c2 = time / r;
            long long c = floor(sqrt(c2));
            carDone += c;
        }
        return carDone >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long ans;
        long long left = 1;
        long long right = ranks[ranks.size()-1]*(long long)cars*cars;
        while(left<=right)
        {
            long long mid = (left+right)/2;

            if(timeStuff(cars,ranks,mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left  = mid + 1;
            }
        }
        return ans;
    }
};