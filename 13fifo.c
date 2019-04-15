#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int psearch(int num, int arr[],int capacity)
{
    int i;
    
    for(i=0;i<capacity;i++)
        if(num==arr[i])
            return 1;
            
    return 0;
}

int fifopg(int n,int a[], int capacity)
{
    int ptr=0,count=0,i;
    int frame[capacity];
    
    for(i=0;i<capacity;i++)
        frame[i]=-1;
  
    for(i=0;i<n;i++)
    {
            if(psearch(a[i],frame,capacity)==0)
            {
                frame[ptr]=a[i];
                ptr=(ptr+1)%capacity;
                count++;
            }        
    }
    return count;
}
    

int main()
{
    int capacity,n,a[MAX],i,pagefault;
    
    printf("Enter number of pages\n");
    scanf("%d",&n);
    
    printf("Enter the reference string\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    printf("Enter no. of page frames\n");
    scanf("%d",&capacity);
   
    pagefault=fifopg(n,a,capacity);
    
    printf("No. of page faults : %d\n",pagefault);
    
    return 0;
}