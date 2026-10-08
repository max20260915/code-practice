#include <stdio.h>
#include <stdlib.h>
int maxProfit(int* prices,int pricesSize){
    int profit = 0;
    for(int i = 1;i<pricesSize;i++)
    {
        if(prices[i] > prices[i-1])
        {
        profit += prices[i] - prices[i-1];
        }
        
    }
return profit;
}
int main(void)
{
    int prices1[] ={7,1,5,3,6,4};
    int sz1 = sizeof(prices1)/sizeof(prices1[0]);
    printf("样例1最大利润 = %d\n",maxProfit(prices1,sz1));
    int prices2[] ={7,6,4,3,1};
    int sz2 = sizeof(prices2)/sizeof(prices1[0]);
    printf("样例2最大利润 = %d\n",maxProfit(prices2,sz2));
    
}
