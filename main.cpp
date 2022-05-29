#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "tictactoe_game.h"

#define keyUp 72
#define keyDown 80
#define keyEnter 13

void title();
void menu();

int main() {
  menu();
}


void title(int *num) {
  int screenTitle[20][80] =
  {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
  };

  printf("\e[?25l");
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);


	puts("");
	for(int i = 0; i < 10; i++) {
		printf("           ");
		for(int j = 0; j < 69; j++) {
			if(screenTitle[i][j]) {
				int state = (j + *num + 3 * i) % 69;
				if((0 <= state and state <= 9) or (50 <= state and state <= 59)) {
					printf("%c", char(176));
				}
				else if((10 <= state and state <= 19) or (40 <= state and state <= 49)) {
					printf("%c", char(177));
				}
				else if((20 <= state and state <= 29) or (30 <= state and state <= 39)) {
					printf("%c", char(178));
				}
				else {
					printf("%c", char(219));
				}
			}
			else printf(" ");
		}
		puts("");
  }
}


void menu() {
  int num = 0, currentPos = 0;
  int quit = 0;
  char key;
  char options[2][12] = {"   Play","   Quit"};

  system("CLS");
  do
  {
    title(&num);
    num += 68;

    printf("     ");

    for (int i = 0; i < 60; i++)
    {
      if (i == 59)
      {
        printf("%c", char(187));
      }
      else if (i == 0)
      {
        printf("%c", char(201));
      }
      else
      {
        printf("%c", char(205));
      }
    }

    puts("");

    for (int i = 0; i < 2; i++)
    {
      printf("     ");
      for (int j = 0; j < 60; j++)
      {
        if (j == 0 || j == 59)
        {
          printf("%c", char(186));
        }
        else
        {
          printf(" ");
        }
      }
      puts("");
    }

    for(int i = 0; i < 2; i++) {
			printf("     %c  ", char(186));
      for (int j = 0; j < 15; j++)
      {
        printf(" ");
      }
			if(currentPos == i) printf(">>   ");
			else printf("     ");

			printf("%s", options[i]);
			for(int j = strlen(options[i]); j < 11; j++) printf(" ");

			if(currentPos == i) printf("   <<");
			else printf("     ");
      for (int j = 0; j < 17; j++)
      {
        printf(" ");
      }
			printf("   %c", char(186));
			puts("");

		}

    for (int i = 0; i < 2; i++)
    {
      printf("     ");
      for (int j = 0; j < 60; j++)
      {
        if (j == 0 || j == 59)
        {
          printf("%c", char(186));
        }
        else
        {
          printf(" ");
        }
      }
      puts("");
    }

    printf("     ");

    for (int i = 0; i < 60; i++)
    {
      if (i == 59)
      {
        printf("%c", char(188));
      }
      else if (i == 0)
      {
        printf("%c", char(200));
      }
      else
      {
        printf("%c", char(205));
      }
    }

    if(kbhit())
    {
			key = getch();
			if(key == keyUp && currentPos != 0) currentPos--;
			else if(key == keyDown && currentPos != 1) currentPos++;
      else if(key == keyEnter)
      {
        switch(currentPos)
        {
          case 0:
            game();
            break;
          case 1:
            quit = 1;
            break;
        }
      }
    }
  }
  while (!quit);
}
