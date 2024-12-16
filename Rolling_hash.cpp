        int p=53;
        int mod=1e9+9;
        
        int n=txt.size();
        
        vector<ll> pwr(n+1,1);
        
        vector<ll> hash(n+1);
        
        for(int i=1;i<=n;i++){
            pwr[i]=(pwr[i-1]*p)%mod;
        }
        
        for(int i=1;i<=n;i++){
            hash[i]=((hash[i-1]*p)%mod + (txt[i-1]-'a'))%mod;
        }
        
        
        
        auto getHash=[&](int l,int r){
            return (hash[r+1]-(hash[l]*pwr[r-l+1])%mod + mod)%mod;
        };
        
