//zhangjinpeng
#include<stdio.h>
#include"csv.h"
#include"menu.h"
void inputCourseSources(){
    struct course course_Info;
    int i;
    while(i<=MAX_VALUE){
    printf("请输入课程信息\n");
    printf("课程id:(返回主页请输入-1)");
    scanf("%d",&course_Info.course_id);
    if(course_Info.course_id==-1){
        menu();
        break;
    }
    printf("课程名:");
    scanf("%s",course_Info.course_name);
    printf("课程性质:");
    scanf("%s",course_Info.course_property);
    printf("学分:");
    scanf("%d",&course_Info.course_credit);
    printf("总学时:");
    scanf("%d",&course_Info.course_totalHour);
    printf("授课时长:");
    scanf("%d",&course_Info.course_classHour);
    printf("实验时长:");
    scanf("%d",&course_Info.course_practiceHour);
    printf("开课学期:");
    scanf("%d",&course_Info.course_term);
    writeCourseInfo(course_Info);
    i++;
    }
    printf("\n");
    menu();
}