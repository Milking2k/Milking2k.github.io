#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h> // get the keyboard
using namespace std;

bool gameOver;
const int WIDTH = 20;
const int HEIGHT = 18;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;//length of the tail

enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir;//the snake

void Setup()
{
    gameOver = false;
    dir = STOP;

    //cnt on the map
    x = WIDTH / 2;
    y = HEIGHT / 2;
    nTail = 0;


    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;

    score = 0;
}
void Draw()
{
    system("cls");// linux is clear
    for (int i = 0; i < WIDTH + 2;i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < HEIGHT+2;i++) {
        for (int j = 0; j < WIDTH + 2;j++){
            if(j==0 || j==WIDTH+1)
                cout << "#";
            else if(i==y && j==x)
                cout << "O";
            else if(i==fruitY && j==fruitX)
                cout << "F";
            else
            {
                bool printFlag = false;
                for (int k = 0; k < nTail;k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        printFlag = true;
                        break;
                    }
                }
                if(!printFlag){
                    cout << " ";
                }

            }
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score:" << score << endl;
    cout << "nTail:" << nTail << endl;
}
void Input()
{
    if(_kbhit()){ // press return key Or return 0;
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
            default:
                gameOver = true;
                break;
        }
    }
}
void logic()
{
    int prevX = x;
    int prevY = y;
    int prev2X,prev2Y;
    for (int i = 0; i < nTail;i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }


    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    
        default:
            break;
    }


    if (x > WIDTH+2) x = 1;
    if (x <= 0) x = WIDTH;
    if (y > HEIGHT+2) y = 0;
    if (y < 0) y = HEIGHT+1;

    // for (int i = 0; i < nTail;i++)
    // {
    //     if(tailX[i]==x && tailY[i] == y){
    //         gameOver = true;
    //         cout << "Game Over" << endl;
    //     }
    // }

    if (x == fruitX && y == fruitY)
    {
        score += 100;
        tailX[nTail] = fruitX;
        tailY[nTail] = fruitY;
        nTail++;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }

}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        logic();
        Sleep(50);
    }
    system("pause");
    return 0;
}