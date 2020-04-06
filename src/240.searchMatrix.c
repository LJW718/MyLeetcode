/*
240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/



bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrix == NULL) {
        return false;
    }
    /* 从矩阵的左下角或者右上角开始搜索，因为左下角是一列当中最大的，右上角是一行之中最大的，
       每次拿最大的数和目标值去比较，都可以缩小搜索的范围 
    */ 
    int row =  0;
    int col = matrixColSize - 1;
    /* 从右上角开始搜索 */
    while (row < matrixRowSize && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }
    return false;
}