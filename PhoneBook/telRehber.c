#include <stdio.h>

// Here we have defined our variables that we need to use in our functions.
int choice;
int flag=-1;
void menu();
void add_number();      
void search();
void list();
void save();
void readDatabase();    



// We defined our structure, which contains 3 arrays and stores the information of 1 person in total.
struct Person
{
	char name[20];	
	char lastname[20];
	int phonenumber[20];
};

struct Person personData[500];



int main()
{
	system("color 3f"); // We made the background color of our guide to AQUA.
    readDatabase(); /// When our program is opened for the first time, it reads and memorizes the previously saved contacts.
    int flag2 = 0;  // we have defined an int variable for control
    
    while(flag2 == 0)  // As long as the 4 key is not pressed, the following operations are performed.
    {
    	
    	menu(); // the menu function is called.
    	
    	if(choice == 1) 
        {
        	system("cls"); // the screen is cleared.
    	    add_number(); // the required function is called.
   	    }
	    else if(choice == 2)
	    {
	  	    system("cls");// the screen is cleared.
  		    search();     // the required function is called.
     	}
	    else if(choice == 3)
     	{
     	   system("cls");// the screen is cleared.
		   list(); // the required function is called.
		}
     	else if(choice == 4)
    	{
    		save();  // the required function is called.
		    system("cls");// the screen is cleared.
		    flag2 = 1;  
    	}
        else
        {
    	       printf("Wrong Choice!");
    	       menu();   // the required function is called.
        } 
	}
    
	return 0;
}

void menu()
{	
	printf("--------------------------\n| Phone Book Application | \n--------------------------\n");
	printf("Main menu:\n");
	printf("  (1) Add new entry\n");
	printf("  (2) Find an entry by name\n");
	printf("  (3) Print the phone book\n");	
	printf("  (4) Save the phone book & quit\n");
	printf("Please enter your selection:");
	scanf("%d",&choice);	
} 



void add_number()
{
	printf("--------------------------\n| Phone Book Application | \n--------------------------\n");
	printf("\n");
	printf("Adding New Entry:");
	printf("\n");   
	
	flag=flag+1;  // a counter to know how many people have been entered
	
	printf("\nPlease enter the first name: ");
    scanf("%s", personData[flag].name);
    
	
    printf("Please enter the last name: ");
    scanf("%s", personData[flag].lastname);
    
    printf("Please enter the phone number: ");
    scanf("%s", personData[flag].phonenumber);
    
    // required variables have been received and assigned to our personData structure.
    
    system("cls"); // the screen is cleared.
	
}



void list()
{
    
	int i;
	printf("--------------------------\n| Phone Book Application | \n--------------------------\n");
    printf("\n");    


	printf("Recorded Entries:\n");
	printf("\n");

	printf("List No\t\tFirst Name\t     Last Name\t        Phone Number\n");
	printf("------     ---------------  ------------------    ------------------\n");
	
	
	for(i=0; i <= flag; i++)   // as many people as the flag variable were entered in our directory.
	{ 
		printf("%d", i+1 );
        printf("%25s", personData[i].name) ;
		printf("%20s", personData[i].lastname);
		printf("%22s\n", personData[i].phonenumber);// we printed a person in the guide.
	}
	
			
	printf("\n");
	printf("Enter any character to return main menu...");  
	getch();
	
	system("cls");  
	
}



