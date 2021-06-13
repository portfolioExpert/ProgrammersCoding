//괄호 변환
bool check(string s){
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '(')
            cnt++;
        else{
            if(!cnt)
                return false;
            cnt--;
        }
    }
    return true;
}
string fx(string s){
    if(s == "")return s;
    string u, v;
    int lcnt = 0, rcnt = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '(')
            lcnt++;
        else
            rcnt++;
        if(lcnt == rcnt){
            u = s.substr(0, i+1);
            v = s.substr(i + 1);
            break;
        }
    }
    if(check(u)){
        return u + fx(v);
    }
    string str = "(";
    str+=fx(v)+")";
    u = u.substr(1, u.size()-2);
    for(int i = 0;i<u.size();i++){
        if(u[i] == '(')
            str+=")";
        else if(u[i] == ')')
            str+="(";
    }
    return str;
}
string solution(string p) {
    if(p == "")return p;
    else return fx(p);
}