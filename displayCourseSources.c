#include<stdio.h>
#include "csv.h"
#include"menu.h"
void displayCourseSources()
{
    struct course courseInfo[MAX_VALUE];
    readCourseInfo(courseInfo);
    printf("id �γ��� �γ����� ѧ�� ��ѧʱ �ڿ�ѧʱ ʵ��ѧʱ ѧ��\n");
    int i=0;
    while (1)
    {
        
        
        if (courseInfo[i].course_id==-1)
        {
            break;
        }
        printf("%d %s %s %d %d %d %d %d\n", courseInfo[i].course_id, 
        courseInfo[i].course_name,
        courseInfo[i].course_property, 
        courseInfo[i].course_credit,
        courseInfo[i].course_totalHour,
        courseInfo[i].course_classHour,
        courseInfo[i].course_practiceHour,
        courseInfo[i].course_term);
        i++;
    }
    printf("\n");
    menu();
    
}