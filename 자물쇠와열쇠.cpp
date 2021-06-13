//자물쇠와 열쇠
#include <vector>
int keysize, locksize, boardsize;

vector<vector<int>> rotate(vector<vector<int>> v){
    vector<vector<int>> result(keysize, vector<int>(keysize, 0));
    for(int i = 0;i<keysize;i++){
        for(int j = 0;j<keysize;j++){
            result[i][j] = v[keysize - j - 1][i];
        }
    }
    return result;
}

bool in(int x, int y, vector<vector<int>> key, vector<vector<int >> lock){
    for(int i = x; i<x+keysize;i++){
        for(int j = y;j<y+keysize;j++){
            lock[i][j]+=key[i - x][j - y];
        }
    }
    for(int i = keysize - 1;i<=boardsize - keysize;i++){
        for(int j = keysize - 1;j<=boardsize - keysize;j++){
            if(lock[i][j] != 1)return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    keysize = (int)key.size();
    locksize = (int)lock.size();
    boardsize = locksize + (keysize - 1) * 2;
    vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));

    for(int i = keysize - 1; i<=boardsize - keysize;i++){
        for(int j = keysize - 1;j<=boardsize - keysize;j++){
            board[i][j] = lock[i- keysize + 1][j - keysize + 1];
        }
    }

    for(int i = 0;i<4;i++){
        for(int j = 0;j<=boardsize - keysize;j++){
            for(int k = 0;k<=boardsize - keysize;k++){
                if(in(j, k, key, board)){
                    answer = true;
                    return answer;
                }
            }
        }
        key = rotate(key);
    }
    return answer;
}