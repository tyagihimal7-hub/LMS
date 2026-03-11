#ifndef BOOK_H
#define BOOK_H
void add_book(int serial,char book_name[20]);
void display_book_list();
void remove_book(int serial);
void book_detail(int serial,int *flag);
void issue_book(int serial);
void return_book(int serial);
#endif