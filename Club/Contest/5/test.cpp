#include<bits/stdc++.h>
using namespace std;
 #define clr(a,v) memset(a,v,sizeof(a))
 #define PI acos(-1.0)
 #define PII pair<int,int>
 #define fi first
 #define se second
 #define pb push_back
 typedef long long ll;
 const int INF=0x3f3f3f3f;
 const int maxn=5010;
 int n,m,x,y;
 int Min[maxn],out[maxn];
 int dis(int i,int j){return j>=i? j-i:j-i+n;}
 int main()
 {
     scanf("%d%d",&n,&m);
     clr(out,0);clr(Min,INF);
     for(int i=1;i<=m;++i)
     {
         scanf("%d%d",&x,&y);
        if(y>=x) Min[x]=min(Min[x],y-x);
         else if(y<x) Min[x]=min(Min[x],y-x+n);
         out[x]++;
     }
     
    for(int i=1;i<=n;++i)
     {
         int ans=0;
         for(int j=1;j<=n;++j)
         {
             if(out[j]) ans=max(ans,dis(i,j)+Min[j]+(out[j]-1)*n);
         }
         printf("%d%c",ans,i==n?'\n':' ');
     }
     return 0;
 }