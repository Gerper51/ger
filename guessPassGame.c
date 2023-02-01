#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define EASY 20
#define MODERATE 15
#define HARD 10

enum difficultyLevels{Easy=1,Moderate,Hard,Crazy}; //All difficulty levels in the game.
 
int RandPassword();
int ClacNumOfGuesses(int num);
int turnToNum(int d1,int d2,int d3,int d4);
void StartGame(int crazy,int numOfGuess,int randomPassword,int d1OfRand,int d2OfRand,int d3OfRand,int d4OfRand);
int ChekerOfSimillerityHits(int d1, int d2,int d3,int d4,int dR1,int dR2,int dR3,int dR4);
int ChekerOfSimillerityMisses(int d1, int d2,int d3,int d4,int dR1,int dR2,int dR3,int dR4);

int main() 
{
	int randomPassword=0,d1OfRand=0,d2OfRand=0,d3OfRand=0,d4OfRand=0,numOfGuesses=0,crazy=0;
	char stoper=' '; //stops the code when it equals 'n'.
	enum difficultyLevels difLvl;
  do
  {  
	srand(time(NULL));
	randomPassword=RandPassword();  
	d4OfRand=randomPassword%10;
	d3OfRand=(randomPassword/10)%10;
	d2OfRand=(randomPassword/100)%10;
	d1OfRand=(randomPassword/1000)%10;    //All digits of random number.
    printf("Welcome to \"MAGSHIMIM CODE-BREAKER\"!!!\n\nA secret password was chosen to protect card of Pancratius,\nthe descedant of Antiochus.\nYour misson is to stop Pancratius by revealing secret password.\n\nThe reles are as foolows:\n1. In each round you try to guess the secret password (4distinct digits)\n2. After every guess you'll receive two hints about the password\n   HITS:   The number of digits in your guess wich were exactly right.\n   MISSES: The number of digits in your guess belongs to \n           the password but were miss-placed.\n3. If you'll fail to guess the password after a certain number of rounds\n    Pancratius will buy all the gifts for Hanukah!!!\n\nPlease choose the game level:\n1 - Easy (20 rounds)\n2 - Moderate (15 rounds)\n3 - Hard (10 rounds)\n4 - Crazy (Random number of rounds 5-25)");	
    do
	{
	   printf("\nEnter difficulty level:");
       scanf("%d",&difLvl);
	   getchar();//cleaning the buffer
	}while(difLvl!=1 && difLvl!=2 && difLvl!=3 && difLvl!=4);//There is only four right options
	numOfGuesses=ClacNumOfGuesses(difLvl);
	if(difLvl==4)
	{
		crazy++;
	}
	StartGame(crazy,numOfGuesses,randomPassword,d1OfRand,d2OfRand,d3OfRand,d4OfRand);
	do
	{
	  printf("\n\nWould you like to play again? (y/n): ");  
	  stoper=getche();  
	}while(stoper != 121 && stoper != 110); //121 is y in ascii and 110 is n in ascii.
	if (stoper==121)
	{
		stoper=' '; //cleaning stoper for the next game.
	}
  }while(stoper != 110);
  printf("\n\nGood bye!");
    return 0;
}

 /*
 Function will randomly give number from 1000 to 9999,in number will not be 0 digit,all digit will be different and in array 1-6 only.
 input: none.
 output: num-the random number which meets all the conditions.
 */
int RandPassword()
{
	int num=0,d1=0,d2=0,d3=0,d4=0;
	do
	{
	 	num=rand() % 9000+1000;//1000-9999
		d4=num%10;
		d3=(num/10)%10;
		d2=(num/100)%10;
		d1=(num/1000)%10;
	}while( (d1==d2) || (d1==d3) || (d1==d4) || (d2==d3) || (d2==d4) || (d3==d4) || (d2==0) || (d3==0) || (d4==0) || (d1>6) || (d2>6) || (d3>6) || (d4>6) );//checing all conditons
	return(num);
}

 /*
 Function will calculate a number of guesses.
 input: num-the number between 1-4 which stands for difficulty level.
 output: num-a number of guesses which is set by chosen level of difficulty.
 */
