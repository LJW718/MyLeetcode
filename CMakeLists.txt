cmake_minimum_required(VERSION 3.16)
project(MyLeetcode C)

set(CMAKE_C_STANDARD 11)

add_executable(MyLeetcode main.c
        PublicHeaderFile.h
        Array/167.twoSum.c
        Array/561.arrayPairSum.c
        List/2.addTwoNumbers.c
        String/12.intToRoman.c
        String/22.generateParenthesis.c
        List/19.removeNthFromEnd.c List/24.swapPairs.c Array/34.searchRange.c Math/50.myPow.c String/17.letterCombinations.c)
