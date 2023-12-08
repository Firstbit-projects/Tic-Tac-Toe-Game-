#include<stdio.h>

void display(char*);
int play(char*, char*, char, char, char*);
int player1_wincheck(char*,char,char);
int player2_wincheck(char*,char,char);
int cplay(char*, char*, char, char, char*);

void main(){
	int choice, i, control;
	char player1[10], player2[10], computer[10]="Computer";
	char p1, p2, c;
	printf("Choose mode:\n");
	printf("1.player vs player\n");
	printf("2.Player vs Computer\n");
	
	scanf("%d", &choice);
	if(choice==1){
		printf("Enter player 1 name: ");
		scanf("%s", player1);
		printf("Enter player 2 name: ");
		fflush(stdin);
		scanf("%s", player2);
		printf("%s please choose symbol-> 'X' or 'O' : ", player1);
		fflush(stdin);
		scanf("%c", &p1);
		if(p1=='x' || p1=='X')
		{
			p2='O';
		}
		else if(p1=='O' || p1=='o'){
			p2='X';
		}
		
		do
		{
			char arr[9]= {'1','2','3','4','5','6','7','8','9'};
			printf("\n--------------------------------\n");
			printf("%s: %c\n", player1, p1);
			printf("%s: %c\n\n", player2, p2);
			
			printf("Who is going to play first-\n");
			printf("1.%s\n", player1);
			printf("2.%s\n", player2);
			scanf("%d", &control);
			
			if(control==1)
				control=play(player1, player2, p1, p2, arr);
			else
				control=play(player2, player1, p2, p1, arr);
		}while(control);
	}
	else
	{
		printf("Enter player name: ");
		scanf("%s", player1);
		printf("%s please choose symbol-> 'X' or 'O' : ", player1);
		fflush(stdin);
		scanf("%c", &p1);
		if(p1=='x' || p1=='X')
		{
			c='O';
		}
		else if(p1=='O' || p1=='o')
		{
			c='X';
		}
		do
		{
			char arr[9]= {'1','2','3','4','5','6','7','8','9'};
			control=cplay(player1, computer, p1, c, arr);
		}while(control);
	}
	printf("\n----------------------Closing the Tic-Tac-Toe--------------------------\n");
	printf("-----------------------Thank You for Playing---------------------------\n");
	getch();
}

void display(char* arr)
{
	printf("-------------\n");
	printf("| %c | %c | %c |\n", arr[0], arr[1], arr[2]);
//	printf("-------------\n");
	printf("| %c | %c | %c |\n", arr[3], arr[4], arr[5]);
//	printf("-------------\n");
	printf("| %c | %c | %c |\n", arr[6], arr[7], arr[8]);
	printf("-------------\n");
}

int play(char* player1, char* player2, char p1, char p2, char* arr){

	int choice, flag=0, z=1;
	
	while(1){
		display(arr);
		
		if(z)
			printf("%s: ", player1);
		else
			printf("%s: ", player2);
			
		scanf("%d", &choice);
		if(choice<1 ||  choice>9)
		{
			printf("Wrong choice***\n");
			printf("Enter valid choice!!\n");
		}
		else if(arr[choice-1]==p1 || arr[choice-1]==p2)
		{
			printf("Place not available**\n");
			printf("Enter valid choice!!\n");
		}
		else{
			if(z){
				arr[choice-1]=p1;
				z--;
			}
			else{
				arr[choice-1]=p2;
				z++;
			}
			flag=player1_wincheck(arr, p1, p2);
			if(flag){
				printf("\n%s win\n", player1);
				break;
			}
			flag=player2_wincheck(arr, p1, p2);
			if(flag){
				printf("\n%s win\n", player2);
				break;
			}
		}
		if(arr[0] != '1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' && arr[6]!='7' && arr[7]!='8' && arr[8]!='9')
		{
			printf("\nDraw!!\n");
			break;
		}
	}
	printf("Do you want to play again? : \n");
	printf("Enter 1 for Yes\n");
	printf("Enter 0 for No\n");
	scanf("%d", &flag);
	
	return flag;	
}

