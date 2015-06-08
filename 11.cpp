// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCap = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            maxCap = std::max(maxCap, std::min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) {
                --j;
            } else {
                ++i;
            }
        }
        return maxCap;
    }
};

