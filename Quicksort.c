#include<stdio.h>
//#include <algorithm>
int A[100],n;
int Partition(int[],int ,int);
void Quicksort(int[],int,int);
main()
{   printf("\nEnter size of array");
  scanf("%d",&n);
  int i;
  printf("\n\nEnter array elements");
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
   printf("\n\n Array before sorting  ");
   for(i=0;i<n;i++)
        printf("%d ",A[i]);

  Quicksort(A,0,n-1);

    printf("\n\n Array after sorting  ");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
  return 0;
}

void Quicksort(int A[],int start , int end)
{  if(start<end)
    { int pindex=Partitiion(A,start,end);
      Quicksort(A,start,pindex-1);
      Quicksort(A,pindex+1,end);
    }
}

int Partitiion(int A[],int start,int end)
{ int pivot , pindex,j,temp;
  pivot=A[end];
  pindex=start;

  for(j=start;j<=end-1;j++)
  {  if(A[j]<=pivot)
     { temp=A[j];
     A[j]=A[pindex];
     A[pindex]=temp;
         pindex++;
     }
  }
  temp=A[pindex];
  A[pindex]=A[end];
  A[end]=temp;
  return pindex;
}


