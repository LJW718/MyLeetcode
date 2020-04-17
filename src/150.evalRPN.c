/*
150. 逆波兰表达式求值
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


// 用栈实现，遇到数字入栈，遇到符号，栈顶两个元素出站作运算，移除栈顶元素，结果再入栈，最终返回栈顶元素即可

#define  MAX_SIZE  10000

int evalRPN(char ** tokens, int tokensSize){
    if (tokens == NULL) {
        return -1;
    }
    // printf("%d   %s\n", tokensSize,tokens[tokensSize - 1]);
    int stack[MAX_SIZE] = {0};
    int top = 0;
    int tmp = 0;
    int i = 0;
    while (i < tokensSize) {
        if ((0 != strcmp(tokens[i],"+")) && (0 != strcmp(tokens[i],"-")) && 
            (0 != strcmp(tokens[i],"*")) && (0 != strcmp(tokens[i],"/"))) {
            stack[top] = atoi(tokens[i]);
            top++;
        } 
        else if (0 == strcmp(tokens[i],"+")) {
            if (top > 1) {
                tmp = stack[top - 2] + stack[top - 1]; //栈顶2元素进行相应运算  
                stack[top - 1] = 0;   //栈顶置0，相当于栈顶元素出站
                stack[top - 2] = tmp; //将运算结果保存在栈顶
                top -= 1;             //栈顶减一
            }
        } 
        else if (0 == strcmp(tokens[i],"-")) {
            if (top > 1) {
                tmp = stack[top - 2] - stack[top - 1]; //栈顶2元素进行相应运算  
                stack[top - 1] = 0; //栈顶置0，相当于栈顶元素出站
                stack[top - 2] = tmp; //将运算结果保存在栈顶
                top -= 1;
            }
        } else if (0 == strcmp(tokens[i],"*")) {
            if (top > 1) {
                tmp = stack[top - 2] * stack[top - 1]; //栈顶2元素进行相应运算  
                stack[top - 1] = 0; //栈顶置0，相当于栈顶元素出站
                stack[top - 2] = tmp; //将运算结果保存在栈顶
                top -= 1;
            }
        } else if (0 == strcmp(tokens[i],"/")) {
            if (top > 1) {
                tmp = stack[top - 2] / stack[top - 1]; //栈顶2元素进行相应运算  
                stack[top - 1] = 0; //栈顶置0，相当于栈顶元素出站
                stack[top - 2] = tmp; //将运算结果保存在栈顶
                top -= 1;
            }
        }
        i++;
    }
    return stack[0];;
}
