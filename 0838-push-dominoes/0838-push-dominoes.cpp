class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans="";
        queue<char> q;
        int idx = 0;
        char mostLeft=' ';
        for(int i=0;i<dominoes.size();i++)
        {
            if(mostLeft==' '){
                mostLeft = dominoes[i];
                idx = i;
            }
            else{
                if(mostLeft=='.' && dominoes[i]=='L'){
                    for(int j=idx;j<i;j++){
                        ans+='L';
                    }
                    idx=i;
                    mostLeft='L';
                }
                else if(mostLeft=='.' && dominoes[i]=='R'){
                    for(int j=idx;j<i;j++)
                        ans+='.';
                    idx=i;
                    mostLeft='R';
                }
                else if(mostLeft=='L' && dominoes[i]=='.'){
                    ans+='L';
                    idx=i;
                    mostLeft='.';
                }
                else if(mostLeft=='L' && dominoes[i]=='L'){
                    ans+='L';
                    idx=i;
                    mostLeft='L';
                }
                else if(mostLeft=='L' && dominoes[i]=='R'){
                    ans+='L';
                    idx = i;
                    mostLeft='R';
                }
                else if(mostLeft=='R' && dominoes[i]=='R'){
                    for(int j=idx;j<i;j++)
                        ans+='R';
                    idx=i;
                    mostLeft='R';
                }
                else if(mostLeft=='R' && dominoes[i]=='L'){
                    int left = idx;
                    int right = i;
                    int cnt = right - left + 1;
                    if(cnt%2==0){
                        for(int j=0;j<cnt/2;j++)
                            ans+='R';
                        for(int j=0;j<cnt/2-1;j++)
                            ans+='L';
                    }
                    else{
                        for(int j=0;j<cnt/2;j++)
                            ans+='R';
                        ans+='.';
                        for(int j=0;j<cnt/2-1;j++)
                            ans+='L';
                    }
                    idx=i;
                    mostLeft='L';
                }
            }
            //cout << ans << endl;
        }
        if(mostLeft=='.'){
            for(int i=0;i<dominoes.size()-idx;i++)
                ans+='.';
        }
        else if(mostLeft=='R'){
            for(int i=0;i<dominoes.size()-idx;i++)
                ans+='R';
        }
        else if(mostLeft=='L'){
            for(int i=0;i<dominoes.size()-idx;i++)
                ans+='L';
        }
        return ans;
    }
};
//.인 경우
    //.이다가 L인경우
    //.이다가 R인경우
//L인 경우
    //L이다가 R인경우
    //L이다가 .인경우
//R인 경우
    //R이다가 L인 경우
    //R이다가 .인 경우
//가장 좌측이 L인지 R인지 .인지 알고있어야함, 
//LR == L...R
//RL == R...L, R..L