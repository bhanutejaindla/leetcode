class Solution {
public:
    bool dfs(vector<vector<char>>&board,int ind1,int ind2,int ind,string word)
    {
        if(ind==word.length())
        {
            return true;
        }

        if(ind1<0|| ind2<0 || ind1==board.size() || ind2==board[0].size() || board[ind1][ind2]!=word[ind] || board[ind1][ind2]=='!')
        {
            return false;
        }
        char c=board[ind1][ind2];
        board[ind1][ind2]='!';
        bool top=dfs(board,ind1-1,ind2,ind+1,word);
        bool bottom=dfs(board,ind1+1,ind2,ind+1,word);
        bool right=dfs(board,ind1,ind2+1,ind+1,word);
        bool left=dfs(board,ind1,ind2-1,ind+1,word);
        board[ind1][ind2] = c;
        return top || bottom || right || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
       
       for(int i=0;i<board.size();i++)
       {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]==word[0])
            {
                if(dfs(board,i,j,0,word))return true;
            }
        }
       }
       return false;
    }
};