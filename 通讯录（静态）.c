#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//联系人的信息
typedef struct PeoInFo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInFo;

//通讯录
typedef struct Contact
{
    PeoInFo data[MAX];
    int count;
}Contact;

//初始化通讯录的信息
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示通讯录的信息
void ShowContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人信息
void ModifyContact(Contact* pc);

//按字母排序
void SortContact(Contact* pc);

void InitContact(Contact* pc)
{
    assert(pc);
    pc-> count = 0;
    memset(pc -> data,0,sizeof(pc -> data));
}

void AddContact(Contact* pc)
{
    assert(pc);
    if(pc -> count == 100)
    {
        printf("The address book is full and cannot add new contacts\n");
        return;
    }
    printf("please print name\n");
    scanf("%s",pc -> data[pc -> count].name);
    printf("please print age\n");
    scanf("%d",&(pc -> data[pc -> count].age));
    printf("please print sex\n");
    scanf("%s",pc -> data[pc -> count].sex);
    printf("please print telephone\n");
    scanf("%s",pc -> data[pc -> count].tele);
    printf("please print address\n");
    scanf("%s",pc -> data[pc -> count].addr);
    pc -> count++;
    printf("added successfully\n");
}

void ShowContact(const Contact* pc)
{
    assert(pc);
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","name","age","sex","telephone","address");
    for(int i = 0; i < pc -> count; i++)
    {
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",pc -> data[i].name,
               pc -> data[i].age,
               pc -> data[i].sex,
               pc -> data[i].tele,
               pc -> data[i].addr);
    }
}

int FindByName(Contact* pc,char name[])
{
    assert(pc);
    for(int i = 0; i < pc -> count; i++)
    {
        if(strcmp(pc -> data[i].name,name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void DelContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = {0};
    if(pc -> count == 0)
    {
        printf("The address book is empty, please select again\n");
        return;
    }
    printf("Please enter the name of the contact you want to delete\n");
    scanf("%s", name);
    int pos = FindByName(pc,name);
    if(pos == -1)
    {
        printf("This contact does not exist\n");
        return;
    }
    for(int i = pos; i < pc -> count - 1; i++)
    {
        pc -> data[i] = pc -> data[i + 1];
    }
    pc -> count--;
    printf("deleted successfully\n");
}

void SearchContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = {0};
    printf("Please enter the name of the contact you want to search\n");
    scanf("%s", name);
    int pos = FindByName(pc,name);
    if(pos == -1)
    {
        printf("This contact does not exist\n");
        return;
    }
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","name","age","sex","telephone","address");
    printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",pc -> data[pos].name,
               pc -> data[pos].age,
               pc -> data[pos].sex,
               pc -> data[pos].tele,
               pc -> data[pos].addr);
}

void ModifyContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = {0};
    printf("Please enter the name of the contact you want to modify\n");
    scanf("%s", name);
    int pos = FindByName(pc,name);
    if(pos == -1)
    {
        printf("This contact does not exist\n");
        return;
    }
    printf("Found, starting to modify\n");
    printf("please print name\n");
    scanf("%s",pc -> data[pos].name);
    printf("please print age\n");
    scanf("%d",&(pc -> data[pos].age));
    printf("please print sex\n");
    scanf("%s",pc -> data[pos].sex);
    printf("please print telephone\n");
    scanf("%s",pc -> data[pos].tele);
    printf("please print address\n");
    scanf("%s",pc -> data[pos].addr);
    printf("Modified successfully\n");
}

int com_peo_by_name(const void* e1, const void* e2)
{
    return strcmp(((PeoInFo*)e1) -> name,((PeoInFo*)e2) -> name);
}

void SortContact(Contact* pc)
{
    assert(pc);
    qsort(pc -> data, pc -> count, sizeof(PeoInFo), com_peo_by_name);
    printf("Sorted successfully\n") ;
}

void menu()
{
    printf("***********************************\n");
    printf("*******1. add     2. del   ********\n");
    printf("*******3. search  4. modify********\n");
    printf("*******5. show    6. sort  ********\n");
    printf("*******0. exit             ********\n");
    printf("***********************************\n");
}

int main()
{
    int input = 0;
    Contact con; //contact
    //Initialize Contacts
    InitContact(&con);
    do
    {
        menu();
        printf("please choose\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                AddContact(&con);
                break;
            case 2:
                DelContact(&con);
                break;
            case 3:
                SearchContact(&con);
                break;
            case 4:
                ModifyContact(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
            case 6:
                SortContact(&con);
                break;
            case 0:
                printf("exit contacts\n");
                break;
            default:
                printf("choose error\n");
                break;
        }
    }while(input);
    return 0;
}

