#include<stdio.h>
#include"displayCourseSources.h"
#include"inputCourseSources.h"
#include"queryCourseInfo.h"
#include"selectCourse.h"

int menu(){
    printf("1.¼��γ�\n2.�鿴���пγ�\n3.��ѯ�γ�\n4.ѡ��γ�\n5.�˳�\n����������ʹ�õĹ���");
    int n;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        inputCourseSources();
        break;
    case 2:
        displayCourseSources();
        break;
    case 3:
        queryCourseInfo();
        break;
    case 4:
        selectCourse();
        break;
    case 5:
        exit(0);
    default:
        printf("����ȷ����");
        menu();
    }
}