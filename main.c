#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();  //FUNCTIONS
void list();
void room_type();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();
void check_out();
void room_rest();

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //This is used to get the handle to current output buffer.

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.

     COORD coord = {0, 0};
                      //This is a return value indicating how many characterss were written
                        //   It is not used but we need to capture this since it will be
                          //   written anyway (passing NULL causes an access violation).

     DWORD count;

                                   //This is a structure containing all the console info
                          // It is used here to find the size of the console.

     CONSOLE_SCREEN_BUFFER_INFO csbi;
                     //Now the current color will be set by this handle

     SetConsoleTextAttribute(hStdOut, wColor);

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                              //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                              //This will set our cursor position for the next print statement
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="1";
    char pass[10]="1";
    do
{
	system("cls");

    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t|        *****************************          |\n");
	printf("\t\t\t|        *                          *           |\n");
	printf("\t\t\t|        *     WELCOME TO HOTEL   *             |\n");
	printf("\t\t\t|        *          LEXUS       *               |\n");
	printf("\t\t\t|        *                        *             |\n");
	printf("\t\t\t|        *                          *           |\n");
	printf("\t\t\t|        *****************************          |\n");
	printf("\t\t\t|    Team name:Prisoners                        |\n");
	printf("\t\t\t|    Members:1.MD.SADID AHMED SAFIN             |\n");
	printf("\t\t\t|            2.ABDUR RAHMAN GALIB               |\n");
	printf("\t\t\t|            3.ADIL                             |\n");
	printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[11];
	char nationality[15];
	char email[20];
	char time[10];
	char arrivaldate[10];
}s;

int main(){     // MAIN FUNCTION
	int i=0;

	ClearConsoleToColors(1,14);         //function call to change console background color
    Sleep(1000);
	time_t t;
	time(&t);
	char customername;
	char choice;
    login();
    system("cls");
	while (1)      // INFINITE LOOP
	{
		system("cls");

		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ~~~~~~~~~~~~~~~~~~~~~~  MENU   ~~~~~~~~~~~~~~~~~~~~~~\n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");

		printf("\t\t ***Enter the command you want to choose***:");
		printf("\n\n");
		printf(" \n Enter 1 -> Room Booking System");
		printf("\n--------------------------------");
		printf(" \n Enter 2 -> Room Types");
		printf("\n-----------------------");
		printf(" \n Enter 3 -> Customer Details System ");
		printf("\n-------------------------------------");
		printf(" \n Enter 4 -> Delete Customer Details");
		printf("\n------------------------------------");
		printf(" \n Enter 5 -> Search Customer Details");
		printf("\n------------------------------------");
		printf(" \n Enter 6 -> Edit Details");
		printf("\n-------------------------");
		printf(" \n Enter 7-> Checkout option");
		printf("\n----------------------------");
		printf(" \n Enter 8 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				add();
				break;
			case '2':
				room_type();
				break;
			case '3':
				list();
				break;
			case '4':
				delete1();
				break;
			case '5':
				search();
				break;
			case '6':
			    edit();
			    break;
            case '7':
                check_out();
            case '8':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

void add()                     //Add function for booking a room
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter days wants to reside(\'x\'days):\n");
		scanf("%s",&s.time);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}


void room_type(){

	//system("cls");


	//ascii_line(177);
	printf("\n\n\t\t\t\tROOM TYPES\n\n");
	//ascii_line(177);

	printf("\n%cFollowing are the available Room Types:\n",4);

	printf("\n\n1.  Single Room: \"A room with a single bed facility\"\n\n");
	printf("2.  Double Room: \"A room with a double bed facility\"\n\n");
	printf("3.  Double Double: \"A room with two double bed facility\"\n\n");
	printf("4.  Twin Room: \"A room with two single bed facility\"\n\n");
	printf("5.  Interconnecting Room: \"Two rooms which shares a common door\"\n\n");
	printf("6.  Duplex: \"A room which is been spread on two floors\"\n\n");
	printf("7.  Adjoining Room: \"Two rooms which shares a common wall\"\n\n");
	printf("8.  Cabana: \"A room near or beside swimming pool\"\n\n");
	printf("9.  Parlor: \"A room which is used for sitting & cannot be used for sleeping\"\n\n");
	printf("10. Efficiency Room: \"A room with a kitchen facility\"\n\n");
	printf("11. Suit Room: \"Room with two or more bedrooms, a living room & a dinning area\"\n\n");
	printf("12. King Room: \"A room with a King size bed\"\n\n");
	printf("13. Queen Room: \"A room with a Queen size bed\"\n\n");
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		/*printf("ROOMNUMBER :\t%s\n",s.roomnumber);
		printf("NAME:\t%s\n",,s.name);
		printf("ADDRESS:\t%s\n",s.address);
		printf("PHONENUMBER:\t%s\n",s.phonenumber);
		printf("NATIONALITY \n");*/
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.time,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)        // reads address and size of function named "s" in 'l' and 't'
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);     //  writing address and size of function named "s" in 'l' and 't'
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nHow many days want to reside:\t%s",s.time);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",roomnumber);    //Edit conversion code
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter how much days want to reside :");
			scanf("%s",&s.time);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}


