// 2. N queens Problem

class Solution {
public:
    bool isSafe(int row,int col, vector<string>& board, int n){
        int duprow = row;
        int dupcol = col;
        
        // upper diagonal 
        while(row>=0 and col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        col = dupcol;
        row =duprow;
        // left side
        while(col>=0){
            if(board[row][col]=='Q') return false;
            // row--;
            col--;	
        }
        
        // lower diagonal
        col = dupcol;
        row =duprow;
        while(row<n and col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;	
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>>&
        ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row =0; row<n; row++){
            // if(1){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    
    }
    
    vector<vector<string>> solveNQueens(int n){
        //  for the output
        vector<vector<string>> ans;
        
        vector<string> board(n);
        string s(n, '.');
        
        // creating the grid
        for(int i=0;i<n;i++){
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};