#include<iostream>
using namespace std;


#define v 4
#define INF 99999
void printsolution(int dist[][v])
{
	for(int i=0;i<v;i++)
	{
		cout<<endl;
		for(int j=0;j<v;j++)
		{
			if(dist[i][j]==INF)
			{
				cout<<"INF";	
			}
			else
			{
				cout<<dist[i][j]<<" ";
			}
		}
	}
}
void floydwarshall(int dist[][v])
{
	int i,j,k;
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][j]>(dist[i][k]+dist[k][j]))
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printsolution(dist);
}

int main()
{
	int graph[v][v]={{0,5,INF,4},{INF,0,2,INF},{3,INF,0,INF},{INF,INF,3,0}};
	floydwarshall(graph);
}
