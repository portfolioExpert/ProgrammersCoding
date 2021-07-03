//프로그래머스 프린터 레벨2
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
queue<pair<int,int>>q;
vector<int>v;
vector<pair<int,int>>result;
int solution(vector<int> priorities, int location) {
    int answer = 1;
    for(int i = 0;i<(int)priorities.size();i++){
        q.push({priorities[i],i});
        v.push_back(priorities[i]);
    }
    sort(v.begin(), v.end());
    while(!q.empty()){
        int now = q.front().first;
        int index = q.front().second;
        q.pop();
        if(now == v[v.size() - 1]){
            result.push_back({now, index});
            v.pop_back();
        }
        else{
            q.push({now, index});
        }
    }
    for(int i = 0 ;i<(int)result.size();i++){
        if(result[i].second == location)
            return answer;
        answer++;
    }
    return answer;
}