class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int Find(int node){
        return parent[node] = (parent[node] == node) ? node : Find(parent[node]);
    }

    void Reset(int node){
        parent[node] = node;
    }

    void Union(int nodea, int nodeb){
        int apar = Find(nodea), bpar = Find(nodeb);
        if(apar != bpar){
            rank[apar] < rank[bpar] ? parent[apar] = bpar : parent[bpar] = apar;
            rank[apar] += rank[apar] == rank[bpar] ? 1 : 0;
        }
    }
};
