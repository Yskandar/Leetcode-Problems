class Solution {
public:
    int search(vector<int>& nums, int target) {

        int N = nums.size();
        int left = 0;
        int right = N - 1;

        while (left <= right){
        
            int mid = (left + right) / 2;
            if (nums[mid] == target) { return mid; }
            if (nums[left] == target) { return left; }
            if (nums[right] == target) { return right; }

            if (nums[mid] >= nums[left] && target < nums[left]) { left = mid + 1; }
            else if (nums[mid] >= nums[left] && target > nums[mid]) { left = mid + 1; }
            else if (nums[mid] >= nums[left] && target < nums[mid]) { right = mid; }

            else if (nums[mid] <= nums[left] && target > nums[left]) { right = mid; }
            else if (nums[mid] <= nums[left] && target < nums[mid]) { right = mid; }
            else if (nums[mid] <= nums[left] && target > nums[mid]) { left = mid + 1; }
        
        
        }
        return -1;


    }
};
