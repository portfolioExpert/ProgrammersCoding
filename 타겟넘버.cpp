//프로그래머스 타겟넘버 레벨2
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0, sum = 0;
void dfs(int index, int target, vector<int>numbers){
    if(index == numbers.size()){
        if(sum == target)
            answer++;
        return;
    }
    for(int i = 0;i<2;i++){
        if(i == 0){
            sum+=numbers[index];
            dfs(index + 1, target, numbers);
            sum-=numbers[index];
        }
        else{
            sum-=numbers[index];
            dfs(index + 1, target, numbers);
            sum+=numbers[index];
        }
    }
}
int solution(vector<int> numbers, int target) {
    for(int i = 0;i<2;i++){
        if(i == 0){
            sum+=numbers[0];
            dfs(1, target, numbers);
            sum-=numbers[0];
        }
        else{
            sum-=numbers[0];
            dfs(1, target, numbers);
            sum+=numbers[0];
        }
    }
    return answer;
}