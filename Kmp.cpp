 public:
        vector <int> search(string txt, string pat)
        {
           int n=txt.size();
           int m=pat.size();
           
           vector<int> ans,lps(m,0);
           
           int i=1,j=0;
           
           lps[0]=0;
           int len=0;
           while(i<m){
                if(pat[i]==pat[len]){
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
           
           i=0;
           
           while(i<n){
              
               if(txt[i]==pat[j]){
                   i++;
                   j++;
               }
               
                if(j==m)
               {
                   ans.push_back(i-m);
                   j=lps[j-1];
               }
               else if(txt[i]!=pat[j]){
                   if(j>0){
                       j=lps[j-1];
                   }
                   else
                   i++;
               }
           }
           return ans;
          
        }
