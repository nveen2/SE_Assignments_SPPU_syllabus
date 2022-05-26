#include<iostream>
#include<queue>
using namespace std;
void input(){
	int n,m;
	cin>>n>>m;
 
	int matrix[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=0;		
		}	
	}
	int directed_node[n];
	for(int i=0; i<n; i++){ directed_node[i] = 0; }
 
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		matrix[x][y]=1;
		directed_node[y]++;
 
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(directed_node[i]==0){
			q.push(i);
		}		
	}
	while(q.size()>0){
		int curr=q.front();
		q.pop();
 
		for(int i=0;i< n; i++){
			if(matrix[curr][i]==1){
				directed_node[i]--;
				if(directed_node[i]==0){
					q.push(i);
				}		
			}
		}	
		cout<<curr<<" ";
	}
	cout<<endl;
}	
int main(){
input();
return 0;
 
 
 
}