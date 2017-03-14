#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

struct student//学生结构体
{
    int id;
    char name[20];
    float score;
    struct student *next;
};


struct student *head = NULL;

struct student *insert(struct student *head);

void manage1();

void Sleep(int minsecond);


void Sleep(int minsecond) {
    sleep((unsigned int) (minsecond / 1000));
}

char getch() {
    char c;
    system("stty -echo");
    system("stty -icanon");
    c = (char) getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}


int cont;//全局变量，计数


int is_exist(int num) {
    int i;
    struct student *p;
    p = head;
    for (i = 0; i < cont && p != NULL; i++) {
        if (p->id == num)
            return 1;
        p = p->next;
    }
    return 0;
}

int substring(char str[], char substr[]) {
    char *p = str, *q = substr;
    int flag = 0;
    for (; *(p + strlen(substr) - 1); p++) {
        for (q = substr; *p == *q && *q; p++, q++);
        if (!*q) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        return 1;
    } else {
        return 0;
    }
}

struct student *input()//录入信息函数
{
    int test;
    struct student *p, *Old = NULL, *New;
    if (head != NULL) {
        p = head;
        while (p->next != NULL)
            p = p->next;
        for (test = 0;; test++) {
            New = (struct student *) malloc(sizeof(struct student));
            printf("请输入学号,姓名,linux课成绩(用空格隔开),输入0表示结束:");
            scanf("%d%s%f", &New->id, New->name, &New->score);
            if (is_exist(New->id) == 0) {
                if (New->id == 0)
                    break;
                else {
                    New->next = NULL;
                    p->next = New;
                    p = New;
                    cont++;
                }
            } else {
                printf("学号重复，录入失败,请重新录入\n");
                test--;
                continue;
            }
        }
    } else {
        test = 0;
        New = (struct student *) malloc(sizeof(struct student));
        printf("请输入学号,姓名,linux课成绩(用空格隔开):");
        scanf("%d%s%f", &New->id, New->name, &New->score);
        while (New->id != 0) {
            test++;
            cont++;
            if (cont == 1) {
                New->next = NULL;
                Old = New;
                head = New;
            } else {
                New->next = NULL;
                Old->next = New;
                Old = New;
            }
            New = (struct student *) malloc(sizeof(struct student));
            while (1) {
                printf("请输入学号,姓名,linux课成绩(用空格隔开):");
                scanf("%d%s%f", &New->id, New->name, &New->score);
                if (is_exist(New->id) == 0)
                    break;
                else
                    printf("学号重复，录入失败，请重新输入！\n");
            }
        }
    }
    free(New);
    printf("%d条信息录入成功！\n", test);
    Sleep(1000);
    system("clear");
    return head;
}

//头部插入单个
struct student *insert11(struct student *head) {
    struct student *New;
    New = (struct student *) malloc(sizeof(struct student));
    while (1) {
        printf("请输入学号,姓名,linux课成绩(用空格隔开):");
        scanf("%d%s%f", &New->id, New->name, &New->score);
        if (is_exist(New->id) == 0) {
            break;
        } else {
            printf("学号重复，请重新输入！\n");
        }
    }
    New->next = head;
    head = New;
    cont++;
    printf("插入成功\n");
    Sleep(1000);
    return head;
}

//头部插入多个
struct student *insert12(struct student *head) {
    int i;
    struct student *Old, *New;
    for (i = 0;; i++) {
        Old = head;
        New = (struct student *) malloc(sizeof(struct student));
        while (1) {
            printf("请输入学号,姓名,linux课成绩(用空格隔开):");
            scanf("%d%s%f", &New->id, New->name, &New->score);
            if (is_exist(New->id) == 0) {
                break;
            } else {
                printf("学号重复，请重新输入！\n");
            }
        }
        if (New->id != 0) {
            New->next = Old;
            head = New;
            cont++;
        } else {
            break;
        }
    }
    printf("插入成功\n");
    Sleep(1000);
    return head;
}

