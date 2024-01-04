/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/



// TIme compelxity = O(9^(n*2)) [ beacuse in the worst case , all boxes can be empty, and for each box we have 9 options]
//  Space Complexity=O(1)
/*
Problem :

-> We need to fill the blanks boxes
-> Each row must contain numbers from 1 to 9
-> Each column must contain numbers from 1 to 9
-> Each 3*3 matrix must contain numbers from 1 to 9



-> Solution :

-> Find the first blank box, then create one isPossible function(start with 1 and go till 9)
-> If it is possible then , don't do backtracking 
-> If it is not possible to place that number, then do backtrack and remove the current number and place the next number at that place.
-> It can have multiple solutions, but in the constraints it is given that (It is guaranteed that the input board has only one solution.), so find that solution



The formula if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num) in the Sudoku solver is used to check whether it is possible to place a number num in a particular cell (row, col) of the Sudoku board. This formula checks if the number num already exists in the 3x3 subgrid to which the cell (row, col) belongs.

Let's break down the formula step by step:

1)(row/3) and (col/3) determine which 3x3 subgrid the cell (row, col) belongs to. Since the Sudoku board is divided into 9 equal 3x3 subgrids, (row/3) and (col/3) essentially map the row and column indices to the corresponding subgrid indices. For example, if row = 4 and col = 7, then (row/3) = 1 and (col/3) = 2, indicating that the cell (4, 7) belongs to the second (1-based index) 3x3 subgrid.

2)3*(row/3) and 3*(col/3) are used to find the top-left cell of the 3x3 subgrid to which (row, col) belongs. Multiplying by 3 ensures that we get the row and column indices of the top-left cell of the subgrid.

3)i/3 and i%3 are used to iterate over all cells within the 3x3 subgrid. i takes on values from 0 to 8, and (i/3) and (i%3) allow us to navigate through the 3x3 subgrid row by row and column by column.

Finally, board[3*(row/3)+i/3][3*(col/3)+i%3] checks the value of the cell within the 3x3 subgrid at position (3*(row/3)+i/3, 3*(col/3)+i%3) to see if it is equal to the number num.
*/
class Solution {
public:

    bool isPossible(int num, int row, int col, vector<vector<char>> & board){
        for(int i=0;i<9;i++){
            //  chech for col
            if(board[row][i]==num) return false;
            if(board[i][col]==num) return false;

            //  to check 3*3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int rowSize=board.size();
        int colSize = board.size();

        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(board[i][j]=='.'){
                    //  **** Here u need to place char and not num
                    for(char num='1';num<='9';num++){
                    if(isPossible(num,i,j,board)){
                        board[i][j]=num;
                        if(solve(board)) return true;
                        else {
                            //  backtrack
                             board[i][j]='.';
                        }

                  }
                    
                }

                //  If it was not able to find any number from 1 to 9 which is possible to place at the empty box, so we should return false;

                return false;
                }
            }
        }

        //  It can also be the case , that all the boxes are already filled , so just simply return true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};