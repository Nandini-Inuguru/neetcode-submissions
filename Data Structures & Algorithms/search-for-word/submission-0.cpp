class Solution {
public:
    int rows,cols;

    bool dfs(vector<vector<char>>& board,string& word,int r,int c,int idx){
        if(idx==word.size())
            return true;

        if(r<0||c<0||r>=rows||c>=cols||
           board[r][c]!=word[idx]||
           board[r][c]=='#')
            return false;

        char temp=board[r][c];
        board[r][c]='#';

        bool found=
            dfs(board,word,r+1,c,idx+1)||
            dfs(board,word,r-1,c,idx+1)||
            dfs(board,word,r,c+1,idx+1)||
            dfs(board,word,r,c-1,idx+1);

        board[r][c]=temp;

        return found;
    }

    bool exist(vector<vector<char>>& board,string word){
        rows=board.size();
        cols=board[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};