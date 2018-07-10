#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x,int y)
{
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }




int login()
{
    {
                int c=0,i=0,j=0,c1=0,c2=0;
                long int v;
                char jk[31],s1[10],s2[31],s3[10],e,l;
                FILE *f1,*f2,*f3;
                f1=fopen("DATA.txt","r");
                f2=fopen("pass.txt","r");


//*********************************************************************
//              FOR ENTERING A NEW USERNAME
//*********************************************************************
lbl:
                do
                {
                    printf("\n\tEnter user name:");
                    scanf("%s",s1);
                    fseek(f1,0L,0);
                    fscanf(f1,"%c",&s3[0]);


                    while(s3[j]!=EOF)
                    {
                        j++;
                        fscanf(f1,"%c",&s3[j]);
                        if(s3[j]==32)
                        {
                            s3[j]='\0';
                            if(!strcmp(s3,s1))
                            {

                                break;
                            }
                            c2++;
                            j=0;

                            fscanf(f1,"%c",&s3[j]);
                        }
                    }
                    if(strcmp(s3,s1))
                    {
                        printf("\n\tuser name does not exists");
                        c2=0;
                    }
                    j=0;
                }while(strcmp(s1,s3)!=0);


//*********************************************************************
//              FOR ENTERING PASSWORD
//*********************************************************************
                string pass="";
                char ch;
                int ng=0;

                do
                {
                    restart:
                    printf("\n\tenter password:");
                    a:
                        pass="";
                    ch=_getch();
                    while(ch!=13)
                    {
                        if(ch!=8)
                        {
                        pass.push_back(ch);
                        cout<<"*";
                        //cout<<ch;
                        ch=_getch();
                        }
                        else{
                           // fseek(f2,-1,1);
                            goto a;
                        }
                    }
                     strcpy(s, pass.c_str());
                    v=11*c2;
                    fseek(f2,v,0);
                    fscanf(f2,"%c",&s2[j]);
                    while(s2[j]!=32)
                    {
                        j++;
                        fscanf(f2,"%c",&s2[j]);
                    }
                    s2[j]='\0';
                    //cout<<"\n\n\n"<<s2;system("pause");
                    if(strcmp(s2,s))
                    {
                        printf("\n\twrong password try again");
                        ng++;
                        if(ng==3)
                        {
                            system("cls");
                            goto lbl;
                           // login();
                        }
                    }


                    j=0;

                }while(strcmp(s2,jk)!=0);

                return 0;
            }
}


//*********************************************************************
//              FOR CREATING A NEW ACCOUNT
//*********************************************************************




void createacc()
{
            int c=0,i=0,j=0,c1=0,c2=0;
            long int v;
            char s[10],s1[10],s2[10],s3[10],e;
            FILE *f1,*f2,*f3,*f4;
            f1= fopen("DATA.txt","a");
            f2 = fopen("pass.txt","a");
            f3=fopen("DATA.txt","r");


//*********************************************************************
//              FOR  CREATING A NEW USERNAME
//*********************************************************************
            do
            {
                printf("\n\tEnter user name:");
                scanf("%s",s1);

                fscanf(f3,"%c",&s3[0]);

                while(s3[j]!=EOF)
                {
                    j++;
                    fscanf(f3,"%c",&s3[j]);
                    if(s3[j]==32)
                    {
                        s3[j]='\0';
                        if(!strcmp(s3,s1))
                        {
                            printf("\n\tUsername already exists");
                            break;
                        }
                        j=0;
                        fscanf(f3,"%c",&s3[j]);
                    }
                }
            }while(strcmp(s1,s3)==0);

            fprintf(f1,"%s ",s1);


//*********************************************************************
//              FOR CREATING A NEW PASSWORD
//*********************************************************************
                string pass="";
                char ch;

                do
                {
                    do
                    {
                        printf("\n\tenter password:");
                        b: pass="";
                        ch=_getch();
                        //ch=getchar();
                        while(ch!=13)
                        {
                            if(ch!=8)
                            {
                            pass.push_back(ch);
                            cout<<"*";
                            ch=_getch();
                          //  ch=getchar();
                            }
                            else{
                              //  fseek(f2,-1,1);
                                goto b;
                            }
                        }
                         strcpy(s, pass.c_str());
                         //cout<<s;system("pause");
                        if(strlen(s)<8)
                        {
                            printf("\n\tEnter password of 10 character");
                        }
                        if(strlen(s)>10)
                        {
                            printf("\n\tPassword should be equals to 10 characters.");
                        }
                    }while(strlen(s)<8 || strlen(s)>10);

                    for(i=0;s[i]!='\0';i++)
                    {
                        if(s[i]=='@')
                        c1=1;
                    }
                    i=0;
                    if(c1!=1)
                    printf("\n\tPlease use atleast one time @ in password..");
               }while(c1==0);

                do
                {
                    printf("\n\tConfirm your password:");

                    a:
                        ch=_getch();
                            pass="";
                            while(ch!=13)
                            {
                                if(ch!=8)
                                {
                                pass.push_back(ch);
                                cout<<"*";
                                ch=_getch();
                                }
                                else{
                                   // fseek(f2,-1,1);
                                    goto a;
                                }
                            }
                         strcpy(s2, pass.c_str());

                    if(strcmp(s,s2)!=0)
                    {
                        printf("\n\tPassword don't match.");
                    }

                }while(strcmp(s,s2));

                for(i=strlen(s);i<10;i++)
                {
                    s[i]=' ';
                }
                //printf("%s",s);cout<<endl;system("pause");
                for(i=0;s[i]!='\0';i++){
                    fprintf(f2,"%c",s[i]);
                    }

                fprintf(f2," ",stdout);

                fclose(f3);
                fclose(f2);
                fclose(f1);
                c1=0;
                c2=2;
}