//插入方法一，随机插入
struct student *insert21(struct student *head) {
    int judge = 0, num;
    struct student *New, *p;
    p = head;
    printf(" 请输入你要插入的前一个学生的学号：");
    scanf("%d", &num);
    while (p != NULL) {
        if (p->id == num) {
            judge = 1;
            break;
        }
        p = p->next;
    }
    p = head;
    if (judge == 1) {
        while (p->id != num)
            p = p->next;
        New = (struct student *) malloc(sizeof(struct student));
        while (1) {
            printf("请输入学号,姓名,linux课成绩(用空格隔开):");
            scanf("%d%s%f", &New->id, New->name, &New->score);
            if (is_exist(New->id) == 0)
                break;
            else
                printf("学号重复，请重新输入！\n");
        }
        New->next = p->next;
        p->next = New;
        cont++;
        printf("插入成功\n");
        Sleep(1000);
    } else
        printf("Not Found:%d\n", num);
    printf("Press Any Key To Continue.......");
    getch();
    system("clear");
    return head;
}

struct student *insert22(struct student *head) {
    int j = 0, judge = 0, test = 0, num;
    struct student *New, *p;
    p = head;
    printf(" 请输入你要插入的前一个学生的学号：");
    scanf("%d", &num);
    while (p != NULL) {
        if (p->id == num) {
            judge = 1;
            break;
        }
        p = p->next;
    }
    p = head;
    do {
        if (judge == 1) {
            while (p->id != num)
                p = p->next;
            for (j = 0;; j++) {
                New = (struct student *) malloc(sizeof(struct student));
                while (1) {
                    printf("请输入学号,姓名,linux课成绩(用空格隔开):");
                    scanf("%d%s%f", &New->id, New->name, &New->score);
                    if (is_exist(New->id) == 0)
                        break;
                    else
                        printf("学号重复，请重新输入！\n");
                }
                if (New->id == 0) {
                    test = 1;
                    break;
                } else {
                    New->next = p->next;
                    p->next = New;
                    p = New;
                    cont++;
                }
            }
        } else {
            printf("Not Found:%d\n", num);
            test = 1;
        }
    } while (test == 0);
    printf("%d条信息插入成功\n", j);
    printf("Press Any Key To Continue.......");
    getch();
    system("clear");
    return head;
}

struct student *insert31(struct student *head)//插入方法二，末尾插入
{
    struct student *New, *p;
    p = head;
    while (p->next != NULL)
        p = p->next;
    New = (struct student *) malloc(sizeof(struct student));
    while (1) {
        printf("请输入学号,姓名,linux课成绩(用空格隔开):");
        scanf("%d%s%f", &New->id, New->name, &New->score);
        if (is_exist(New->id) == 0)
            break;
        else
            printf("学号重复，请重新输入！\n");
    }
    New->next = NULL;
    p->next = New;
    cont++;
    printf("插入成功\n");
    printf("Press Any Key To Continue.......");
    getch();
    system("clear");
    return head;
}

struct student *insert32(struct student *head) {
    int test;
    struct student *New, *p;
    p = head;
    while (p->next != NULL)
        p = p->next;
    for (test = 0;; test++) {
        New = (struct student *) malloc(sizeof(struct student));
        while (1) {
            printf("请输入学号,姓名,linux课成绩(用空格隔开):");
            scanf("%d%s%f", &New->id, New->name, &New->score);
            if (is_exist(New->id) == 0)
                break;
            else
                printf("学号重复，请重新输入！\n");
        }
        if (New->id == 0)
            break;
        else {
            New->next = NULL;
            p->next = New;
            p = New;
            cont++;
        }
    }
    printf("%d条信息插入成功\n", test);
    printf("Press Any Key To Continue.......");
    getch();
    system("clear");
    return head;
}

struct student *insert1(struct student *head) {
    int num, test;
    do {
        test = 0;
        printf("*************************************************************\n");
        Sleep(100);
        printf("**********+           ***首部插入***             +***********\n");
        Sleep(100);
        printf("**********+======================================+***********\n");
        Sleep(100);
        printf("**********+            **1.插入单个              +***********\n");
        Sleep(100);
        printf("**********+            **2.批量插入              +***********\n");
        Sleep(100);
        printf("**********+            **3.上一步                +***********\n");
        Sleep(100);
        printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
        Sleep(100);
        printf("*************************************************************\n");
        Sleep(100);
        printf("Please Input Number :");
        num = getch();
        system("clear");
        switch (num) {
            case '1':
                head = insert11(head);
                system("clear");
                break;
            case '2':
                head = insert12(head);
                system("clear");
                break;
            case '3':
                head = insert(head);
                system("clear");
                break;
            default :
                printf("输入有误，请重新输入！");
                Sleep(1000);
                system("clear");
                test = 1;
        }
    } while (test == 1);
    return head;
}

