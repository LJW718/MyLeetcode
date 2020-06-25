# MyLeetcode项目介绍

1、题目源自leetCode网站 https://leetcode-cn.com/problemset/all/

2、题目难度主要以简单、中等为主

3、题目解法多为原创，有部分参考题解，方法较笨，还望见谅

4、本项目仅作为业余爱好创建，欢迎下载，欢迎指正！

# 开发工具
CLion 2020.1.2 + MingW64

# 代码框架介绍
```
MyLeetCode
    |——.idea  //工具自动生成，无需手动修改
    |——cmake-bulid-debug  //工具调试生成的目录，无需手动修改
    |——CMakeList.txt  //cmake列表，工具自动生成，可手动修改
    |——Array  //数组相关题目代码目录
    |——List   //链表相关题目代码目录
    |——String //字符串相关题目代码目录
    |——PublicHeaderFile.h  //新增函数实现时，手动添加函数声明到此文件
    |——main.c  //程序入口，在此文件中main()函数中调用代码目录中已实现接口
    |——README.md  //readme文件
    |——其他
为了减少测试用例定义过多变量来接受函数返回值，在函数返回之前，打印函数返回结果
```






