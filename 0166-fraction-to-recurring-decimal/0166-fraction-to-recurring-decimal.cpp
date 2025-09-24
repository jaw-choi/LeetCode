class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long numer = (long long)numerator;
        long long denom = (long long)denominator;
        string answer = "";
        map<long long, int> mp;
        bool flag = false;
        int cnt = 0;
        bool minus = false;
        //if(denominator==INT_MIN)
            //return "0";
        if(numer==0)
            return "0";
        if (numer < 0 && denom < 0) {
            // minus=true;
            numer = -numer;
            denom = -denom;
        } else if (numer < 0) {
            minus = true;
            numer = -numer;
        } else if (denom < 0) {
            minus = true;
            denom = -denom;
        }
        //cout << numer << endl << denom <<endl;
        while (1) {
            if (numer % denom == 0) {
                long long result = numer / denom;
                answer += to_string(result);
        //cout << numer << endl << denom <<endl<<answer<<endl;

                if(minus)
                    return "-"+answer;
                return answer;
                //break;
            } else {
                if (numer > denom && !flag) {
                    answer += to_string(numer / denom);
                    numer = numer % denom;
                    continue;
                } else {
                    if (!flag) {

                        if (answer.size() == 0) {
                            answer += "0.";
                            numer *= 10;
                        } else {
                            answer += ".";
                            numer *= 10;
                        }
                        flag = true;
                    } else {
                        if (mp.find(numer) != mp.end()) {
                            answer.insert(mp[numer], "(");
                            answer += ')';
                            break;
                        }
                        mp[numer] = answer.length();
                        int result = numer / denom;
                        answer += to_string(result);
                        if (result != 0)
                            numer = numer - (result * denom);
                        numer *= 10;
                    }
                }
            }
        }
        if (minus == true)
            return "-" + answer;
        return answer;
    }
};