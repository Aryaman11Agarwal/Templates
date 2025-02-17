//Problem Link: https://atcoder.jp/contests/abc393/tasks/abc393_f
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;  // Size of the array

    // Merge function: Returns the max of two segments
    int merge(int left, int right) {
        return max(left, right);
    }

    // Build segment tree (not needed since all values are 0 initially)
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;  // All elements are initially 0
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Query max in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INT_MIN;  // No overlap
        if (l <= start && end <= r) return tree[node];  // Total overlap

        // Partial overlap
        int mid = (start + end) / 2;
        int left_result = query(2 * node + 1, start, mid, l, r);
        int right_result = query(2 * node + 2, mid + 1, end, l, r);
        
        return merge(left_result, right_result);
    }

    // Point update: Set arr[idx] = value
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node + 1, start, mid, idx, value);
            else
                update(2 * node + 2, mid + 1, end, idx, value);

            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(int size) {
        n = size;
        if (n > 0) {
            tree.assign(4 * n, 0);
           // build(0, 0, n - 1);
        }
    }

    // Get max in range [l, r]
    int range_query(int l, int r) {
        if (n == 0) return 0;  // If tree is empty, return 0
        return query(0, 0, n - 1, l, r);
    }

    // Update a[idx] = value
    void point_update(int idx, int value) {
        if (n == 0) return;  // No elements to update
        update(0, 0, n - 1, idx, value);
    }
};





void fun(){
    
    int n,q;
    cin>>n>>q;
    
    vector<int> v(n);
    vector<int> compressor;
    
    for(auto &i:v) cin>>i, compressor.push_back(i);
    
    vector<pair<pair<int,int>,int>>  vq;
    
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        u--;
        compressor.push_back(v);
        vq.push_back({{u,v},i});
    }
    
   
    sort(compressor.begin(),compressor.end());
    
    compressor.erase(unique(compressor.begin(),compressor.end()),compressor.end());
    
    
    map<int,int> hash;
    
    for(int i=0;i<compressor.size();i++){
        //cout<<compressor[i]<<" ";
        hash[compressor[i]]=i+1;
    }
  //  cout<<"\n";
    
    for(auto &i:v){
        i=hash[i];
    }
    
    // for(auto i:v)
    // cout<<i<<" ";
    // cout<<endl;
    
    for(auto &i:vq){
        
        i.ff.ss=hash[i.ff.ss];
        
        
    }
    // cout<<compressor[5]<<""<<compressor[2]<<endl;
    //  for(auto i:vq){
    //     cout<<i.ff.ff<<" "<<i.ff.ss<<" "<<i.ss<<" "<<endl;
    // }
    
    
   SegmentTree sg(hash.size()+10);
   vector<int> lis(n,INT_MAX);
   int j=0;
   
   sort(vq.begin(),vq.end());
   
//   for(auto [i,j]:vq){
//       cout<<i.ff<<" "<<i.ss<<endl;
//   }
   vector<int> ans(q,0);
   
   for(int i=0;i<n;i++){
       
       int x=v[i];
       //cout<<x<<" ";
       
       int index= lower_bound(lis.begin(),lis.end(),x)-lis.begin();
      // cout<<index<<" ";
       
       lis[index]=x;
       
       int prev=sg.range_query(x,x);
      // cout<<prev<<" ";
       int nvalue=max(index+1,prev);
      // cout<<nvalue<<endl;
       sg.point_update(x,nvalue);
      // cout<<vq[j].ff.ff<<" "<<i<<endl;
       
       while(j<q && vq[j].ff.ff==i){
           
           ans[vq[j].ss]=sg.range_query(1,vq[j].ff.ss);
           j++;
           
       }
        
   }
   
   for(auto i:ans) cout<<i<<endl;
   
    
    
    
}
int32_t main()
{
    
    int t=1;
    while(t--) fun();
}
