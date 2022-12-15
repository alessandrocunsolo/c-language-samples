
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
/*#include<unistd.h>*/
#include<windows.h>
#include <windows.h> 

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clsscr(){
    printf("\e[1;1H\e[2J");
}


#endif
#ifdef __linux__
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}
int kbhit(void) 
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
#endif

int main(){
    int x=0,ix=1;
    while(1){
        gotoxy(x,10);
        printf("%c",219);
        Sleep(100);
        clsscr();
        x+=ix;
        if (x>100 || x==0){
            ix=-ix;
        }
    }
}