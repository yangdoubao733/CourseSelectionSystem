#include<stdio.h>
#include "csv.h"
#include"menu.h"
void displayCourseSources()
{
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    printf("id 课程名称 课程性质 学分 总学时 教学课时 实践课时 学期\n");
    while (1)
    {
        
        int i=0;
        if (courseInfo[i].course_id==-1)
        {
            break;
        }
        printf("%d %s %s %d %d %d\n", courseInfo[i].course_id, 
        courseInfo[i].course_name,
        courseInfo[i].course_property, 
        courseInfo[i].course_credit,
        courseInfo[i].course_totalHour,
        courseInfo[i].course_classHour,
        courseInfo[i].course_practiceHour,
        courseInfo[i].course_term);
        i++;
    }
    menu();
    
}