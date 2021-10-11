class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int i, j, n;
        
        int arr[26][501] = {0};
        
        vector<int> ans;
        n = s.size();
        
        for(i=0; i<n; i++)
        {
            int x = s[i] - 'a';
            j = arr[x][0] + 1;
            
            arr[x][j] = i;
            
            arr[x][0] = j;
        }
        
        int m = -1;
        int count = 0;
        
        for(i=0; i<n; i++)
        {
            int x = s[i] - 'a';
            int k = arr[x][0];
            j = arr[x][k];
            
            m = max(m, j);
            count++;
            
            if(i==m)
            {
                ans.push_back(count);
                count = 0;
                m = -1;
            }
            
        }
        
        return ans;
        
    }
};
