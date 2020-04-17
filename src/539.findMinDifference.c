/*
539. 最小时间差
给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。


示例 1：

输入: ["23:59","00:00"]
输出: 1

备注:

列表中时间数在 2~20000 之间。
每个时间取值在 00:00~23:59 之间。
*/



int TimeDiff(char *timePoints1, char *timePoints2)
{
    if(0 == strcmp(timePoints1, timePoints2)) {
        return 0;
    }
    // 格式化时间
    int hour1, minute1, hour2, minute2;
    (void)sscanf(timePoints1,"%d:%d",&hour1,&minute1);
    (void)sscanf(timePoints2,"%d:%d",&hour2,&minute2);
    // printf("%d %d %d %d \n", hour1, minute1, hour2, minute2);
    int time1 = 0;
    int time2 = 0;
    if (hour1 == 0) {
        time1 = 24 * 60 + minute1;
    } else {
        time1 = hour1 * 60 + minute1;
    }
    if (hour2 == 0) {
        time2 = 24 * 60 + minute2;
    } else {
        time2 =  hour2 * 60 + minute2;
    }
    int tmp = abs(time1 - time2);
    return  tmp < 720 ? tmp : (720 - (tmp % 720));  //时差最大值为12h=720m
}

int findMinDifference(char ** timePoints, int timePointsSize){
    if (timePoints == NULL) {
        return -1;
    }
    if (timePointsSize >= 1440) {
        return 0;  //时间数目大于1440，必有相同时间点，差值必为0
    }
    int cur = 0; //当前两个时间的时差
    int i, j;
    int min = 1440;  //最小时差默认24小时，24h = 24*60 = 1440m
    for (i = 0 ; i < timePointsSize - 1; i++) {
        for (j = i+1; j < timePointsSize; j++) {
            cur = TimeDiff(timePoints[i], timePoints[j]);
            if (cur < min) {
                min = cur;
            }
        }
    }
    return min;
}