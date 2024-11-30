#include<stdio.h>
#include"displayCourseSources.h"
#include"inputCourseSources.h"
#include"queryCourseInfo.h"
#include"selectCourse.h"
#include"searchSelectedCourse.h"

int menu(){
    printf("\n***************************************************\n");
    printf("1.¼��γ�\n2.�鿴���пγ�\n3.��ѯ�γ�\n4.ѡ��γ�\n5.��ѯ��ѡ��γ�\n6.�˳�\n����������ʹ�õĹ���");
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
        searchSelectedCourse();
        break;
    case 6:
        exit(0);
    default:
        printf("����ȷ����");
        menu();
    }
}