class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
        if (begin < size(nums) && nums[begin] == target) {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

private:
    int lower_bound(const vector<int> &nums, int target) {
        int left = -1, right = size(nums);
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    int upper_bound(const vector<int> &nums, int target) {
        int left = -1, right = size(nums);
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};