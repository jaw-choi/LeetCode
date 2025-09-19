class Spreadsheet {
public:
    Spreadsheet(int rows) {
        vector<vector<int>> v(26, vector<int>(rows + 1, 0));
        mVec = v;
    }
    int getCell(string cell) {
        char alp = cell[0];
        int num = 0;
        for (int i = 1; i < cell.length(); i++) {
            num = num * 10 + (cell[i] - '0');
        }
        return mVec[alp - 'A'][num];
    }
    void setCell(string cell, int value) {
        char alp = cell[0];
        int num = 0;
        for (int i = 1; i < cell.length(); i++) {
            num = num * 10 + (cell[i] - '0');
        }
        mVec[alp - 'A'][num] = value;
    }

    void resetCell(string cell) { setCell(cell, 0); }

    int getValue(string formula) {
        string str = "";
        int idx = 0;
        for (int i = 1; i < formula.size(); i++) {
            if (formula[i] == '+'){
                idx = i+1;
                break;
            }
            str += formula[i];
        }
        int a, b;
        if (str[0] >= 'A' && str[0] <= 'Z')
            a = getCell(str);
        else {
            a= stoi(str);
        }

        str = "";
        for (int i = idx; i < formula.size(); i++) {
            str += formula[i];
        }
        if (str[0] >= 'A' && str[0] <= 'Z')
            b = getCell(str);
        else {
            b = stoi(str);
        }

        return a + b;
    }

private:
    vector<vector<int>> mVec;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */