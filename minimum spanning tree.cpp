#include<conio.h>
#include<stdio.h>
#define max 10
int adj[max][max],tree[max][max],n;

void readmatrix()
{
	int i,j;
	printf("\n enter the no. of nodes in the graph");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix of the graph:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
}

int spanningtree(int src)
{
	int visited[max],d[max],parent[max];
	int i,j,k,min,u,v,cost;
	for(i=1;i<=n;i++)
	{
		d[i]=adj[src][i];
		visited[i]=0;
		parent[i]=src;
	}
	visited[src]=1;
	cost=0;
	k=1;
	for(i=1;i<n;i++)
	{
		min=9999;
		for(j=1;j<=n;j++)
		{
			if(visited[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
				cost +=d[u];
			}
		}
		visited[u]=1;
		tree[k][1]=parent[u];
		tree[k++][2]=u;
		for(v=1;v<=n;v++)
		{
			if(visited[v]==0 && (adj[u][v]<d[v]))
			{
				d[v]=adj[u][v];
				parent[v]=u;
			}
		}
	}
	return cost;
}

void display(int cost)
{
	int i;
	printf("\n the edges of minimum spanning tree are");
	for(i=1;i<n;i++)
	{
		printf("%d %d \n",tree[i][1],tree[i][2]);
	}
	printf("\n the total cost of minimum spanning tree is : %d",cost);
}

int main()
{
	int source,treecost;
	readmatrix();
	printf("\n enter the source :");
	scanf("%d ,&source");
	treecost=spanningtree(source);
	display(treecost);
	return 0;
}
