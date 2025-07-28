class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int>rowSum(n,0);
        vector<int>colSum(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowSum[i]+=mat[i][j];
                colSum[j]+=mat[i][j];
            }
        }
        int maxSum=0;
        for(int i=0;i<n;i++){
            maxSum=max(maxSum,rowSum[i]);
            maxSum=max(maxSum,colSum[i]);
        }
        int totalOps=0;
        int i=0,j=0;
        while(i<n&&j<n){
            int diff=min(maxSum-rowSum[i],maxSum-colSum[j]);
            mat[i][j]+=diff;
            rowSum[i]+=diff;
            colSum[j]+=diff;
            totalOps+=diff;
            if(rowSum[i]==maxSum)
                i++;
            if(colSum[j]==maxSum)
                j++;
        }
        return totalOps;
    }
};
