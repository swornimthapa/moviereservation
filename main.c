#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct booking{char name[10];
			   char lname[10];
			   double ph;
			   int seat;
}*p,test;
struct login{char username[20];
 		 	 char password[20];	
}l;
void login();
void movies_list();  
void upcomming_movies();   
void book_ticket();      // for booking tickets
void spidertiming();     //for showing timing for spider man movie
void pushpatiming();       //for showing timing for puspha movie
void avengertiming();    // for showing timing for avenger moive
void peakstiming();      // for showing timing for 14 peaks movie
void hall();            //for showing hall details
void details();        //for getting details of the customer
void count();          //for counting number of detials in the file
void opencountfile();
void booking_status();
//void copydetails();
void cancel();
void file2delete();
void delete2file();
int spiderchoice=0,pushpachoice=0,avengerchoice=0,peakschoice=0,numoftic=0,count1,seatnumber=0,xchoice=0;
int seat[50]={0};
FILE *filep;
FILE *filetest,*cancel1;
int main()
{
	int ch;
	printf("\t\t=======================================================================");
	printf("\n\t\t\t\t MOVIE TICKET BOOKING \n");
	printf("\t\t=======================================================================");
	printf("\n\t\t\t\t LOGIN");
	login();
	do
	{
		system("cls");
		printf("\t\t\t                 Movie Ticket Booking System\n");
		printf("\t\t\t ==================================================================\n");
		printf("\t\t\t||             1- VIEW CURRENTLY SHOWING MOVIE LIST               ||\n");
		printf("\t\t\t||             2- BOOK TICKETS                                    ||\n");
		printf("\t\t\t||             3- VIEW UPCOMING MOVIE LIST                        ||\n");
		//printf("\t\t\t||             4- PRE-BOOKING OF UPCOMING MOVIES                  ||\n");
		printf("\t\t\t||             4- BOOKING STATUS                                  ||\n");
		printf("\t\t\t||             5- CANCEL TICKETS                                  ||\n");
		printf("\t\t\t||             6- Exit system:                                    ||\n");
		printf("\t\t\t||================================================================||\n");
		printf("\n\n\n\t\t\t\tEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				movies_list();
				printf("\n\n\n\t\tplease enter any key to continue.... ");
				getch();
				break;
			case 2:
				book_ticket();
				free(p);
				break;
			case 3:
				upcomming_movies();
				break;
			case 4:
				booking_status();
				break;	
			case 5:
				cancel();
				printf("\n\n\n\t\tplease enter any key to continue.... ");
				getch();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n\tInvalid input");
				printf("\n\n\n\t\tplease enter any key to continue.... ");
				getch();
				break;
		}
	}while(1);
	free(p);
	return 0;
}





void movies_list()
{	
	system("cls");
	printf("\n\t================================================================================================");
	printf("\n\t\tMOVIES LIST\t\t\t CODE \t\tPRICE                                                            ");                                                        
	printf("\n\t================================================================================================\n");
	printf("\n\n\t\t1. SPIDER MAN \t\t\t 01 \t\t 450");
	printf("\n\t\t2. PUSHPA \t\t\t 02 \t\t 350 ");
	printf("\n\t\t3. AVENGER \t\t\t 03 \t\t 500");
	printf("\n\t\t4. 14 PEAKS \t\t\t 04 \t\t 400 ");
}

void upcomming_movies()
{
	system("cls");
	printf("\n\t=================================================================================================");
    printf("\n\t\t    UPCOMING-MOVIES \t \t\t\t    RELEASE DATE  ");
    printf("\n\t=================================================================================================");
    printf("\n\n\t\t1.  BLACK PANTHER:WAKANDA FOREVER \t\t    NOVEMBER 11, 2022 ");
    printf("\n\t\t2.  AVATAR 2 \t\t\t\t\t    DECEMBER 16, 2022  ");
    printf("\n\t\t3.  MISSION IMPOSSIBLE 7 \t\t\t    SEPTEMBER 30, 2022");
    printf("\n\t\t4.  DOCTOR STRANGE IN THE MULTIVERSE OF MADNESS     MAY 6, 2022 ");
    printf("\n\t\t5.  SHERLOCK HOLMES 3 \t\t\t \t    DECEMBER 25,2020");
    printf("\n\t\t6.  MISSION IMPOSSIBLE 7\t\t\t    SEPTEMBER 30, 2022 ");
    printf("\n\t\t7.  THOR:LOVE AND THUNDER  \t\t\t    JULY 8, 2022 ");
    printf("\n\t\t8.  ONE PIECE FILM:RED \t\t\t\t    AUGUST 6,2022 ");
    printf("\n\t\t9.  FANTASTIC BEATS \t\t\t\t    APRIL 15, 2022 ");
    printf("\n\t\t10. HOTEL TRANSYLVANIA: TRANSFORMANIA \t\t    JANUARY 14, 2022");
    printf("\n\n\n\t\tplease enter any key to continue.... ");
	getch();
}

