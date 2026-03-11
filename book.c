#include <stdio.h>
#include <string.h>
typedef struct book_storage{
    int serial_no;
    char book_name[100];
    char Availability[100];
}book_storage;
void add_book(int serial,char book_name[20]);
void display_book_list();
void remove_book(int serial);
void book_detail(int serial,int *flag);
void issue_book(int serial);
void return_book(int serial);
void add_book(int serial,char book_name1[20]){
    book_storage s;
    s.serial_no=serial;
    strcpy(s.book_name,book_name1);
    strcpy(s.Availability,"available");
    FILE *f1=fopen("book.dat","ab");
    if(f1){
        fwrite(&s,sizeof(book_storage),1,f1);
        fclose(f1);
    }
}
void display_book_list(){
    FILE *f1=fopen("book.dat","rb");
    book_storage s;
    if(!f1){
        printf("No book records found.\n");
        return;
    }
    printf("Serial no\tbook name\tAvailability\n");
    while(fread(&s,sizeof(book_storage),1,f1)){
        printf("%d\t\t%s\t\t%s\n",s.serial_no,s.book_name,s.Availability);
    }
    fclose(f1);
}
void remove_book(int serial){
    FILE *f1=fopen("book.dat","rb");
    FILE *f2=fopen("temp.dat","wb");
    book_storage s;
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(book_storage),1,f1)){
        if(s.serial_no!=serial){
            fwrite(&s,sizeof(book_storage),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("book.dat");
    rename("temp.dat", "book.dat");
}
/*
 * book_detail semantics :
 *  *flag = 0 -> no such book
 *  *flag = 1 -> book found AND available
 *  *flag = 2 -> book found BUT not available
 */
void book_detail(int serial,int *flag){
    *flag = 0;
    FILE *f=fopen("book.dat","rb");
    book_storage s;
    if(!f) return;
    while(fread(&s,sizeof(book_storage),1,f)){
        if(s.serial_no==serial){
            printf("Serial no:%d\nBook name:%s\t%s\n",s.serial_no,s.book_name,s.Availability);
            if(strcmp(s.Availability,"available")==0){
                *flag = 1;
            } else {
                *flag = 2;
            }
            break;
        }
    }
    fclose(f);
}
void issue_book(int serial){
    FILE *f1=fopen("book.dat","rb");
    FILE *f2=fopen("temp.dat","wb");
    book_storage s;
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(book_storage),1,f1)){
        if(serial!=s.serial_no){
            fwrite(&s,sizeof(book_storage),1,f2);
        }
        else{
            book_storage s1;
            s1.serial_no=serial;
            strcpy(s1.book_name,s.book_name);
            strcpy(s1.Availability,"Not available");
            fwrite(&s1,sizeof(book_storage),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("book.dat");
    rename("temp.dat","book.dat");
}
void return_book(int serial){
    FILE *f1=fopen("book.dat","rb");
    FILE *f2=fopen("temp.dat","wb");
    book_storage s;
    if(!f1 || !f2){
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        return;
    }
    while(fread(&s,sizeof(book_storage),1,f1)){
        if(serial!=s.serial_no){
            fwrite(&s,sizeof(book_storage),1,f2);
        }
        else{
            book_storage s1;
            s1.serial_no=serial;
            strcpy(s1.book_name,s.book_name);
            strcpy(s1.Availability,"available");
            fwrite(&s1,sizeof(book_storage),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("book.dat");
    rename("temp.dat","book.dat");
}

