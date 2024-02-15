#include <bits/stdc++.h>
using namespace std;
//lazy propogation

class SegTree{
   vector<int> tree,lazy;
   public:
   SegTree(int n){
       tree.resize(4*n+1,0);
       lazy.resize(4*n+1,0);
   }
   
   void build(int index,int low,int high,vector<int>&arr){
       if(low==high){
           tree[index]=arr[low];
           return;
       }
       
       int mid=(low+high)/2;
       
       build(2*index+1,low,mid,arr);
       build(2*index+2,mid+1,high,arr);
       
       tree[index]=tree[2*index+1]+tree[2*index+2];
       
       
   }
   
   void update(int index,int low,int high,int l,int r,int val){
       if(lazy[index]!=0){
           tree[index]=(high-low+1)*lazy[index];
          if(low!=high){
              lazy[2*index+1]+=lazy[index];
              lazy[2*index+2]+=lazy[index];
          }
          
          lazy[index]=0;
          
       }
       
       
       if(low>r||l>high)
       return ;
       
       else if(l<=low&&high<=r){
           tree[index]+=(high-low+1)*val;
           if(low!=high){
               lazy[2*index+1]+=val;
               lazy[2*index+2]+=val;
           } 
           
        
       }
       else{
         int  mid=(low+high)/2;
           
           update(2*index+1,low,mid,l,r,val);
           update(2*index+2,mid+1,high,l,r,val);
           
           tree[index]=tree[2*index+1]+tree[2*index+2];
           
       }
   }
   
   int query(int index,int low,int high,int l,int h){
       
        if(lazy[index]!=0){
           tree[index]=(high-low+1)*lazy[index];
          if(low!=high){
              lazy[2*index+1]+=lazy[index];
              lazy[2*index+2]+=lazy[index];
          }
          
          lazy[index]=0;
          
       }
       
        if(low>h||l>high)
     return 0;
     
    else if(l<=low&&high<=h)
     return tree[index];
     
     
     else{
         int mid=(low+high)/2;
         
         return (query(2*index+1,low,mid,l,h)+query(2*index+2,mid+1,high,l,h));
     }
   }
};
