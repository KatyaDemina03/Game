#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int N = 7;
int randomNumbers(int numbers[], int N);
int checkSeven(int numbers[], int N, int money);
int checkSame(int numbers[], int N, int money);
int main(){
  srand(time(NULL));
  printf("WELCOME!\n");
  int menu; int N = 7;
  int money;
  int numbers[N];
  printf("Set your bet for the game:     $\b\b\b\b\b\b");
  scanf("%d", &money);
  while(1){
  if(money==0){
  printf("Game over\nPress 0 to exit. If you want to play, enter new bet:     $\b\b\b\b\b\b");
  scanf("%d", &money);
  if(money==0){return 0;
    }
  }
  printf("\nStart the game - 1\nEnd - 0\n\nEnter: ");
  scanf("%d", &menu);
  switch(menu){
    case 1:
      printf("\n Your numbers: ");
      randomNumbers(numbers, N);
      money = checkSeven(numbers, N, money);
      printf("Your balance: %d$\n", money);
      break;
    case 0:
      if(money>0){
        printf("Congradulations! You won %d $\n", money);
      }else{printf("\nYou won nothing(");
      }
      return 0;
      
  }
    }
  int r = rand()%10+1;
  printf("%d", r);
  return 0;
}
int randomNumbers(int numbers[], int N){
  for(int i = 0; i < 7; i++){
    numbers[i] = rand()%10+1;
    printf("%d ", numbers[i]);
  }
  printf("\n\n");
}
int checkSeven(int numbers[], int N, int money){
  int amount = 0;
  for(int i = 0; i < 7; i++){
    if(numbers[i]==7){
    amount += 1;
    }
  }
  if(amount==7){
  money*=3;
  printf("\nCongradulations!!! You've got all 7\n");
  }
  else if(amount>0){
    printf("You have saved your money...\n");
    int moneyHelp = checkSame(numbers, N, money);
    if (moneyHelp>0){
      money = moneyHelp;
    }
  }else{
    money =checkSame(numbers, N, money);
  }
  return money;
}
int checkSame(int numbers[], int N, int money){
  int amount[7]={0,0,0,0,0,0,0};
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(numbers[i]==numbers[j]){
        amount[i]++;
        }
      }
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(amount[i]<amount[j]){
          amount[i]=amount[j];
        }
      }
  }
    if(amount[0]==7){
      money*=2;
    } else if(amount[0]<3){
      money=0;
    } else{
      printf("You have saved your money...\n");
    }
    //printf("%d\n", amount[0]); - Проверка количества одинаковых цифр
    return money;
  }