void check_out(){
	time_t now;
 	time(&now);


	float bill;
	char cus_name[20];
	FILE *f;
	f=fopen("reservation & booking.dat","rb");

	if(f==NULL)
	{
		printf("Error Opening File\n");
	}
	system("cls");
	//ascii_line(177);
	printf("\n\n\t\t\t  CUSTOMER CHECKOUT & PAYMENT\n\n");
	//ascii_line(177);

	printf("\nEnter Name of Customer For Check-Out:");
	fflush(stdin);
	gets(s.name);

	rewind(f);
	//end();
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.name,cus_name)==0)
		{
			//gotoxy(27,22);
			printf("%c Time: %s",16,ctime(&now));
			//gotoxy(27,24);
			printf("%c CUSTOMER NAME: %s",16,s.name);
			//gotoxy(27,26);
			printf("%c ROOM NUMBER: %d",16,s.roomnumber);
			//gotoxy(27,28);
			printf("%c NUMBER OF DAYS: %d",16,s.time);
//			gotoxy(27,30);
//			printf("%c FINAL BILL: %.2f",16,s.final_bill);

		 }
	  }
   }













//   void room_rest(void){
//
//
//	system("cls");
//	ascii_line(177);
//	printf("\n\n\t\t\t    ROOM SERVICE &RESTAURANT\n\n");
//	ascii_line(177);
//
//	printf("\n\nPress Any Key to See the Menu & Order Meal:");
//	getch();
//	system("cls");
//
//	ascii_line(177);
//	printf("\n\n\t\t\t\t    MENU\n\n");
//	ascii_line(177);
//
//	printf("\n\n\n\t\t\t\t\"PAKISTANI CUSINE\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Biryani & Pulao",550.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Karahi",1200.00,"KG");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Shami Kababs",400.0,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Makhani",600.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Tandori Chicken",1050.00,"FULL");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Hyderabadi Chicken",800.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Chicken Handi Boneless",750.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Chicken Green Masala",800.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Chicken Achari",700.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Chicken Qorma",900.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Chicken Kofta",450.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",12,"Chicken Chargha",1300.00,"FULL");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",13,"Chicken Sindhi Biryani",600.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",14,"Nargisi Kofta",550.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",15,"Chapli Kababs",600.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",16,"Aloo Keema",550.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",17,"Mutton Karahi",1100.00,"KG");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",18,"Mutton Haandi",900.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",19,"Mutton Green Masala",750.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",20,"Mutton Qorma",750.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",21,"Plain Rice",300.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",22,"Mix Vegitable",400.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",23,"Andaa Chaana",350.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",24,"Daal",300.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",25,"Palak Paneer",450.00,"PLATE");
//
//	ascii_line(205);
//
//
//	printf("\n\n\n\n\t\t\t\t   \"BARBECUES\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Tikka",400.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Seekh Kababs",500.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Grilled Salmon Tikka",500.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Mutton Seekh Kababs",550.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Grilled Lamb Chops",750.00,"PLATE");
//
//	ascii_line(205);
//
//	printf("\n\n\n\n\t\t\t\t\"CHINESE & SOUPS\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Sizzler",900.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Shashlik",800.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Chicken Chilli Dry",750.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Tempure",800.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Chicken Chow Mien",750.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Chicken Sweet & Sour",700.00,"PLATE");
//	ascii_line(205);
//
//	printf("\n\n\n\n\t\t\t\t   \"SEA FOOD\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Karahi Prawn",1100.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Masala Fish",1000.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Prawn Tikka Masala",1050.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Tawa Chilli Prawn",1100.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Kurkuri Fried Fish",950.00,"PLATE");
//	ascii_line(205);
//
//
//	printf("\n\n\n\n\t\t\t     \"HAMBURGERS & SANDWICHES\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Zinger Burger",600.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Cheese Burger",650.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Beef Cheese Burger",600.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Oriental Chicken Burger",550.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Club Sandwich",400.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"French Fries",200.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",7,"Crispy Fried Burger",600.00,"PCS");
//
//
//	ascii_line(205);
//
//
//	printf("\n\n\n\n\t\t\t\t    \"DESSERTS\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Shahi Kheer",600.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Gulab Jamun",500.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Kulfi",400.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Rass Malai",550.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Halwa",600.00,"PLATE");
//
//	ascii_line(205);
//
//
//
//	printf("\n\n\n\n\t\t\t\t     \"OTHERS\"");
//	printf("\n\n");
//	ascii_line(205);
//	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
//	ascii_line(205);
//
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Plain Naan",50.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Roghani",70.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Tandori Rooti",40.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Paratha",60.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Bread",60.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Tea",150.00,"CUP");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Raita",100.00,"PCS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Coffee",200.00,"CUP");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Halwa Puri",400.00,"PLATE");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Lassi",200.00,"GLASS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Milk Shake",200.00,"GLASS");
//	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",12,"Omelette",120.00,"PCS");
//
//
//
//	ascii_line(205);
//
//	char ch='y';
//	int bill,order_type;
//	int i=0;
//	printf("\n\n%c Please Order the Meal From the Above Menu:\n",4);
//
//
//	printf("\n\n         %cCustomer Name:",16);
//	fflush(stdin);
//	gets(cust_name);
//
//	gotoxy(48,230);
//	printf("%cRoom Number:",16);
//	fflush(stdin);
//	scanf("%d",&room_no_res);
//
//	rest_charges=0; // this variable is for each item its not the final bill
//
//	printf("\n\t %c Order Type(Restaurant=1 Room Service=2):",16);
//	scanf("%d",&order_type);
//
//
//	do{
//		bill=0;
//		printf("\n\n%c Category:",248);
//		fflush(stdin);
//		gets(res[i].item_chat);
//
//		printf("\n%c Item Name:",248);
//		fflush(stdin);
//		gets(res[i].item_name);
//
//		printf("\n%c Quantity:",248);
//		fflush(stdin);
//		scanf("%d",&res[i].unit);
//
//		printf("\n%c Price:",248);
//		scanf("%d",&res[i].charges);
//
//		bill=res[i].unit*res[i].charges;
//
//		rest_charges+=bill;// this will increment the cost of each item to the final bill
//
//
//		printf("\n\nDo You Want to Order Another Meal:");
// 		i++;
//		ch=getche();
//	}
//	while(ch=='y'||ch=='Y');
//
//	printf("Press \"Y\" to Generate Bill:");
//
//this function will generate the bill
//gen_bill(order_type,i,rest_charges);

