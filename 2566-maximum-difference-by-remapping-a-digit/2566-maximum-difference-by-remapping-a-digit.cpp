class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        int max = 0;
        int min = 0;
        char curr = str[0];
        string tmp = str;
        int i = 0;
        while(tmp[i] == '9'){
            i++;
            curr = tmp[i];
        }
        for(auto& ch : tmp)
        {
            if(ch==curr)
                ch='9';
        }
        max = stoi(tmp);

        tmp = str;
        curr = str[0];
        for(auto& ch : tmp)
        {
            if(ch==curr)
                ch='0';
        }
        min = stoi(tmp);
        cout << max <<" "<< min;
        return max - min;
    }
};