void book_ticket()
{
	int movie_code=0,i=0;
	spiderchoice=0;
	pushpachoice=0;
	avengerchoice=0;
	peakschoice=0;
	system("cls");
	printf("\n\t=================================================================================================");
	printf("\n\t\tMOVIES LIST\t\t\t\t CODE \t\t PRICE  ");
	printf("\n\t=================================================================================================");
	printf("\n\n\t\t1. SPIDER MAN \t\t\t\t 01 \t\t 450 ");
	printf("\n\t\t2. PUSHPA \t\t\t\t 02 \t\t 350 ");
	printf("\n\t\t3. AVENGERS \t\t\t\t 03 \t\t 500");
	printf("\n\t\t4. 14 PEAKS \t\t\t\t 04 \t\t 400 ");
	label1:
	printf("\n\n\t\t\t\tTo book ticket Enter movie code: ");
	scanf("%d",&movie_code);
	switch(movie_code)
	{
		case 01:
			printf("\n\t\tThe timing of the spider man movie are: ");
			spidertiming();
			break;
		case 02:
			printf("\n\t\tThe timing of the PUSPHA  movie are: ");
			pushpatiming();
			break;
		case 03:
			printf("\n\t\tThe timing of the AVENGER  movie are: ");
			avengertiming();
			break;
		case 04:
			printf("\n\t\tThe timing of the 14 peaks movie are: ");
			peakstiming();
			break;
		default:
			printf("\n\t\tInvalid movive code entered: ");
			goto label1;
			break;
	}
	if(spiderchoice!=0)
	{
		switch(spiderchoice)
		{
			case 1:
				filep=fopen("spider14feb.txt","a+");
				filetest=fopen("spider14feb.txt","r");
				details();
				break;
			case 2:
				filep=fopen("spider15feb.txt","a+");
				filetest=fopen("spider15feb.txt","r");
				details();
				break;
			case 3:
				filep=fopen("spider16feb.txt","a+");
				filetest=fopen("spider16feb.txt","r");
				details();
				break;
		case 4:
			filep=fopen("spider17feb.txt","a+");
			filetest=fopen("spider17feb.txt","r");
			details();
			break;
		}
	}
	else if(pushpachoice!=0)
	{
		switch(pushpachoice)
		{
			case 1:
				filep=fopen("pushpa14feb.txt","a+");
				filetest=fopen("pushpa14feb.txt","r");
				details();
				break;
			case 2:
				filep=fopen("pushpa15feb.txt","a+");
				filetest=fopen("pushpa15feb.txt","r");
				details();
				break;
			case 3:
				filep=fopen("pushpa16feb.txt","a+");
				filetest=fopen("pushpa16feb.txt","r");
				details();
				break;
			case 4:
				filep=fopen("pushpa17feb.txt","a+");
				filetest=fopen("pushpa17feb.txt","r");
				details();
				break;
		}
	}
	else if(avengerchoice!=0)
	{
		switch(avengerchoice)
		{
			case 1:
				filep=fopen("avenger14feb.txt","a+");
				filetest=fopen("avenger14feb.txt","r");
				details();
				break;
			case 2:
				filep=fopen("avenger15feb.txt","a+");
				filetest=fopen("avenger15feb.txt","r");
				details();
				break;
			case 3:
				filep=fopen("avenger16feb.txt","a+");
				filetest=fopen("avenger16feb.txt","r");
				details();
				break;
			case 4:
				filep=fopen("avenger17feb.txt","a+");
				filetest=fopen("avenger17feb.txt","r");
				details();
				break;
		}
	}
	else//(peakschoice!=0)
	{
		switch(peakschoice)
		{
			case 1:
				filep=fopen("peaks14feb.txt","a+");
				filetest=fopen("peaks14feb.txt","r");
				details();
				break;
			case 2:
				filep=fopen("peaks15feb.txt","a+");
				filetest=fopen("peaks15feb.txt","r");
				details();
				break;
			case 3:
				filep=fopen("peaks16feb.txt","a+");
				filetest=fopen("peaks16feb.txt","r");
				details();
				break;
			case 4:
				filep=fopen("peaks17feb.txt","a+");
				filetest=fopen("peaks17feb.txt","r");
				details();
				break;
		}
	}
	system("cls");
	printf("\n\t===============================");
	printf("\n\tPLEASE SCREENSHOT YOUR TICKETS");
	printf("\n\t==============================");
	printf("\n\t=======YOUR TICKET===========");
	printf("\n\t==============================\n\n\n");
	if(movie_code==01)
	{
		printf("\n\n\t\t\t\t\tSPIDER MAN MOVIE TICKET\n");
		printf("\t\t=======================================================================");
		for(i=0;i<numoftic;i++)
		{
			printf("\n\t\t||                       NAME=%s %s",(p+i)->name,(p+i)->lname);
			printf("\n\t\t||                       number=%.0lf",(p+i)->ph);
			printf("\n\t\t||                       SEAT NUMBER=.%d",(p+i)->seat);
			printf("\n\t\t||                       price=NRS. %d",450);
			switch(xchoice)
			{
				case 1:
			        printf("\n\t\t||\t                 Timing=14th feb 2022 at 8 A.M.");
					break;
				case 2:
					printf("\n\t\t||\t                 Timing= 15th feb 2022 at 7 P.M");
					break;
				case 3:
					printf("\n\t\t||\t                 Timing=16th feb 2022 at 12 P.M.");
					break;
				case 4:
					printf("\n\t\t||\t                 Timing=17th feb 2022 at 3 P.M.");
					break;
			}
			printf("\n\t\t=======================================================================");
		}
		printf("\n\t\t\t\t\t\t\t\t\tTOTAL PRICE=%d",numoftic*450);
	}
	if(movie_code==02)
	{
		printf("\n\n\t\t\t\t\tPUSHPA MOVIE TICKET\n");	
		printf("\t\t=======================================================================");
		for(i=0;i<numoftic;i++)
		{
			printf("\n\t\t||                       NAME=%s %s",(p+i)->name,(p+i)->lname);
			printf("\n\t\t||                       number=%.0lf",(p+i)->ph);
			printf("\n\t\t||                       SEAT NUMBER=.%d",(p+i)->seat);
			printf("\n\t\t||                       price=NRS. %d",350);
			switch(xchoice)
			{
				case 1:
			        printf("\n\t\t||\t                 Timing=14th feb 2022 at 12 P.M.");
					break;
				case 2:
					printf("\n\t\t||\t                 Timing= 15th feb 2022 at 3 P.M");
					break;
				case 3:
					printf("\n\t\t||\t                 Timing=16th feb 2022 at 8 A.M.");
					break;
				case 4:
					printf("\n\t\t||\t                 Timing=17th feb 2022 at 7 P.M.");
					break;
			}
			printf("\n\t\t=======================================================================");
		}
		printf("\n\t\t\t\t\t\t\t\t\tTOTAL PRICE=%d",numoftic*350);
	}
	if(movie_code==03)
	{
		printf("\n\n\t\t\t\t\tAVENGER MOVIE TICKET\n");
		printf("\t\t=======================================================================");
		for(i=0;i<numoftic;i++)
		{
			printf("\n\t\t||                       NAME=%s %s",(p+i)->name,(p+i)->lname);
			printf("\n\t\t||                       number=%.0lf",(p+i)->ph);
			printf("\n\t\t||                       SEAT NUMBER=.%d",(p+i)->seat);
			printf("\n\t\t||                       price=NRS. %d",500);
			switch(xchoice)
			{
				case 1:
			        printf("\n\t\t||\t                 Timing=14th feb 2022 at 3 P.M.");
					break;
				case 2:
					printf("\n\t\t||\t                 Timing= 15th feb 2022 at 12 P.M");
					break;
				case 3:
					printf("\n\t\t||\t                 Timing=16th feb 2022 at 8 A.M.");
					break;
				case 4:
					printf("\n\t\t||\t                 Timing=17th feb 2022 at 7 P.M.");
					break;
			}
			printf("\n\t\t=======================================================================");
		}
		printf("\n\t\t\t\t\t\t\t\t\tTOTAL PRICE=%d",numoftic*500);
	}
	if(movie_code==04)
	{
		printf("\n\n\t\t\t\t\t14 PEAKS MOVIE TICKET\n");
		printf("\t\t=======================================================================");
		for(i=0;i<numoftic;i++)
		{
			printf("\n\t\t||                       NAME=%s %s",(p+i)->name,(p+i)->lname);
			printf("\n\t\t||                       number=%.0lf",(p+i)->ph);
			printf("\n\t\t||                       SEAT NUMBER=.%d",(p+i)->seat);
			printf("\n\t\t||                       price=NRS. %d",400);
			switch(xchoice)
			{
				case 1:
			        printf("\n\t\t||\t                  Timing=14th feb 2022 at 7 P.M.");
					break;
				case 2:
					printf("\n\t\t||\t                 Timing= 15th feb 2022 at 8 A.M");
					break;
				case 3:
					printf("\n\t\t||\t                 Timing=16th feb 2022 at 6 P.M.");
					break;
				case 4:
					printf("\n\t\t||\t                 Timing=17th feb 2022 at 6 P.M.");
					break;
			}
			printf("\n\t\t=======================================================================");
		}
		printf("\n\t\t\t\t\t\t\t\t\tTOTAL PRICE=%d",numoftic*400);
	}
	getch();
}
void details()
{
	spiderchoice=0;
	pushpachoice=0;
	avengerchoice=0;
	peakschoice=0;
	int i=0;
	int ti=0;
	if(filep == NULL)
    {
        printf("ERROR!!...FILE COULDNOT BE OPENED");
        exit(0);
    }
    if(filetest==NULL)
    {
        printf("ERROR!!...FILE COULDNOT BE OPENED");
        exit(0);
   	}
	printf("\n\t\tFill details: \n");
	printf("\n\n\tenter how many tickets you want to buy: ");
	scanf("%d",&numoftic);
	printf("\n\t==========================================");
	fflush(stdin);
	p=(struct booking*)calloc(numoftic,sizeof(struct booking));
	if(p==NULL)
	{
		printf("\n\tERROR!!!!....MEMORY IS NOT ALLOCATED");
		exit(0);
	}
	for(ti=0;ti<numoftic;ti++)
	{
		
		printf("\n\tENTER THE FIRST NAME OF %d PERSON:",ti+1);
		gets((p+ti)->name);
		fflush(stdin);
		printf("\n\tENTER THE LAST NAME OF %d PERSON:",ti+1);
		gets((p+ti)->lname);
		fflush(stdin);
		printf("\n\tENTER THE PHONE NUMBER OF %d PERSON:",ti+1);
		scanf("%lf",&(p+ti)->ph);
		fflush(stdin);
		label2:
		printf("\n\tENTER THE SEAT NUMBER:");
		scanf("%d",&(p+ti)->seat);
		fflush(stdin);
		while(fread(&test,sizeof(struct booking),1,filetest)>0)   
    	{
			if(test.seat==(p+ti)->seat)
			{
				printf("\n\tSEAT ALREADY TAKEN");
				goto label2;
			}
		}
		
	}
	fwrite(p,sizeof(struct booking),numoftic,filep);
	fclose(filetest);
	fclose(filep);
}

