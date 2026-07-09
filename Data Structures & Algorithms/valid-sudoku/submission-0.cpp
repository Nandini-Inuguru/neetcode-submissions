class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char num=board[r][c];
                if(num=='.'){
                    continue;
                }
                int boxindex=(r/3)*3+(c/3);
                if(rows[r].find(num)!=rows[r].end()||columns[c].find(num)!=columns[c].end()||boxes[boxindex].find(num)!=boxes[boxindex].end()){
                    return false;
                }
                rows[r].insert(num);
                columns[c].insert(num);
                boxes[boxindex].insert(num);
            }
        }
        return true;

        
    }
};
