```
class Solution:
    def longestPalindrome(self, s):
        arr=[[0 for x in range(len(s))] for x in range(len(s))] 
        ans=''
        if(len(s)==0):
            return ""
        for x in range(len(s)):
            for y in range(len(s)-x):
                if(x==0):
                    arr[y][y+x]=1
                elif(x==1):
                    if(s[y]==s[y+x]):
                        arr[y][y+x]=1
                    else:
                        arr[y][y+x]=0
                else:
                    if(s[y]==s[y+x] and not arr[y+1][y+x-1]==0):
                        arr[y][y+x]=1
                    else:
                        arr[y][y+x]=0
                
                if(len(s[y:y+x+1])>len(ans) and not arr[y][y+x]==0):
                    ans=s[y:y+x+1]
        return ans            
     
```
