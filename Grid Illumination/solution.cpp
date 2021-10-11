class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int i, j, k, s, s2;
    
    s = lamps.size();
    s2 = queries.size();
    map<int, int> mx;
    map<int, int> my;
    map<int, int> ms;
    map<int, int> mp;
    map<pair<int, int>, int> lamp;
    
    for(i=0; i<s; i++)
    {
        int x, y;
        x = lamps[i][0];
        y = lamps[i][1];
        
        j = x;
        k = y;
        
        if(lamp[make_pair(x,y)]!=1)
        {
            mx[x]++;
            my[y]++;
            ms[x-y]++;
            mp[y+x]++;
            lamp[make_pair(x,y)] = 1;
        }
    }
    
    vector<int> ans;
    
    for(i=0; i<s2; i++)
    {
        int x,y;
        x = queries[i][0];
        y = queries[i][1];
        
        if(ms[x-y]>0 || mx[x]>0 || my[y]>0 || mp[x+y]>0)
        {
            ans.push_back(1);
            for(j=x-1; j<=x+1; j++)
            {
                for(k=y-1; k<=y+1; k++)
                {
                    if(j>=0 && j<N && k>=0 && k<N)
                    {
                        if(lamp[make_pair(j,k)]==1)
                        {
                            ms[j-k]--;
                            mp[j+k]--;
                            mx[j]--;
                            my[k]--;
                            lamp[make_pair(j,k)] = 0;
                        }
                    }
                }
            }
        }
        else
        {
            ans.push_back(0);
        }
        
       
    }

    return ans;
        
    }
};
