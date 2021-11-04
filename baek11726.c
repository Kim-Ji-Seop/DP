#include <stdio.h>
int DP[1001];
int tile(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(DP[n] != 0) return DP[n];
    return DP[n] = (tile(n-1) + tile(n-2)) % 10007;
}
int main(){
    int num;
    scanf("%d",&num);
    printf("%d",tile(num));
}

