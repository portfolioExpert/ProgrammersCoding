//프로그래머스 정수 삼각형
#include <vector>
vector<vector<int>>dp;
void topdown(int height){
    if(height < 0){
        return;
    }
    for(int i = 0;i<dp[height].size();i++){
        dp[height][i] += max(dp[height + 1][i], dp[height + 1][i+1]);
    }
    topdown(height - 1);
}
int solution(vector<vector<int>> triangle) {
    dp = triangle;
    topdown(triangle.size() - 2);
    return dp[0][0];
}