#include <iostream>
#include <vector>
#include <set>

using namespace std;

// bool notInRow(vector<vector<char>>& board, int row) {
//     set<char> st;

//     for (int i = 0; i < 9; i++) {
//         if (st.find(board[row][i]) != st.end())
//             return false;
//         if (board[row][i] != '.')
//             st.insert(board[row][i]);
//     }
//     return true;
// }
 
// bool notInCol(vector<vector<char>>& board, int col){
//     set<char> st;

//     for (int i = 0; i < 9; i++) {
//         if (st.find(board[i][col]) != st.end())
//             return false;
//         if (board[i][col] != '.')
//             st.insert(board[i][col]);
//     }
//     return true;
// }
 
// bool notInBox(vector<vector<char>>& board, int startRow, int startCol) {
//     set<char> st;

//     for (int row = 0; row < 3; row++) {
//         for (int col = 0; col < 3; col++) {
//             char curr = board[row + startRow][col + startCol];
                
//             if (st.find(curr) != st.end())
//                 return false;
//             if (curr != '.')
//                 st.insert(curr);
//         }
//     }
//     return true;
// }
 
// bool isValid(vector<vector<char>>& board, int row, int col) {
//     return notInRow(board, row) && notInCol(board, col) && notInBox(board, row - row % 3, col - col % 3);
// }
    
// bool isValidSudoku(vector<vector<char>>& board) {
//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             if (!isValid(board, i, j))
//                 return false;
//         }
//     }
//     return true;
// }

bool isValidSudoku(vector<vector<char>>& board) {
    set <string> s;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                string row = "row" + to_string(i) + board[i][j];
                string col = "col" + to_string(j) + board[i][j];
                string box = "box" + to_string((i/3)*3 + (j/3)) + board[i][j];

                if(s.find(row) == s.end() && s.find(col) == s.end() && s.find(box) == s.end()) {
                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cout<<boolalpha;
    vector<vector<char>> board = { 
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7','9' } 
        };
    bool res = isValidSudoku(board);
    cout<<res;
    return 0;
}