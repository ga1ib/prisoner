#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void login();
void add();         // prototype of FUNCTIONS
void room_rst();     //resturant
void list();
void room_type();
void edit();
void delete1();
void search();
void check_out();




char uname[10],c=' ';
char cs_name[20];
int room_no_res;
int rest_charges;

//structure for resturant
struct rest{
		char item_name[30];
		char item_chat[20];
		int unit;
		int charges;
	}res[20];


//STRUCTURE for room reservation
struct CustomerDetails
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[12];
	char nationality[15];
	char email[20];
	char time[10];
	char arrivaldate[10];
	int final_bill;
}s;

// login function
void login()
{

	int a=0,i=0;

    char pword[10],code[10];
    char user[10]="prisoners";     // username set
    char pass[10]="1234567";     // password set
    do
{
	system("cls");

    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t|        *****************************          |\n");
	printf("\t\t\t|        *                          *           |\n");
	printf("\t\t\t|        *     WELCOME TO HOTEL   *             |\n");
	printf("\t\t\t|        *        KARAGHAR       *              |\n");
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
	    if(c==13) break;                                           //Enter button is the ASCII code of 13.. loop will end after pressing enter
	    else printf("*");                                          // printing **** for password
	    i++;
	}
	pword[i]='\0';

	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)          // Comparing user and password with the user given one for going to next step
 	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

	break;
	}
	else
	{
		printf("\n\n\n\t        SORRY !!!!  LOGIN IS UNSUCESSFUL");  // if wrong username or password is input then it will retry
		a++;
		printf("\n\t\t       Please try again!");

		getch();

	}
}
	while(a=1);
//	if (a>2)
//	{
//
//
//		getch();
//
//		}
		system("cls");
}                             //End of login function


// MAIN FUNCTION
int main()
{
    system("color B5");     // Changing background color and font color
	int i=0;

//	ClearConsoleToColors(1,14);         //function call to change console background color

    Sleep(1000);
	time_t t;            //declaring time with the computers time
	time(&t);
	char customername;
	char choice;
    login();                    //login function will take place here

    system("cls");              // console will goto new page
	while (1)                  // INFINITE LOOP
	{
		system("cls");

         //New page for displaying main page
		 for(i=0;i<80;i++)
		printf("-");           // printing ------- for design
		printf("\n");
		printf("   ~~~~~~~~~~~~~~~~~~~~~~  MENU   ~~~~~~~~~~~~~~~~~~~~~~\n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");


		printf("\t\t ***Enter the command you want to choose***:");
		printf("\n\n");
		printf(" \n Enter 1 -> Room Booking System");
		printf("\n--------------------------------");
        printf(" \n Enter 2 -> Karaghar Food and Resturant system");
		printf("\n-----------------------------");
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
	    printf("\nCurrent date and time : %s",ctime(&t));           //printing time and date mathching the computers one
 	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)                 // SWITCH STATEMENT
		{
			case '1':                //if user press 1 room types and booking system will appear
				room_type();
				break;
            case'2':                 //if user press 2 resturant order will appear
                room_rst();
                break;
			case '3':               //If user press 3 then list of booked room and information will appear
				list();
				break;
			case '4':               // if user press 4 then information deletion system will appear
				delete1();
				break;
			case '5':               // if user press 5 then search option will appear
				search();
				break;
			case '6':               //if user press 6 then edit option will appear
			    edit();
			    break;
            case '7':               //if user press 7 thn check-out option will appear
                check_out();
                break;
            case '8':               // if user press 8 thn system will be terminated
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
	FILE *f;                   // file saving operation
	char test;
	f=fopen("add.txt","a+");    // declaring file
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)                                  //infinite loop
	{
		system("cls");

		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);     // saving room number in structre build named roomnumber
		fflush(stdin);
		printf("Enter Name:\n");        // saving name in builed structre  named name
		scanf("%s",s.name);
		printf("Enter Address:\n");     // saving address in builed structre  named address
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
		fflush(stdin);                  // to flush the data
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)        //ascii code of escape key is 27. if ESC button is pressed then it will return to the main page
			break;

	}
	fclose(f);
}


