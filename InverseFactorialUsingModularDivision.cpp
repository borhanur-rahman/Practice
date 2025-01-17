#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>fact;
vector<ll>inverseFact;
void preCalc(ll n, ll MOD){
    ll a,b,r,q,i,t1=0,t2=1,t;
    for(i=1,fact.push_back(1);i<=n;i++){
        fact.push_back((i*fact[i-1])%MOD);
    }
    a=MOD,b=fact[n];
    while(b>0){
        q=a/b;  r=a%b;
        a=b;    b=r;
        t=t1-t2*q;
        t1=t2;  t2=t;
    }
    inverseFact.push_back((t1+MOD)%MOD);
    for(i=n;i>0;i--){
        inverseFact.push_back((inverseFact.back()*i)%MOD);
    }
    reverse(inverseFact.begin(),inverseFact.end());
}

int main() {
    ll n,r,MOD=1000000007;
	preCalc(200000,MOD);
	cin>>n>>r;
	cout<<"nCr = "<<(fact[n] * ((inverseFact[r]*inverseFact[n-r])%MOD))%MOD;
    return 0;
}
