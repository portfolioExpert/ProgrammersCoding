//프로그래머스 베스트앨범 레벨3
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int>m;
vector<pair<int,int>>gen[101];
vector<pair<int,int>>song;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //맵에 장르 번호를 1부터 저장
    for(int i = 0;(int)i<genres.size();i++){
        if(m[genres[i]] == 0)
            m[genres[i]] = i + 1;
    }
    //장르번호위치에 값과 고유번호 저장
    //이때 고유번호 낮은것 부터 출력하기 위해서-를 붙여서 넣고
    for(int i = 0;i<(int)plays.size();i++){
        gen[m[genres[i]]].push_back({plays[i], -i});
    }
    //총 재생횟수를 계산해서 장르번호랑 저장
    song.push_back({0, 0});
    for(auto it = m.begin();it != m.end();it++){
        int sum = 0;
        for(int j = 0;j<(int)gen[it->second].size();j++){
            sum+=gen[it->second][j].first;
        }
        song.push_back({sum, it->second});
    }
    //총 재생횟수 내림차순
    sort(song.begin(), song.end());
    reverse(song.begin(), song.end());
    //장르안에서 재생횟수 내림차순
    for(auto it = m.begin();it!=m.end();it++){
        sort(gen[it->second].begin(), gen[it->second].end());
        reverse(gen[it->second].begin(), gen[it->second].end());
    }
    //고유번호를 넣어준다 이때 -를 붙여서 빼주면 낮은 번호부터 나온다
    //ex)1, 2의 순인데 -를 붙여주므로서 sort하면 -2, -1 가 되고 reverse 해주면
    // -1, -2가 되고 -를 붙여주면 1, 2가 되므로 고유번호 낮은순으로 출력이 가능하다.
    for(int i = 0;i<(int)song.size();i++){
        for(int j = 0;j < (int)gen[song[i].second].size() && j<2;j++){
            answer.push_back(-gen[song[i].second][j].second);
        }
    }
    return answer;
}