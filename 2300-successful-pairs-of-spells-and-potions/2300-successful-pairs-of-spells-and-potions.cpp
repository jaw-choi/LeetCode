class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int size_ = 0;
        
        for(int i=0;i<spells.size();i++)
        {
            size_ = potions.size();
            double border = success / (double)spells[i];
            int left = 0;
            int right = potions.size()-1;
            int tmp = 0;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if((double)potions[mid] <border){
                    left = mid + 1;
                    tmp = mid+1;
                }
                else
                    right = mid - 1;
                //cout << tmp <<endl;
            }
            cout <<tmp<< endl;
            // for(int j=0;j<potions.size();j++)
            // {
            //     if((double)potions[j] < border)
            //         size_--;
            //     else
            //         break;
            // }
            ans.push_back(size_-tmp);
        }
        
        return ans;
    }
};