int player1_wincheck(char* arr, char player1, char player2){
	if((arr[0]==player1 && arr[1]==player1 && arr[2]==player1) || (arr[3]==player1 && arr[4]==player1 && arr[5]==player1) || (arr[6]==player1 && arr[7]==player1 && arr[8]==player1) || (arr[0]==player1 && arr[3]==player1 && arr[6]==player1) || (arr[1]==player1 && arr[4]==player1 && arr[7]==player1) || (arr[2]==player1 && arr[5]==player1 && arr[8]==player1) || (arr[0]==player1 && arr[4]==player1 && arr[8]==player1) || (arr[2]==player1 && arr[4]==player1 && arr[6]==player1))
	{
		display(arr);
		return 1;
	}
	else
		return 0;
}
int player2_wincheck(char* arr, char player1, char player2){
	if((arr[0]==player2 && arr[1]==player2 && arr[2]==player2) || (arr[3]==player2 && arr[4]==player2 && arr[5]==player2) || (arr[6]==player2 && arr[7]==player2 && arr[8]==player2) || (arr[0]==player2 && arr[3]==player2 && arr[6]==player2) || (arr[1]==player2 && arr[4]==player2 && arr[7]==player2) || (arr[2]==player2 && arr[5]==player2 && arr[8]==player2) || (arr[0]==player2 && arr[4]==player2 && arr[8]==player2) || (arr[2]==player2 && arr[4]==player2 && arr[6]==player2))
	{
		display(arr);
		return 1;
	}
	else
		return 0;
}