struct student *insert2(struct student *head) {
    int num, test;
    do {
        test = 0;
        printf("*************************************************************\n");
        Sleep(100);
        printf("**********+           ***中部插入***             +***********\n");
        Sleep(100);
        printf("**********+======================================+***********\n");
        Sleep(100);
        printf("**********+            **1.插入单个              +***********\n");
        Sleep(100);
        printf("**********+            **2.批量插入              +***********\n");
        Sleep(100);
        printf("**********+            **3.上一步                +***********\n");
        Sleep(100);
        printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
        Sleep(100);
        printf("*************************************************************\n");
        Sleep(100);
        printf("Please Input Number :");
        num = getch();
        system("clear");
        switch (num) {
            case '1':
                head = insert21(head);
                system("clear");
                break;
            case '2':
                head = insert22(head);
                system("clear");
                break;
            case '3':
                head = insert(head);
                system("clear");
                break;
            default :
                printf("输入有误，请重新输入！");
                Sleep(1000);
                system("clear");
                test = 1;
        }
    } while (test == 1);
    return head;
}

struct student *insert3(struct student *head) {
    int num, test;
    do {
        test = 0;
        printf("*************************************************************\n");
        Sleep(100);
        printf("**********+           ***尾部插入***             +***********\n");
        Sleep(100);
        printf("**********+======================================+***********\n");
        Sleep(100);
        printf("**********+            **1.插入单个              +***********\n");
        Sleep(100);
        printf("**********+            **2.批量插入              +***********\n");
        Sleep(100);
        printf("**********+            **3.上一步                +***********\n");
        Sleep(100);
        printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
        Sleep(100);
        printf("*************************************************************\n");
        Sleep(100);
        printf("Please Input Number :");
        num = getch();
        system("clear");
        switch (num) {
            case '1':
                head = insert31(head);
                system("clear");
                break;
            case '2':
                head = insert32(head);
                system("clear");
                break;
            case '3':
                head = insert(head);
                system("clear");
                break;
            default :
                printf("输入有误，请重新输入！");
                Sleep(1000);
                system("clear");
                test = 1;
        }
    } while (test == 1);
    return head;
}

struct student *insert(struct student *head) {
    if (head == NULL) {
        printf("信息为空!");
        Sleep(500);
        system("clear");
    } else {
        int num, test;
        do {
            test = 0;
            printf("*************************************************************\n");
            Sleep(100);
            printf("**********+             ***插入***               +***********\n");
            Sleep(100);
            printf("**********+======================================+***********\n");
            Sleep(100);
            printf("**********+            **1.首部插入              +***********\n");
            Sleep(100);
            printf("**********+            **2.内部插入              +***********\n");
            Sleep(100);
            printf("**********+            **3.尾部插入              +***********\n");
            Sleep(100);
            printf("**********+            **4.上一步                +***********\n");
            Sleep(100);
            printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
            Sleep(100);
            printf("*************************************************************\n");
            Sleep(100);
            printf("Please Input Number :");
            num = getch();
            system("clear");
            switch (num) {
                case '1':
                    head = insert1(head);
                    system("clear");
                    break;
                case '2':
                    head = insert2(head);
                    system("clear");
                    break;
                case '3':
                    head = insert3(head);
                    system("clear");
                    break;
                case '4':
                    manage1();
                    system("clear");
                    break;
                default :
                    printf("输入有误，请重新输入！");
                    Sleep(1000);
                    system("clear");
                    test = 1;
            }
        } while (test == 1);
    }
    return head;
}

