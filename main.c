#include <stdio.h>
#include <string.h>
#include "book.h"
#include "student.h"
#include "employee.h"
const char admin[16]="ADMIN";
const int pin=1234;
int main(){
    printf("--------------------------------------------------------WELCOME TO LIBRARY--------------------------------------------------------\n");
    printf("Login interface\n");
    int login;
    printf("Enter 1 for Student and 0 for Staff:");
    if (scanf("%d",&login) != 1) return 0;
    if(login==1){
        int id; int flag=0;
        printf("Enter your student id:");
        if (scanf("%d",&id) != 1) return 0;
        Student_detail(id,&flag);
        if(flag){
            printf("You can perform the following tasks\n1 to issue book\n2 to return book\n3 to all book list\n4 to view detail for particular book\n0 to exit\n");
            int terminator =1;
            while(terminator){
                int choice;
                printf("What you want to do:");
                if (scanf("%d", &choice) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (choice==1){
                    int serial; int bflag=0;
                    printf("Enter the serial number of the book:");
                    if (scanf("%d",&serial) != 1) { while(getchar()!='\n'); continue; }
                    book_detail(serial,&bflag);
                    if(bflag==1){
                        /* book available */
                        student_issue(id,serial);
                        issue_book(serial);
                        printf("Book issued successful\n");
                    }
                    else if(bflag==2){
                        printf("Book is currently not available\n");
                    }
                    else{
                        printf("no such book available\n");
                    }
                }
                else if(choice==2){
                    int serial; int bflag=0;
                    printf("Enter the serial number of the book:");
                    if (scanf("%d",&serial) != 1) { while(getchar()!='\n'); continue; }
                    book_detail(serial,&bflag);
                    if(bflag==2){
                        /* book currently not available -> can be returned */
                        student_return(id,serial);
                        return_book(serial);
                        printf("Book returned successful\n");
                    }
                    else if(bflag==1){
                        printf("This book is not issued currently\n");
                    }
                    else{
                        printf("no such book was part of library\n");
                    }
                }
                else if(choice==3){
                    printf("All this book belong to library\n");
                    display_book_list();
                }
                else if(choice==4){
                    int serial;int bflag=0;
                    printf("Enter the serial number of the book:");
                    if (scanf("%d",&serial) != 1) { while(getchar()!='\n'); continue; }
                    book_detail(serial,&bflag);
                    if(bflag){
                        printf("Displayed book detail  successful\n");
                    }
                    else{
                        printf("no such book was part of library\n");
                    }
                }
                else if(choice==0){
                    terminator=0;
                }
                else{
                    printf("Enter the correct input\n");
                }
            }
        }
        else{
            printf("Student data not available");
        }
    }
    else if(login==0){
        int login1;
        printf("Enter 0 for admin and 1 for employee:");
        if (scanf("%d",&login1) != 1) return 0;
        if(login1==0){
            char user[16];int password;
            printf("Enter the user name:");
            scanf("%s",user);
            printf("Enter the password:");
            scanf("%d",&password);
            if ((strcmp(user, admin) == 0) && (password == pin)){
                printf("Task you can perform\n1 to add employee\n2 to remove employee\n3 to view employee list\n4 to view detail for particular employee\n0 to exit\n");
                int terminator=1;
                while(terminator){
                    int choice;
                    printf("What you want to do:");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input! Please enter a number.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (choice==1){
                        int id;char name[20];
                        printf("Enter the employee id:");
                        scanf("%d",&id);
                        printf("Enter the employee name:");
                        scanf(" %[^\n]",name);
                        add_employee(id,name);
                        printf("Employee added successfully\n");
                    }
                    else if(choice==2){
                        int id;
                        printf("Enter the employee id:");
                        scanf("%d",&id);
                        remove_employee(id);
                        printf("Employee removed successfully\n");
                    }
                    else if(choice==3){
                        display_employee_list();
                        printf("Employee list displayed successfully\n");
                    }
                    else if(choice==4){
                        int id;int flag=0;
                        printf("Enter the id of that employee:");
                        scanf("%d",&id);
                        employee_detail(id,&flag);
                        if(flag){
                            printf("Employee detail display successfully\n");
                        }
                        else{
                            printf("No such detail available\n");
                        }
                    }
                    else if(choice==0){
                        terminator=0;
                    }
                    else{
                        printf("Enter the correct input\n");
                    }
                }
            } else {
                printf("Invalid admin credentials.\n");
            }
        }
        else if(login1==1){
            int id;int flag=0;
            printf("Enter your employee id:");
            if (scanf("%d",&id) != 1) return 0;
            employee_detail(id,&flag);
            if (flag){
                printf("Task you can perform\n1 to add student\n2 to remove student\n3 to view students list\n4 to view  detail of particular student\n5 to add book\n6 to remove book\n7 to view book list\n8 to view detail of particular book\n0 to exit\n");
                int terminator=1;
                while(terminator){
                    int choice;
                    printf("What you want to do:");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input! Please enter a number.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (choice==1){
                        int id;char name[20];
                        printf("Enter the student id:");
                        scanf("%d",&id);
                        printf("Enter the student name:");
                        scanf(" %[^\n]",name);
                        add_Student(id,name);
                        printf("Student detail added successfully\n");
                    }
                    else if(choice==2){
                        int id;
                        printf("Enter the student id:");
                        scanf("%d",&id);
                        remove_Student(id);
                        printf("student removed successfully\n");
                    }
                    else if(choice==3){
                        display_Student_list();
                        printf("student list display successfully\n");
                    }
                    else if(choice==4){
                        int id;int flag=0;
                        printf("Enter the student id:");
                        scanf("%d",&id);
                        Student_detail(id,&flag);
                        if (flag){
                             printf("Student detail displayed successfully\n");
                        }
                        else{
                            printf("Student detail is not available\n");
                        }
                    }
                    else if(choice==5){
                        int serial;char name[20];
                        printf("Enter the serial number of the book:");
                        scanf("%d",&serial);
                        printf("Enter the book name:");
                        scanf(" %[^\n]",name);
                        add_book(serial,name);
                        printf("Book added successfully\n");
                    }
                    else if(choice==6){
                        int serial;
                        printf("Enter the serial number of book:");
                        scanf("%d",&serial);
                        remove_book(serial);
                        printf("book removed successfully\n");
                    }
                    else if(choice==7){
                        display_book_list();
                        printf("Book list displayed successfully\n");
                    }
                    else if(choice==8){
                        int serial;int bflag=0;
                        printf("Enter the serial number of book:");
                        scanf("%d",&serial);
                        book_detail(serial,&bflag);
                        if(bflag){
                            printf("Book detail displayed successfully\n");
                        }
                        else{
                            printf("Book detail not available\n");
                        }
                    }
                    else if(choice==0){
                        terminator=0;
                    }
                    else{
                        printf("Enter correct input\n");
                    }
                }
            }  
            else{
                printf("Employee detail is not available\n");
            }  
        }
    }
    return 0;
}
