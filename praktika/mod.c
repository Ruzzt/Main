
#include "materialswarehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

void read()
{
    FILE *in = 0, *in2 = 0;
    char buf[500];
    int i, mN = 0;
    char s[10];
    in = fopen("/home/user/dev/praktika/materialswarehouse.db","r");
    if (!in) {
        printf("\n\nERROR\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
        return file();
    }
    while(fscanf(in,"%[^\n]%*c",buf)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/materialswarehouse.db","r");
    in2 = fopen("/home/user/dev/praktika/mainf.db","w");
    for(i=0;i<mN;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nSuccessful\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    vivod(0);
    return;
}

void savefile(){
    FILE *in = 0, *in2 = 0;
    int i, mN = 0;
    char buf[100], nc[100] = {0};
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    char s[10];
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
        return file();
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    in2 = fopen("/home/user/dev/praktika/materialswarehouse.db","w");
    for(i=0;i<mN;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nFile saved\n");
    printf("write BACK to escape: ");
    scanf("%s",s);
    return;
}

void closefile(){
    FILE *in = 0;
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    char s[10];
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
    }
    else {
        printf("\n\nFile closed\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
        remove("/home/user/dev/praktika/mainf.db");
    }
    return;
}

void mainAdd(){
    FILE *in = 0;
    int id, key, materials, unit, mN = 0,count;
    char place[50];
    char nc[100]= {0};
    char s[10];
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
        return;
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/mainf.db","a+");
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write key: ");
    scanf("%d", &key);
    printf("Write material id: ");
    scanf("%d", &materials);
    printf("Write place: ");
    scanf("%s", &place);
    printf("Write unit id: ");
    scanf("%d", &unit);
    printf("Write count): ");
    scanf("%d", &count);
    fseek(in,0,SEEK_END);
    fprintf(in, "\n%d;%d;%d;%s;%d;%d;", id, key, materials, place, unit, count);// сначала переход на новую строку потом вывод
    fclose(in);
    printf("\n\nSuccessful");
    savefile();
    vivod(0);
    return;
}

void mainDel(){
    FILE *in = 0;
    int i, id, mN = 0;
    char str[100] = {0}, nc[100]= {0};
    char s[10];
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write BACK to escape: ");
        scanf("%s",s);
        return edit();
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    struct list*mainf;
    mainf = (struct list*)malloc(mN * sizeof(struct list));
    for (i = 0; i < mN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            mainf[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            mainf[i].name = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idMaterials, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].places, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idUnit, tok);
            tok = strtok(NULL, ";");
            mainf[i].count = atoi(tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    in = fopen("/home/user/dev/praktika/mainf.db","w");
    printf("\n\nWrite id to delete: ");
    scanf("%d", &id);
    for(i=0;i<mN;i++)
        if(id==mainf[i].id)
            continue;
        else
            if(i == 0)
                fprintf(in, "%d;%d;%s;%s;%s;%d;", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);//если первая строка то просто вывод
            else
                fprintf(in, "\n%d;%d;%s;%s;%s;%d;", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);//если не первая то сначала переход на новую строку потом вывод
    fclose(in);
    printf("\n\nSuccessful");
    savefile();
    vivod(0);
    return;
}

void mainEdit(){
    FILE *in = 0;
    int i, id, key, materials, unit, mN = 0,count;
    char place[50];
    char str[100] = {0}, nc[100]= {0};
    char s[10];
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    if (!in) {
        printf("\n\nERROR: file is not open\n");
        printf("write BACK to escape: ");scanf("%s",s);
        return edit();
    }
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        mN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/mainf.db","r");
    struct list *mainf;
    mainf = (struct list*)malloc(mN * sizeof(struct list));
    for (i = 0; i < mN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            mainf[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            mainf[i].name = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idMaterials, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].places, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idUnit, tok);
            tok = strtok(NULL, ";");
            mainf[i].count = atoi(tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write key: ");
    scanf("%d", &key);
    printf("Write material id: ");
    scanf("%d", &materials);
    printf("Write place: ");
    scanf("%s", &place);
    printf("Write unit id: ");
    scanf("%d", &unit);
    printf("Write count): ");
    scanf("%d", &count);
    in = fopen("/home/user/dev/praktika/mainf.db","w");
    for(i=0;i<mN;i++)
        if(id==mainf[i].id)
            if (i == 0)
                fprintf(in, "%d;%d;%d;%s;%d;%d;", id, key, materials, place, unit, count);//если первая строка то просто вывод
            else
                fprintf(in, "\n%d;%d;%d;%s;%d;%d;", id, key, materials, place, unit, count);//если не первая то сначала переход на новую строку потом вывод
        else
            if(i == 0)
                fprintf(in, "%d;%d;%s;%s;%s;%d;", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);//если первая строка то просто вывод
            else
                fprintf(in, "\n%d;%d;%s;%s;%s;%d;", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);//если не первая то сначала переход на новую строку потом вывод
    fclose(in);
    printf("\n\nSuccessful");
    savefile();
    vivod(0);
    return;
}

void vivod(int protect)
{
    FILE *in = 0, *in2 = 0, *in3 = 0;
    int lN = 0, nN = 0, pN = 0, tN = 0;
    char nc[100] = { 0 };
    in = fopen("/home/user/dev/praktika/materialswarehouse.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        lN++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/materialswarehouse.db","r");
    in2 = fopen("/home/user/dev/praktika/materials.db","r");
    while(fscanf(in2, "%[^\n]%*c", nc)!=EOF)
        nN++;
    fclose(in2);
    in2 = fopen("/home/user/dev/praktika/materials.db","r");
    in3 = fopen("/home/user/dev/praktika/unit.db","r");
    while(fscanf(in3,"%[^\n]%*c",nc)!=EOF)
        pN++;
    fclose(in3);
    in3 = fopen("/home/user/dev/praktika/unit.db","r");
    struct list *mainf;
    mainf = (struct list*)malloc(lN * sizeof(struct list));
    int i, j, k;
    char str[100] = { 0 };
    for (i = 0; i < lN; i++) {
        fscanf(in,"%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            mainf[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            mainf[i].name = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idMaterials, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].places, tok);
            tok = strtok(NULL, ";");
            strcpy(mainf[i].idUnit, tok);
            tok = strtok(NULL, ";");
            mainf[i].count = atoi(tok);
            tok = strtok(NULL, ";");
        }
    }
    struct materials *sprav;
    sprav = (struct materials*)malloc(nN * sizeof(struct materials));
    for (i = 0; i < nN; i++) {
        fscanf(in2, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].Materials, tok);
            tok = strtok(NULL, ";");
        }
    }
    struct unit *md;
    md = (struct unit*)malloc(pN * sizeof(struct unit));
    for (i = 0; i < pN; i++) {
        fscanf(in3,"%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            md[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(md[i].Unit, tok);
            tok = strtok(NULL, ";");
        }
    }

    if(protect == 1){
        FILE *EXPORTTXT = 0;
        EXPORTTXT = fopen("/home/user/dev/praktika/EXPORT.txt","w");
        fprintf(EXPORTTXT, "--------------------------------------------------------------------\n");
        for (i=0;i<lN;i++){
            for (j=0;j<nN;j++)
                if (sprav[j].id==atoi(mainf[i].idMaterials))
                    strcpy(mainf[i].idMaterials,sprav[j].Materials);
            for (k=0;k<pN;k++)
                if (atoi(mainf[i].idUnit)==md[k].id)
                    strcpy(mainf[i].idUnit,md[k].Unit);

            fprintf(EXPORTTXT, "%-5d%-5d%-25s%-20s%-10s%-8.2d\n", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);
        }
        fprintf(EXPORTTXT, "--------------------------------------------------------------------\n");
        fclose(EXPORTTXT);
        printf("Export was succsessful");
        printf("\nwrite BACK to escape: ");
        char s[10];
        scanf("%s",s);
        protect = 0;
        return;
    }
    system("clear");
    for(i=0;i<100;i++)
        str[i]=' ';
    for(i=0;i<100;i++)
        nc[i]=' ';
    printf("--------------------------------------------------------------------\n");
    for (i=0;i<lN;i++){
        for (j=0;j<nN;j++)
            if (sprav[j].id==atoi(mainf[i].idMaterials))
                strcpy(mainf[i].idMaterials,sprav[j].Materials);
        for (k=0;k<pN;k++)
            if (atoi(mainf[i].idUnit)==md[k].id)
                strcpy(mainf[i].idUnit,md[k].Unit);

        printf("%-5d%-5d%-25s%-20s%-10s%-8.2d\n", mainf[i].id, mainf[i].name, mainf[i].idMaterials, mainf[i].places, mainf[i].idUnit, mainf[i].count);
    }
    printf("--------------------------------------------------------------------\n");
    printf("\n\nwrite BACK to escape: ");
    char s[10];
    scanf("%s",s);
    return;
}

void EXPORT(){
    int protect = 1;
    vivod(protect);
}

void firopen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/user/dev/praktika/materials.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in, "%[^\n]%*c", str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/materials.db","r");
    in2 = fopen("/home/user/dev/praktika/sprav.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nFile opened\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    dispSpr();
    return;
}

void sopen(){
    FILE *in = 0, *in2 = 0;
    int i = 0;
    char buf[500];
    in = fopen("/home/user/dev/praktika/unit.db","r");
    int NC=0;
    char str[50] = { 0 };
    while(fscanf(in,"%[^\n]%*c",str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/unit.db","r");
    in2 = fopen("/home/user/dev/praktika/sprav.db","w");
    for(i=0;i<NC;i++)
        fputs(fgets(buf,499,in),in2);
    fclose(in);
    fclose(in2);
    printf("\n\nFile opened\n");
    printf("write SHOW to show file: ");
    char z[5];
    scanf("%s",z);
    dispSpr();
    return;
}


void dispSpr(){
    system("clear");
    FILE *in =0;
    in = fopen("/home/user/dev/praktika/sprav.db","r");
    if (!in){
        printf("\n\nFile is not opened");
        return;
    }
    int NC=0;
    char str[100] = { 0 };
    while(fscanf(in, "%[^\n]%*c", str)!=EOF)
        NC++;
    fclose(in);
    in = fopen("/home/user/dev/praktika/sprav.db","r");
    struct materials *sprav;
    sprav = (struct materials*)malloc(NC * sizeof(struct materials));
    int i;
    for (i = 0; i < NC; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].Materials, tok);
            tok = strtok(NULL, ";");
        }
    }
    for(i=0;i<NC;i++)
        printf("%-3d %-20s\n", sprav[i].id, sprav[i].Materials);
    printf("\n\nwrite BACK to escape: ");
    char su[10];
    scanf("%s",su);
    return;
}

void sprAdd1(){
    FILE *in = 0;
    char z[5];
    int id;
    char zap[20];
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write info: ");
    scanf("%*c%[^\n]", zap);
    in = fopen("/home/user/dev/praktika/materials.db","a+");
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;\n", id, zap);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    scanf("%s",z);
    return;
}

void sprAdd2(){
    FILE *in = 0;
    char z[5];
    int id;
    char zap[20];
    printf("\n\nWrite id: ");
    scanf("%d", &id);
    printf("Write info: ");
    scanf("%*c%[^\n]", zap);
    in = fopen("/home/user/dev/praktika/unit.db","a+");
    fseek(in,0,SEEK_END);
    fprintf(in, "%d;%s;\n", id, zap);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    scanf("%s",z);
    return;
}


void sprDel1(int Edit){
    FILE *in = 0;
    int i, k = 0;
    struct materials *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in = fopen("/home/user/dev/praktika/materials.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    sprav = (struct materials*)malloc(nN * sizeof(struct materials));
    in = fopen("/home/user/dev/praktika/materials.db","r");
    for (i = 0; i < nN; i++) {
        fscanf(in, "%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].Materials, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    char zap[20];
    if(Edit == 1){
        printf("\n\nWrite id: ");
        scanf("%d", &k);
        printf("Write info: ");
        scanf("%*c%[^\n]", zap);
    }
    else{
        printf("\n\nWrite id to delete: ");
        scanf("%d", &k);
    }
    in = fopen("/home/user/dev/praktika/materials.db","w");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id){
            if (Edit == 1){
                fprintf(in, "%d;%s;\n", k, zap);
            }
            else
                continue;
        }
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].Materials);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}

void sprDel2(int Edit){
    FILE *in = 0;
    int i, k = 0;
    struct materials *sprav;
    int nN = 0;
    char nc[50] = { 0 };
    char str[100] = { 0 };
    in = fopen("/home/user/dev/praktika/unit.db","r");
    while(fscanf(in,"%[^\n]%*c",nc)!=EOF)
        nN++;
    fclose(in);
    sprav = (struct materials*)malloc(nN * sizeof(struct materials));
    in = fopen("/home/user/dev/praktika/unit.db","r");
    for (i = 0; i < nN; i++) {
        fscanf(in,"%[^\n]%*c", str);
        char *tok = strtok(str, ";");
        while (tok!=NULL) {
            sprav[i].id = atoi(tok);
            tok = strtok(NULL, ";");
            strcpy(sprav[i].Materials, tok);
            tok = strtok(NULL, ";");
        }
    }
    fclose(in);
    char zap[20];
    if(Edit == 1){
        printf("\n\nWrite id to Edit: ");
        scanf("%d", &k);
        printf("Write info: ");
        scanf("%*c%[^\n]", zap);
    }
    else{
        printf("\n\nWrite id to delete: ");
        scanf("%d", &k);
    }
    in = fopen("/home/user/dev/praktika/unit.db","w");
    for(i=0;i<nN;i++)
        if(k==sprav[i].id){
            if (Edit == 1){
                fprintf(in, "%d;%s;\n", k, zap);
            }
            else
                continue;
        }
        else
            fprintf(in, "%d;%s;\n", sprav[i].id, sprav[i].Materials);
    fclose(in);
    printf("\n\nSuccessful\n");
    printf("write BACK to escape: ");
    char z[5];
    scanf("%s",z);
    return;
}
