//프로그래머스 다리를 지나는 트럭 레벨2
#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int>q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int state = 0;
    for(int i = 0;i<(int)truck_weights.size();i++){
        while(1){
            if(q.empty()){
                state += truck_weights[i];
                q.push(truck_weights[i]);
                answer++;
                break;
            }
            else if(q.size() == bridge_length){
                state-= q.front();
                q.pop();
            }
            else{
                if(state + truck_weights[i] > weight){
                    q.push(0);
                    answer++;
                }
                else{
                    q.push(truck_weights[i]);
                    answer++;
                    state+=truck_weights[i];
                    break;
                }
            }
        }
    }
    return answer + bridge_length;
}