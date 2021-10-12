class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector< int >::const_iterator i = nums.begin();
        int k=0;
        int h = nums.size();
        int j=0;
        for(; i!=nums.end();)
        {
            if(nums[k]==0)
            {
                nums.erase(i);
                j++;
            }
            else
            {
                k++;
                i++;
            }
        }
        
         while(j>0)
        {
            nums.push_back(0);
            j--;
        }
      
        
    }
};
