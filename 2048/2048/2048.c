#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "game.h"

int main()
{
	int input = 0;
	do
	{
		printf("*******************************\n");
		printf("****  1.开始       0.退出  ****\n");
		printf("*******************************\n");
		printf("请选择>");
		scanf("%d", &input);
		clear_input_buffer();//清除缓冲区中的换行符
		system("cls");
		switch (input)
		{
		case 1:
		{
			int board[ROW][COL] = { 0 };
			play_game(board, ROW, COL);
			break;
		}
		case 0:
		{
			printf("已退出\n");
			Sleep(1000);
			system("cls");
			break;
		}
		default:
		{
			printf("输入错误！\n");
			break;
		}
		}
	} 
	while (input != 0);
	return 0;
}
