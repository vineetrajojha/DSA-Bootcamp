struct TrieNode{
public:
    TrieNode* child[26] = {};
    string word = ""; 
};
class Solution {
public:
    void insert(TrieNode* root, string& word){
        TrieNode* node = root;
        for(char ch : word){
            if(!node->child[ch-'a']){
                node->child[ch-'a'] = new TrieNode();
            }
            node = node->child[ch-'a'];
        }
        node->word = word;
    }
    void dfs(int i, int j, TrieNode* node, vector<vector<char>>& board, vector<string>& res, int m, int n){
        char ch = board[i][j];
        if(ch=='#' || !node->child[ch-'a']) return;
        node = node->child[ch-'a'];
        if(!node->word.size()==0){
            res.push_back(node->word);
            node->word="";
        }
        int dx[4] = {0,+1,0,-1};
        int dy[4] = {-1,0,+1,0};
        board[i][j] = '#';
        for(int it=0;it<4;it++){
            int ni = i + dx[it];
            int nj = j + dy[it];
            if(ni>=0 && ni<m && nj>=0 && nj<n){
                dfs(ni,nj,node,board,res,m,n);
            }
        }
        board[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word : words){
            insert(root,word);
        }
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        TrieNode* node = root;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,node,board,res,m,n);
            }
        }
        return res;
    }
};