int ClacNumOfGuesses(int num)
{
	switch(num)
	{
		case 1:
	num=EASY;
	break;
	    case 2:
	num=MODERATE;
	break;
        case 3:
    num=HARD;
    break;
	    case 4:
	num=rand() % 21+5;
	}
	return (num);
}

 /*
 // Function will turn entered number as an ascii inputs to integer number.
 input: d1-first digit in number,d2-second digit in number,d3-thiird digit in number,d4-fourth digit in number.
 output: num-4-digit number.
 */
int turnToNum(int d1,int d2,int d3,int d4)
{
  int num=0;
  num=num*10+(d4-'0');
  num=num*10+(d3-'0');
  num=num*10+(d2-'0');
  num=num*10+(d1-'0');
  return(num);
}

 /*
 Function will start the game where a user needs to enter a number that is simillar to random number and cheks if it is.
 input: if a difficulty is crazy or not,a number of guesses that are set by dif level,the password and all digits of the password.
 output: none.
 */
void StartGame(int crazy,int numOfGuess,int randomPassword,int d1OfRand,int d2OfRand,int d3OfRand,int d4OfRand)
{
	int guessNum=0,d1=0,d2=0,d3=0,d4=0,hits=0,misses=0,numG=0;
	char charD1=' ',charD2=' ',charD3=' ',charD4=' ';
	numG=numOfGuess; //Saving number of guesses to calculate how many guesses it took to find a password for a user.
	while( (guessNum != randomPassword) && (numOfGuess != 0) )
	{
		do
		{
		  printf("\nWrite your guess(only 1-6,no ENTER is needed)\n");
		  if(crazy==1)
		  {
			 printf("CRAZY MODE!\n");  
		  }
		  else
		  {
			 printf("%d guesses left\n",numOfGuess);  
		  }
		  charD4=getche();
          charD3=getche();
          charD2=getche();
          charD1=getche();                           
		  guessNum=turnToNum(charD1,charD2,charD3,charD4);     
		  d4=guessNum%10;
	      d3=(guessNum/10)%10;
	      d2=(guessNum/100)%10;
	      d1=(guessNum/1000)%10;
		  if((d1==0) || (d2==0) || (d3==0) || (d4==0) || (d1>6) || (d2>6) || (d3>6) || (d4>6) ||  (int)charD1<48 || (int)charD1>57 || (int)charD2<48 || (int)charD2>57 || (int)charD3<48 || (int)charD3>57 || (int)charD4<48 || (int)charD4>57 )
		  {
			printf("\nOnly 1-6 are allowed,try again!\n");  
		  }
		  //bonus 2
		  else if( (d1==d2) || (d1==d3) || (d1==d4) || (d2==d3) || (d2==d4) || (d3==d4) )
		  {
			printf("\nOnly number where all digits is different are allowed,try again!\n");
		  }
		  //bonus 2
		}while((d1==0) || (d2==0) || (d3==0) || (d4==0) || (d1>6) || (d2>6) || (d3>6) || (d4>6) ||  (int)charD1<48 || (int)charD1>57 || (int)charD2<48 || (int)charD2>57 || (int)charD3<48 || (int)charD3>57 || (int)charD4<48 || (int)charD4>57 ||  (d1==d2) || (d1==d3) || (d1==d4) || (d2==d3) || (d2==d4) || (d3==d4));
		hits=ChekerOfSimillerityHits(d1,d2,d3,d4,d1OfRand,d2OfRand,d3OfRand,d4OfRand);
		misses=ChekerOfSimillerityMisses(d1,d2,d3,d4,d1OfRand,d2OfRand,d3OfRand,d4OfRand);
		numOfGuess--;
		if(hits==4)
		{
			printf("\n   4 HITS YOU WON!!!\n");
		    printf("                    ____                    \n");
            printf("                 _.' :  `._                 \n");
            printf("             .-.'`.  ;   .'`.-.             \n");
            printf("    __      / : ___\\ ;  /___ ; \\      __    \n");
            printf("  ,'_ \"\"--.:__;\".-.\";: :\".-.\":__;.--\"\" _`,  \n");
            printf("  :' `.t\"\"--.. '<@.`;_  ',@>` ..--\"\"j.' `;  \n");
            printf("       `:-.._J '-.-'L__ `-- ' L_..-;'       \n");
            printf("         \"-.__ ;  .-\"  \"-.  : __.-\"         \n");
            printf("             L ' /.------.\\ ' J             \n");
            printf("              \"-.   \"--\"   .-\"              \n");
            printf("             __.l\"-:_JL_;-\";.__             \n");
            printf("          .-j/'.;  ;\"\"\"\"  / .'\\\"-.          \n");
            printf("        .' /:`. \"-.:     .-\" .';  `.        \n");     
            printf("     .-\"  / ;  \"-. \"-..-\" .-\"  :    \"-.     \n");
            printf("  .+\"-.  : :      \"-.__.-\"      ;-._   \\    \n");
            printf("  ; \\  `.; ;                    : : \"+. ;   \n");
            printf("  :  ;   ; ;                    : ;  : \\:   \n");
            printf(" : `.\"-; ;  ;                  :  ;   ,/;   \n");
            printf("  ;    -: ;  :                ;  : .-\"'  :  \n");
            printf("  :\\     \\  : ;             : \\.-\"      :   \n");
            printf("   ;`.    \\  ; :            ;.'_..--  / ;   \n");
            printf("   :  \"-.  \"-:  ;          :/.\"      .'  :  \n");
            printf("     \\       .-`.\\        /t-\"\"  \":-+.   :  \n");
            printf("      `.  .-\"    `l    __/ /`. :  ; ; \\  ;  \n");
            printf("        \\   .-\" .-\"-.-\"  .' .'j \\  /   ;/   \n");
            printf("         \\ / .-\"   /.     .'.' ;_:'    ;    \n");
            printf("          :-\"\"-.`./-.'     /    `.___.'     \n");
            printf("                \\ `t  ._  /  bug :F_P:      \n");
            printf("                 \"-.t-._:'                  \n");
		}
		else
		{
			printf("\nYou got  %d HITS   %d MISSES.\n",hits,misses);

		}
	}
	if(numOfGuess==0 && guessNum != randomPassword)
	{
		printf("\n\nOOOOHHH!!!! Pancratius won and bought all of Hanukkkah's gifts!\nNothig left for you...\nThe secret password was %d",randomPassword);
	}
	else
	{
	   printf("\n\nIt took you only %d guesses, you are a professional code breaker!",numG-numOfGuess);
	}
}

 /*
 Function will check if digit of entered num is in the random num and if it is in the same place.
 input: All digits of entered number 1 to 4 and all digits of random num 1 to 4.
 output: hits-number of hits(digits that is in random number and in right place).
 */
