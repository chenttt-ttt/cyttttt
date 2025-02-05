#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisPlayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
    printf("----MineSweeper----\n");
    for(int j = 0; j <= row; j++)
    {
        printf("%d ",j);
    }
    printf("\n");;
    for(int i = 1; i <= row; i++)
    {
        printf("%d ",i);
        for(int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("----MineSweeper----\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
        }
        count--;
    }
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
    return (board[x - 1][y] +
    board[x - 1][y - 1] +
    board[x][y - 1] +
    board[x + 1][y] +
    board[x + 1][y + 1] +
    board[x + 1][y] +
    board[x][y + 1] +
    board[x - 1][y + 1]) - (8 * '0');
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while(win < row * col - EASY_COUNT)
    {
        printf("please choose coordinate\n");
        scanf("%d%d",&x,&y);
        if(show[x][y] != '*')
        {
            printf("Coordinates are occupied, please select another coordinate\n");
        }
        else
        {
            if(x >= 1 && x <= row && y >= 1 && y <= col)
            {
                if(mine[x][y] == '1')
                {
                    printf("boom!you die!\n");
                    DisPlayBoard(mine,ROWS, COLS);
                    break;
                }
                else
                {
                    win++;
                    int count = get_mine_count(mine,x,y);
                    show[x][y] = count + '0';
                    DisPlayBoard(show,ROW,COL);
                }
            }
            else
            {
                printf("error,please choose again\n");
            }
        }
    }
}

void menu()
{
    printf("************************\n");
    printf("*****1.play  0.exit*****\n");
    printf("************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    SetMine(mine, ROW, COL);
    DisPlayBoard(show,ROW,COL);
    FindMine(mine, show,ROW,COL);
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("please choose\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("exit game");
                break;
            default:
                printf("error");
                break;
        }
    }while(input);
    return 0;
}
