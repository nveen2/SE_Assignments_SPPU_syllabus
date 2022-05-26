#include<bits/stdc++.h>
using namespace std;
int vis[20001]={0};
vector<int>arr[20001];
void dfs(int n)
{
    vis[n]=1;
    cout<<n<<" ";
    for(int i=0;i<arr[n].size();i++)
    {
        if(vis[i]==0)
        {dfs(arr[n][i]);}
    }
}
int main()
{
  int n,m;
  cin>>n>>m;
  while(m--)
  {
      int a,b;
      cin>>a>>b;
      arr[a].push_back(b);
      arr[b].push_back(a);
  }
  dfs(1);
}