#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) 
        return result;
        
    int rows = matrix.size(), cols = matrix[0].size();
    int startCol = 0, endCol = cols-1, startRow = 0, endRow = rows-1;
        
    while (startCol <= endCol && startRow <= endRow) {
        // Traversing the top border
        for (int i = startCol; i <= endCol; i++) {
            result.push_back(matrix[startRow][i]);
        }
        startRow++;

        // Traversing the right border
        for (int i = startRow; i <= endRow; i++) {
            result.push_back(matrix[i][endCol]);
        }
        endCol--;
            
        // Traversing the bottom border
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                result.push_back(matrix[endRow][i]);
            }
            endRow--;
        }
            
        // Traversing the left border
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                result.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    vector<int> res = spiralOrder(matrix);
    for(int i : res)
        cout<<i<<" ";
    return 0;
}