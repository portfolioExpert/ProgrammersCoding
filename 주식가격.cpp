//프로그래머스 주식가격 레벨2
#include <stack>
#include <vector>
#include <string>
stack<pair<int,int>>s;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int result[100001];
    for(int i = 0;i<(int)prices.size();i++){
        if(s.empty()){
            s.push({prices[i], i});
            continue;
        }
        if(s.top().first <= prices[i])
            s.push({prices[i],i});
        else{
            while(!s.empty() && s.top().first > prices[i]){
                result[s.top().second] = i - s.top().second;
            s.pop();
            }
            s.push({prices[i],i});
        }
    }
    while(!s.empty()){
        result[s.top().second] = (int)prices.size() - 1 - s.top().second;
        s.pop();
    }
    for(int i = 0;i<prices.size();i++){
        answer.push_back(result[i]);
    }
    return answer;
}