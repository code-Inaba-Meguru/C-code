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
		printf("****  1.��ʼ       0.�˳�  ****\n");
		printf("*******************************\n");
		printf("��ѡ��>");
		scanf("%d", &input);
		clear_input_buffer();//����������еĻ��з�
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
			printf("���˳�\n");
			Sleep(1000);
			system("cls");
			break;
		}
		default:
		{
			printf("�������\n");
			break;
		}
		}
	} 
	while (input != 0);
	return 0;
}
