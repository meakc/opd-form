/*
---------------------
OPD REGISTRATION FORM
---------------------
A Project For Mid term Evaluation
By:-
Abhishek Kumar Choudahry 2K21/B6/25
Anand Jha 2K21/B6/52

Submitted to :-
Ms. Gull Kaur 
*/

//headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define dash "-------------------------------------------------------------------------\n"


	struct user
{
    char userID[50];
    char username[50];
    char password[50];
};

struct patient
{
    char name[50];
    char age[6];
    char gender[11];
    char address[100];
    char depar[20];
    char mobile[15];

};

int opdregistration()
{
    char inp[50];
    printf("\n\nNew patient or revisit?: ('N or R')  ");
    fgets(inp,50,stdin);
    char str1[]="N\n";
    if (strcmp(inp,str1)==0)
    {
        printf ("--------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tWelcome to OPD registration Page\n");
        printf ("--------------------------------------------------------------------------------------\n\n");
    
        struct patient p1;

        printf("Enter Patient Name:");
        fgets(p1.name,50,stdin);
        printf("Enter Age:");
        fgets(p1.age, 6, stdin);
        printf("Address:");
        fgets(p1.address, 100, stdin);
        printf("Department :");
        fgets(p1.depar, 20, stdin);
        printf("Gender : ");
        fgets(p1.gender, 11, stdin);
        printf("Enter your Mobile number:");
        fgets(p1.mobile,15, stdin);

        FILE *outfile;

    // open file for writing
    outfile = fopen ("patient_data.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }


    // write struct to file
    fwrite (&p1, sizeof(struct patient), 1, outfile);
    fclose(outfile);

    //creating OPD registration Form
    FILE *filePointer;

    filePointer = fopen("reg.txt", "w");

		// Check if this filePointer is null
		// which maybe if the file does not exist
		if (filePointer == NULL)
		{
			printf("reg.txt file failed to open.");
		}
		else
		{

			printf("The file is now opened.\n");

			// Write the dataToBeWritten into the file
			//fprintf(filePointer, dash);
			//fprintf(filePointer, "\t\t\t\t\t HOSPITAL NAME \n\n");
			//fprintf(filePointer, dash);

			// writing in the file using fputs()
			fprintf(filePointer, "-----------------------------\n");
			fprintf(filePointer, "PATIENT DETAILS");
			fprintf(filePointer, "\n-----------------------------\n");
			fprintf(filePointer, "Name - %s", p1.name);
			// fputs("age-",filePointer);
			fprintf(filePointer, "Age - %s", p1.age);
			fprintf(filePointer, "Address- %s", p1.address);
			fprintf(filePointer, "Mobile no. :- %s", p1.mobile);
			fprintf(filePointer, "Department :- %s", p1.depar);
			fprintf(filePointer, "----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			int i;
			for (i = 0; i <= 34; i++)
			{
				fprintf(filePointer, "\n");
			}
			fprintf(filePointer, " \t\t\tDoctor's sign");

			// Closing the file using fclose()
			fclose(filePointer);

			// printf("Data successfully written in file pro.txt\n");
			// printf("The file is now closed.\n");
            printf(dash);
            printf("\n\nYour OPD registration form is now named as reg.txt.\n\n ");
            printf(dash);
    
    }
    }
    else if (strcmp(inp,"R\n")==0)
    {
        printf ("--------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tWelcome to OPD Revisitation Form Page\n");
        printf ("--------------------------------------------------------------------------------------\n\n");
        //date();

        char name[50];
        char mobile[15];

        FILE *infile;
        struct patient p1;


        printf("\nPlease Enter Name, Mobile Number to Proceed\n\n");
        printf("\n\nName: ");
        fgets(name,50,stdin);
        printf("\nMobile: ");
        fgets(mobile,15,stdin);

        infile = fopen ("patient_data.txt", "r");
        if (infile == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }

        // read file contents till end of file

        while(fread(&p1, sizeof(struct patient), 1, infile))
        {
            if((strcmp(name,p1.name) == 0) && \
            (strcmp(mobile, p1.mobile) ==0))
            {

                //creating OPD registration Form
            FILE *filePointer;

            filePointer = fopen("reg1.txt", "w");

                // Check if this filePointer is null
                // which maybe if the file does not exist
            if (filePointer == NULL)
            {
                printf("\nreg1.txt file failed to open.\n");
            }
            else
            {

                printf("The file is now opened.\n");

                // writing in the file using fputs()
                fprintf(filePointer, "-----------------------------\n");
                fprintf(filePointer, "PATIENT DETAILS");
                fprintf(filePointer, "\n-----------------------------\n");
                fprintf(filePointer, "Name - %s", p1.name);
                // fputs("age-",filePointer);
                fprintf(filePointer, "Age - %s", p1.age);
                fprintf(filePointer, "Address- %s", p1.address);
                fprintf(filePointer, "Mobile no. :- %s", p1.mobile);
                fprintf(filePointer, "Department :- %s", p1.depar);
                fprintf(filePointer, dash);
                fprintf(filePointer,"Visit No : 2\n");
                fprintf(filePointer, "----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                for (i = 0; i <= 34; i++)
                {
                    fprintf(filePointer, "\n");
                }
                fprintf(filePointer, "\t\t\t\tDoctor's sign");

                // Closing the file using fclose()
                fclose(filePointer);
                printf("\nYour OPD registration form is now named as reg1.txt.\n \n");
        
            }



                break;
            }    
         }
    }
    else{
        printf("Wrong Input!\n");
        opdregistration();
    }
    
    return 0;
}

int login()
{
    //system("cls");
    printf ("--------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tWelcome to Login Page\n");
    printf ("--------------------------------------------------------------------------------------\n\n");
    //date();

    char username[50];
    char password[50];

    FILE *infile;
    struct user person;


    printf("\nPlease Enter your Username, Password to Proceed\n\n");
    printf("\n\nUsername: ");
    fgets(username,50,stdin);
    printf("\nPassword: ");
    fgets(password,50,stdin);

    infile = fopen ("user_login_data.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    int count=0;

    while(fread(&person, sizeof(struct user), 1, infile)){
        if(strcmp(username,person.username) == 0 && \
           strcmp(password, person.password) ==0)
        {
            count=1;
            
            opdregistration();
        }
    }
    if (count==0) 
    {
        printf("Wrong Credentials!, Please try again!\n\n");
        login();
    }
        // else
        // {
        //     printf("\nWrong Credentials, Please try again!\n\n");
        //     login();    
        // }
    return 0;
}


char registration()
{

    //system("cls");
    printf ("--------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tWelcome to Registration Page\n");
    printf ("--------------------------------------------------------------------------------------\n\n");
    //date();

    struct user person;

    printf("Enter the UserID: ");
    fgets(person.userID,10,stdin);

    printf("\nEnter the username: ");
    fgets(person.username,50,stdin);

    printf("\nEnter the password: ");
    fgets(person.password,50,stdin);

    printf("This person has username %s and password %s\n", person.username, person.password);


    FILE *outfile;

    // open file for writing
    outfile = fopen ("user_login_data.txt", "a+");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }


    // write struct to file
    fwrite (&person, sizeof(struct user), 1, outfile);
    fclose(outfile);

    // if(fwrite != 0)
    //     printf("\ncontents to file written successfully !\n");
    // else
    //     printf("error writing file !\n");

    login();
    return '0';
}




int main()
{
    char h[5];
    printf(dash);
    printf("\t\t\t\t Welcome to OPD Registration Portal \n");
    printf(dash);
    printf("\n\nNew User? ('Y' or 'N'):");
    fgets(h,5,stdin);

    if (strcmp(h,"Y\n")==0 || strcmp(h,"y\n")==0)
    {
    registration();
    }
    else if (strcmp(h,"N\n")==0 || strcmp(h,"n\n")==0)
    {
        login();
    }
    else
    {
        printf("\t<< Wrong input >>\n \t ! Try Again !\n");
    }
    return 0;
}
