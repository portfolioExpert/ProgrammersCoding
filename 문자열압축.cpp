//문자열 압축
#include <string>
int main(){
    string s = "xababcdcdababcdcd";
    int answer = 987654321;
    int i, j;
    for(i = 1;i<=s.size();i++){
        string str = s.substr(0,i);
        string result = "";
        int cnt = 0;
        for(j = 0;j + i <= s.size();j+=i){
            if(str == s.substr(j,i)){
                cnt++;
            }
            else{
                if(cnt >= 2){
                    result+=to_string(cnt)+str;
                }
                else{
                    result+=str;
                }
                cnt = 1;
                str = s.substr(j, i);
            }
        }
        if(cnt >= 2){
            result+=to_string(cnt)+str;
        }
        else
            result+=str;
        result+=s.substr(j, s.size() - j);
        answer = min(answer, (int)result.size());
    }
    return answer;
}