#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d",&k);

    k = k % n;  

    int result[n];

    for(int i = 0; i < n; i++)
    {
        int new_index = (i + k) % n;
        result[new_index] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}