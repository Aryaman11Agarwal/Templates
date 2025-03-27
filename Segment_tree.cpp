#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
const int MOD=1e9+7;

class SegmentTree{

private:
  int n;
  
  vector<int> tree;
  
  void build(int index,int lo,int hi,vector<int> &tree,vector<int> &arr){
      
      if(lo==hi){
          tree[index]=arr[lo];
          
          return;
      }
      
      int mid=(lo+hi)/2;
      build(2*index+1,lo,mid,tree,arr);
      build(2*index+2,mid+1,hi,tree,arr);
      
      tree[index]=tree[2*index+1]+tree[2*index+2];
  }
  
  int query(int index,int lo, int hi,int left,int right,vector<int> &tree){
      
      if(left<=lo && hi<=right){
          return tree[index];
      }
      
      if(lo>right || hi<left) return 0;
      
      int mid=(lo+hi)/2;
      
      return query(2*index+1,lo,mid,left,right,tree)+query(2*index+2,mid+1,hi,left,right,tree);
  }
  
  void update(int index,int lo,int hi,vector<int> &tree, int i,int val){
      
      if(lo==hi){
          tree[index]=val;
          return ;
          
      }
      
      int mid=(lo+hi)/2;
      
      if(i<=mid)
      update(2*index+1,lo,mid,tree,i,val);
      
      else update(2*index+2,mid+1,hi,tree,i,val);
      
      tree[index]=tree[2*index+1]+ tree[2*index+2];
  }
  
  public:
  
  SegmentTree(vector<int> &arr){
      this->n=arr.size();
      
      tree=vector<int>(4*n+1,0);
      build(0,0,n-1,tree,arr);
  }
  
  int rangeQuery(int l,int r){
      
      return query(0,0,n-1,l,r,tree);
  }
  
  void pointUpdate(int i,int val){
      update(0,0,n-1,tree,i,val);
  }
    
    
};

void fun(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    SegmentTree sg(v);

    while(q--){

        int type;
        cin>>type;

        if(type==1){
            int i,v;
            cin>>i>>v;
            i--;

            sg.pointUpdate(i,v);
        }
        else{
            int i,j;
            cin>>i>>j;

            i--;
            j--;

            cout<<sg.rangeQuery(i,j)<<endl;
        }
    }



    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     int t=1;
   //  cin>>t;

     while(t--) fun();
    
}
