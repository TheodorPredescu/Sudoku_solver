#include <iostream>
#include <vector> 
#include <string>

using namespace std;   

class Solution {
public:
    vector<vector<char>> A;


    bool check_if_solved() {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (A[i][j] == '.') {
                    return 0;
                }
            }
        }
        return 1;
    }

    // check if the value is in the line or column
    bool line_column_check(int pozi, int pozj, char value) {
        for (int i = 0; i < 9; i ++) {
            if (A[pozi][i] == value || A[i][pozj] == value) {
                return 0;
            }
        }                
        return 1;
    }

    // check if the value is in the square
    bool square_check(int starti, int startj, char value) {
        for (int i = starti; i < starti + 3; i ++) {
            for (int j = startj; j < startj + 3; j ++) {
                if (A[i][j] == value) {
                    return 0;
                }
            }
        }
        return 1;
    }

    void square(int pozi , int pozj) {
        int starti = pozi - pozi % 3, startj = pozj - pozj % 3;
        int puti = -1, putj = -1;

        // i take the possibilities for the square
        for (int value = 1; value <= 9 ;value ++) {
            // check how many are in the square
            int possibility = 0;

            for (int i = starti; i < starti + 3; i ++) {
                for (int j = startj; j < startj + 3; j ++) {
                    
                    // check if there is any "value" in the square
                    if (square_check(starti, startj, to_string(value)[0]) == 1 && 
                        line_column_check(i, j, to_string(value)[0]) == 1 &&
                        A[i][j] == '.') {

                        possibility ++;
                        puti = i;
                        putj = j;
                    }
                    
                }
            }

            // if there is only one possibility, we put the value in the square
            if (possibility == 1) {
                A[puti][putj] = to_string(value)[0];
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        A = board;
        int possible = 0;
        while (check_if_solved() == 0) {
            for (int i = 0; i < 9; i = i + 3) {
                for (int j = 0; j < 9; j = j + 3) {
                    square(i, j);
                    
                }   
            }

        }
    }

    void print() {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<char>> x = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(x);
    s.print();
    return 0;
}