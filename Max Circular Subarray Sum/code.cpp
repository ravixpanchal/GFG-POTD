class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // Using the Kadane's Algorithm
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int totalSum=0;
        int currMinSum=0;
        int currMaxSum=0;
        
        for(int i=0;i<arr.size();i++){
            totalSum+=arr[i];
            currMinSum+=arr[i];
            currMaxSum+=arr[i];
            
            //Update the value,then Reset
            maxSum=max(maxSum,currMaxSum);
            if(currMaxSum<0) currMaxSum=0;
            
            minSum=min(minSum,currMinSum);
            if(currMinSum>0) currMinSum=0;
            
        }
        //Edge Case
        if(totalSum==minSum) return maxSum;
        return max(maxSum, totalSum-minSum);
        
    }
};