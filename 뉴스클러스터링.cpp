//뉴스 클러스터링
int solution(string str1, string str2) {
    int firstsize = 0, secondsize = 0;
    int answer = 0;
    double sum = 0;
    int index = 0;
    string first[1001], second[1001];
    for(int i = 0;i<str1.size() - 1;i++){
        if((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z')){
            if((str1[i+1] >= 'A' && str1[i+1] <= 'Z') || (str1[i+1] >= 'a' && str1[i+1] <= 'z')){
                string str;
                if(str1[i]>='A' && str1[i]<='Z')
                    str1[i]+=32;
                if(str1[i+1]>='A' && str1[i+1] <='Z')
                    str1[i+1]+=32;
                first[index]+=str1[i];
                first[index++]+=str1[i+1];
                firstsize++;
            }
        }
    }
    index = 0;
    for(int i = 0;i<str2.size() - 1;i++){
        if((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z')){
            if((str2[i+1] >= 'A' && str2[i+1] <= 'Z') || (str2[i+1] >= 'a' && str2[i+1] <= 'z')){
                if(str2[i]>='A' && str2[i]<='Z')
                    str2[i]+=32;
                if(str2[i+1]>='A' && str2[i+1] <='Z')
                    str2[i+1]+=32;
                second[index]+= str2[i];
                second[index++]+=str2[i+1];
                secondsize++;
            }
        }
    }
    sort(first, first+firstsize);
    sort(second, second+secondsize);
    int i, j = 0;
    for(i = 0;first[i] != "" && second[j] != "";){
        if(first[i] == second[j]){
            i++;
            j++;
            answer++;
            sum++;
        }
        else if(first[i] > second[j]){
            j++;
            sum++;
        }
        else if(first[i] < second[j]){
            i++;
            sum++;
        }
    }
    if(firstsize > i)
        sum+= firstsize - i;
    if(secondsize > j){
        sum+= secondsize - j;
    }
    if(answer == 0){
        if(sum == 0)
            answer = 65536;
        else{
            //교집합이 하나도 없을경우 공집합도 교집합이므로 1로 계산해야한다.
            sum = (double)1/sum;
            answer = sum / 65536;
        }
    }
    else{
        sum = (double)answer / sum;
        answer = sum * 65536;
    }
    return answer;
}