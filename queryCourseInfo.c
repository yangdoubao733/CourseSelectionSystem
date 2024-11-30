#include<stdio.h>
#include<string.h>
#include"csv.h"
#include"menu.h"

void queryCourseInfo(){
    int target;
    printf("1.��ѧ�ֲ��� 2.���γ����ʲ���\n��ѡ������Ҫʹ�õĲ�ѯ��ʽ:");
    scanf("%d",&target);
    switch (target)
    {
    case 1:
        queryByCredit();
        printf("\n");
        menu();
        break;
    case 2:
        queryByProperty();
        printf("\n");
        menu();
        break;
    default:
        printf("����ȷ����\n");
        queryCourseInfo();
    }
}
void queryByCredit(){
    printf("����������Ҫ��ѯ��ѧ����:");
    int target;
    scanf("%d",&target);
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    int id = courseInfo[0].course_id;
    int i=0;
    printf("id �γ��� �γ����� ѧ�� ��ѧʱ �ڿ�ѧʱ ʵ��ѧʱ ѧ��\n");
    while(id != -1){
        if(courseInfo[i].course_credit == target){
            printf("%d %s %s %d %d %d %d %d",courseInfo[i].course_id,
            courseInfo[i].course_name,
            courseInfo[i].course_property,
            courseInfo[i].course_credit,
            courseInfo[i].course_totalHour,
            courseInfo[i].course_classHour,
            courseInfo[i].course_practiceHour,
            courseInfo[i].course_term
            );
        }
        id = courseInfo[i].course_id;
        i++;
    }


}
void queryByProperty(){
    printf("����������Ҫ��ѯ�Ŀγ�����:");
    char target[50];
    scanf("%s",target);
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    int id = courseInfo[0].course_id;
    int i=0;
    printf("id �γ��� �γ����� ѧ�� ��ѧʱ �ڿ�ѧʱ ʵ��ѧʱ ѧ��\n");
    while(id != -1){
        if(strcmp(courseInfo[i].course_property,target) == 0){
            printf("%d %s %s %d %d %d %d %d\n",courseInfo[i].course_id,
            courseInfo[i].course_name,
            courseInfo[i].course_property,
            courseInfo[i].course_credit,
            courseInfo[i].course_totalHour,
            courseInfo[i].course_classHour,
            courseInfo[i].course_practiceHour,
            courseInfo[i].course_term
            );
        }
        id = courseInfo[i].course_id;
        i++;
    }
}