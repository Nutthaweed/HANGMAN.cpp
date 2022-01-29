#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void gameFunction(char *wordinFunction, char *userWordinFunction, int letterNumber);   
void printUserWord(char * userWordinPrint,int letterNumber);			       
void printFigure(int failinFigure);						      

int main(void)
{
	FILE *fpointer;     
	fpointer = fopen("hangman.txt", "r");

	if(fpointer== NULL)
	{
		printf("hangman.txt couldn't found");
		return 0;
	}
	char readFromFile[300];
	
	while(!feof(fpointer))
	{
		fgets(readFromFile, 300, fpointer);
	}
	
	fclose(fpointer);
	
	srand(time(NULL));  
	
	int restartGame= 1; //At the end, that variable's value can change so the game terminates
	while(restartGame==1)
  {
	    int gameType;   
		   printf(">->o-]   WELCOME TO KRUNGTEPIAN HANGMAN C++!\n\nChoose a game\n1. Six Letters Game\n2. Seven Letters Game\n3. Random Game\n");
		   scanf("%d", &gameType);
		while(gameType != 1 && gameType != 2 && gameType !=3)
		{
			system("cls");
			printf(">->o-]   WELCOME TO T KRUNGTEPIAN HANGMAN C++\n\nChoose a game\n1. Six Letters Game\n2. Seven Letters Game\n3. Random Game\n");
			scanf("%d", &gameType);
		}
	
		system("cls");
	
		if(gameType == 3)
		{
			gameType = rand() % 2 + 1;
		}
	
		int categoryType; 
		printf("\n\nChoose a category\n1. Fruits and Vegetables\n2. Sports\n3. Technological Devices\n4. Countries\n5. Random Category\n");
	
		scanf("%d", &categoryType);
	
		while(categoryType != 1 && categoryType != 2 && categoryType != 3 && categoryType != 4 && categoryType != 5)
		{
			system("cls");
			printf("\n\nChoose a category\n1. Fruits and Vegetables\n2. Sports\n3. Technological Devices\n4. Countries\n5. Random Category\n");		
			scanf("%d", &categoryType);
		}
	
		if(categoryType== 5)
		{
			categoryType= rand() % 4 + 1;
		}
	
		char askedWord[8];									
		char userWord[8]= {'_','_','_','_','_','_','_'};    
		
		int randomer = rand()% 5;                           
		
		if(categoryType == 1)      
		{	
			if(gameType== 1)
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 0)+ (randomer * 7)+ i];
				}
				
			}
			
			else
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 1)+ (randomer * 7)+ i];
				}
				
			}
		}
	
		else if(categoryType == 2) 
		{		
			if(gameType==1)
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 2)+ (randomer * 7)+ i];
				}
				
			}
			
			else
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 3)+ (randomer * 7)+ i];
				}
				
			}
		}
	
		else if(categoryType == 3) 
		{
			if(gameType==1)
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 4)+ (randomer * 7)+ i];
				}
				
			}
			
			else
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 5)+ (randomer * 7)+ i];
				}
				
			}
		}
	
		else			        
		{
			if(gameType==1)
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 6)+ (randomer * 7)+ i];
				}
				
			}
			
			else
			{
				for(int i= 0; i< 7; i++)
				{
					askedWord[i]= readFromFile[(35* 7)+ (randomer * 7)+ i];
				}
				
			}
		}
		
		gameFunction(askedWord, userWord, (gameType+ 5));    
		
		printf("\n\nEnter 1 to restart game\nEnter any other number to exit\n");   
		scanf(" %d", &restartGame);
		system("cls");
	}
}

void gameFunction(char *wordinFunction, char *userWordinFunction, int letterNumber)      
	int totalTrue= 0;		
	int totalFail= 0;			
	char scannedChar;
	
	while(totalFail< 9)
	{
		printFigure(totalFail);		
		printf("\n\n\n");
		printUserWord(userWordinFunction, letterNumber);     
		printf("\nEnter a character: ");
		scanf(" %c", &scannedChar);
		scannedChar= toupper(scannedChar);
	
		int letterAlreadyUsed= 1;			
		while(letterAlreadyUsed== 1)
		{
			for(int i=  0; i< letterNumber; i++)
			{
				if(userWordinFunction[i]!= scannedChar)
				{
					letterAlreadyUsed= 0;	
				}
				
				else
				{
					letterAlreadyUsed= 1;
					printFigure(totalFail);
					printf("\n\n\n");
					printUserWord(userWordinFunction, letterNumber);
					printf("\nLetter already found!\nEnter a new character: ");
					scanf(" %c", &scannedChar);
					scannedChar= toupper(scannedChar);
					break;
				}
			}
		
		}
	
		int letterTrueCheck= 0;                        .
		for(int i= 0; i< letterNumber; i++)			   
		{
			if(scannedChar== wordinFunction[i])		   
			{
				userWordinFunction[i]= wordinFunction[i];
				letterTrueCheck++;
				totalTrue++;				
			}
		}
		
		if(letterTrueCheck== 0)						
		{
			totalFail++;
		}
		
		if(totalTrue== letterNumber)                
		{
			printFigure(totalFail);
			printf("\n\n\n");
			printUserWord(userWordinFunction, letterNumber);
			printf("\n\nYOU WON!");
			return;
		}
	}
	
	printFigure(totalFail);	                         
	printf("\n\n\n");
	for(int i= 0; i< letterNumber; i++)
	{
		printf("%c ", wordinFunction[i]);
	}
	printf("\n\nYOU LOST!");		
	return;
	
}

void printUserWord(char *userWordinPrint,int letterNumber)    
{
	for(int i= 0; i< letterNumber; i++)
	{
		printf("%c ", userWordinPrint[i]);
	}
}

void printFigure(int failinFigure)    
{
	system("cls");
	
	switch(failinFigure)
	{
		case 0:
			printf("\n\n\n\n\n        \n        \n        \n     __|__");
			break;
		case 1:
			printf("\n\n\n\n\n       |\n       |\n       |\n     __|__");
			break;
		case 2:
			printf("  _ _ _\n       |\n       |\n       |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 3: 
			printf("  _ _ _  \n |     | \n |     | \n       |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 4:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n       |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 5:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/      |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 6:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/ \\    |\n       |\n       |\n       |\n     __|__ ");
			break;
		case 7:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n       |\n     __|__ ");
			break;
		case 8:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n/      |\n     __|__ ");
			break;
		case 9:
			printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n/ \\    |\n     __|__ ");
			break;
	}
	
	return;
	
}