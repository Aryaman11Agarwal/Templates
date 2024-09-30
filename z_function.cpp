#include <bits/stdc++.h>
using namespace std;
int main() {
  string s="ababadababae";

  int n=s.size();

  vector<int> z(n,0);

  int l=0,r=0;

  for(int i=1;i<n;i++){
      if(i<=r){
          z[i]=min(r-i+1,z[i-l]);
      }

      while(s[z[i]]==s[i+z[i]])
      z[i]++;

      if(i+z[i]-1>r){
          l=i;
          r=i+z[i]-1;
      }
  }

  for(auto i:z)
  cout<<i<<" ";

  cout<<endl;
}
