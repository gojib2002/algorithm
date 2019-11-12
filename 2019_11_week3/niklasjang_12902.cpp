/*
오류의 원인
1. vector 0초기화 진행하지 않았다.
2. int dp[5001]로 풀 때는 memset 하지 않고 그냥 사용했다.
3. return이 int라고 long long을 사용하면 안되는 줄 알았다. 
dp[0] = 1이라고 하면 식이 간단해 진다.
dp[i] = dp[i-2]*3 + dp[i-4]*2 + ... + dp[0]*2
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(n+1, 0);
    dp[0] = 1; 
    dp[2] = 3;
    for(int i=4; i<=n; i+=2){
        dp[i] += (dp[i-2]*3)%1000000007;
        for(int j=i-4; j>=0; j-=2){
            dp[i] += (dp[j]*2)%1000000007;
        }
    }
    answer = dp[n]%1000000007;
    return answer;
}