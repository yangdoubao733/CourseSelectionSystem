// ����
#include <stdio.h>
#include "csv.h"
#include "menu.h"

void selectCourse()
{
    printf("��������������ѧ��,��ʽ������ ѧ��");
    struct student studentInfo;
    int n;
    scanf("%s %d", &studentInfo.student_name, &studentInfo.student_id);
    printf("������������Ҫѡ�Ŀγ�id�����롮-1����ʾ����(ע��ÿ�˽���ѡ��һ�Σ������󲻿��޸�)");
    for (int i = 0; i <= MAX_VALUE; i++)
    {
        scanf("%d", &n);
        studentInfo.student_selectedCourseId[i] = n;
        if (n == -1)
        {
            printf("ѡ�ν���");
            break;
        }
    }
    writeStudentInfo(studentInfo);
    printf("\n");
    menu();
}
