#include <stdio.h>

int climbStairs(int n){
    int p = 0,q=0, r=1;
    for (int i =1 ; i<=n; ++i){
        p=q;
        q=r;
        r=q+p;
    }
    return r;
}

int main(void)
{
    int n = 5;
    int ans = climbStairs(n);
    printf("爬%d阶楼梯，方法数：%d\n", n, ans);
    return 0;
}