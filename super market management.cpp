//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************
#include<windows.h>
#include<mmsystem.h>
#include<iomanip>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include"jlogin.h"
#include<conio.h>
#include<process.h>
#include<fstream>
#include<iostream>
using namespace std;
void admin_menu();
void r_admin_menu();
void main_menu();
void gotoxy(int ,int);
int mini_main();
//***************************************************************
//                   CLASS USED IN PROJECT
//***************************************************************

class item
{
 int ino;
 char name[100];
 float price,qty,tax,dis;
 public:
	void create_item()
	{
	 cout<<"\n\nPlease Enter The No. of The Item : ";
	 cin>>ino;
	 cout<<"\nPlease Enter The Name of The Item : ";
	fflush(stdin);
	cin.getline(name,100);
	 cout<<"\nPlease Enter The price of The Item : ";
	 cin>>price;
	 cout<<"\nPlease Enter The Discount (%) : ";
	 cin>>dis;
	 }

	void show_item()
	{
	 cout<<"\nThe Item No. of The Item : "<<ino;
	 cout<<"\nThe Name of The Item : ";
	 puts(name);
	 cout<<"\nThe price of The Item : "<<price;
	 cout<<"\nDiscount : "<<dis;
	 }

  int  retino()
  {return ino;}

  float retprice()
  {return price;}

  char* retname()
  {return name;}

  int retdis()
  {return dis;}

};         //class ends here



//***************************************************************
//    	global declaration for stream object
//****************************************************************

 fstream fp;
 item itm;
// COORD coord={0,0};

//***************************************************************
//    	function to write in file
//****************************************************************

void write_item()
{

 fp.open("Shop.dat",ios::out|ios::app);
    char a;
    gotoxy(5,0);
    cout<<"CREATE ITEM";
    do{
        itm.create_item();
        fp.write((char*)&itm,sizeof(item));
        cout<<"\nDo you want to add another item please confirm ? (y/n) : ";
        	 PlaySound("confirm.wav", NULL, SND_ASYNC);
        cin>>a;
    }while(a=='y' || a=='Y');

    fp.close();
    cout<<"\n\nThe item Has Been Created : ";
    gotoxy(175,49);
    //system("pause");
    r_admin_menu();

    }




