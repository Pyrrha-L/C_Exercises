#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+10;
const int maxm=1e5+10;
const int maxt=2139062143;
inline int min_(int x,int y){return x<y?x:y;}

int n,m,s,t,nflow,nfee,flow,fee;
int a,b,c,d;
int h[maxn],hs=1;
int e_q[maxm],e_z[maxm],e_n[maxm],e_w[maxm],e_f[maxm];
int add(int q,int z,int k,int w,int f){
	e_q[k]=q,e_z[k]=z,e_n[k]=h[q],e_w[k]=w,e_f[k]=f,h[q]=k;
}
int q[maxm],head,tail;
int w[maxn],p[maxn];
bool v[maxn];

int ap(int k,int v){
    if(k==s) return v;
    int ret=ap(e_q[p[k]],min_(v,e_w[p[k]]));
    if(!e_f[p[k]^1]) add(k,e_q[p[k]],p[k]^1,0,-e_f[p[k]]);
    e_w[p[k]]-=ret,e_w[p[k]^1]+=ret;
    return ret;
}

void Mcmf(){
    while(1){
        memset(w,0x7f,sizeof(w));
        memset(v,0,sizeof(v));
        head=tail=w[s]=0;
        q[head++]=s,v[s]=1;
        while(head>tail){
            a=q[tail++],v[a]=0;
            for(int i=h[a];i;i=e_n[i])
            if(0ll+e_f[i]+w[a]<w[e_z[i]]&&e_w[i]){
                p[e_z[i]]=i;
                w[e_z[i]]=e_f[i]+w[a];
                if(!v[e_z[i]]) q[head++]=e_z[i],v[e_z[i]]=1;
            }
        }
        if(w[t]==maxt) break;
        nflow=ap(t,maxt);
        flow+=nflow;
        fee+=nflow*w[t];
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ++hs,add(a,b,hs,c,d),hs++;
    }
    Mcmf();
    printf("%d %d\n",flow,fee);
    return 0;
}
