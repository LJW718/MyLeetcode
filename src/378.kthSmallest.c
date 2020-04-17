/*
378. 有序矩阵中第K小的元素
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

 

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
 

提示：
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/




int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    if (matrix == NULL) {
        return -1;
    }

    int *result = (int *)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    if (result == NULL) {
        return -1;
    }
    memset(result, 0, matrixSize * (*matrixColSize));
    int i, j;
    int m = 0;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < (*matrixColSize); j++) {
            result[m] = matrix[i][j];
            m++;
        }
    }
    qsort(result, matrixSize * (*matrixColSize), sizeof(int), compare);
    //printf("%d   \n", matrixSize);
    return result[k-1];
}