#include<iostream>

using namespace std;

class graph
{
    public:
            int ar[20][20] , n ,e;
            void accept();
            void display();
            void prims();

};

void graph::accept()
{
    int src , dest , cost,i,j;

    cout<<"\n Enter Number of vertices and edges";
    cin>>n>>e;

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       ar[i][j]=0;
    }


    for(i=1;i<=e;i++)
    {
        cout<<"\n Enter src , destination and cost : ";
        cin>>src>>dest>>cost;
        ar[src][dest]=cost;
        ar[dest][src]=cost;
    }

}


void graph::display()
{
   int i , j;
    cout<<"\n The adjacency matrix representation of given graph is";

    for(i=1;i<=n;i++)
        {   cout<<endl;
            for(j=1;j<=n;j++)
                {
                    cout<<ar[i][j]<<"\t";

                }
        }

}

void graph::prims()
{
  int visited[n+1]={0},src,dest,min=9999,i,j,total=0;
e=0;
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {

    if(ar[i][j]==0)
    ar[i][j]=9999;
  }

  cout<<"\n Enter source vertex ";
  cin>>src;
  visited[src]=1;

  while(e<n-1)
  {
        min=9999;
        for(i=1;i<=n;i++)
            {
                if(visited[i]==1)
                for(j=1;j<=n;j++)
                    {
                        if(visited[j]!=1)
                            {

                                if(min>ar[i][j])

                                {min=ar[i][j];
                                 src=i;
                                 dest=j;
                                 }
                            }
                    }
            }

  total=total+min;
  visited[dest]=1;
  cout<<"\nEDGE :"<<src<<"------"<<dest;
  e++;
  }




  cout<<"\nMinimum cost : "<<total;
}


main()
{
    graph g;
    int k;

    cout<<"\n\t PRIMS ALGORITHM\n";

do{ cout<<"\n\t Press 1 to enter an adjacency matrix";
    cout<<"\n\t Press 2 to display the adjacency matrix";
    cout<<"\n\t Press 3 to find MST using PRIM's algorithm";
    cout<<"\n\t Press 4 to exit";
    cin>>k;
    switch(k)
        {
            case 1: g.accept();
                    break;
            case 2: g.display();
                    break;
            case 3: g.prims();
                    break;
        }
 }while(k!=4);

 return 0;
 }
