class Solution {
public:
    vector<int> longestPrefix(string s) {
     int m=s.size();

     int i=1;
     vector<int> lps(m,0);
     int len=0;

     lps[0]=0;
     while(i<m){
         if(s[i]==s[len]){
             len++;
             lps[i]=len;
             i++;
         }
         else{
             if(len>0){
                 len=lps[len-1];
             }
             else{
                 lps[i]=0;
                 i++;
             }
         }
     }

     return lps;
    }
};
