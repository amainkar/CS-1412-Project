//Name: Atharva Mainkar
//Group: Alex Jaziel Atharva
//Section: Lab 504/Lecture 004
//Problem: Project
//Date: 5/5/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void topupBalance()
{
  FILE *fp;
  char playerName[100];
  char name[20][100];
  int i,x, money[20], gain[20], addMoney, a=0;

  printf("Please enter the player name\n");
  scanf("%s",&playerName);
  printf("How much money do you want to add to your balance?\n");
  scanf("%d",&addMoney);

  fp=fopen("players.txt","r");

  if(fp==NULL)
  {
    printf("FILE DOES NOT EXIST!");
    exit(EXIT_FAILURE);
  }

  for(i=0;!feof(fp);i++)
  {
    fscanf(fp,"%s %d %d", &name[i], &money[i], &gain[i]);
    if(strcmp(name[i],playerName)==0)
    {
      money[i]=money[i]+addMoney;
      a=1;
    }
  }
  if(a==0)
  {
    printf("The player does not exist.\n");
  }
  
  fclose(fp);
  fp=fopen("players.txt","w");

  for(x=0;x+1<i;x++)
    {
      fprintf(fp,"%s %d %d\n",name[x], money[x], gain[x]);
    }

  fclose(fp);


}

void topPlayersbyBalance()
{
  FILE *fp;
  char name[20][100];
  int i,x, money[20], gain[20], addMoney,q,r,moneycopy[20],temp;
  fp=fopen("players.txt","r");

  if(fp==NULL)
  {
    printf("FILE DOES NOT EXIST!");
    exit(EXIT_FAILURE);
  }

  for(i=0;!feof(fp);i++)
  {
    fscanf(fp,"%s %d %d", &name[i], &money[i], &gain[i]);
  }
  
  --i;

  for(q=0;q<=i;q++)
  {
    moneycopy[q]=money[q];
    //printf("%s\n",name[q]);
  }
  
  for (q = 0; q < i; q++)
	{
		for (r = q + 1; r < i; r++)
		{
			if(moneycopy[q] < moneycopy[r])
			{
				temp = moneycopy[q];
				moneycopy[q] = moneycopy[r];
				moneycopy[r] = temp;
			}
			
		}
	}

  for(q=0;q<=4;q++)
  {
    for(r=0;r<=i;r++)
    {
      if(money[r]==moneycopy[q])
      {
        printf("%s %d %d\n",name[r],money[r],gain[r]);
      }
    }
  }
  printf("\n");
}
void topPlayersbyGain()
{
  FILE *fp;
  char name[20][100];
  int i,x, money[20], gain[20], addMoney,q,r,moneycopy[20],temp;
  fp=fopen("players.txt","r");

  if(fp==NULL)
  {
    printf("FILE DOES NOT EXIST!");
    exit(EXIT_FAILURE);
  }

  for(i=0;!feof(fp);i++)
  {
    fscanf(fp,"%s %d %d", &name[i], &money[i], &gain[i]);
  }
  
  --i;

  for(q=0;q<=i;q++)
  {
    moneycopy[q]=gain[q];
    //printf("%s\n",name[q]);
  }
  
  for (q = 0; q < i; q++)
	{
		for (r = q + 1; r < i; r++)
		{
			if(moneycopy[q] < moneycopy[r])
			{
				temp = moneycopy[q];
				moneycopy[q] = moneycopy[r];
				moneycopy[r] = temp;
			}
			
		}
	}

  for(q=0;q<=4;q++)
  {
    for(r=0;r<=i;r++)
    {
      if(gain[r]==moneycopy[q])
      {
        printf("%s %d %d\n",name[r],money[r],gain[r]);
      }
    }
  }
  printf("\n");


}





void playGame() {
	FILE *fp;
  char playerName[100];
  char name[20][100];
  int i, x, money[20], gain[20], a=0, pos;
  int dice1, dice2, sum, pointvalue, count, num;


  fp=fopen("players.txt","r");
  if(fp==NULL)
  {
    printf("FILE DOES NOT EXIST!");
    exit(EXIT_FAILURE);
  }

  for(i=0;!feof(fp);i++)
  {
    fscanf(fp,"%s %d %d", &name[i], &money[i], &gain[i]);
  }

  fclose(fp);

	printf("Please enter your full name\n");
	scanf("%s",playerName);
  for(x=0;i>x;x++)
  {
    if(strcmp(playerName,name[x]) == 0)
    {
      a=1;
      pos=x;
    }
  }
	
	for(;;) {
		
		if(a == 1) {
			
			if(money[pos] <= 0) {
				printf("The given player has an insufficient amount of money to keep playing.\n");
				break;
			}
			
			else {
				printf("Press Enter to Roll the dice.\n");
				getchar();
				getchar();
				dice1=(rand()%6)+1;
				dice2=(rand()%6)+1;
				sum = dice1 + dice2;
				printf("\nThe values of the dices are %d and %d whose sum is %d.\n",dice1,dice2,sum);
			}
			
			if(sum == 7 || sum == 11) {
				money[pos]+=10;
				gain[pos]+=10;
				printf("You win the game. Your current balance is %d.\n",money[pos]);
			}
			
			else if(sum == 2 || sum == 3 || sum == 12) {
				money[pos]-=1;
				gain[pos]-=1;
				printf("You lost the game. Your current balance is %d.\n",money[pos]);
			}
			
			else {
				pointvalue = sum;
				for(;;) {
						printf("Press Enter to Roll the dice.\n");
						getchar();
						dice1=(rand()%6)+1;
						dice2=(rand()%6)+1;
						sum = dice1 + dice2;
						printf("\nThe values of the dices are %d and %d whose sum is %d.\n",dice1,dice2,sum);

					if(sum == pointvalue) {
						money[pos]+=10;
						gain[pos]+=10;
						printf("You win the game. Your current balance is %d.\n",money[pos]);
						break;
					}
					else if(sum == 7) {
						money[pos]-=1;
						gain[pos]-=1;
						printf("You lost the game. Your current balance is %d.\n",money[pos]);
						break;
					}
				}	
			}
			
		printf("Play another game? 0 for yes/1 for no\n");
		scanf("%d",&num);
		
		if(num == 0) {
			continue;
		}
		else
			break;

		}
		else
		{
        printf("Player does not exist\n");
        break;
		}
		count++;
	}
	fp=fopen("players.txt","w");

	for(x=0;x+1<i;x++)
    {
      fprintf(fp,"%s %d %d\n",name[x], money[x], gain[x]);
    }

  fclose(fp);
}






int main() {
  int menuSelect=1;
  while(menuSelect!=4)
  {
    printf("Select one of the following options\n0)Top up balance\n1) play game\n2) top 5 players by balance\n3) top 5 winners by what they have won\n4) exit the game\n");
    scanf("%d",&menuSelect);
    if(menuSelect==0)
    {
      topupBalance();
    }
    if(menuSelect==1)
    {
      playGame();
    }
    if(menuSelect==2)
    {
     topPlayersbyBalance(); 
    }
    if(menuSelect==3)
    {
     topPlayersbyGain(); 
    }
  }
  return 0;
}