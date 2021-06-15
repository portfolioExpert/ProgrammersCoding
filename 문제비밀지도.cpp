//문제 비밀지도
#include <vector>
#include <cmath>
char map1[17][17];
char map2[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0;i<n;i++){
        for(int j = n - 1;j >= 0;j--){
            if(arr1[i] / (int)pow(2, j) > 0){
                arr1[i] = arr1[i] % (int)pow(2, j);
                map1[i][n - j - 1] = '#';
            }
            else
                map1[i][n - j - 1] = ' ';
            if(arr2[i] / (int)pow(2, j) > 0){
                arr2[i] = arr2[i] % (int)pow(2, j);
                map2[i][n - j - 1] = '#';
            }
            else
                map2[i][n - j - 1] = ' ';
        }
    }
    for(int i = 0;i<n;i++){
        string s = "";
        for(int j = 0;j<n;j++){
            if(map1[i][j] == '#' || map2[i][j] == '#')
                s+='#';
            else
                s+=' ';
        }
        answer.push_back(s);
    }
    return answer;
}