void room_type()                      //room type  function for displaying the availaible rooms
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
    while (1)                       // INFINITE LOOP
	{
		system("cls");
		int choice;

   printf("\n\n\t\t\t\tROOM TYPES\n\n");


	printf("\nFollowing are the available Room Types:\n");
	printf("*******************************************");

	printf("\n\n1.  Single Room: \"A room with a single bed facility--------------------------------1000 BDT / per night.\"\n\n");
	printf("2.  Double Room: \"A room with a double bed facility------------------------------------1500 BDT / per night.\"\n\n");
	printf("3.  Double Double: \"A room with two double bed facility--------------------------------2000 BDT / per night.\"\n\n");
	printf("4.  Twin Room: \"A room with two single bed facility------------------------------------2000 BDT / per night.\"\n\n");
	printf("5.  Interconnecting Room: \"Two rooms which shares a common door------------------------2500 BDT / per night.\"\n\n");
	printf("6.  Duplex: \"A room which is been spread on two floors---------------------------------3000 BDT / per night.\"\n\n");
	printf("7.  Adjoining Room: \"Two rooms which shares a common wall-----------------------------32000 BDT / per night.\"\n\n");
	printf("8.  Cabana: \"A room near or beside swimming pool---------------------------------------5000 BDT / per night.\"\n\n");
	printf("9.  Parlor: \"A room which is used for sitting & cannot be used for sleeping------------1000 BDT / per night.\"\n\n");
	printf("10. Efficiency Room: \"A room with a kitchen facility------------------------------------1000 BDT / per night.\n\n");
	printf("11. Suit Room: \"Room with two or more bedrooms, a living room & a dinning area-------10,000 BDT / per night.\"\n\n");
	printf("12. King Room: \"A room with a King size bed------------------------------------------12,000 BDT / per night.\n\n");
	printf("13. Queen Room: \"A room with a Queen size bed-------------------------------------------8000 BDT / per night.\n\n");
	printf("\n\tDouble Press ESC to go back to menu");

	scanf("%d",&choice);
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{        // pressing desired room numbers it will take to reervation page
			case 1:
				add();
				break;
			case 2:
				add();
				break;
            case 3:
                add();
                break;
			case 4:
				add();
				break;
			case 5:
				add();
				break;
			case 6:
				add();
				break;
			case 7:
			    add();
			    break;
            case 8:
                add();
                break;
            case 9:
                add();
                break;
            case 10:
				add();
				break;
			case 11:
				add();
				break;
			case 12:
			    add();
			    break;
            case 13:
                add();
                break;

				//system("cls");

				break;
			default:
			    printf("\n\tPlease select a Room type");



				system("cls");

		}

		test=getche();
		if(test==27)
			break;
	}


}


