#include <stdio.h>
#include <stdlib.h>
#include "materialswarehouse.h"

int main()
{
    menu();
    return 0;
}

void menu()
{
    while(1){
        system("clear");
        printf("1. File\n");
        printf("2. Edit file\n");
        printf("3. Display file\n");
        printf("4. Export file to TXT\n");
        printf("5. Directory\n");
        printf("6. About programm\n");
        printf("7. Exit\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': file();break;
            case '2': edit(); break;
            case '3': vivod(0); break;
            case '4': EXPORT(); break;
            case '5': spravochnik(); break;
            case '6': about(); break;
            case '7': exit(0);
        }
    }
}

void file()
{
    while(1) {
        system("clear");
        printf("1. Open\n");
        printf("2. Save\n");
        printf("3. Close\n");
        printf("4. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': read(); break;
            case '2': savefile(); break;
            case '3': closefile(); break;
            case '4': return;
        }
    }
}

void edit()
{
    while(1){
        system("clear");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Edit\n");
        printf("4. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': mainAdd(); break;
            case '2': mainDel(); break;
            case '3': mainEdit(); break;
            case '4': return;
        }
    }
}

void spravochnik(){
    while(1){
        system("clear");
        printf("1. Choose\n");
        printf("2. Display\n");
        printf("3. Edit\n");
        printf("4. Add\n");
        printf("5. Delete\n");
        printf("6. Back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': choose(); break;
            case '2': dispSpr(); break;
            case '3': sprEdit(); break;
            case '4': sprAdd(); break;
            case '5': sprDel(); break;
            case '6': remove("/home/user/dev/praktika/sprav.db"); return;
        }
    }
}

void choose(){
    while(1){
        system("clear");
        printf("1. materials.db\n");
        printf("2. unit.db\n");
        printf("3. back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': firopen(); break;
            case '2': sopen(); break;
            case '3': return;
        }
    }
}

void sprAdd(){
    while(1){
        system("clear");
        printf("1. materials.db\n");
        printf("2. unit.db\n");
        printf("3. back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': sprAdd1(); break;
            case '2': sprAdd2(); break;
            case '3': return;
        }
    }
}

void sprDel(){
    while(1){
        system("clear");
        printf("1. materials.db\n");
        printf("2. unit.db\n");
        printf("3. back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': sprDel1(0); break;
            case '2': sprDel2(0); break;
            case '3': return;
        }
    }
}

void sprEdit(){
    while(1){
        system("clear");
        printf("1. materials.db\n");
        printf("2. unit.db\n");
        printf("3. back\n");
        printf("\nChoose: ");
        int ch = 0;
        ch = getchar();
        printf("\n");
        switch (ch) {
            case '1': sprDel1(1); break;
            case '2': sprDel2(1); break;
            case '3': return;
        }
    }
}


void about()
{
    printf("\n\n\nDevelopment of a program for working with lists of materials stored in a warehouse");
    printf("\nDeveloped by student of ICTMS 1-4");
    printf("\nRuzavina Tatyana, 2023 year");
    printf("\n\nwrite BACK to escape: ");
    char s[10];
    scanf("%s",s);
    return;
}
