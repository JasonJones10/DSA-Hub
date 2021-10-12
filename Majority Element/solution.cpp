class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int i, j, s;
        s = nums.size();
        
        map<int, int> ms;
        
        int ans = nums[0];
        
        ms[nums[0]]++;
        
        for(i=1; i<s; i++)
        {
            ms[nums[i]]++;
            
            if(ms[ans]<ms[nums[i]])
            {
                ans = nums[i];
            }
        }
        
        return ans;
        
    }
};
