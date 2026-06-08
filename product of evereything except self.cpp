class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int N=nums.size();
       vector<int>ans(N,1);
       int prefix=1;
       for(int i=0;i<N;i++){
            ans[i]=prefix;
           prefix*=nums[i];
          
       }
       int sufix=1;
       for(int i=N-1;i>=0;i--){
        ans[i]*=sufix;
        sufix*=nums[i];
       }
   return ans;
    }
};
