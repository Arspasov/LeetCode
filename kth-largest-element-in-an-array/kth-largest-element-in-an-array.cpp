class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto kth = nums.begin() + (nums.size()  - k);
           std::nth_element(nums.begin(),kth, nums.end());
        return *kth;
    }
};

//brute force: to sort array and then find the largest from right to left;
// its not useful because we do a lot of useless operations for sorting the array;

//can be done with heap because we can create heap with linear complexity and we can access the top element easily
