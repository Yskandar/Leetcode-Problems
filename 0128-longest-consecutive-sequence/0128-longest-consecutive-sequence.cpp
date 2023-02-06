
class Solution {
public:

	int longestConsecutive(std::vector<int> nums) {

		std::unordered_set<int> numset;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			numset.insert(nums[i]);
		}

		for (int i = 0; i < nums.size(); i++) {
			if (numset.find(nums[i] - 1) == numset.end()) {
				int length = 1;
				while (numset.find(nums[i] + length) != numset.end()) {
					length += 1;

				}
				ans = std::max(ans, length);
			}

		}

		return ans;


	}


};