#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,d,e,f,i,j,k,l,m,n,t,x,y,p,q,r,mn,mx,cnt;
void srt(int a[], int l, int r){
    if(l==r)return;
    int m=(l+r)/2;
    srt(a,l,m);srt(a,m+1,r);
  /*cout<<l<<" "<<r<<": ";
  for(i=l;i<=r;i++){cout<<a[i]<<" ";}
  cout<<"\n";*/
    vector<int>v;
    for(i=l,j=m+1;;){
        if(j>r || (a[i]<=a[j] && i<=m))
            {v.push_back(a[i++]);}
        else if(i>m || (a[i]>a[j] && j<=r) )
            {v.push_back(a[j++]);}
        //cout<<"("<<i<<j<<")";
        if(v.size()==r-l+1) break;

    }
    for(i=l;i<=r;i++) a[i]=v[i-l];
  /*for(i=l;i<=r;i++)cout<<a[i]<<" ";
  cout<<"\n";*/
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int a[10]={5,1,0,3,8,6,9,5,2,8};
    srt(a,2,8); 
    for(i=0;i<=9;i++) cout<<a[i]<<" ";  
    return 0;
}
