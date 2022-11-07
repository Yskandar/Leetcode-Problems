class Solution {
public:
    int maxProduct(vector<int>& nums) {


        const int& N = nums.size();
        int prod = nums[0];
        int min_prod = nums[0];
        int max_prod = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < N; i++) {

            int temp = max_prod;
            max_prod = max(nums[i], max(nums[i] * min_prod, nums[i] * temp));
            min_prod = min(nums[i], min(nums[i] * min_prod, nums[i] * temp));
            



            maxi = max(maxi, max_prod);




        }
        return maxi;

    }
};