void search()
{		
    int i,j;
    
    int u=0;
	char searchingArray[40]; // we created an array to assign the letters entered while searching to an array.
	
    
   	printf("--------------------------\n| Phone Book Application | \n--------------------------\n");
	printf("Searching on the Phone Book\n");
	printf("Please enter the first letters of the name(max. 3 characters):");
	
	
	gets(searchingArray); // we assigned the letters entered while searching to an array.
	
	int sayac=0;   // We assigned an int variable to determine how many letters the searched word has.
	
	gets(searchingArray);
	
	
	while(searchingArray[sayac] != '\0')   
	{
		sayac++;  // we found how many letters the searched word is.
	}
	
	system("cls");
	printf("--------------------------\n| Phone Book Application | \n--------------------------\n");
	printf("Searching on the Phone Book\n");
	printf("Keyword is %s", searchingArray); // we printed on the screen what letters the user entered to search.
	printf("\n");
	printf("\n");
	
	
	printf("List No\t\tFirst Name\t     Last Name\t        Phone Number\n");
	printf("------     ---------------  ------------------    ------------------\n");
	
	
	if(sayac==1) /// If 1 letter is typed, the following operations are done.
	{ 
		for(i=0; i<=flag; i++)  // To scan all contacts in database.txt i get all values from 0 to flag variable. (Our flag value is the number of people in the directory.)
		{
			if(searchingArray[0] == personData[i].name[0]) // If the single letter entered by the user is equal to the first letters of the persons in the person structure, the following actions are performed.
			{
				printf("%d", i+1 );
                printf("%25s", personData[i].name) ;
	        	printf("%20s", personData[i].lastname);
	        	printf("%22s\n", personData[i].phonenumber);	
			}
		}
	}
	else if(sayac==2) // If 2 letters are typed, the following operations are done.
	{
		for(i=0; i<=flag; i++) // To scan all contacts in database.txr i get all values from 0 to flag variable. (Our flag value is the number of people in the guide.)
		{
			if(searchingArray[0] == personData[i].name[0]  && searchingArray[1] == personData[i].name[1]) // If the first and second letters entered by the user are equal to the first and second letters of the people in the person structure, the following actions are done.
			{
      	   		printf("%d", i+1 );
                printf("%25s", personData[i].name) ;
	         	printf("%20s", personData[i].lastname);
	         	printf("%22s\n", personData[i].phonenumber);	
			}
		}	
	}
	else if(sayac==3) // If 3 letters are typed, the following operations are done.
	{
		for(i=0; i<=flag; i++)  // To scan all contacts in database.txr i get all values from 0 to flag variable. (Our flag value is the number of people in the guide.)
		{
			if(searchingArray[0] == personData[i].name[0]  && searchingArray[1] == personData[i].name[1]  && searchingArray[2] == personData[i].name[2])  // If the 3 letters entered by the user are equal to the first 3 letters of the people in the person structure, the following operations are done.
			{
				printf("%d", i+1 );
                printf("%25s", personData[i].name) ;
	        	printf("%20s", personData[i].lastname);
	    	    printf("%22s\n", personData[i].phonenumber);	
			}
		}	
	}
	else // If more than 3 letters are written, the following operations are done.
	{
		printf("Wrong entry.Please enter any character to return main menu... ");
		goto entry; // go to the entry tag.
	}
		printf("Enter any character to return main menu...");  
        getch();
        system("cls");
        
        entry:  // If more than 3 letters are entered, it will come here because of the goto function.
        getch();
        system("cls");
        main(); // If more than 3 letters are entered, it returns to the main function, that is, the main menu.
	}
	

void save() // Contacts entered in the directory are saved in database.txt file.
{
	FILE *mainfile = fopen("database.txt" , "w+");
	int i;
	
    for(i=0; i <= flag; i++)
	{
	  //printf("%d  ", i+1 );
		fprintf( mainfile,"%s  ", personData[i].name);
		fprintf( mainfile,"%s  ", personData[i].lastname);
		fprintf( mainfile,"%s\n", personData[i].phonenumber);	
		
	}  
	
	fclose(mainfile);
}


void readDatabase() // Contacts entered in the directory are read from the database.txt file.
{
	FILE *mainfile = fopen("database.txt","r+");
	int i;
	if(mainfile != NULL)
	{
		for(i=0; i<500; i++)
		{
			fscanf( mainfile,"%s  ", personData[i].name);
	    	fscanf( mainfile,"%s  ", personData[i].lastname);
		    fscanf( mainfile,"%s\n", &personData[i].phonenumber);	
		    
		    if(feof(mainfile) )
		    {
		    	break;
			}
		}
		flag = i;
	}
	else
	{
		return;
	}
}

