#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int a[100][100],c[100][100];
void copy (int m,int n)
{int i,j;
for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
    	a[i][j]=c[i][j];
}

int Neigh_Sum(int x, int y)
{
	return a[x][y-1]+a[x+1][y-1]+a[x+1][y]+a[x+1][y+1]+a[x][y+1]+a[x-1][y+1]+a[x-1][y]+a[x-1][y-1];
}

void Evolution(int m,int n)
{
	int i,j,neighbour;

	for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
		{
			neighbour=Neigh_Sum(i,j);
			if(a[i][j]&&neighbour<2) c[i][j]=0;
			else
				if(a[i][j]&&neighbour<=3) c[i][j]=1;
				else
					if(a[i][j]) c[i][j]=0;
					else
						if(!a[i][j]&&(neighbour==3)) c[i][j]=1;
		}
	copy(m,n);
}

void print(int m, int n)
{
	int i,j;
   for(i=1;i<=m;i++)
   {
   		for(j=1;j<=n;j++)
   		if(a[i][j]==0)printf("  "); else printf(" *");
		 printf("\n");

	}
}

void play_Game(int m, int n, unsigned milis)
{
	//int i,j;
	while(1)
	{
		print(m,n);


		Evolution(m,n);
		Sleep(milis);
		system("cls");
	}

}

int main(){
int i,j,m,n;
freopen("intrare.txt","r",stdin);
scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
	   		scanf("%d",&a[i][j]);

play_Game(m,n,500);


return 0;
}
