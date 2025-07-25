class Solution {
  public:
    int maxCircularSum(vector<int> &arr){
        int n = arr.size();
        auto kadane = [](vector<int>& nums) {
            int max_end_here = nums[0], max_so_far = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                max_end_here = max(nums[i], max_end_here + nums[i]);
                max_so_far = max(max_so_far, max_end_here);
            }
            return max_so_far;
        };
        int max_kadane = kadane(arr);
        int total_sum = 0;
        for (int i = 0; i < n; i++) total_sum += arr[i];
        for (int i = 0; i < n; i++) arr[i] = -arr[i];
        int max_inverse_kadane = kadane(arr);
        int max_wrap = total_sum + max_inverse_kadane;
        if (max_wrap == 0)
            return max_kadane;
        return max(max_kadane, max_wrap);
    }   
};
