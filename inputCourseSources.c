//zhangjinpeng
#include<stdio.h>
#include"csv.h"
#include"menu.h"
void inputCourseSources(){
    struct course course_Info;
    int i;
    while(i<=MAX_VALUE){
    printf("������γ���Ϣ\n");
    printf("�γ�id:(������ҳ������-1)");
    scanf("%d",&course_Info.course_id);
    if(course_Info.course_id==-1){
        menu();
        break;
    }
    printf("�γ���:");
    scanf("%s",course_Info.course_name);
    printf("�γ�����:");
    scanf("%s",course_Info.course_property);
    printf("ѧ��:");
    scanf("%d",&course_Info.course_credit);
    printf("��ѧʱ:");
    scanf("%d",&course_Info.course_totalHour);
    printf("�ڿ�ʱ��:");
    scanf("%d",&course_Info.course_classHour);
    printf("ʵ��ʱ��:");
    scanf("%d",&course_Info.course_practiceHour);
    printf("����ѧ��:");
    scanf("%d",&course_Info.course_term);
    writeCourseInfo(course_Info);
    i++;
    }
    printf("\n");
    menu();
}