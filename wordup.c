//Anthony Jacoboni
//4/21/25
//Project 10, Word Up game

#include <stdio.h>

#define wordfile "mystery.txt"
#define limit 100
#define numguess 6


int fileIO(char fileword[]);
void printline(char sym, int length);
int getguess(int num, char input[][limit], int check);
int fixguess(int num, char input[][limit]);
int checkguess(int num, char input[][limit], char inputcheck[][6], char fileword[]);
void printguess(int num, char input[][limit], char inputcheck[][6]);

int main(){

int guess = 0, spacer, tempguess = 0, filesuccess, fix;
char fileword[6], input[numguess][limit], inputcheck[numguess][6];

	filesuccess = fileIO(fileword);
	
	if(filesuccess == 0){
		printf("Could not open file.\n");
		return 0;
		}

	do{
		
		guess++;
		fix = 0;
		
		do{
			fix = getguess(guess, input, fix);
		}while(fix != 0);
		
		spacer = checkguess(guess, input, inputcheck, fileword);
		
		printline('=', 32);
		
		if(spacer == 5){
			tempguess = guess;
			guess = 7;
			}
		
		if (guess != 7){
			printguess(guess, input, inputcheck);
			}
		

	}while(guess < 6);

	if(tempguess != 0){
		 printf("                %s\n"
			"        You won in %d guesses!\n", input[tempguess - 1], tempguess);
		if(tempguess == 1){
		 printf("                GOATED!\n");
			}
		else if(tempguess == 2 || tempguess == 3){
		 printf("                Amazing!\n");
			}
		else if(tempguess == 4 || tempguess == 5){
		 printf("                Nice!\n");
			}
		}
	else{
		printf("You lost, better luck next time!\n");
		}

	return 0;
	}


int fileIO(char fileword[]){

FILE* wordPtr;
	
	wordPtr = fopen(wordfile, "r");

	if(wordPtr == NULL){
		printf("Could not open file.\n");
		return 0;
		}
	else{
		fscanf(wordPtr, "%s", fileword);
		return 1;
		}
	}

void printline(char sym, int length){

	for(int i = 0; i < length; i++){
		printf("%c", sym);
		}
	printf("\n");

	}

int getguess(int num, char input[][limit], int check){

	if(check == 0){
		if(num < 6){
			printf("GUESS %d! Enter your guess: ", num);
			}
		else{
			printf("FINAL GUESS: ");
			}
		}
		
	else if(check == 1){
		printf("\nPlease try again: ");
		}
	
	scanf("%s", &input[num - 1]);

	return fixguess(num, input);
	}
	
int fixguess(int num, char input[][limit]){

int check = 0;
	
	if(input[num - 1][5] != '\0'){
			check = 1;
			printf("Your guess must be 5 letters long.");
			}
	
	for(int i = 0; input[num - 1][i] != '\0'; i++){
		
		if(input[num - 1][i] >= 'A' && input[num - 1][i] <= 'Z'){
			input[num - 1][i] += 32;
			}
		
		if((input[num - 1][i] > 'z') || (input[num - 1][i] < 'a')){
			check = 1;
			printf("Your guess must contain only letters.");
			break;
			}
		}

	return check;
	}
		
	
int checkguess(int num, char input[][limit], char inputcheck[][6], char fileword[]){
int spacer = 0;

	for(int i = 0; i < 5; i++){
	
		inputcheck[num - 1][i] = ' ';
		
		for(int j = 0; j < 5; j++){
			if(input[num - 1][i] == fileword[j]){
				inputcheck[num - 1][i] = '^';
				}
			}
			
		if(input[num - 1][i] == fileword[i]){
			input[num - 1][i] -= 32;
			inputcheck[num - 1][i] = ' ';
			spacer++;
			}
		}
		
		return spacer;
		
	}


void printguess(int num, char input[][limit], char inputcheck[][6]){

	for(int i = 0; i < num; i++){
		
		printf("%s\n", input[i]);
		
		for(int j = 0; j < 5; j++){
		
			printf("%c", inputcheck[i][j]);
			
			}
		printf("\n");
		}
	}
