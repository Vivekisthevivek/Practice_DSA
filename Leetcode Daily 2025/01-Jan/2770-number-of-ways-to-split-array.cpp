class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // sum = accumulate(nums.begin(), nums.end(), 0); // Run time error
        long long preSum = 0;

        for (int i = 0; i < n - 1; i++) {
            sum -= nums[i];
            preSum += nums[i];
            if (preSum >= sum) {
            // if (preSum >= sum - preSum) {
                cnt++;
            }
        }

        return cnt;
    }
};