void spidertiming()
{
	spiderchoice=0;
	printf("\n\n\t\t1. 14th feb 2022 at 8 A.M.");
	printf("\n\n\t\t2. 15th feb 2022 at 7 P.M");
	printf("\n\n\t\t3. 16th feb 2022 at 12 P.M.");
	printf("\n\n\t\t4. 17th feb 2022 at 3 P.M.");
	flag3:
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d",&spiderchoice);
	xchoice=spiderchoice;
	switch(spiderchoice)
	{
		case 1:
			hall();
			break;
		case 2:
			hall();
			break;
		case 3:
			hall();
			break;
		case 4:
			hall();
			break;
		default:
			printf("INVALID INPUT");
			goto flag3;
			break;	
	}
}
void pushpatiming()
{
	pushpachoice=0;
	printf("\n\n\t\t1. 14th feb 2022 at 12 P.M.");
	printf("\n\n\t\t2. 15th feb 2022 at 3 P.M.");
	printf("\n\n\t\t3. 16th feb 2022 at 8 A.M.");
	printf("\n\n\t\t4. 17th feb 2022 at 7 P.M.");
	flag4:
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d",&pushpachoice);
	xchoice=pushpachoice;
	switch(pushpachoice)
	{
		case 1:
			hall();
			break;
		case 2:
			hall();
			break;
		case 3:
			hall();
			break;
		case 4:
			hall();
			break;
		default:
			printf("INVALID INPUT");
			goto flag4;
			break;	
	}
}
void avengertiming()
{
	avengerchoice=0;
	printf("\n\n\t\t1. 14th feb 2022 at 3 P.M.");
	printf("\n\n\t\t2. 15th feb 2022 at 12 P.M.");
	printf("\n\n\t\t3. 16th feb 2022 at 8 A.M.");
	printf("\n\n\t\t4. 17th feb 2022 at 7 P.M.");
	flag5:
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d",&avengerchoice);
	xchoice=avengerchoice;
	switch(avengerchoice)
	{
		case 1:
			hall();
			break;
		case 2:
			hall();
			break;
		case 3:
			hall();
			break;
		case 4:
			hall();
			break;
		default:
			printf("INVALID INPUT");
			goto flag5;
			break;	
	}
}
void peakstiming()
{
	peakschoice=0;
	printf("\n\n\t\t1. 14th feb 2022 at 7 P.M.");
	printf("\n\n\t\t2. 15th feb 2022 at 8 A.M");
	printf("\n\n\t\t3. 16th feb 2022 at 6 P.M.");
	printf("\n\n\t\t4. 17th feb 2022 at 6 P.M.");
	flag6:
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d",&peakschoice);
	xchoice=peakschoice;
	switch(peakschoice)
	{
		case 1:
			hall();
			break;
		case 2:
			hall();
			break;
		case 3:
			hall();
			break;
		case 4:
			hall();
			break;
		default:
			printf("INVALID INPUT");
			goto flag6;
			break;	
	}
}


