//프로그래머스 기능개발 레벨2
#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int>q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0;i<(int)progresses.size();i++){
        if((100 - progresses[i]) % speeds[i] == 0)
            q.push((100 - progresses[i]) / speeds[i]);
        else
            q.push((100 - progresses[i]) / speeds[i] + 1);
    }
    while(!q.empty()){
        int val = q.front();
        q.pop();
        int cnt = 1;
        while(!q.empty() && q.front() <= val){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}