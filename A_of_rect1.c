#include<stdio.h>
#include<stdlib.h>
//brute force
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int max=0,i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int j;
    for(i=0;i<n;i++)
    {
        int width=1;
        int j=i+1;
        int k=i-1;
        while(j<n)
        {
            if(arr[j]>=arr[i])
            {
                width++;
                j++;
            }
            else
            break;
        }
        while(k>=0)
        {
            if(arr[k]>=arr[i])
            {
                width++;
                k--;
            }
            else
            break;
        }
        int area= width * arr[i];
        if(max<area)
        max=area;
    }
    printf("%d\n",max);
}