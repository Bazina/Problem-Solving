#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n , pair = 0 ;
    scanf("%i" , &n) ;
    char arr[n] ;
    scanf("%s" , &arr) ;
    for(int i = 1 ; i < n ; i ++)
    {
        if(arr[i] == arr[i - 1])
        {
            pair ++ ;
        }
    }
    printf("%i" , pair) ;
}
