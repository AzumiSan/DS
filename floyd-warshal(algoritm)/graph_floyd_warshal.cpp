#include <iostream>
#include <stdio.h>
using namespace std;

class graph
{
   int adj[10][10],dis[10][10],n,i,j,k;
   public:
        void getData();
        void floyd();
        void print();
};
void graph::getData()
{
  printf("\n garaas heden opoigoo opuulna uu ? =>  ");
  scanf("%d",&n);
  printf("\n garaas matrix iin utgaa opuul(garaas opuulsan utga bupuu bol 999 )=> \n\n");
  for(i = 1;i <= n;i++)
  {
       for(j = 1;j <= n;j++)
       {
             scanf("%d",&adj[i][j]);
       }
  }
}
void graph::floyd()
{
   for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        {
             dis[i][j]=adj[i][j];
        }
   }
   for(k=1;k<=n;k++)
   {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                      dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
   }
}
void graph::print()
{

  printf("\n\nsuuliin up dun=> \n\n");
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=n;j++)
      {
          printf("%d\t\t",dis[i][j]);
      }
      printf("\n");
  }
}
int main()
{
  graph g;
  g.getData();
  g.floyd();
  g.print();
  return 0;
}