void list()               // it will display the reserved and booked rooms in hotel
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");

	while(fread(&s,sizeof(s),1,f)==1)
	{
	    for(i=0;i<121;i++)
		printf("-");
		printf("\tROOMNUMBER :\t%s\n",s.roomnumber);
		printf("\tNAME:\t\t%s\n",s.name);
		printf("\tADDRESS:\t%s\n",s.address);
		printf("\tPHONENUMBER:\t%s\n",s.phonenumber);
		printf("\tNATIONALITY:\t%s\n",s.nationality);
		printf("\tRESIDE FOR:\t%s\n",s.time);
		printf("\tARRIVAL DATE:\t%s\n",s.arrivaldate);
		for(i=0;i<120;i++)
		printf("-");

	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()           // this function will delete any infotmation user wants
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
		if(strcmp(s.roomnumber,roomnumber)==0)       //comparing room number
        {
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
			fseek(f,size,SEEK_CUR);       //to go to desired position infile
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
	int flag=1;
	 char roomnumber[20];
	FILE *f;
	f=fopen("add.txt","r+");
	if(f==NULL)
	{
		printf("Error Opening File\n");
	}
	system("cls");

	printf("\n\n\t\t\t  CUSTOMER CHECKOUT & PAYMENT\n\n");


	printf("\nEnter Room number of Customer For Check-Out:");

	scanf("%s",roomnumber);


	while(fread(&s,sizeof(s),1,f)==1)
{



		if(strcmp(s.roomnumber,roomnumber)==0)
		{
		    flag=0;
		    for(int i=0;i<120;i++)
		    printf("-");

			printf("\t\t\t\t\t Time: %s\n",ctime(&now));

			printf("CUSTOMER NAME: %s\n",s.name);

			printf("ROOM NUMBER: %s\n",s.roomnumber);

			printf("NUMBER OF DAYS: %s\n",s.time);
			  for(int i=0;i<120;i++)
		      printf("-");

			printf("\n\n\n\t*******************************THANK YOU FOR CHOOSING OUR HOTEL*****************************");

			flag=0;
			break;



		 }
		 if(flag==1)
		printf("\n\tRequested Customer could not be found!");
}
	getch();
	fclose(f);


   }


void room_rst(void){


	system("cls");

	printf("\n\n\t\t\t    ROOM SERVICE &RESTAURANT\n\n");


	printf("\n\nPress Any Key to See the Menu & Order Meal:");
	getch();
	system("cls");


	printf("\n\n\t\t\t\t    MENU\n\n");


	printf("\n\n\n\t\t\t\t\"BANGLADESHI CUSINE\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT.)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Biryani & Pulao",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Karahi",1200.00,"KG");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Shami Kababs",400.0,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Makhani",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Tandori Chicken",1050.00,"FULL");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Hyderabadi Chicken",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Chicken Handi Boneless",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Chicken Green Masala",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Chicken Achari",700.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Chicken Qorma",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Chicken Kofta",450.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",12,"Chicken Chargha",1300.00,"FULL");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",13,"Chicken Sindhi Biryani",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",14,"Nargisi Kofta",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",15,"Chapli Kababs",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",16,"Aloo Keema",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",17,"Mutton Karahi",1100.00,"KG");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",18,"Mutton Haandi",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",19,"Mutton Green Masala",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",20,"Mutton Qorma",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",21,"Plain Rice",300.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",22,"Mix Vegitable",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",23,"Andaa Chaana",350.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",24,"Daal",300.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",25,"Palak Paneer",450.00,"PLATE");




	printf("\n\n\n\n\t\t\t\t   \"BARBECUES\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT..)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Tikka",400.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Seekh Kababs",500.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Grilled Salmon Tikka",500.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Mutton Seekh Kababs",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Grilled Lamb Chops",750.00,"PLATE");



	printf("\n\n\n\n\t\t\t\t\"CHINESE & SOUPS\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT..)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Sizzler",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Shashlik",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Chicken Chilli Dry",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Tempure",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Chicken Chow Mien",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Chicken Sweet & Sour",700.00,"PLATE");


	printf("\n\n\n\n\t\t\t\t   \"SEA FOOD\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT..)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Karahi Prawn",1100.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Masala Fish",1000.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Prawn Tikka Masala",1050.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Tawa Chilli Prawn",1100.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Kurkuri Fried Fish",950.00,"PLATE");



	printf("\n\n\n\n\t\t\t     \"HAMBURGERS & SANDWICHES\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT..)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Zinger Burger",600.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Cheese Burger",650.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Beef Cheese Burger",600.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Oriental Chicken Burger",550.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Club Sandwich",400.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"French Fries",200.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",7,"Crispy Fried Burger",600.00,"PCS");





	printf("\n\n\n\n\t\t\t\t    \"DESSERTS\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT.)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Shahi Kheer",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Gulab Jamun",500.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Kulfi",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Rass Malai",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Halwa",600.00,"PLATE");





	printf("\n\n\n\n\t\t\t\t     \"OTHERS\"");
	printf("\n\n");

	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(BDT.)","Unit");


	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Plain Naan",50.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Roghani",70.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Tandori Rooti",40.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Paratha",60.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Bread",60.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Tea",150.00,"CUP");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Raita",100.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Coffee",200.00,"CUP");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Halwa Puri",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Lassi",200.00,"GLASS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Milk Shake",200.00,"GLASS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",12,"Omelette",120.00,"PCS");





	char ch='y';
	int bill,order_type;
	int i=0;
	printf("\n\n%c Please Order the Meal From the Above Menu:\n",4);


	printf("\n\n         Customer Name:");
	fflush(stdin);
	gets(s.name);

	//gotoxy(48,230);
	printf("Room Number:");
	//fflush(stdin);
	scanf("%d",&room_no_res);

	rest_charges=0; // this variable is for each item its not the final bill

	printf("\n\t %c Order Type(Restaurant=1 Room Service=2):",16);
	scanf("%d",&order_type);


	do{
		bill=0;
		printf("\n\n%c Category:",248);
		fflush(stdin);
		gets(res[i].item_chat);

		printf("\n%c Item Name:",248);
		fflush(stdin);
		gets(res[i].item_name);

		printf("\n%c Quantity:",248);
		fflush(stdin);
		scanf("%d",&res[i].unit);

		printf("\n%c Price:",248);
		scanf("%d",&res[i].charges);
        fflush(stdin);
		bill=res[i].unit*res[i].charges;

		rest_charges+=bill;// this will increment the cost of each item to the final bill

        printf("\n\nYou ordered %d %s",res[i].unit,res[i].item_name);
        printf("\nYour bill is :%d ", rest_charges);
		printf("\n\nDo You Want to Order Another Meal:\n");
 		i++;
		ch=getche();

	}

	while(ch=='y'||ch=='Y');






}





