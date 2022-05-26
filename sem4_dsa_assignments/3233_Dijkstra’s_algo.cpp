#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n,m,a,b,c,src;
    cin>>n>>m>>src;
    int adj[n+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            adj[i][j]=-1;
        }
    }
    while(m--){
        cin>>a>>b>>c;
        adj[a][b]=c;
        adj[b][a]=c;

    }
    priority_queue<pair<int, int>,vector<pair<int,int> >, greater<pair<int, int> > > pq;
    vector<int> weight(n+1,INT_MAX),vis(n+1,0);
    weight[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int we=pq.top().first;
        int prev=pq.top().second;
        if(!vis[prev]){
            vis[prev]=1;
        }
        pq.pop();
        for(int i=0;i<n;i++){
            if(adj[prev][i]!=-1){
                int ver=i;
                int next_we=adj[prev][i];
                if(weight[ver]>weight[prev]+next_we){
                    weight[ver]=weight[prev]+next_we;
                    pq.push(make_pair(weight[ver],ver));
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<weight[i]<<" ";

    }
    cout<<endl;

}