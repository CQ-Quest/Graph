#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6+10;
int t,n,q,a,b;
int s[maxn],num[maxn],weight[maxn];
void init(){
    for(int i=1;i<=n;i++){
        s[i]=i;       
        num[i]=1;      //龙珠数量 
        weight[i]=0;   //移动次数 
    }
}
int find(int x){
    if(x==s[x]) return x;
    int temp=s[x];
    s[x]=find(s[x]);
    weight[x]+=weight[temp];
    return s[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) {
        s[x]=y;
        num[y]+=num[x];
        weight[x]=1;
    }
}
int main(){
    scanf("%d",&t);
    int cnt=1;
    char c;
    while(t--){
        scanf("%d %d",&n,&q);
        getchar();
        init();
        printf("Case %d:\n",cnt++);
        for(int i=0;i<q;i++)
        {
            scanf("%c",&c);
            if(c=='Q'){
                scanf("%d",&a);
                getchar();
                int x=find(a);
              printf("%d %d %d\n",x,num[x],weight[a]);
            }
            else {
                scanf("%d %d",&a,&b);          //a,b分别代表A城市，B城市 
                getchar();
                merge(a,b);
            }
        }
    }
      return 0;
}

