#include <iostream>
#include <vector>
#include <algorithm> // swap only — NOT sort

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low  = 0;
        int mid  = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    std::swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    std::swap(nums[mid], nums[high--]);
                    // Do NOT increment mid
                    break;
            }
        }
    }
};

// ── Helpers ──────────────────────────────────────────────
void print(const std::string& label, const std::vector<int>& nums) {
    std::cout << label;
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";
}

void test(std::vector<int> nums) {
    Solution sol;
    print("Before: ", nums);
    sol.sortColors(nums);
    print("After:  ", nums);
    std::cout << "\n";
}

// ── Main ─────────────────────────────────────────────────
int main() {
    test({2, 0, 2, 1, 1, 0});   // mixed
    test({2, 2, 2});             // all blue
    test({0, 0, 0});             // all red
    test({1});                   // single element
    test({1, 2, 0});             // already needs sorting
    return 0;
}