//}

//void gen_bill(int order_type,int i,int bill_res){
//	system("cls");
//
//	the following two lines of code will display the current time in the bill
//	time_t now;
// 	time(&now);
// 	int j,k=1;
//
//	printf("\n\t\t\t\t ULYSSES RESTAURANT\n");
//	printf("\t\t\t\tTel-No:021-363425633\n");
//	printf("\t\t\t\t     CASH BILL\n");
//
//	printf("\nOrder Tpye:",4);
//	if(order_type==1)
//	printf("Restaurant\n");
//	else if(order_type==2)
//	printf("Room Service");
//
//	gotoxy(40,5);
//	printf("           Time:");
//  	printf("%s",ctime(&now));
//
//	printf("\nCustomer Name:");
//	puts(cust_name);
//	gotoxy(51,8);
//	printf("Room Number:%d",room_no_res);
//
//	printf("\n");
//	ascii_line(95);
//	printf("\n      %-10s %-30s %-20s %-15s \n","S.No","Item Name","Rate(BDT.)","Unit");
//	ascii_line(95);
//
//	for(j=0;j<i;j++)
//	{
//	printf("\n      %-10d %-30s %-20d %-15d\n",k,res[j].item_name,res[j].charges,res[j].unit);
//	k++;
//	}
//	ascii_line(95);
//
//
//
//	printf("\n\t\t\t\t\"TOTAL BILL:%d\"",bill_res);
//	printf("\n\n\t\t\t      THANK YOU & VISIT AGAIN");
//
//}
//
//
//
//
//
//
//

