#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> s;
    int i;
    int cur;
    
    answer.resize(prices.size());
    prices.push_back(-1);
    
    for(i=0;i<prices.size();i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            cur = s.top();
            s.pop();
            
            answer[cur] = i - cur;
            if(i == prices.size()-1) answer[cur]--;
        }
        s.push(i);
    }
    
    return answer;
}
