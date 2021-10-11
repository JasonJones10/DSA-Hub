class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> ms;
        
        int i, j, s;
        s = nums.size();
        
        for(i=0; i<s; i++)
        {
            ms[nums[i]]++;
        }
        
        vector<pair<int,int>> temp;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto x = ms.begin(); x!=ms.end(); x++)
        {
            if(pq.size()<k)
            {
                pq.push(make_pair(x->second, x->first));
            }
            else
            {
                pair<int, int> pp = pq.top();
                
                if(pp.first<x->second)
                {
                    pq.pop();
                    pq.push(make_pair(x->second, x->first));
                }
            }
        }
        
       // sort(temp.begin(), temp.end());
        
        vector<int> ans;
        
        while(pq.size()>0)
        {
            pair<int, int> pp = pq.top();
            pq.pop();
            ans.push_back(pp.second);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
