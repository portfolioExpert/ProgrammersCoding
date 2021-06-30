//프로그래머스 소수찾기
#include <string>
#include <vector>
string str;
int answer = 0;
vector<int>num;
bool use[7];
bool search(int n){
    for(int i = 0;i<num.size();i++){
        if(num[i] == n)
            return false;
    }
    return true;
}
bool fx(int x){
    if(x == 1)
        return false;
    for(int i = 2; i * i <= x;i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
void dfs(int index, string numbers){
    if(index == numbers.size()){
        return;
    }
    for(int i = 0;i<(int)numbers.size();i++){
        if(use[i] == 0){
            use[i] = 1;
            str+=numbers[i];
            if(fx(stoi(str)) && search(stoi(str))){
                answer++;
                num.push_back(stoi(str));
            }
            dfs(index + 1, numbers);
            str = str.substr(0, str.size() - 1);
            use[i] = 0;
        }
    }
}
int solution(string numbers) {
    for(int i = 0;i<(int)numbers.size();i++){
        if(numbers[i] != '0' && use[i] == 0){
            use[i] = 1;
            str+=numbers[i];
            if(fx(stoi(str)) && search(stoi(str))){
                answer++;
                num.push_back(stoi(str));
            }
            dfs(0, numbers);
            str = str.substr(0, str.size() - 1);
            use[i] = 0;
        }
    }
    return answer;
}