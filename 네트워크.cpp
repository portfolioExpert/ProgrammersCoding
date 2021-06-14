//네트워크
#include <vector>
int visit[201];
vector<int>node[201];
void dfs(int go){
    visit[go] = 1;
    for(int y : node[go]){
        if(visit[y] == 0){
            visit[y] = 1;
            dfs(y);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0;i<computers.size();i++){
        for(int j = 0;j<computers.size();j++){
            if(computers[i][j] == 1 && i != j){
                node[i+1].push_back(j+1);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0){
            dfs(i);
            answer++;
        }
    }
    return answer;
}