#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<graphics.h>
#include<conio.h>

   int i = 0, j, fail = 0, l = 0;
   int f1 = 0, cat, len;
   char ch = 'Y', guess;
   char word[20];
   char game[10]={"-------"};
   char guessed[20];
   char fstr[1];

// Function to select a random word from the given category
void selectWord(char *word, char category[][20], int num_words)
 {
    strcpy(word, category[rand() % num_words]);
  }
//fun for title
void title()
 {
   settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
   outtextxy(190,0,"HANGMAN");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  }
// Function to display the current state of the game
void displayGame(char *game, int x, int y)
 {
    outtextxy(x, y, game);
  }

//function to display guesses
void guessc()
  {
       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
       outtextxy(375, 320, "You have ");
       outtextxy(375 + textwidth("You have "),320,itoa(7 - fail, game, 10));
       outtextxy(375 + textwidth("You have ") + textwidth(itoa(7 - fail, game, 10)) , 320, " guesses left");
       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   }

//function of the word has n letters
void letters()
  {

	outtextxy(375, 70, "THE WORD HAS ");
	outtextxy(375 + textwidth("THE WORD HAS "), 70, itoa(len, game, 10));
	outtextxy(375 + textwidth("THE WORD HAS ") + textwidth(itoa(len, game, 10)) , 70, " LETTERS");

   }

// Function to draw the hangman structure

void drawHangman(int incorrectGuesses)
 {
    int inc=incorrectGuesses;
    line(420,100,500,100);
    line(500,100,500,290);
    rectangle(390,290,520,300);

    if(inc>=1)
	line(450,100,450,130);
    if (incorrectGuesses >= 2) // Draw head
	circle(450, 150, 20);
    if (incorrectGuesses >= 3) // Draw body
	line(450, 170, 450, 230);
    if (incorrectGuesses >= 4) // Draw left arm
	line(450, 190, 420, 220);
    if (incorrectGuesses >= 5) // Draw right arm
	line(450, 190, 480, 220);
    if (incorrectGuesses >= 6) // Draw left leg
	line(450, 230, 430, 270);
    if (incorrectGuesses >= 7) // Draw right leg
	line(450, 230, 470, 270);
 }

void clrin()
  {
	int c;
	while((c=getchar())!='\n'&&c!=EOF);
   }

void guessedw()
  {
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	 outtextxy(410,340,guessed);
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

    }
int main()
 {

    char country[20][20] = {"oman", "cuba", "gaza", "iran","iraq","chile", "india", "italy", "japan", "nepal"};
    char sports[20][20] = {"soccer", "basketball", "cricket", "tennis", "rugby", "golf", "athletics", "formula1", "boxing", "baseball"};
    char cars[20][20] = {"toyota", "volkswagen", "ford", "honda", "chevrolet", "nissan", "mercedes", "bmw", "audi", "hyundai"};


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    srand(time(NULL));

	title();
	fail = 0;
	printf("\n\n\n\nEnter the corresponding numbers for required categories\n1: Countries\n2: Sports\n3: Cars\n");
	scanf("%d", &cat);

	switch (cat)
	{
	    case 1:
		selectWord(word, country, 10);
		break;
	    case 2:
		selectWord(word, sports, 10);
		break;
	    case 3:
		selectWord(word, cars, 10);
		break;
	   }

	len = strlen(word);
	for(i=0;i<len;i++)
		guessed[i]='_';
	guessed[len]='\0';

	letters();
	while (1)
	 {
		delay(0000);
		cleardevice();
		letters();
		title();
		drawHangman(fail);
		guessc();
		guessedw();
	    clrin();
	    outtextxy(0,100,"Enter Your Guess:");
	    scanf("%c", &guess);
	    clrin();
	    f1 = 0;
	    for (i = 0; i < len; i++)
	     {
		if (tolower(guess) == word[i] && guess != game[i])
		 {
		    game[i] = word[i];
		    guessed[i]=word[i];
		    l++;
		    f1 = 1;
		  }
	      }


	    if (f1 == 1){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(0,250,"You Got It Right!!");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		guessedw();}
	    else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(0,250,"Sorry!,You Got It Wrong");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		guessedw();
		fail++;
	    }

		outtextxy(0,300,"press ENTER key to continue");
		getch();
	    guessedw();
	    cleardevice();
	    letters();
	    guessc();
	    title();
	    drawHangman(fail);
	    guessedw();

	    if (fail >= 7) {

		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		outtextxy(20, 200, "YOU LOST");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(30, 250, "The word is ");
		outtextxy(30 + textwidth("The word is "), 250, word);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

		break;
	    }
	    if (l >= len) {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(20, 200, "YOU WON!!");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(30, 250, "The word is ");
		outtextxy(30 + textwidth("The word is "), 250, word);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		break;
	    }

	}
	getch();
	closegraph();
	return 0;
}
