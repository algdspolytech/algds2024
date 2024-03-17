#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_sum(int n, int k, int sum, int iteration) 
{
    if ((iteration == n) && (sum == k))
    {
        return(1);
    }
    if ((n - iteration) * 9 < (k - sum)) {
        return(0);
    }
    if (sum > k) {
        return(0);
    }
}
int recursion_search(int n, int k, int sum, int iteration, int result)
{
    int a=(check_sum(n, k, sum, iteration));
    if ((a == 0) || (a == 1))
    {

        return(a);

    }
    for (int i = 0; i < 10; i++) 
    {
        result = result + recursion_search(n, k, (sum + i), (iteration + 1), 0);
    }
    return(result);
}
int kolvo_number(int n, int k) 
{
    int sum = 0;
    int iteration = 0;
    int result = 0;
    result = recursion_search(n, k, sum, iteration,result);
    return(result);
}