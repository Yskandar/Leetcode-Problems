class Solution {
public:
    int findMin(vector<int>& nums) {

        int N = nums.size();
        int left_idx = 0;
        int right_idx = N - 1;

        if (nums[left_idx] < nums[right_idx]) { return nums[left_idx]; }
        if (N == 2) { return nums[right_idx]; }

        while (left_idx < right_idx) {
            
            int mid_idx = floor((left_idx + right_idx) / 2);
            std::cout << "perc N " <<  N << std::endl;
            std::cout << "left" << left_idx << std::endl;
            std::cout << "right" << right_idx << std::endl;
            std::cout << "mid" << mid_idx << std::endl;

            if (nums[(mid_idx - 1)%N] > nums[mid_idx]) { return nums[mid_idx]; }
            if (nums[mid_idx] > nums[mid_idx + 1]) { return nums[mid_idx + 1]; }
            if (nums[mid_idx] >= nums[left_idx]) { left_idx = mid_idx + 1; }
            else { right_idx = mid_idx; }


        }
        return nums[left_idx];
    }
};
