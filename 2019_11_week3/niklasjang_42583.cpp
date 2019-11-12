/*
queue
트럭의 무게가 될 수 없는 0을 사용해서 트럭의 위치를 표현한다.
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size = truck_weights.size();
    int curr = 0;
    int on = 0;
    int result = 0;
    int time=0;
    queue<int> q;
    for(int i=0; i<bridge_length; i++) q.push(0);
    for(int i=0; i<size; i++){
        curr = truck_weights[i];
        while(true){
            on -= q.front(); q.pop();
            if(on + curr <= weight) break; 
            else q.push(0);
            ++answer;
        }
        q.push(curr);
        on += curr;
        ++answer;
    }
    answer += bridge_length;
    return answer;
}