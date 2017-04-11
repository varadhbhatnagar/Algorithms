#include<stdio.h>
int ar[40],mid;
void MergeSort(int[],int);
void Merge(int[],int,int[],int,int[]);



void main()
{ int i,n;
  printf("\n Enter the size of array");
  scanf("%d",&n);
  printf("\n Enter array elements");
  for(i=0;i<n;i++)
  { scanf("%d",&ar[i]);

  }

  printf("\nUnsorted arrray");
  for(i=0;i<n;i++)
  { printf(" %d  ",ar[i]);
  }

  MergeSort(ar,n);

  printf("\n Sorted array");
  for(i=0;i<n;i++)
  { printf(" %d  ",ar[i]);
  }

}
void Merge(int left[],int l,int right[],int r,int ara[])
{ int i=0,j=0,k=0;

  while(i<l && j<r)
    if(left[i]<=right[j])
    {
        ara[k]=left[i];
        k++; i++;
    }
    else
    {
        ara[k]=right[j];
        k++;j++;

    }
   while(i<l)
   {

       ara[k]=left[i];
       k++;i++;
   }
   while(j<r)
   {

       ara[k]=right[j];
       k++;j++;

   }
   printf("\n After merging till now : ");
   for(i=0;i<k;i++)
    printf("%d",ara[i]);
   printf("\n");
}

void MergeSort(int ar[],int n)
{ int i,sizel=0,sizer=0;int left[20],right[20];


  if(n<2)
  {
      return;
  }

   mid=n/2;
   printf("\n Left : ");
    for(i=0;i<mid;i++)
    { left[i]=ar[i];
      printf("%d ",left[i]);
       sizel++;
    }
    printf("\n Right : ");
    for(i=mid;i<n;i++)
    {
        right[i-mid]=ar[i];
        printf("%d ",right[i-mid]);
        sizer++;
    }
   printf("\n");
   printf("Further breaking the left array\n");
    MergeSort(left,sizel);
     printf("\nFurther breaking the right array\n");
     MergeSort(right,sizer);

    Merge(left,sizel,right,sizer,ar);


}
