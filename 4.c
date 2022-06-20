#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = replaceElement(arr, n);
    printf("%d",max);
    return 0;
}
int replaceElement(int arr[], int n)
{
    int i, j, max, count;
     int maxCount = 0;
    for(i = 0; i< n; i++)
    {
        count = 1;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] == arr[i])
            {
                count++;
                if(count > maxCount)
                {
                    max = arr[j];
                }
            }
        }
    }
    return max;
}