//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
    system("cls");

    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&itm,sizeof(item)))
	{
	 itm.show_item();
	 cout<<"\n"<<endl;
	 for(int i=0;i<30;i++)
        cout<<"=";
	 }
    fp.close();
   //gotoxy(175,49);
  cout<<"\n\n";
   system("pause");
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&itm,sizeof(item)))
	{
	 if(itm.retino()==n)
		{
		 //system("cls");
		 itm.show_item();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nRecord not Exist";
    gotoxy(175,49);system("pause");
    r_admin_menu();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_item()
{
    int no,found=0;
    system("cls");
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The Item No. of The Item";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    while(fp.read((char*)&itm,sizeof(item)) && found==0)
	   {
	    if(itm.retino()==no)
		   {
		    itm.show_item();
		    cout<<"\n\nPlease Enter The New Details of Item"<<endl;
		    itm.create_item();
		    int pos=-1*sizeof(itm);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&itm,sizeof(item));
		    cout<<"\n\n\t Record Updated\n";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found \n\n";
    gotoxy(175,49);
    system("pause");
    r_admin_menu();
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_item()
   {

    int no;
    system("cls");
    display_all();
    cout<<"\n\n\n\t\t**********    Delete Record    **********";
    cout<<"\n\nPlease Enter The Item no. of The Item You Want To Delete : ";
    cin>>no;

    cout<<"\nAre you sure ? (y/n) : ";
    char a;
 PlaySound("confirm.wav", NULL, SND_ASYNC);
    cin>>a;
    if(a=='y' || a=='Y'){
    fp.open("Shop.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&itm,sizeof(item)))
	{
	 if(itm.retino()!=no)
		{
		 fp2.write((char*)&itm,sizeof(item));
		 }
	 }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat","Shop.dat");
    cout<<"\n\n\tRecord Deleted ..";
    gotoxy(175,49);
    system("pause");
    r_admin_menu();
    }
    else
        r_admin_menu();
    gotoxy(175,49);system("pause");
    }


//***************************************************************
//    	function to display all Items price list
//****************************************************************

void menu()
{
    system("cls");

     fp.open("Shop.dat",ios::in);
     if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n program is closing ....";
       gotoxy(175,49);system("pause");
       admin_menu();
       exit(0);
     }

     cout<<"\n\t\tITEM MENU\n\n";
	  for(int i=0;i<71;i++)
        cout<<"=";
    cout<<"\n";
	  gotoxy(0,4);
	  cout<<"P.NO."<<"\t\t\t\t";
	  //gotoxy(14,4);
	  cout<<"NAME"<<"\t\t\t\t";
	  //gotoxy(28,4);
	  cout<<"PRICE";
	  cout<<"\n";
	  for(int i=0;i<71;i++)
        cout<<"=";
        cout<<"\n";
      while(fp.read((char*)&itm,sizeof(item)))
	 {
	     int i=0;
	     //gotoxy(0,8+i);
	   cout<<"\n"<<itm.retino()<<"\t\t\t\t";
	   //gotoxy(14,8+i);
	   cout<<itm.retname()<<"\t\t\t\t";
	   //gotoxy(66,5);
	   cout<<itm.retprice()<<endl;
	   i++;
	}
	 for(int i=0;i<71;i++)
        cout<<"=";
    cout<<"\n\n\n\t\t";
    //gotoxy(180,75);
        system("pause");
     fp.close();


}

//***************************************************************
//    	function to place order and generating bill for Items
//****************************************************************
void place_order()
{
    int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu();
    for(int i=0;i<64;i++)
        cout<<"_";
    //cout<<"\n============================";
    cout<<"\n\n\t\t\tPLACE YOUR ORDER";
    cout<<"\n";
    for(int i=0;i<64;i++)
        cout<<"=";
    //cout<<"\n============================\n";
    do{
	 cout<<"\n\nEnter The Item No. Of The Item : ";
	 cin>>order_arr[c];
	 cout<<"\nQuantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\nDo You Want To Order Another Item ? (y/n) : ";
	 PlaySound("confirm.wav", NULL, SND_ASYNC);
	 cin>>ch;

    }while(ch=='y' ||ch=='Y');
     cout<<"\n\nThank You For Placing The Order";gotoxy(175,49);system("pause");system("cls");
     system("color 70");
     cout<<"\n\n";
     for(int i=0;i<125;i++)
        cout<<"-";
    cout<<"\n";
     for(int i=0;i<53;i++)
        cout<<"*";
     cout<<"      INVOICE      ";
     for(int i=0;i<53;i++)
        cout<<"*";
        cout<<"\n";
    for(int i=0;i<125;i++)
        cout<<"-";
    cout<<"\n";
    gotoxy(2,5);
     cout<<"Item No.";//<<"\t\t";
    gotoxy(22,5);
     cout<<"Item Name";//<<"\t\t";
     gotoxy(42,5);
     cout<<"Quantity";//<<"\t\t";
     gotoxy(62,5);
     cout<<"Price";//<<"\t\t";
     gotoxy(82,5);
     cout<<"Amount";//<<"\t\t";
     gotoxy(102,5);
     cout<<"Amount after discount\n";
     for(int i=0;i<125;i++)
        cout<<"=";
     int X=2,Y,J=0;
     for(int x=0;x<=c;x++)
	 {
		 fp.open("Shop.dat",ios::in);
		 fp.read((char*)&itm,sizeof(item));
		  while(!fp.eof())
			{
			if(itm.retino()==order_arr[x])
				{


				    Y=7+J;
				 amt=itm.retprice()*quan[x];
				 damt=amt-(amt*itm.retdis()/100);
				 gotoxy(X,Y);
				 cout<<order_arr[x]<<"\t\t";X=X+(20);
				  gotoxy(X,Y);
				  cout<<itm.retname();X=X+(20);
				  gotoxy(X,Y);
				  cout<<quan[x];X=X+(20);//<<"\t\t";
				  gotoxy(X,Y);
				  cout<<itm.retprice();X=X+(20);//<<"\t\t";
				  gotoxy(X,Y);
				   cout<<amt;X=X+(20);//<<"\t\t";
				  gotoxy(X,Y);
				   cout<<damt;
				 total+=damt;
				 J++;
				 X=2;
				}
			fp.read((char*)&itm,sizeof(item));
			}
		 fp.close();
	  }
	  cout<<"\n";
	   for(int i=0;i<125;i++)
        cout<<"=";
	  gotoxy(102,Y+2);
    cout<<"TOTAL = "<<total<<"  RS";
    //gotoxy(175,49);
    gotoxy(102,Y+4);
    cout<<"Visit Again :)";
    cout<<"\n\n\n\t";
    PlaySound("thankyou.wav", NULL, SND_ASYNC);
    system("pause");


    }

//***************************************************************
//    	GOTOXY FUNCTION
//****************************************************************
/*void gotoxy(int x,int y)
{
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }*/
//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************

void intro()
{
         system("cls");
         PlaySound("welcome.wav", NULL, SND_ASYNC);
         gotoxy(90,11);
         cout<<"SUPER MARKET";
         gotoxy(90,14);
         cout<<"BILLING PROJECT";
         gotoxy(90,20);
         /*cout<<"MADE BY : ";
         gotoxy(99,21);
          cout<<"Jay Khatri (17CE044)";
          gotoxy(99,22);
          cout<<"Isha Khimsurya (17CE045)\n\n\n";
         gotoxy(175,49);
         */system("pause");
}


void admin()
{
    int c=0,i=0,j=0,c1=0,c2=0;
    long int v;
    char s[31],s1[10],s2[31],s3[10],e;
    FILE *f1,*f2,*f3,*f4;
        a:
            system("cls");
            cout<<"\n\n\n\tADMIN MENU\n";
        printf("\n\t1.for creating new account.\n");
       printf("\n\t2.for logging in.\n");
         printf("\n\t3.Exit\n");
        printf("\n\n\n\tEnter your choice:-");
         fflush(stdin);
         scanf("%d",&c);

    //        cout<<"\t\t\t\t\t\t\t-----------------------\n\t\t\t\t\t\t\t|  EXIT  |  CONTINUE  |\n\t\t\t\t\t\t\t-----------------------\t\t\t\t\t\t\t";
  //          menuMouse(c);
        switch(c)
        {
            case 1:
                 Beep(500,500);
                createacc();

                goto a;
                    break;
            case 2:
                 Beep(500,500);
                login();
                break;
            case 3:
                {
                     Beep(500,500);
                     mini_main();
                }
                default:
                   PlaySound("atention.wav", NULL, SND_ASYNC);
                cout<<"\nChoose correct option!!! ";
                system("pause");
                system("cls");
                goto a;
        }
}
//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
     system("color f4");
  system("cls");
  cout<<"\n\n\n\tADMIN MENU\n";
  admin();
  r_admin_menu();
}
void r_admin_menu()
{
  char ch2;
  system("cls");
  cout<<"\n\n\n\tADMIN MENU\n";
  for(int i=0;i<7;i++)
        cout<<" ";
  for(int i=0;i<12;i++)
        cout<<"=";
  cout<<"\n\n\t01.CREATE Item";
  cout<<"\n\n\t02.DISPLAY ALL Item$";
  cout<<"\n\n\t03.QUERY ";
  cout<<"\n\n\t04.MODIFY Item";
  cout<<"\n\n\t05.DELETE Item";
  cout<<"\n\n\t06.VIEW Item MENU";
  cout<<"\n\n\t07.BACK TO MAIN MENU";
  cout<<"\n\n\tPlease Enter Your Choice (1-7) : ";fflush(stdin);
  ch2=cin.get();
  switch(ch2)
  {
    case '1':
        Beep(500,500);
        system("cls");
	      write_item();
	      break;
    case '2':
        Beep(500,500);
         display_all();
              r_admin_menu();
    break;
    case '3':
        Beep(500,500);
	       int num;
	       system("cls");
	       cout<<"\n\n\tPlease Enter The Item No. : ";
	       cin>>num;
	       display_sp(num);
	       break;
      case '4':
          Beep(500,500);
          modify_item();break;
      case '5':
          Beep(500,500);
           delete_item();break;
      case '6':
                Beep(500,500);
                menu();
                 r_admin_menu();
                 break;
      case '7': break;
      default:
           PlaySound("atention.wav", NULL, SND_ASYNC);
          cout<<"\a";
   }
}

void main_menu()
{
      system("cls");
      system("color 07");
      cout<<"\n\n\n\tMAIN MENU";
      cout<<"\n       ===========";
	  cout<<"\n\n\t01. CUSTOMER";
	  cout<<"\n\n\t02. ADMINISTRATOR";
	  cout<<"\n\n\t03. ABOUT THE PROJECT";
	   cout<<"\n\n\t04. EXIT";
	  cout<<"\n\n\tPlease Select Your Option (1-4) ";
}


//***************************************************************
//    	THE MAIN FUNCTION OF program
//****************************************************************
int mini_main()
{
  char ch;
  do
    {
         system("color 07");

	  x: system("cls");
     main_menu();
        fflush(stdin);
	  p:ch=cin.get();
	  switch(ch)
	  {
		 case '1': system("cls");
                   Beep(500,500);
                   place_order();
                  // gotoxy(175,49);system("pause");
                break;
		  case '2':
                Beep(500,500);

                admin_menu();
			    break;
		  case '4':
		      Beep(500,500);
		      exit(0);
		  case '3':
		      system("cls");
		      Beep(500,500);
		       gotoxy(90,15);
		  cout<<"MADE BY : ";
			  gotoxy(99,20);
			  cout<<"Jay Khatri";
                        gotoxy(99,22);
			  cout<<"Isha Khimsurya\n\n\n";
                        gotoxy(99,24);
			  cout<<"Naimish Ghevariya\n\n\n";
                         
                    gotoxy(90,30);
                    cout<<"MENTORED BY: ";
                        gotoxy(99,35);
                         cout<<"Prof. Mayuri Popat\n\n\n";
                        gotoxy(99,37);
                        cout<<"Prof. Aniruddh Fatania\n\n\n";
                        gotoxy(99,39);
                         cout<<"Prof. Ronak Patel\n\n\n";
                         system("pause");
                         goto x;
                         break;

		  default :
		       PlaySound("atention.wav", NULL, SND_ASYNC);
		      cout<<"\a";break;
	}
    }while(ch!='3');
    return 0;
}
int main()
{
    intro();
    mini_main();
    return 0;
}
//***************************************************************
//    			END OF PROJECT
//***************************************************************


