#include <iostream>
#include <vector>

using namespace std;


bool search(int row,int col,vector<vector<char>>& board, string word,int index) {
    if(index == word.size())
        return true;
    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        return false;
    bool ans = false;
    if(word[index] == board[row][col]) {
        board[row][col] = '*';
        ans = search(row+1,col,board,word,index+1) ||  
              search(row-1,col,board,word,index+1) ||  
              search(row,col+1,board,word,index+1) ||  
              search(row,col-1,board,word,index+1);  

        board[row][col] = word[index];
    } 
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    int index = 0;
    bool ans = false;
    for(int row=0;row<board.size();row++) {
        for(int col=0;col<board[0].size();col++) {
            if(word[index] == board[row][col]) {
                if(search(row,col,board,word,index))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cout<<boolalpha;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    bool res = exist(board,word);
    cout<<res;
    return 0;
}