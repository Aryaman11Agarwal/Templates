#define ll int

const ll MAX=100001;

bool prime[MAX];
int spf[MAX];

void sieve(){

    for(int i=0;i<MAX;i++)
    spf[i]=i;

    fill(prime,prime+MAX,true);

    prime[0]=0;
    prime[1]=0;

    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                if(prime[j])
                spf[j]=i;
                prime[j]=0;
            }
        }
    }
}

vector<ll> getFactorisation(int num){
   
   vector<int> ans; 
    int x=num;

    while(x!=1){
        ans.push_back(spf[x]);
        if(spf[x]!=0)
        x/=spf[x];
    }



    return ans;
}
