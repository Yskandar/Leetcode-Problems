class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;

        while (left < right) {

            if (height[left] <= height[right]) {
                area = max(area, height[left] * (right - left));
                left += 1;
            }
            else {
                area = max(area, height[right] * (right - left));
                right -= 1;
            }
        }
        return area;
        }
};
