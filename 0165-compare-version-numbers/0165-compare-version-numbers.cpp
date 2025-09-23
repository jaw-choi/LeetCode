class Solution {
public:
vector<string> splitByDot(const string& input) {
    stringstream ss(input);
    string token;
    vector<string> result;
    while (getline(ss, token, '.')) {
        result.push_back(token);
    }
    return result;
}
    int compareVersion(string version1, string version2) {
        auto va = splitByDot(version1);
        auto vb = splitByDot(version2);
        int n = max(va.size(),vb.size());
        int na,nb;
        for(int i=0;i<n;i++)
        {
            na = 0;
            nb = 0;
            if(i<va.size())
                na = stoi(va[i]);
            if(i<vb.size())
                nb = stoi(vb[i]);
            if(na<nb) return -1;
            if(na>nb) return 1;
        }
        return 0;
    }
};