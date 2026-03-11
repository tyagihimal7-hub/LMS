#include <stdio.h>
#include <string.h>
typedef struct employee{
    int employee_id;
    char employee_name[20];
}employee;
void add_employee(int id,char name[20]);
void display_employee_list();
void remove_employee(int id);
void employee_detail(int id,int *flag);
void add_employee(int id,char name[20]){
    employee s;
    s.employee_id=id;
    strcpy(s.employee_name,name);
    FILE *f1=fopen("emp.dat","ab");
    fwrite(&s,sizeof(employee),1,f1);
    fclose(f1);
}
void display_employee_list(){
    FILE *f1=fopen("emp.dat","rb");
    employee s;
    printf("Employee id\tEmployee name\n");
    while(fread(&s,sizeof(employee),1,f1)){
        printf("%d\t\t%s\n",s.employee_id,s.employee_name);
    }
    fclose(f1);
}
void remove_employee(int id){
    FILE *f1=fopen("emp.dat","rb");
    FILE *f2=fopen("temp2.dat","wb");
    employee s;
    while(fread(&s,sizeof(employee),1,f1)){
        if(s.employee_id!=id){
            fwrite(&s,sizeof(employee),1,f2);
        }
    }

    fclose(f1);
    fclose(f2);
    remove("emp.dat");
    rename("temp2.dat","emp.dat");
}
void employee_detail(int id,int *flag){
    FILE *f=fopen("emp.dat","rb");
    employee s;
    while(fread(&s,sizeof(employee),1,f)){
        if(s.employee_id==id){
            printf("Employee id:%d\nEmployee name:%s\n",s.employee_id,s.employee_name);
            *flag=1;
        }
    }
    fclose(f);
}
