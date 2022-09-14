# MyLeetcode项目介绍

1、题目源自leetCode网站 https://leetcode-cn.com/problemset/all/

2、题目难度主要以简单、中等为主

3、题目解法多为原创，有部分参考题解，方法较笨，还望见谅

4、本项目仅作为业余爱好创建，欢迎下载，欢迎指正！

# 开发工具
CLion + MingW64

# 代码框架介绍
```
MyLeetCode
    |——CMakeList.txt  //cmake列表，工具自动生成，可手动修改
    |——Array  //数组相关题目代码目录
    |——List   //链表相关题目代码目录
    |——String //字符串相关题目代码目录
    |——Math   //数学相关题目
    |——UT_hash   //UT哈希
    |——CBase   //C语言基础相关
    |——PublicHeaderFile.h  //新增函数实现时，手动添加函数声明到此文件
    |——main.c  //程序入口，在此文件中main()函数中调用代码目录中已实现接口
    |——README.md  
    |——其他
为了减少测试用例定义过多变量来接受函数返回值，在函数返回之前，打印函数返回结果
```

**常用git命令:**

克隆远端仓库到本地 : git clone https://github.com/LJW718/MyLeetcode.git

查看状态 : git status

查看远程仓库地址 : git remote -v

新建分支并切换到新分支 : git checkout -b br_name

删除本地分支 : git branch -d  br_name

删除远程分支 : git push origin --delete  br_name

增加/删除文件到缓冲区 : git add/rm  [file]

git reset HEAD 命令用于取消已缓存的内容 : git reset HEAD xxx.c

提交 : git commit -am "【第50题】计算x的n次幂函数"

推送到远端仓库(默认本地分支和远端分支同名) : git  push origin master




