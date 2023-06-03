#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
typedef struct new
{
    char name[40];
    long int db;
    long int aad;
    long long int ph;
}str;
str s;
FILE *fp;
char type[]=".txt",person_name[30];
int bal=2000;
int m,i;
void display();
void newacc();
void tran();
void delete(str*);
void balance();
void update(str*);
void details();
void main()
{ 
    int n;
    printf("----------");
    printf("\twelcome to BanKing managment system\t");
    printf("----------");
    while(n!=7)
    { 
    xy:
    {   
    display();
    scanf("%d",&n);
    }
    
    switch(n)
    {    case 1:
        newacc();
        printf("Do you want to go bacK to main menu(y/n):\n");
        scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
        
            break;
        }
        else if(m=='n'||m=='N')
        {
            printf("\nSucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
            printf("Choose y/n\n");
            exit(1);
        }
        break;
        case 2:
            delete(&s);
            printf("Do you want to go bacK to main menu(y/n):\n");
            scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        
        else if(m=='n'||m=='N')
        {
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
            printf("Choose y/n\n");
            exit(1);
        }
        break;
        case 3:
        tran();
        printf("Suggestion:\nDo you want to checK balance(y/n):\n");
        scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            balance(); 
            printf("Do you want to go bacK to main menu(y/n):\n");
            scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        
        else if(m=='n'||m=='N')
        {
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
        printf("Choose y/n\n");
        exit(1);
        }
        }
        else if(m=='n'||m=='N')
        {
            printf("Do you want to go bacK to main menu(y/n):\n");
            scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        
        else if(m=='n'||m=='N')
        {
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
        printf("Choose y/n\n");
        exit(1);
        }    
        }
        break;
        case 4:
            update(&s);
            printf("Sucessfully Completed!!\n");
            printf("Do you want to go bacK to main menu(y/n):\n");
            scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        else if(m=='n'||m=='N')
        {
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
        printf("choose y/n\n");
        exit(1);
        }
        break;
        case 5:
        details();
        printf("Sucessfully Completed!!\n");
        printf("Do you want to go bacK to main menu(y/n):\n");
        scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        else if(m=='n'||m=='N')
        {
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
            printf("Choose y/n\n");
            exit(1);
        }
        break;
        case 6:
        balance();
        printf("Sucessfully Completed!!\n");
        printf("\nDo you want to go bacK to main menu(y/n):\n");
        scanf(" %c",&m);
        if(m=='y'||m=='Y')
        {
            break;
        }
        else if(m=='n'||m=='N')
        {
    
            printf("Sucessfully Completed!!\n");
            printf("ThanK you for visiting our banK\n");
            exit(1);
        }
        else
        {
            printf("Choose y/n\n");
            exit(1);
        }
        break;
        case 7:
            printf("ThanK you for visiting our banK\n");
            break;
            exit(1);
        default:
        printf("Choose correct option!!!\n");
        exit(1);

    }
    
    }
}
    

void display()
    {
    printf("\n1.create a new account\n2.Remove existing account\n3.Transitions\n4.update information of existing account\n");
    printf("5.checK the details of existing account\n6.Balance enquiry\n7.Exit\n");
    }
    void newacc()
    {  //printf("Enter file name(.dat/.txt):\n");
        //scanf("%s",&f);
        printf("enter full name:\n");
        scanf(" %[^\n]s",&(s.name));
        fp=fopen(strcat(s.name,type),"w");
        printf("Enter your date of birth:\n");
        scanf("%d",&(s.db));
        printf("Enter your aadhar number:\n");
        scanf("%ld",&(s.aad));
        printf("Enter your phone number:\n");
        scanf("%lld",&(s.ph));
        fwrite(&s,sizeof(s),1,fp);
        printf("Your inital balance :%d\n",bal);
        fclose(fp);

    }
    void tran()
    {   int n,dep,tran;
        printf("\nChoose transtion type:\n");
        printf("1.deposite\n2.transfer\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                printf("Enter amount to deposite:\n");
                scanf("%d",&dep);
                bal=2000+dep;
                printf("\nSucessfully deposited!!!\n");
                break;
            }
            case 2:
            { printf("Enter amount to transfer:\n");
            scanf("%d",&tran);
            if((tran<=bal)&&(bal>=1000))
            {                
            bal=bal-tran;
            printf("\nSucessfully transfered money!!!\n");
            }
            else
            printf("\nInsufficent balance!!!\n");
            break;
            }
            default:
            printf("Choose correct option!!!\n");
        }
    }
    void delete(struct new *s)
    {   printf("Enter name:\n");
        scanf(" %[^\n]s",&person_name);
        if((remove(strcat(person_name,type))==0))
    {
        printf("Sucessfully removed account\n");
    }
    else
    {
        printf("Account not removed\nreason:");
        perror(strcat(person_name,type));
    }   
    }
    void balance()
    {
        printf("\n--------------\n");
        printf("Balance=%d",bal);
        printf("\n--------------\n");
    }
    void update(str *s)
    {   int n;
        printf("\nchoose above options:\n");
        printf("1.Update name\n2.Update Date of birth\n3.Update aadhar number\n4.Update phone number\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter new name:\n");
            scanf(" %[^\n]s",&(s->name));
            printf("Name sucessfully updated!!\n");
                break;
            case 2:
                printf("Enter new date of birth:\n");
                scanf("%d",&(s->db));
                printf("Date of birth sucessfully updated!!\n");
                break;
            case 3:
                printf("Enter new aadhar number:\n");
                scanf("%ld",&(s->aad));
                printf("Aadhar number sucessfully updated!!\n");
                break;
            case 4:
            printf("Enter new phone number:\n");
            scanf("%ld",&(s->ph));
            printf("Phone number sucessfully updated!!\n");
            break;
            default:
            printf("Choose correct option!!!\n");
        }
    }
    void details()
    {   printf("Enter your name :\n");
        scanf(" %[^\n]s",&person_name);
        fp=fopen(strcat(person_name,type),"r");
        fread(&s,sizeof(s),1,fp);
        printf("Date of birth: %ld\nAadhar number: %ld\nPhone number: %lld\n",s.db,s.aad,s.ph);
        fclose(fp);
    }