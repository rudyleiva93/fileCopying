// Daniel Hernandez
// Rudy Leiva
// 2/15/16
// CSC 341

/*
Project 1: This program prompts the user for the filename of the file to copy from. The program verifies that a valid filename has been entered, otherwise it will keep prompting until a valid filename is entered. Currently, this source code / executable file and the file you want as the source file must be in the same folder/directory or the program will always tell you that the file could not be found. Next, the program asks for the filename of the destination file. If the file doesnt exist, it will be created and the data from the source file will be copied to the destination file. If the file exists, then the user has the option to write data to the end of the previous data in the file (append), overwrite the data in the file, or cancel the copy action and end the program. To demonstrate this code using an existing destination file, this source code / executable file and the destination file must be in the same folder/directory otherwise the program will proceed to create the file instead of recognizing an existing file.
*/

// Required include statements
#include <stdio.h>
#include <stdlib.h>

int main(void) // begin main()
{
	FILE *openFile;			// pointer of type FILE for the source file
	FILE *fileCopyTo;		// pointer of type FILE for the destination file
	char fileNameOpen[256];		// Character array to store the filename provided by the user for the source file
	char fileNameCopyTo[256];	// Character array to store the filename provided by the user for the destination file
	char read;			// character variable used to copy from source to destination file
	int choice;			// used to store the numberical value entered by the user for the option selected
	
	// Loop will keep prompting the user for a filename of the source file until a valid filename has been entered.
	do
	{
		printf("Enter the name of the file you want to copy from.\n"); //prompts for user input
		scanf("%s", fileNameOpen);
	
		openFile = fopen(fileNameOpen, "r"); // Invokes the fopen function to open a file with the filename entered by the user
		
		printf("\n"); // blank line - used to make output nicer
		
		if(openFile == NULL) // Tells the user if the file was not found or couldnt be read
		{
			printf("Either the file does not exist or you dont have permission to read the file.\n\n");
		}
	} while (openFile == NULL);
	
	// Prompts the user to enter a filename for the destination file
	printf("Enter the name of the file you want to copy to. If the file does not exist, it will be created.\n");
	scanf("%s", fileNameCopyTo);
	
	fileCopyTo = fopen(fileNameCopyTo, "r+"); // The call to fopen here is used simply as a test to check if the file exists or not.
	
	printf("\n"); // blank line - used to make output nicer
	
	// If the file wasnt found, then the if section of the if-else block is executed
	if(fileCopyTo == NULL)
	{
		fileCopyTo = fopen(fileNameCopyTo, "w"); // create the destination file for writing
		
		printf("File %s created successfully.\n", fileNameCopyTo); // lets the user know a file was created
		
		// Loop copies the contents of the source file the destination file, character by character and ends when EOF is reached
		do
		{
			read = fgetc(openFile); // copy character from source into variable read
			if(read != EOF)
			{
				fputc(read, fileCopyTo); // write character stored in read to the destination file
			}
		} while (read != EOF);
		
		fclose(fileCopyTo); // close the write stream to the destination file
		
		printf("%s ---> %s copied successfully.\n", fileNameOpen, fileNameCopyTo); // Lets the user know the copy operation was successful
	}
	else // If the destination file exists, this else section of the if-else statement is executed
	{
		// Shows available options to the user and prompts for an input of their desired choice
		printf("A file already exists. Please select an option by entering its number.\n"
			"1. Append to the file.\n"
			"2. Overwrite the file.\n"
			"3. Do nothing.\n");
		scanf("%d", &choice);
		
		printf("\n"); // blank line - used to make output nicer
		
		if(choice == 1) // Option 1 selected: Append data to the end of the file.
		{
			fileCopyTo = fopen(fileNameCopyTo, "a"); // Open write stream to append data
			
			// Loop writes data to the destination file, ending when EOF of source file is reached
			do
			{
				read = fgetc(openFile);
				if(read != EOF)
				{
					fputc(read, fileCopyTo);
				}
			} while(read != EOF);
			
			fclose(fileCopyTo); // close the write stream to the destination file
			
			printf("%s ---> %s copied successfully without overwritting previous data.\n", fileNameOpen, fileNameCopyTo);
		}
		
		if(choice == 2) // Option 2 selected: Overwrite the existing data in the file with the data in the source file
		{
			fileCopyTo = fopen(fileNameCopyTo, "w"); // open write stream to write data
			
			// Loop writes data to the destination file, ending when EOF of source file is reached
			do
			{
				read = fgetc(openFile);
				if(read != EOF)
				{
					fputc(read, fileCopyTo);
				}
			} while(read != EOF);
			
			fclose(fileCopyTo); // close the write stream to the destination file
			
			printf("%s ---> %s copied successfully by overwritting previous data.\n", fileNameOpen, fileNameCopyTo);
		}
		if(choice == 3) // Option 3 selected: do nothing and end the program
		{
			printf("Action cancelled. Exiting program.\n"); // No data is written and tells user the program will close
		}
	}
	
	fclose(openFile); // close read stream of the source file
	
	return 0; // required
} // end main()