struct student *change(struct student *head)//更改函数
{
    if (head == NULL)
        printf("信息为空!\n");
    else {
        int judge = 0, num;
        struct student *p;
        p = head;
        printf(" 请输入你要修改的学生的学号：");
        scanf("%d", &num);
        while (p != NULL) {
            if (p->id == num) {
                judge = 1;
                break;
            }
            p = p->next;
        }
        p = head;
        if (judge == 1) {
            while (p->id != num)
                p = p->next;
            printf("请输入新的姓名,linux课成绩(用空格隔开):");
            scanf("%s%f", p->name, &p->score);
            p->id = num;
            printf("修改成功！\n");
            Sleep(1000);
        } else
            printf("Not Found:%d\n", num);
    }
    printf("Press Any Key To Continue.......\n");
    getch();
    system("clear");
    return head;
}

struct student *Delete(struct student *head)//删除函数
{
    if (head == NULL)
        printf("信息为空!\n");
    else {
        int judge = 0, num;
        struct student *p1, *p2;
        p2 = head;
        p1 = p2;
        printf(" 请输入你要删除的学生的学号：");
        scanf("%d", &num);
        if (num == head->id) {
            head = head->next;
            cont--;
            printf("删除成功！\n");
            Sleep(200);

        } else {
            while (p2 != NULL) {
                if (p2->id == num) {
                    judge = 1;
                    break;
                }
                p1 = p2;
                p2 = p2->next;
            }
            if (judge == 1) {
                if (cont == 1)
                    head = NULL;
                else
                    p1->next = p2->next;
                cont--;
                printf("删除成功！\n");
                Sleep(200);

            } else
                printf("Not Found:%d\n", num);
        }
    }
    printf("Press Any Key To Continue.......\n");
    getchar();
    getch();
    system("clear");
    return head;
}

