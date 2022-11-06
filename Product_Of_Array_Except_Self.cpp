class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        const int N = nums.size();
        vector<int> pre(N);
        vector<int> suff(N);
        vector<int> ans(N);

        pre[0] = nums[0];
        suff[N - 1] = nums[N - 1];

        for (int i = 1; i < N; i++)
        {
            pre[i] = nums[i] * pre[i - 1];
            suff[N - i - 1] = nums[N - i - 1] * suff[N - i];
        }
        for (int i = 1; i < N - 1; i++)
        {
            ans[i] = pre[i - 1] * suff[i + 1];

        }
        ans[N-1] = pre[N-2];
        ans[0] = suff[1];
        
        return ans;

    }
};