void count() //for counting the number of details in the file;
{
	count1=0;
	if(spiderchoice!=0)
	{
		switch(spiderchoice)
		{
			case 1:
				filetest=fopen("spider14feb.txt","r");
				opencountfile();
				break;
			case 2:	
				filetest=fopen("spider15feb.txt","r");
				opencountfile();
				break;
			case 3:
				filetest=fopen("spider16feb.txt","r");
				opencountfile();
				break;
			case 4:
				filetest=fopen("spider17feb.txt","r");
				opencountfile();
				break;
		}
	}
	else if(pushpachoice!=0)
	{
		switch(pushpachoice)
		{
			case 1:
				filetest=fopen("pushpa14feb.txt","r");
				opencountfile();
				break;
			case 2:	
				filetest=fopen("pushpa15feb.txt","r");
				opencountfile();
				break;
			case 3:
				filetest=fopen("pushpa16feb.txt","r");
				opencountfile();
				break;
			case 4:
				filetest=fopen("pushpa17feb.txt","r");
				opencountfile();
				break;
		}
	}
	else if(avengerchoice!=0)
	{
		switch(avengerchoice)
		{
			case 1:
				filetest=fopen("avenger14feb.txt","r");
				opencountfile();
				break;
			case 2:	
				filetest=fopen("avenger15feb.txt","r");
				opencountfile();
				break;
			case 3:
				filetest=fopen("avenger16feb.txt","r");
				opencountfile();
				break;
			case 4:
				filetest=fopen("avenger17feb.txt","r");
				opencountfile();
				break;
		}
	}
	else //(peakschoice!=0)
	{
		switch(peakschoice)
		{
			case 1:
				filetest=fopen("peaks14feb.txt","r");
				opencountfile();
				break;
			case 2:	
				filetest=fopen("peaks15feb.txt","r");
				opencountfile();
				break;
			case 3:
				filetest=fopen("peaks16feb.txt","r");
				opencountfile();
				break;
			case 4:
				filetest=fopen("peaks17feb.txt","r");
				opencountfile();
				break;
		}
	}
}

