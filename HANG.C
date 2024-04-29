//without fflush()
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void main(){
    int i=0,j,fail=0,l=0;
    int f1=0,cat,len;
    char ch='Y',guess;
    char word[100],game[20];
    
    char country[20][20]={"oman", "cuba", "gaza", "iran","iraq","chile", "india", "italy", "japan", "nepal"};
    char sports[20][20]={"soccer", "basketball", "cricket", "tennis", "rugby", "golf", "athletics", "formula1", "boxing", "baseball"};
    char cars[20][20]={"toyota", "volkswagen", "ford", "honda", "chevrolet", "nissan", "mercedes", "bmw", "audi", "hyundai"};

    srand(time(NULL));
    
    
    while(toupper(ch)=='Y'){
        fail=0;
    printf("Enter the corresponding numbers for required categories\n1:Countries\n2:sports\n3:cars\n");
        if (scanf("%d", &cat) != 1 || cat < 1 || cat > 3) {
        printf("\nInvalid input. Please enter a number between 1 and 3.\n");
        flush(stdin);
        continue;
        }

    strcpy(game,"____________________");

    
    switch(cat)
    {
        case 1:strcpy(word,country[rand()%10]);
                break;
        case 2:strcpy(word,sports[rand()%10]);   
                break;
        case 3:strcpy(word,cars[rand()%10]);
                break;
    }

    len=strlen(word);
    
    printf("THE WORD HAS %d LETTERS\n",strlen(word));
    l=0;
    while(1){
        flush(stdin);
        printf("Enter Your Guess:");
            if (scanf("%c", &guess) != 1 || !isalpha(guess)) {
            printf("Invalid input. Please enter a single alphabet character.\n");
            flush(stdin);
            continue;
            }


        f1=0;
        
        for(i=0;i<len;i++)
        {   
            if (tolower(guess)==word[i]&&guess!=game[i])
            {
                game[i]=word[i];
                l++;
                f1=1;
            }
        }   
            
            if(f1==1)
                printf("You Got It Right!!\n");
            else {printf("Sorry!\n");
                    fail++;}
        for(j=0;j<len;j++) 
            printf("%c",game[j]);
               
        printf("\n");

        printf("you have %d guesses left\n",7-fail);

        
        printf("\n");
        printf("\n");

        if(fail>=7){
            printf("you lost\n");
            printf("the word is %s",word);
            break;}
        if(l>=len){
            printf("You Won\n");
            break;}

     } flush(stdin);
        printf("\nEnter Y to continue\nEnter N to stop");
        scanf("%c",&ch);
    
}}
