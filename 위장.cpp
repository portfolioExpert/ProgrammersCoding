//프로그래머스 위장 레벨2
#include <map>
#include <vector>
map<string,int>m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i = 0;i<(int)clothes.size();i++){
        m[clothes[i][1]]++;
    }
    for(auto it = m.begin(); it != m.end();it++){
        answer *= (m[it->first] + 1);
    }
    return answer - 1;
}