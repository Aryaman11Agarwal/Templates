class DSU{
    vector<int> size,parent;
    public:
    DSU(int n){
          size=vector<int>(n+1,1);
          parent=vector<int>(n+1,0);

          for(int i=0;i<=n;i++)
          parent[i]=i;
    }

    int Find(int node){
        if(node==parent[node])
        return node;

        else return parent[node]=Find(parent[node]);
    }

    void Union(int a,int b){
        a=Find(a);
        b=Find(b);

        if(a==b)
        return ;

        if(size[b]>size[a])
        swap(a,b);

        parent[b]=a;
        size[a]+=size[b];
    }

    bool inSameComp(int a,int b){
         a=Find(a);
        b=Find(b);

        if(a==b)
        return true;
        return false;
    }
};
