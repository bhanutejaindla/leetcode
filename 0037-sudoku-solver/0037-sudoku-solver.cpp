class Solution {
public:
    bool isValid(vector<vector<char>>&board,int row,int col,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch) return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch) return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==ch) return false;
        }
        return true;
    }
    bool solvesudoku(vector<vector<char>>&board)
    {
          for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solvesudoku(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solvesudoku(board);
      
    }
};