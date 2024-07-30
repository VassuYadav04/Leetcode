class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {

            uniform_int_distribution<int> dis(left, right);
            int pivot_idx = dis(gen);
            int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, &nums);
            if (new_pivot_idx == k - 1) {
                break;
            } else if (new_pivot_idx > k - 1) {
                right = new_pivot_idx - 1;
            } else {
                left = new_pivot_idx + 1;
            }
        }
        return nums[k - 1];
    }
    
    int PartitionAroundPivot(int left, int right, int pivot_idx, vector<int>* nums) {
        auto& nums_ref = *nums;
        int pivot_value = nums_ref[pivot_idx];
        int new_pivot_idx = left;
        swap(nums_ref[pivot_idx], nums_ref[right]);
        for (int i = left; i < right; ++i) {
            if (nums_ref[i] > pivot_value) {
                swap(nums_ref[i], nums_ref[new_pivot_idx++]);
            }
        }
        swap(nums_ref[right], nums_ref[new_pivot_idx]);
        return new_pivot_idx;
    }
};