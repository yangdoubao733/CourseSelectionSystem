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
    scanf("%d\n",&course_Info.course_id);
    if(course_Info.course_id==-1){
        break;
    }
    printf("�γ���:");
    scanf("%s\n",course_Info.course_name);
    printf("�γ�����:");
    scanf("%s\n",course_Info.course_property);
    printf("ѧ��:");
    scanf("%d\n",&course_Info.course_credit);
    printf("��ѧʱ:");
    scanf("%d\n",&course_Info.course_totalHour);
    printf("�ڿ�ʱ��:");
    scanf("%d\n",&course_Info.course_classHour);
    printf("ʵ��ʱ��:");
    scanf("%d\n",&course_Info.course_practiceHour);
    printf("����ѧ��:");
    scanf("%d\n",&course_Info.course_term);
    writeCourseInfo(course_Info);
    i++;
    }
    menu();
}