#define ll long long
class SegmentTree{
    vector<ll> tree,lazy;
    public:
    SegmentTree(int n){
        tree.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }

    void build(int index,int low,int high,vector<int>&arr){
        if(low==high)
        {
            tree[index]=arr[low];
            return ;
        }


        int mid=(low+high)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);

        tree[index]=tree[2*index+1]+tree[2*index+2];
    }

    void update(int index,int low,int high,int l,int h){
        if(lazy[index]!=0){
            tree[index]=(high-low+1)-tree[index];
            if(high!=low){
               lazy[2*index+1]=!lazy[2*index+1];
               lazy[2*index+2]=!lazy[2*index+2];
            }

            lazy[index]=0;
            
        }

        if(l>high||low>h)
        return ;

        else if(l<=low&&high<=h){
            tree[index]=(high-low+1)-tree[index];
             if(high!=low){
               lazy[2*index+1]=!lazy[2*index+1];
               lazy[2*index+2]=!lazy[2*index+2];
            }

            return ;
        }

        
       int  mid=(low+high)/2;

         update(2*index+1,low,mid,l,h);
          update(2*index+2,mid+1,high,l,h);

          tree[index]=tree[2*index+1]+tree[2*index+2];


    }


    ll query(int index,int low,int high,int l,int h){
         if(lazy[index]!=0){
            tree[index]=(high-low+1)-tree[index];
            if(high!=low){
               lazy[2*index+1]=!lazy[2*index+1];
               lazy[2*index+2]=!lazy[2*index+2];
            }

            lazy[index]=0;
            
        }

        if(l>high||low>h)
        return 0;

        else if(l<=low&&high<=h)
        return tree[index];

        int mid=(low+high)/2;

       return query(2*index+1,low,mid,l,h)+query(2*index+2,mid+1,high,l,h);

    }
};
