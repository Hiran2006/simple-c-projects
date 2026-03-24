#include<stdlib.h>
#include<stdio.h>

int main(){
    while(1){
        int from,to;
        printf("From ");
        scanf("%d", &from);
        printf("To ");
        scanf("%d", &to);
        int num = rand() % (to - from + 1) + from;
        int guess;
        int attempts = 0;
        while(guess != num){
            printf("Guess the number: ");
            scanf("%d", &guess);
            attempts++;
            if(guess < num){
                printf("Too low\n");
            }else if(guess > num){
                printf("Too high\n");
            }
        }
        printf("You guessed the number in %d attempts\n", attempts);
    }
}