#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

//Initialize checkerboard
void InitBoard(char board[ROW][COL], int row, int col);

//Print board
void DisPlayBoard(char board[ROW][COL], int row, int col);

//Player play chess
void PlayerMove(char board[ROW][COL], int row, int col);

//Computer play chess
void ComputerMove(char board[ROW][COL], int row, int col);

//Call the shots
//Player win - '*'
//Computer win - '#'
//Tie game - 'Q'
//continue - 'C'
char IsWin(char board[ROW][COL], int row, int col);
//Initialize checkerboard
void InitBoard(char board[ROW][COL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//Print board
void DisPlayBoard(char board[ROW][COL], int row, int col)
{
    printf("  1   2   3\n");  // 添加列号
    for(int i = 0; i < row; i++)
    {
        printf("%d ", i + 1);  // 添加行号
        //Print digit
        for(int j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        //Print split message
        if(i < row - 1)
        {
            printf("  ");  // 对齐分隔线
            for(int j = 0; j < col; j++)
            {
                printf("---");
                if(j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

//Player play chess
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("请选择下棋坐标(行 列)：");
        scanf("%d %d",&x,&y);
        
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("该位置已被占用，请重新选择\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入\n");
        }
    }
}

//Computer play chess
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

    printf("computer play chess\n");
    while(1)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//if full return 1
//else return 0
int IsFull(char board[ROW][COL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}
//Call the shots
char IsWin(char board[ROW][COL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return  board[i][1];
        }
    }
    for(int j = 0; j < col; j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
        {
            return board[1][j];
        }
    }
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') || 
       (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '))
    {
        return board[1][1];
    }
    if(IsFull(board, row, col))
    {
         return 'Q';
    }
    return 'C';
}

void menu()
{
    printf("**************************\n");
    printf("******1. play 0.exit******\n");
    printf("**************************\n");
}

void game()
{
    char ret;
    char board[ROW][COL] = {0};
    //Initialize the chessboard function
    InitBoard(board,ROW,COL);
    DisPlayBoard(board,ROW,COL);
    //Play chess
    while(1)
    {
        PlayerMove(board,ROW,COL);
        DisPlayBoard(board,ROW,COL);  // 显示玩家移动后的棋盘
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')
        {
            break;
        }
        
        ComputerMove(board,ROW,COL);
        DisPlayBoard(board,ROW,COL);  // 显示电脑移动后的棋盘
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')
        {
            break;
        }
    }
    if(ret == '*')
    {
        printf("You win!\n");
    }
    else if(ret == '#')
    {
        printf("Computer win!\n");
    }
    else if(ret == 'Q')
    {
        printf("Tie game!\n");
    }
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();//print menu
        printf("please choose");
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
