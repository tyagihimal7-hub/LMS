#ifndef STUDENT_H
#define STUDENT_H
void add_Student(int id,char name[20]);
void display_Student_list();
void remove_Student(int id);
void Student_detail(int id,int *flag);
void student_issue(int id1,int serial);
void student_return(int id1,int serial);
#endif