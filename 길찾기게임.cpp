//길 찾기 게임
#include <vector>
#include <algorithm>
typedef struct Node {
    int val, x ,y;
    struct Node *left;
    struct Node *right;
}Node;
void maketree(Node *root, Node *v);
Node *root = NULL;
vector<pair<pair<int,int>,int>> v;
vector<Node>result;
void pre(Node *root, vector<int> &answer){
    answer.push_back(root->val);
    if(root->left!=NULL)
        pre(root->left, answer);
    if(root->right != NULL)
        pre(root->right, answer);
}
void post(Node *root, vector<int> &answer){
    if(root->left!=NULL)
        post(root->left, answer);
    if(root->right!= NULL)
        post(root->right, answer);
    answer.push_back(root->val);
}
vector<vector<int>> solution (vector<vector<int>> nodeinfo){
    vector<vector<int>> answer = {{}, {}};
    int index = 1;
    for(int i = 0;i<nodeinfo.size();i++){
        int num1 = nodeinfo[i][0];
        int num2 = nodeinfo[i][1];
        v.push_back({{num2, num1}, index++});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0;i<v.size();i++){
        Node input;
        input.val = v[i].second;
        input.x = v[i].first.second;
        input.y = v[i].first.first;
        result.push_back(input);
    }
    root = &result[0];
    for(int i = 1;i<result.size();i++){
        maketree(root, &result[i]);
    }
    pre(root, answer[0]);
    post(root, answer[1]);
    return answer;
}
void maketree(Node *root, Node *v){
    if(v->x < root->x){
        if(root->left != NULL)
            maketree(root->left, v);
        else
            root->left = v;
    }
    if(v->x > root->x){
        if(root->right != NULL)
            maketree(root->right, v);
        else
            root->right = v;
    }
}