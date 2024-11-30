#include<stdio.h>
#include<string.h>
#include"csv.h"
#include"menu.h"

void queryCourseInfo(){
    int target;
    printf("1.按学分查找 2.按课程性质查找\n请选择你想要使用的查询方式:");
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
        printf("请正确输入\n");
        queryCourseInfo();
    }
}
void queryByCredit(){
    printf("请输入你想要查询的学分数:");
    int target;
    scanf("%d",&target);
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    int id = courseInfo[0].course_id;
    int i=0;
    printf("id 课程名 课程性质 学分 总学时 授课学时 实验学时 学期\n");
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
    printf("请输入你想要查询的课程性质:");
    char target[50];
    scanf("%s",target);
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    int id = courseInfo[0].course_id;
    int i=0;
    printf("id 课程名 课程性质 学分 总学时 授课学时 实验学时 学期\n");
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