class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        set<char> myset;
        int i, count=0;
        int l = J.length();
        for(i=0; i<l; i++)
        {
            myset.insert(J[i]);
        }
        l=S.length();
        for(i=0; i<l; i++)
        {
            if(myset.count(S[i])!=0)
            {
                count++;
            }
        }
        return count;
    }
};
