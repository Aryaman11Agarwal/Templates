#define ll long long
class TrieNode{
    public:
    char ch;
    int len,cost;

    bool isTerminal;

    unordered_map<char,TrieNode*> children;

    TrieNode(char ch){
        this->ch=ch;
        this->len=0;
        this->cost=INT_MAX;
        isTerminal=false;
    }
};

class Trie{
    public:

    TrieNode * root;

    Trie(){
        root=new TrieNode('\0');


    }

    void insertUtil(string &s,int cost){
        TrieNode * crawler=root;

        int n=s.size();

        for(int i=0;i<n;i++){
            if(crawler->children.find(s[i])==crawler->children.end())
            {
                crawler->children[s[i]]=new TrieNode(s[i]);
            }

            crawler=crawler->children[s[i]];
        }

        crawler->isTerminal=true;
        crawler->cost=min(crawler->cost,cost);
    }


};

class Solution {
public:
Trie trie;
ll dp[50001];
    ll solve(int index,string &target,int n){

        if(index>=n)
        return 0;

        if(dp[index]!=-1)
        return dp[index];

        TrieNode * crawler=trie.root;
        ll ans=INT_MAX;
        for(int i=index;i<n;i++){

             if(crawler->children.find(target[i])!=crawler->children.end()){
                crawler=crawler->children[target[i]];
            }
            else break;
            
            if(crawler->isTerminal==true){
             //   cout<<crawler->cost<<endl;
                ans=min(ans,crawler->cost+solve(i+1,target,n));
            }

           
        }

        return dp[index]=ans;

    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n=words.size();
         for(auto i=0;i<n;i++){
             trie.insertUtil(words[i],costs[i]); 
         }
         memset(dp,-1,sizeof(dp));
         int ans=solve(0,target,target.size());

         if(ans==INT_MAX)  return -1;

         return ans;
        
    }
};
