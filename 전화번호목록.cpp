//프로그래머스 전화번호 목록
#include <map>
#include <vector>
map<string, int>m;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i = 0;i<(int)phone_book.size();i++){
        m[phone_book[i]] = i+1;
    }
    for(int i = 0;i<(int)phone_book.size();i++){
        cout << m[phone_book[i]] << " ";
    }
    for(int i = 0;i<(int)phone_book.size();i++){
        string str = "";
        for(int j = 0;j<(int)phone_book[i].size() - 1;j++){
            str+=phone_book[i][j];
            if(m[str] != 0)
                return false;
        }
    }
    return answer;
}
