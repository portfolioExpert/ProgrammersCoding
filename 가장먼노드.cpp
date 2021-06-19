//프로그래머스 가장먼 노드
#include <vector>
#include <queue>
queue<int>q;
int maxval = -1;
vector<int>node[20001];
int visit[20001];
void bfs(int go){
    visit[go] = 1;
    q.push(go);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int y : node[now]){
            if(visit[y] == 0){
                visit[y] = visit[now] + 1;
                q.push(y);
                maxval = max(maxval, visit[y]);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0;i<edge.size();i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    for(int i = 1;i<=n;i++){
        if(maxval == visit[i]){
            answer++;
        }
    }
    return answer;
}