class Solution {
public:
    #define ll int
    ll par[10005];
    void make()
    {
        ll i;
        for(i=0;i<=10000;i++)
            par[i]=i;
    }
    ll find(ll x)
{
   if(par[x]==x)return x;
  return par[x]=find(par[x]);
}
    ll unite(ll x,ll y)
    {
        ll p1=find(x);
        ll p2=find(y);
        if(p1!=p2)
        {
            par[p1]=p2;
        }
        return 0;
    }
    int removeStones(vector<vector<int>>& stones) {
        make();
        set<ll>s;
        ll i,j,n=stones.size();
        for(i=0;i<n;i++)
        {
            
           for(j=i+1;j<n;j++)
           {
               
               if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
               {
                   unite(i,j);
               }
           }
        }
        ll cnt=0;
        for(i=0;i<n;i++)
        {
            if(par[i]==i)cnt++;
        }
        return stones.size()-cnt;
    }
};