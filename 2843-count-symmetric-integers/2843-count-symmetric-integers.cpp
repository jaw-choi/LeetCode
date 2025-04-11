class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int num=low;num<=high;num++)
        {
            if(num<10)
                continue;
            else if(num>=100 && num <=999)
                continue;
            else if(num>9999)
                continue;
            else
            {
                if(num>=10 && num<100)
                {
                    if(num/10 == num%10){
                        //cout <<num<<endl;
                        ans++;
                    }
                }
                else
                {

                    if((num/1000 + ((num/100) %10))==((num%100) / 10)+(num%10)){
                        //cout <<num<<endl;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};