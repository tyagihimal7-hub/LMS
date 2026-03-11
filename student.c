#include <stdio.h>
#include <string.h>
typedef struct student{
    int student_id;
    char student_name[20];
    char book[20];
    int book_serial;
}student;
void add_Student(int id,char name[20]);
void display_Student_list();
void remove_Student(int id);
void Student_detail(int id,int *flag);
void student_issue(int id1,int serial);
void student_return(int id1,int serial);
void add_Student(int id,char name[20]){
    student s;
    s.student_id=id;
    strcpy(s.student_name,name);
    strcpy(s.book,"No Book");
    s.book_serial=0;
    FILE *f1=fopen("Student.dat","ab");
    if(f1){
        fwrite(&s,sizeof(student),1,f1);
        fclose(f1);
    }
}
void display_Student_list(){
    FILE *f1=fopen("Student.dat","rb");
    student s;
    if(!f1){
        printf("No student records found.\n");
        return;
    }
    printf("Student id\tStudent name\tBook\t\tBook serial no\n");
    while(fread(&s,sizeof(student),1,f1)){
        printf("%d\t\t%s\t\t%s\t\t%d\n",s.student_id,s.student_name,s.book,s.book_serial);
    }
    fclose(f1);
}
void remove_Student(int id){
    FILE *f1=fopen("Student.dat","rb");
    FILE *f2=fopen("temp1.dat","wb");
    student s;
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(student),1,f1)){
        if(s.student_id!=id){
            fwrite(&s,sizeof(student),1,f2);
        }
    }

    fclose(f1);
    fclose(f2);
    remove("Student.dat");
    rename("temp1.dat","Student.dat");
}
void Student_detail(int id,int *flag){
    FILE *f=fopen("Student.dat","rb");
    student s;
    *flag = 0;
    if(!f) return;
    while(fread(&s,sizeof(student),1,f)){
        if(s.student_id==id){
            printf("Student id:%d\nStudent name:%s\t%s\n",s.student_id,s.student_name,s.book);
            *flag=1;
            break;
        }
    }
    fclose(f);
}
void student_issue(int id1,int serial){
    FILE *f1=fopen("Student.dat","rb");
    FILE *f2=fopen("temp1.dat","wb");
    student s;
    
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(student),1,f1)){
        if(id1!=s.student_id){
            fwrite(&s,sizeof(student),1,f2);
        }
        else{
            student s1;
            s1.student_id=id1;
            strcpy(s1.student_name,s.student_name);
            s1.book_serial=serial;
            strcpy(s1.book,"own book");
            fwrite(&s1,sizeof(student),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("Student.dat");
    rename("temp1.dat","Student.dat");
}
void student_return(int id1,int serial){
    FILE *f1=fopen("Student.dat","rb");
    FILE *f2=fopen("temp1.dat","wb");
    student s;
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(student),1,f1)){
        if(id1!=s.student_id){
            fwrite(&s,sizeof(student),1,f2);
        }
        else{
            student s1;
            s1.book_serial=0;
            s1.student_id=id1;
            strcpy(s1.student_name,s.student_name);
            strcpy(s1.book,"NO book");
            fwrite(&s1,sizeof(student),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("Student.dat");
    rename("temp1.dat","Student.dat");
}
