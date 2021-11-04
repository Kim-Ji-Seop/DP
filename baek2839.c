#include <stdio.h>
#include <string.h>
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int DP[5000];

int sugar(int n){
    if(n == 0) return DP[n] = 0;//n이 0이라면 0을 DP[0]에 넣고 해당 DP값을 리턴한다.
    if(n < 0) return 5001;// n이 재귀호출로 인해 음수가 된다면 해당리턴은 모두 5001로 올려버린다.
    if(DP[n] != -1) return DP[n];// DP테이블의 값이 -1이 아니라면(값이 저장된적이 있다면) 바로 DP테이블 리턴
    return DP[n] = min(sugar(n-3),sugar(n-5)) + 1;// 3으로 뺐을때와 5로 뺐을때의 최소값과 1을 더한 값을 DP에 저장후 리턴
}
int main(){
    memset(DP,-1,sizeof(DP)); //DP테이블의 메모리 내의 값을 -1로 초기화
    int num;
    scanf("%d",&num);

    if(sugar(num) > 5000){
        printf("-1");// DP테이블의 해당 위치 값이 5000이 넘는 수라면 -1 출력
    }else{
        printf("%d",sugar(num));// 정상출력
    }
    
    return 0;
}