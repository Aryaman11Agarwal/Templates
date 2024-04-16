class SegTree{
    vector<int> sgtree;
    public:
    SegTree(int n){
        sgtree.resize(4*n,1e9);
    }

    int query(int index,int low,int high,int l,int h){
     if(low>h||l>high)
     return 1e9;
     
    else if(l<=low&&high<=h)
     return sgtree[index];
     
     
     else{
         int mid=(low+high)/2;
         
         return min(query(2*index+1,low,mid,l,h),query(2*index+2,mid+1,high,l,h));
     }
 }
 
 void update(int index,int low,int high,int i,int val){
     if(low==high){
         sgtree[index]=val;
         return ;
     }
     
     int mid=(low+high)/2;
     
     if(i<=mid)
     update(2*index+1,low,mid,i,val);
     
     else
     update(2*index+2,mid+1,high,i,val);
     
     sgtree[index]=min(sgtree[2*index+1],sgtree[2*index+2]);
 }
};

class Solution {
public:

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
       vector<SegTree> rows(m,SegTree(n)),cols(n,SegTree(m));

       vector<vector<int>> dp(m,vector<int>(n,1e9));

       dp[m-1][n-1]=1;
       rows[m-1].update(0,0,n-1,n-1,1);
       cols[n-1].update(0,0,m-1,m-1,1);

      for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]==0)
            continue;
            int rowmin=min(m-1,grid[i][j]+i);
            int colmin=min(n-1,grid[i][j]+j);

            if(j+1<n)
            dp[i][j]=min(dp[i][j],1+rows[i].query(0,0,n-1,j+1,colmin));
            if(i+1<m)
            dp[i][j]=min(dp[i][j],1+cols[j].query(0,0,m-1,i+1,rowmin));

            rows[i].update(0,0,n-1,j,dp[i][j]);
            cols[j].update(0,0,m-1,i,dp[i][j]);
        }
      }


      if(dp[0][0]!=1e9)
      return dp[0][0];
      return -1;


    }
};
