#include<bits/stdc++.h>
using namespace std;

int ar[100]={0};

int parent(int i)
{ int c;
    if(ar[i]==i)
        return i;
    else
    return parent(ar[i]);

}

main()
{
    int n ,j , k,a,b,c,i,ct=0;
    vector < pair <int, pair<int,int> > > vp;

    cout<<"\n KRUSKAL MST ALGORITHM";
    a:
    cout<<"\n Enter the number of vertices";
    cin>>n;
    int visited[n]={0};
    cout<<"\n Enter the number of edges";
    cin>>k;

    for(i=1;i<=n;i++)
    {
        ar[i]=i;
    }

    if(k>((n)*(n-1)/2))
    {
        cout<<"\n Invalid graph";
        goto a;
    }
    for(i=0;i<k;i++)
    {

    cout<<"\n Enter weight and edge ";
    cin>>a>>b>>c;
    vp.push_back(make_pair(a,make_pair(b,c)));
    }
    sort(vp.begin(),vp.end());

    cout<<"\n\n MST \n\n";

    for(i=0;i<k;i++)
    {
      if(parent(vp[i].second.first)!=parent(vp[i].second.second) && !(visited[vp[i].second.second]==1 && visited[vp[i].second.first]==1))
      {
          cout<<vp[i].second.first<<"----"<<vp[i].second.second<<endl;
          if(visited[vp[i].second.second]==0)
            ar[vp[i].second.second]=ar[vp[i].second.first];
          else
            ar[vp[i].second.first]=ar[vp[i].second.second];

          visited[vp[i].second.first]=1;
          visited[vp[i].second.second]=1;
          ct++;
      }


      if(ct==n-1)
      {
          break;
      }

    }


    return 0;
}