int ChekerOfSimillerityHits(int d1, int d2,int d3,int d4,int dR1,int dR2,int dR3,int dR4)
{
	int hits=0;
	if(d1==dR1)
	{
		hits++;
	}
	if(d2==dR2)
	{
		hits++;
	}
	if(d3==dR3)
	{
		hits++;
	}
	if(d4==dR4)
	{
		hits++;
	}
	return(hits);
}

 /*
 Function will check if digit of entered num is in the random num and if it is not in the same place.
 input: All digits of entered number 1 to 4 and all digits of random num 1 to 4.
 output: misses-number of misses(digits that is in random number and not in right place).
 */
int ChekerOfSimillerityMisses(int d1, int d2,int d3,int d4,int dR1,int dR2,int dR3,int dR4)
{
	int misses=0;
	if ( (d1!= dR1) && (d1==dR2 || d1==dR3 || d1==dR4))
	{
		misses++;
	}
	if ( (d2!= dR2) && (d2==dR1 || d2==dR3 || d2==dR4))
	{
		misses++;
	}
	if ( (d3!= dR3) && (d3==dR2 || d3==dR1 || d3==dR4))
	{
		misses++;
	}
	if ( (d4!= dR4) && (d4==dR2 || d4==dR3 || d4==dR1))
	{
		misses++;
	}
	return(misses);
}
