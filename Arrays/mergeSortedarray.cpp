class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        int len1=m+n;
        int endIdx=len1-1;
        //we will place the greater elemnt at the end of nums1
        while(n>0 && m>0){
            if(nums2[n-1]>=nums1[m-1]){
                nums1[endIdx]=nums2[n-1];
                n--;
            }
            else{
                nums1[endIdx]=nums1[m-1];
                m--;
            }
            endIdx--;
        }

        while(n>0){
        //in this case only array 2 elemnts is left so just copy the values in nums1
            nums1[endIdx]=nums2[n-1];
            n--;
            endIdx--;
        }
        
            }
};