void find_By_Name(struct student *head) {
    struct student *p;
    int count = 0;
    p = head;
    char name[100];
    printf("请输入你要查询的学生姓名：");
    scanf("%s", name);
    while (p != NULL) {
        if (!strcmp(name, p->name)) {
            printf("学号：%d\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("linux课成绩：%f\n", p->score);
            printf("\n\n");
            count++;
        }
        p = p->next;
    }
    if (!count) {
        printf("Not Found!\n");
    }
    getchar();
    printf("Press Any Key To Continue.......\n");
    getch();
    system("clear");
}

void find_By_Fuzzy_Name(struct student *head) {
    struct student *p;
    int count = 0;
    p = head;
    char name[100];
    printf("请输入你要查询的学生姓名：");
    scanf("%s", name);
    while (p != NULL) {
        if (substring(p->name, name)) {
            printf("学号：%d\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("linux课成绩：%f\n", p->score);
            printf("\n\n");
            count++;
        }
        p = p->next;
    }
    if (!count) {
        printf("Not Found!\n");
    }
    getchar();
    printf("Press Any Key To Continue.......\n");
    getch();
    system("clear");
}

void find_By_id(struct student *head)//查询函数
{
    if (head == NULL) {
        printf("信息为空!\n");
        return;
    }
    int num;
    struct student *p;
    p = head;
    printf(" 请输入你要查找的学生的学号：");
    scanf("%d", &num);
    while (p != NULL) {
        if (p->id == num) {
            printf("你所查询的学生信息如下：\n");
            printf("学号：%d\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("linux课成绩：%f\n", p->score);
            printf("\n\n");
            getchar();
            printf("Press Any Key To Continue.......");
            getch();
            system("clear");
            return;
        } else {
            p = p->next;
        }
    }
    printf("未找到，请核对你输入的学号是否正确！\n");
    getchar();
    printf("Press Any Key To Continue.......\n");
    getch();
    system("clear");
}

void write_to_file() {
    struct student *p;
    p = head;
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("data.dat", "wb");
    fp2 = fopen("count.dat", "wb");
    fprintf(fp2, "%d", cont);
    while (p != NULL) {
        fwrite(p, sizeof(struct student), 1, fp1);
        p = p->next;
    }
    printf("%d条信息写入成功！\n", cont);
    fclose(fp1);
    fclose(fp2);
}

void look(struct student *head) {
    int i = 0;
    if (head == NULL)
        printf("信息为空!\n");
    else {
        struct student *p;
        p = head;
        printf("  \t学号\t姓名\tlinux课成绩\n");
        while (p != NULL) {
            i++;
            printf("[%d]\t%d\t%s\t%f\n", i, p->id, p->name, p->score);
            p = p->next;
        }
        printf("共%d条信息\n", cont);
    }
    getchar();
    printf("Press Any Key To Continue.......\n");
    getch();
    system("clear");
}

void read_from_file() {
    int i, count = 0;
    struct student *New = NULL, *Old = NULL;
    FILE *fp1;
    FILE *fp2;
    fp2 = fopen("count.dat", "rb");
    fp1 = fopen("data.dat", "rb");
    if (fp2 == NULL || fp1 == NULL) {
        printf("文件打开失败！\n");
        Sleep(2000);
        system("clear");
        return;
    }
    fscanf(fp2, "%d", &cont);

    for (i = 0; i < cont; i++) {
        New = (struct student *) malloc(sizeof(struct student));
        fread(New, sizeof(struct student), 1, fp1);
        count++;
        if (count == 1) {
            head = New;
            Old = New;
            New->next = NULL;
        } else {
            New->next = NULL;
            Old->next = New;
            Old = New;
        }
    }
    printf("\n%d条信息读取成功！\n", count);
    Sleep(2000);
    system("clear");
    fclose(fp1);
    fclose(fp2);
}

void find() {
    char num;
    do {
        printf("*******************************************************************************\n");
        Sleep(100);
        printf("***********                                                       *************\n");
        Sleep(100);
        printf("***********            ** 1.通过姓名精确查找学生信息              *************\n");
        Sleep(100);
        printf("***********            ** 2.通过姓名模糊查找学生信息              *************\n");
        Sleep(100);
        printf("***********            ** 3.通过学号查找学生信息                  *************\n");
        Sleep(100);
        printf("***********            ** 4.返回上一层                            *************\n");
        Sleep(100);
        printf("***********                                                       *************\n");
        Sleep(100);
        printf("*******************************************************************************\n");
        Sleep(100);
        printf("Please Input Number :");
        num = getch();
        system("clear");
        switch (num) {

            case '1':
                find_By_Name(head);
                break;
            case '2':
                find_By_Fuzzy_Name(head);
                break;
            case '3':
                find_By_id(head);
                break;
            case '4':
                return;
            default:
                printf("你的输入错误请重新输入！\n");
                Sleep(1000);
                system("clear");
        }
    } while (1);
}

void manage1()//管理函数
{
    char num;
    do {
        printf("*********************************************************************************\n");
        Sleep(100);
        printf("***********                                                         *************\n");
        Sleep(100);
        printf("***********            ** 1.录入学生信息                            *************\n");
        Sleep(100);
        printf("***********            ** 2.修改学生信息                            *************\n");
        Sleep(100);
        printf("***********            ** 3.删除学生信息                            *************\n");
        Sleep(100);
        printf("***********            ** 4.查找学生信息                            *************\n");
        Sleep(100);
        printf("***********            ** 5.插入学生信息                            *************\n");
        Sleep(100);
        printf("***********            ** 6.查看已录入的学生信息                    *************\n");
        Sleep(100);
        printf("***********            ** 7.退出程序                                *************\n");
        Sleep(100);
        printf("***********                                                         *************\n");
        Sleep(100);
        printf("***********                                                         *************\n");
        Sleep(100);
        printf("*********************************************************************************\n");
        Sleep(100);
        printf("Please Input Number :");
        num = getch();
        system("clear");
        switch (num) {
            case '1':
                head = input();
                getchar();
                break;
            case '2':
                head = change(head);
                break;
            case '3':
                head = Delete(head);
                break;
            case '4':
                find();
                break;
            case '5':
                head = insert(head);
                break;
            case '6':
                look(head);
                break;
            case '7':
                system("clear");
                write_to_file();
                exit(0);
            default:
                printf("你的输入错误请重新输入！\n");
                Sleep(1000);
                system("clear");
        }
    } while (1);
}


void main() {
    system("clear");
    read_from_file();
    manage1();
}