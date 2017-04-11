#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void adjacency(int ar [100][100], int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ar[i][j]<<"   ";
        }
        cout<<endl;
    }

}

int through[100]={0};
void djikstra(int ar[100][100], int n)
{
  int visited[100]={0},distance[100]={99999} , mi =99999 , prev =1;

  through[0]=0;
  int i , j,temp;

  for(i=0;i<n;i++)
  {
      distance[i]=ar[0][i];
  }

  visited[0]=1;



  for(i=0;i<n;i++)
  {
      mi=99999;


  for(j=0;j<n;j++)
  {
      if(distance[j]<mi && visited[j]!=1)
      {
          mi=distance[j];
          temp=j;
      }


  }

    visited[temp]=1;
    for(j=0;j<n;j++)
    {

        if(( distance[temp]+ar[temp][j])< distance [j] )
        {
            through[j]=temp;
        }

        distance[j]=min(distance[j] , distance [temp] + ar[temp][j]);


    }


  }

   cout<<"\n\nTHE MINIMUM DISTANCE ARRAY IS\n\n";
  for(i=0;i<n;i++)
  {

    cout<<distance[i]<<" ";

}

}

main()
{
    int n,m,i,j,k;
    cout<<"\n Djikstra's Shortest Path Algorithm \n";
    cout<<"\n Enter the number of vertices";
    cin>>n;
    int ar[100][100]={0};

    for(i=0;i<n;i++)

    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                ar[i][j]=0;
                continue;
            }
            cout<<"Enter distance of node "<<i+1<<" from the node "<<j+1;
            cout<<"\n If there is no path , enter 9999\n";
            cin>>k;
            ar[i][j]=k;
            cout<<endl<<endl;
        }
    }


   do{ cout<<"\n Press 1 to display adjacency matrix";
    cout<<"\n Press 2 to implement Djikstra's algorithm";
    cout<<"\n Press 3 to find shortest path";
    cout<<"\n Press 4 to exit";
    cin>>m;


    if(m==1)
        adjacency(ar,n);

    else if(m==2)
    {
        djikstra(ar,n);
    }

    else if(m==3)
    { through[0]=-1;
    for(i=0;i<n;i++)
        cout<<through[i]<<" ";

        int d; vector <int> v;
        cout<<"Enter destination vertex";
        cin>>d;
        v.push_back(d);
        while(through[d]!=-1)
        { //cout<<through[d]<<" ";
            v.push_back(through[d]);
                 d=through[d];

        }

        for(i=v.size()-1;i>=0;i--)
            cout<<v[i]<<" ";



    }


   }while(m!=3);

}
