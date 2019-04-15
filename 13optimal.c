#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int capacity, n, a[MAX];
int frame[MAX], dist[MAX];

int optindex(int index)
{
    int i,j,max,val=0;
        
    for(i=0;i<capacity;i++)
        dist[i]=-1;
    
    for(j=0;j<capacity;j++)
    {
        for(i=index;i<n;i++)
        {
            if(frame[j]==a[i])
            {
                 dist[j]=i;
                 break;
            }
            dist[j]=n;
        }
     }
         
    max=dist[0];
    for(i=1;i<capacity;i++)
        if(max<dist[i])
        {    
         	max=dist[i];  
            val=i;
        }
                
    return val;
}   

int psearch(int num, int arr[],int m)
{
    int i;
    
    for(i=0;i<m;i++)
        if(num==arr[i])
            return 1;
            
    return 0;
}

int optimal()
{
    int ptr=0,count=0,i,j;
        
    for(i=0;i<capacity;i++)     //initialize all frames to -1
        frame[i]=-1;
  
    for(i=0;i<n;i++)
    {
            if(i<capacity)
            {
                if(psearch(a[i],frame,capacity)==0)
                {
                    frame[ptr]=a[i];
                    ptr=(ptr+1)%capacity;
                    count++;
                }  
            }
            else
            {
                if(psearch(a[i],frame,capacity)==0)
                {
                     ptr=optindex(i);
                     frame[ptr]=a[i];
                     count++;
                }
            }  
    }
    return count;
}  

int main()
{
    int pagefault,i;
    
    printf("Enter number of pages\n");
    scanf("%d",&n);
    
    printf("Enter the reference string\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    printf("Enter no. of page frames\n");
    scanf("%d",&capacity);
   
    pagefault=optimal();
    
    printf("No. of page faults : %d\n",pagefault);
    
    return 0;   
}