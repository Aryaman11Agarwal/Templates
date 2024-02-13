class SegmentTree{
   
vector<int> sgtree;

  public:
 
  SegmentTree(int n){
     sgtree.resize(4*n+1);
     
     
 }
 
 
 void build(int index,int low,int high,vector<int> &arr){
     if(low==high){
         sgtree[index]=arr[low];
         return ;
     }
     
     int mid=(low+high)/2;
     
     build(2*index+1,low,mid,arr);
     build(2*index+2,mid+1,high,arr);
     
     sgtree[index]=min(sgtree[2*index+1],sgtree[2*index+2]);
     
     
 }
 
 int query(int index,int low,int high,int l,int h){
     if(low>h||l>high)
     return INT_MAX;
     
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
