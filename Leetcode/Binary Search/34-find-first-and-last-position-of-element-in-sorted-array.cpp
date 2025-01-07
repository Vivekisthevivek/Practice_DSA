class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lower = -1, upper = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                lower = mid;
            }
            if(nums[mid] >= target){
                right = mid - 1; 
            }
            else{
                left = mid + 1;
            }
        }
        if(lower > -1){
            right = nums.size() - 1;
        }
        else{
            return {-1, -1};
        }
        upper = right;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                upper = mid - 1;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {lower, upper};
    }
};