void opencountfile()
{
	if(filetest== NULL)
    {
        printf("ERROR!!...FILE COULDNOT BE OPENED");
        exit(0);
    }
    while(fread(&test,sizeof(struct booking),1,filetest)>0)   
    {
		count1++;
	}
    fclose(filetest);
}


void hall()
{
	count();
	int seatcount=0;
	char name[count1][10];
	char h[51][10]={"EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY"};
	int i=0,j=0,index=1;
	if(spiderchoice!=0)
	{
		switch(spiderchoice)
		{
			case 1:
				filetest=fopen("spider14feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
	  		case 2:
		  		filetest=fopen("spider15feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 3:
				filetest=fopen("spider16feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 4:
				filetest=fopen("spider17feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;		
		}
	}
	else if(pushpachoice!=0)
	{
		switch(pushpachoice)
		{
			case 1:
				filetest=fopen("pushpa14feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
	 	 	case 2:
			  	filetest=fopen("pushpa15feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 3:
				filetest=fopen("pushpa16feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 4:
				filetest=fopen("pushpa17feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;		
		}
	}
	else if(avengerchoice!=0)
	{
		switch(avengerchoice)
		{
			case 1:
				filetest=fopen("avenger14feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
		  	case 2:
			  	filetest=fopen("avenger15feb.txt","r");
				if(filetest==NULL)
   				{
    	    		printf("ERROR!!...FILE COULDNOT BE OPENED");
    	    		exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 3:
				filetest=fopen("avenger16feb.txt","r");
				if(filetest==NULL)
   				{
    	    		printf("ERROR!!...FILE COULDNOT BE OPENED");
    	    		exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
	    		{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 4:
				filetest=fopen("avenger17feb.txt","r");
				if(filetest==NULL)
   				{
   		     		printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;		
		}
	}
	else//(peakschoice!=0)
	{
		switch(peakschoice)
		{
			case 1:
				filetest=fopen("peaks14feb.txt","r");
				if(filetest==NULL)
   				{
    	    		printf("ERROR!!...FILE COULDNOT BE OPENED");
    	    		exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
	 	 	case 2:
			  	filetest=fopen("peaks15feb.txt","r");
				if(filetest==NULL)
   				{
    	    		printf("ERROR!!...FILE COULDNOT BE OPENED");
    	    		exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 3:
				filetest=fopen("peaks16feb.txt","r");
				if(filetest==NULL)
   				{
        			printf("ERROR!!...FILE COULDNOT BE OPENED");
        			exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;
			case 4:
				filetest=fopen("peaks17feb.txt","r");
				if(filetest==NULL)
   				{
    	    		printf("ERROR!!...FILE COULDNOT BE OPENED");
    	    		exit(0);
    			}
				while(fread(&test,sizeof(struct booking),1,filetest)>0)  
    			{
					seat[j]=test.seat;          
					strcpy(name[j],test.name);
    				j++;
				}
				fclose(filetest);
				break;		
		}
	}
	system("cls");
	printf("      ________________________________________________________________________________________________________________________________________________________________ \n ");
	printf("    /                                                                    SCREEN                                                                                      \\\n");
	printf("    /__________________________________________________________________________________________________________________________________________________________________\\\n\n\n\n ");
	j=0;
	for(i=0;i<count1;i++)
	{
		strcpy(h[seat[i]],name[i]);           
	}
	for(i=0;i<5;i++)
	{
		
		for(j=0;j<10;j++)
		{
			printf("\t0%d. %s",index+j,h[j+index]);	
		}
		index=index+10;
		printf("\n");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\tAVAILABLE SEAT: %d",50-count1);
	printf("\n\t\t\t\t\t\t\t\t\t\t\tOCCUPIED SEAT: %d",count1);
}

void booking_status()
{
	spiderchoice=0;
	pushpachoice=0;
	avengerchoice=0;
	peakschoice=0;
	int movie_code1=0;
	system("cls");
	movies_list();
	label3:
	printf("\n\n\t\t\t\t Enter the movie code to  check the status: ");
	scanf("%d",&movie_code1);
	switch(movie_code1)
	{
		case 01:
			printf("\n\t\tThe timing of the spider man movie are: ");
			spidertiming();
			break;
		case 02:
			printf("\n\t\tThe timing of the PUSPHA  movie are: ");
			pushpatiming();
			break;
		case 03:
			printf("\n\t\tThe timing of the AVENGER  movie are: ");
			avengertiming();
			break;
		case 04:
			printf("\n\t\tThe timing of the 14 peaks movie are: ");
			peakstiming();
			break;
		default:
			printf("\n\t\tInvalid movive code entered: ");
			goto label3;
			break;
	}
    printf("\n\n\n\t\tplease enter any key to continue.... ");
	getch();
}


void cancel()
{
	int movie_code=0;
	//char x;	
	movies_list();
	printf("\n\n\tPLEASE NOTE : 50 PERCENT AMOUNT WILL BE DEDUCTED AS A CANCELLATION CHARGE");
	spiderchoice=0;
	pushpachoice=0;
	avengerchoice=0;
	peakschoice=0;
	printf("\n\n\tENTER THE MOIVE CODE:");
	scanf("%d",&movie_code);
	switch(movie_code)
	{
		case 01:
			printf("\n\t\tThe timing of the spider man movie are: ");
			spidertiming();
			break;
		case 02:
			printf("\n\t\tThe timing of the PUSPHA  movie are: ");
			pushpatiming();
			break;
		case 03:
			printf("\n\t\tThe timing of the AVENGER  movie are: ");
			avengertiming();
			break;
		case 04:
			printf("\n\t\tThe timing of the 14 peaks movie are: ");
			peakstiming();
			break;
		default:
			printf("\n\t\tInvalid movive code entered: ");
			break;
	}
	//label4:
	printf("\n\tENTER FOR WHICH SEAT YOU WANT TO CANCEL THE TICKET:");
    scanf("%d",&seatnumber);
	switch(spiderchoice)
	{
		case 1:
			filetest=fopen("spider14feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("spider14feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    		/*printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag2;
			}
		//	else
			//{
				printf("\n\tINVALID INPUT");
			}
			flag2:*/
    		break;
    	case 2:
    		filetest=fopen("spider15feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("spider15feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag3;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag3:*/
    		break;
    	case 3:
    		filetest=fopen("spider16feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("spider16feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag4;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag4:*/
    		break;
    	case 4:
    		filetest=fopen("spider17feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("spider17feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag5;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag5: */
    		break;
	}
	switch(pushpachoice)
	{
		case 1:
			filetest=fopen("pushpa14feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("pushpa14feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag6;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag6:*/
    		break;
    	case 2:
    		filetest=fopen("pushpa15feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("pushpa15feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag7;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag7:*/
    		break;
    	case 3:
    		filetest=fopen("pushpa16feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("pushpa16feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag8;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag8:*/
    		break;
    	case 4:
    		filetest=fopen("pushpa17feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("pushpa17feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    		/*printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag9;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag9:*/
    		break;
	}
	switch(avengerchoice)
	{
		case 1:
			filetest=fopen("avenger14feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("avenger14feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    		/*printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag10;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag10:*/
    		break;
    	case 2:
    		filetest=fopen("avenger15feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("avenger15feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag11;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag11:*/
    		break;
    	case 3:
    		filetest=fopen("avenger16feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("avenger16feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag12;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag12:*/
    		break;
    	case 4:
    		filetest=fopen("avenger17feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("avenger17feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag13;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag13:*/
    		break;
	}
	switch(peakschoice)
	{
		case 1:
			filetest=fopen("peaks14feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("peaks14feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    		/*printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag14;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag14:*/
    		break;
    	case 2:
    		filetest=fopen("peaks15feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("peaks15feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag15;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag15:*/
    		break;
    	case 3:
    		filetest=fopen("peaks16feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("peaks16feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag16;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag16:*/
    		break;
    	case 4:
    		filetest=fopen("peaks17feb.txt","r");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			file2delete();
    		fclose(filetest);
    		filetest=fopen("peaks17feb.txt","w+");
			if(filetest==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
			delete2file();
    		fclose(filetest);
    	/*	printf("\n\tDO YOU WANT TO CANCEL ANOTHER TICKET(Y/N):");
    		x=getche();
    		if(x=='y' || x== 'Y')
    		{
    			goto label4;
			}
			else if(x=='n' || x=='N')
			{
				goto flag17;
			}
			else
			{
				printf("\n\tINVALID INPUT");
			}
			flag17: */
    		break;
	}
} 

void file2delete()
{
	cancel1=fopen("delete.txt","w+");
	if(cancel1==NULL)
	{
		printf("ERROR!!...FILE COULD NOT BE OPENED");
		exit(0);
	}
	while(fread(&test,sizeof(struct booking),1,filetest)>0)   
   	{
		if(test.seat!=seatnumber)
		{
			fwrite(&test,sizeof(struct booking),1,cancel1);
		}
	}
	fclose(cancel1);		
}
void delete2file()
{
	
	cancel1=fopen("delete.txt","r");
    if(cancel1==NULL)
    {
    	printf("ERROR!!...FILE COULD NOT BE OPENED");
		exit(0);
	}
	while(fread(&test,sizeof(struct booking),1,cancel1)>0)   
   	{
		fwrite(&test,sizeof(struct booking),1,filetest);
	}
	fclose(cancel1);
	printf("\n\t50 PERCENT AMOUNT HAS BEEN DEDUCTED AS A CANCELLATION CHARGE");
} 

void login()
{
	int t=0,i=0,choice=0;
	char username[20];
	char password[20];
	char pw,space=' ';
	FILE *pointer;
	printf("\n\t[1]. CREATE A NEW ACCOUNT");
	printf("\n\t[2]. LOGIN");
	flag5:
	printf("\n\tENTER THE CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			pointer=fopen("login.txt","w");
			if(pointer==NULL)
			{
				printf("ERROR!!...FILE COULDNOT BE OPENED");
				exit(0);
			}
			printf("\n\tENTER THE NEW USERNAME:");
		    scanf("%s",&l.username);
			printf("\tENTER THE NEW PASSWORD:");
			while((pw=getch())!=13)  // 13 is the ASCII of enter.. this loop hides the password.
			{
				l.password[i]=pw;
				i++;
				printf("*");
			}
			l.password[i]='\0';
			fwrite(&l,sizeof(l),1,pointer);
			fclose(pointer);
			goto flag;
			break;
		case 2:
			flag:
			i=0;
			printf("\n\tENTER THE DETAILS FOR LOGIN:");
			again:
			printf("\n\tENTER THE USERNAME:");
			scanf("%s",username);
			printf("\tENTER THE PASSWORD:");
			while((pw=getch())!=13)  // 13 is the ASCII of enter.. this loop hides the password.
			{
				password[i]=pw;
				i++;
				printf("*");
			}
			password[i]='\0';
			pointer=fopen("login.txt","r");
			if(pointer==NULL)
			{
				printf("ERROR!!...FILE COULD NOT BE OPENED");
				exit(0);
			}
            while(fread(&l,sizeof(l),1,pointer))
            {
            	if(strcmp(username,l.username)==0)
				{
					if(strcmp(password,l.password)==0)
					{
				 		printf("\n\t LOGIN SUCESSFULL....WELCOME USER");
						printf("\n\tpress any key to continue........");
						getch();  // holds the console
					}
				}
			}
    		if(strcmp(username,l.username)!=0 || strcmp(password,l.password)!=0)
			{
				i=0;
				if(t<1)
				{
		   			printf("\n\tINVALID USERNAME OR PASSWORD...TRY AGAIN:");	
				}
				t++;
				if(t==2)
				{
					printf("\n\tSORRY!!..you have entered wrong username and password for 2 times!!");
					exit(0);
				}
	    		goto again;
			}
		    break; 
		default:
			printf("INVALID INPUT");
			goto flag5;
	}
}


