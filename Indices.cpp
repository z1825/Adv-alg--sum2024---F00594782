#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<std::pair<int, int>> matrix;

        for (int i = 0; i < n; ++i) {
            matrix.push_back({nums[i], i});
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (matrix[i].first + matrix[j].first == target) {
                    return {matrix[i].second, matrix[j].second};
                }
            }
        }

        return {};
    }
};

// Main function for local testing
int main() {
    Solution sol;

    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = sol.twoSum(nums1, target1);
    if (!result1.empty()) {
        std::cout << "Example 1 Indices: [" << result1[0] << ", " << result1[1] << "]\n";
    } else {
        std::cout << "Example 1 No solution found\n";
    }

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = sol.twoSum(nums2, target2);
    if (!result2.empty()) {
        std::cout << "Example 2 Indices: [" << result2[0] << ", " << result2[1] << "]\n";
    } else {
        std::cout << "Example 2 No solution found\n";
    }

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = sol.twoSum(nums3, target3);
    if (!result3.empty()) {
        std::cout << "Example 3 Indices: [" << result3[0] << ", " << result3[1] << "]\n";
    } else {
        std::cout << "Example 3 No solution found\n";
    }

    return 0;
}
