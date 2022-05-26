#include<bits/stdc++.h>
using namespace std;
int vis[20001]={0};
vector<int>arr[20001];
void bfs(int n)
{
    vis[n]=1;
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        int a=q.front();
        // vis[a]=1;
        q.pop();
        cout<<a<<" ";
        for(int i=0;i<arr[a].size();i++)
        {
            if(vis[arr[a][i]]==0)
            {q.push(arr[a][i]);
                vis[arr[a][i]]=1;
            }
        }

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
  bfs(1);
}