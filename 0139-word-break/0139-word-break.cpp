class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // Initialize dp array
        const int N = s.size();
        vector<bool> dp(N+1, false);
        dp[N] = true;

        // Fill dp array
        for (int i = N - 1; i >= 0; i--) {

            // go through every word
            for (string& word : wordDict) {
                if (i + word.size() > N) { continue; }
                else if ((s.substr(i, word.size()) == word) && dp[i + word.size()]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};