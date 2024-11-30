// 张轶淮
#include <stdio.h>
#include "csv.h"
#include "menu.h"

void selectCourse()
{
    printf("请输入您的姓名学号,格式：姓名 学号");
    struct student studentInfo;
    int n;
    scanf("%s %d", &studentInfo.student_name, &studentInfo.student_id);
    printf("请依次输入您要选的课程id，输入‘-1’表示结束(注；每人仅可选择一次，结束后不可修改)");
    for (int i = 0; i <= MAX_VALUE; i++)
    {
        scanf("%d", &n);
        studentInfo.student_selectedCourseId[i] = n;
        if (n == -1)
        {
            printf("选课结束");
            break;
        }
    }
    writeStudentInfo(studentInfo);
    printf("\n");
    menu();
}
