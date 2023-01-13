class Solution {
public:
    int numDecodings(string& s) {
        int n = s.size();
        int dp_2 = 1, dp_1 = 0;
        int temp = 0;
        if (s[n - 1] != '0') { dp_1 = 1; }

        for (int i = n - 2; i >= 0; i--) {

            string sub = s.substr(i, 2);
            int num = stoi(sub);

            if ((s[i] != '0') && (num <= 26)) {
                temp = dp_1 + dp_2;
                dp_2 = dp_1;
                dp_1 = temp;
            }

            if (s[i] == '0') {
                dp_2 = dp_1;
                dp_1 = 0;
            }
            if ((s[i] != '0') && (num > 26)) {
                dp_2 = dp_1;

            }


        }
        return dp_1;

    }
    
};