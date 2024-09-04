#ifndef MATERIALSWAREHOUSE_H
#define MATERIALSWAREHOUSE_H

struct list
{
int id;
int name;
char idMaterials[50];
char places[50];
char idUnit[50];
int count;
} ;

struct materials
{
int id;
char Materials[50];
} ;

struct unit
{
int id;
char Unit[50];
} ;

void read();
void closefile();
void savefile();
void menu();
void vivod(int protect);
void spravochnik();
void choose();
void firopen();
void sopen();
void dispSpr();
void file();
void edit();
void mainAdd();
void mainDel();
void mainEdit();
void about();
void sprAdd();
void sprAdd1();
void sprAdd2();
void sprDel();
void sprDel1(int Edit);
void sprDel2(int Edit);
void sprEdit();
void EXPORT();
void SPpr();
#endif // MATERIALSWAREHOUSE_H