int cplay(char* player1, char* computer, char p1, char p2, char* arr){

	int choice, i, flag=0, control;
	printf("\n--------------------------------\n");
	printf("%s: %c\n", player1, p1);
	printf("%s: %c\n\n", computer, p2);
	
	printf("Who is going to play first-\n");
	printf("1.%s\n", player1);
	printf("2.%s\n", computer);
	scanf("%d", &control);
	if(control!=1)
		control=0;
	while(1){
		display(arr);
		int total_count=0;
		for(i=0;i<9;i++){
			if(arr[i]!=p1 && arr[i]!=p2)
				total_count++;
		}
		if(total_count==1){
			printf("\nDraw!!\n");
			break;
		}
		if(control){
			printf("%s: ", player1);
			scanf("%d", &choice);
			if(choice<1 ||  choice>9)
			{
				printf("Wrong choice***\n");
				printf("Enter valid choice!!\n");
			}
			else if(arr[choice-1]==p1 || arr[choice-1]==p2)
			{
				printf("Place not available**\n");
				printf("Enter valid choice!!\n");
			}
			else{
				arr[choice-1]=p1;
				control--;
			}
		}
		else
		{
			
			printf("%s: \n", computer);
			control++;
			
			//For computer win			
			//first row
			if(arr[0]==p2 && arr[1]==p2 && arr[2]=='3')
				arr[2]=p2;
			else if(arr[0]=='1' && arr[1]==p2 && arr[2]==p2)
				arr[0]=p2;
			else if(arr[0]==p2 && arr[1]=='2' && arr[2]==p2)
				arr[1]=p2;
				
			//2nd row
			else if(arr[3]==p2 && arr[4]==p2 && arr[5]=='6')
				arr[5]=p2;
			else if(arr[3]=='4' && arr[4]==p2 && arr[5]==p2)
				arr[3]=p2;
			else if(arr[3]==p2 && arr[4]=='5' && arr[5]==p2)
				arr[4]=p2;
			
			//3rd row
			else if(arr[6]==p2 && arr[7]==p2 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[6]=='7' && arr[7]==p2 && arr[8]==p2)
				arr[6]=p2;
			else if(arr[6]==p2 && arr[7]=='8' && arr[8]==p2)
				arr[7]=p2;
			
			//1st column
			else if(arr[0]==p2 && arr[3]==p2 && arr[6]=='7')
				arr[6]=p2;
			else if(arr[0]=='1' && arr[3]==p2 && arr[6]==p2)
				arr[0]=p2;
			else if(arr[0]==p2 && arr[3]=='4' && arr[6]==p2)
				arr[0]=p2;
			
			//2nd column
			else if(arr[1]==p2 && arr[4]==p2 && arr[7]=='8')
				arr[7]=p2;
			else if(arr[1]=='2' && arr[4]==p2 && arr[7]==p2)
				arr[1]=p2;
			else if(arr[1]==p2 && arr[4]=='5' && arr[7]==p2)
				arr[4]=p2;
				
			//3rd column
			else if(arr[2]==p2 && arr[5]==p2 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[2]=='3' && arr[5]==p2 && arr[8]==p2)
				arr[2]=p2;
			else if(arr[2]==p2 && arr[5]=='6' && arr[8]==p2)
				arr[5]=p2;
			
			//Diagonal 1
			else if(arr[0]==p2 && arr[4]==p2 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[0]=='1' && arr[4]==p2 && arr[8]==p2)
				arr[0]=p2;
			else if(arr[0]==p2 && arr[4]=='5' && arr[8]==p2)
				arr[4]=p2;
				
			//Daigonal 2
			else if(arr[2]==p2 && arr[4]==p2 && arr[6]=='7')
				arr[6]=p2;
			else if(arr[2]=='3' && arr[4]==p2 && arr[6]==p2)
				arr[2]=p2;
			else if(arr[2]==p2 && arr[4]=='5' && arr[6]==p2)
				arr[4]=p2;
			
			
			//for player stop
			//first row
			else if(arr[0]==p1 && arr[1]==p1 && arr[2]=='3')
				arr[2]=p2;
			else if(arr[0]=='1' && arr[1]==p1 && arr[2]==p1)
				arr[0]=p2;
			else if(arr[0]==p1 && arr[1]=='2' && arr[2]==p1)
				arr[1]=p2;
				
			//2nd row
			else if(arr[3]==p1 && arr[4]==p1 && arr[5]=='6')
				arr[5]=p2;
			else if(arr[3]=='4' && arr[4]==p1 && arr[5]==p1)
				arr[3]=p2;
			else if(arr[3]==p1 && arr[4]=='5' && arr[5]==p1)
				arr[4]=p2;
			
			//3rd row
			else if(arr[6]==p1 && arr[7]==p1 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[6]=='7' && arr[7]==p1 && arr[8]==p1)
				arr[6]=p2;
			else if(arr[6]==p1 && arr[7]=='8' && arr[8]==p1)
				arr[7]=p2;
			
			//1st column
			else if(arr[0]==p1 && arr[3]==p1 && arr[6]=='7')
				arr[6]=p2;
			else if(arr[0]=='1' && arr[3]==p1 && arr[6]==p1)
				arr[0]=p2;
			else if(arr[0]==p1 && arr[3]=='4' && arr[6]==p1)
				arr[3]=p2;
			
			//2nd column
			else if(arr[1]==p1 && arr[4]==p1 && arr[7]=='8')
				arr[7]=p2;
			else if(arr[1]=='2' && arr[4]==p1 && arr[7]==p1)
				arr[1]=p2;
			else if(arr[1]==p1 && arr[4]=='5' && arr[7]==p1)
				arr[4]=p2;
				
			//3rd column
			else if(arr[2]==p1 && arr[5]==p1 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[2]=='3' && arr[5]==p1 && arr[8]==p1)
				arr[2]=p2;
			else if(arr[2]==p1 && arr[5]=='6' && arr[8]==p1)
				arr[5]=p2;
			
			//Diagonal 1
			else if(arr[0]==p1 && arr[4]==p1 && arr[8]=='9')
				arr[8]=p2;
			else if(arr[0]=='1' && arr[4]==p1 && arr[8]==p1)
				arr[0]=p2;
			else if(arr[0]==p1 && arr[4]=='5' && arr[8]==p1)
				arr[4]=p2;
				
			//Daigonal 2
			else if(arr[2]==p1 && arr[4]==p1 && arr[6]=='7')
				arr[6]=p2;
			else if(arr[2]=='3' && arr[4]==p1 && arr[6]==p1)
				arr[2]=p2;
			else if(arr[2]==p1 && arr[4]=='5' && arr[6]==p1)
				arr[4]=p2;
			
			//for total count 2
			else if(total_count==7)
			{
				// if p2 in corners
				if(arr[0]==p2){
					//for corners
					if(arr[2]==p1 || arr[8]==p1 || arr[6]==p1)
						arr[4]=p2;
					//for adjacent
					else if(arr[1]==p1 || arr[3]==p1)
						arr[4]=p2;
					//for middle
					else if(arr[4]==p1)
						arr[2]=p2;
					else
						arr[4]=p2;
				}
				else if(arr[2]==p2){
					//for corners
					if(arr[0]==p1 || arr[6]==p1 || arr[8]==p1)
						arr[4]=p2;
					//for adjacent
					else if(arr[1]==p1 || arr[5]==p1)
						arr[4]=p2;
					//for middle
					else if(arr[4]==p1)
						arr[0]=p2;
					else
						arr[4]=p2;
				}
				
				else if(arr[8]==p2){
					//for corners
					if(arr[0]==p1 || arr[2]==p1 || arr[6]==p1)
						arr[4]=p2;
					//for adjacent
					else if(arr[7]==p1 || arr[5]==p1)
						arr[4]=p2;
					//for middle
					else if(arr[4]==p1)
						arr[2]=p2;
					else
						arr[4]=p2;
				}
				
				else if(arr[6]==p2){
					//for corners
					if(arr[0]==p1 || arr[2]==p1 || arr[8]==p1)
						arr[4]=p2;
					//for adjacent
					else if(arr[3]==p1 || arr[8]==p1)
						arr[4]=p2;
					//for middle
					else if(arr[4]==p1)
						arr[8]=p2;
					else
						arr[4]=p2;
				}
				
				
				//p2 in middle
				
				else if(arr[4]==p2){
					if(arr[0]==p1 || arr[8]==p1)
						arr[2]=p2;
					else if(arr[2]==p1 || arr[6]==p1)
						arr[0]=p2;
					else if(arr[1]==p1 || arr[7]==p1)
						arr[3]=p2;
					else if(arr[3]==p1 || arr[5]==p1)
						arr[1]=p2;
				}
				
				//for row/column midlle
				else if(arr[1]==p2){
					if(arr[0]==p1 || arr[2]==p1 || arr[8]==p1 || arr[6]==p1 || arr[3]==p1 || arr[5]==p1)
						arr[4]=p2;
					else
						arr[0]=p2;
				}
				else if(arr[3]==p2){
					if(arr[0]==p1 || arr[2]==p1 || arr[8]==p1 || arr[6]==p1 || arr[1]==p1 || arr[5]==p1)
						arr[4]=p2;
					else
						arr[0]=p2;
				}
				else if(arr[5]==p2){
					if(arr[0]==p1 || arr[2]==p1 || arr[8]==p1 || arr[6]==p1 || arr[1]==p1 || arr[3]==p1)
						arr[4]=p2;
					else
						arr[0]=p2;
				}
				else if(arr[7]==p2){
					if(arr[0]==p1 || arr[2]==p1 || arr[8]==p1 || arr[6]==p1 || arr[5]==p1 || arr[3]==p1)
						arr[4]=p2;
					else
						arr[0]=p2;
				}
			}
			else if(total_count==8)
			{
				//last step he bhai
				if(arr[4]!=p1)
					arr[4]=p2;
				else
					arr[2]=p2;
			}
			else{
				for(i=0;i<9;i++){
					if(arr[i]!=p1 && arr[i]!=p2)
					{
						arr[i]=p2;
						break;
					}
				}
			}
		}
		flag=player1_wincheck(arr, p1, p2);
		if(flag){
			printf("\n%s win\n", player1);
			break;
		}
		flag=player2_wincheck(arr, p1, p2);
		if(flag){
			printf("\n%s win\n", computer);
			break;
		}
//		if(arr[0] != '1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' && arr[6]!='7' && arr[7]!='8' && arr[8]!='9')
//		{
//			printf("\nDraw!!\n");
//			break;
//		}
	}
	printf("Do you want to play again? : \n");
	printf("Enter 1 for Yes\n");
	printf("Enter 0 for No\n");
	scanf("%d", &flag);
	
	return flag;	
}
