#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"

void clear_input_buffer()
{
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF);
}

int random_num(int min,int max)
{
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}
//�������min-max����

int init_num()
{
	srand(time(NULL));
	int min = 1, max = 3, index = 0;
	index = rand() % (max - min + 1) + min;
	return pow(2, index);
}
//�������2��4��8����ֵ

void add_rnum(int board[ROW][COL])
{
	int max = ROW * COL - 1, count = 0;
	int arr[ROW * COL] = { 0 };
	for (int i = 0; i <= max;i++)
	{
		if (board[0][i] == 0)
			arr[count++] = i;
	}
	if (count != 0) 
	{
		int rand = random_num(0, count - 1);
		int pos = arr[rand];
		board[0][pos] = init_num();
	}
}
//�ڿ�λ�����µķ���Ԫ��

void display_board(int board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4d", board[i][j]);//%������ֿɿ����ֶο�ȣ�Ĭ���Ҷ��룬������-��
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
				printf("---- ");
			printf("\n");
		}
	}
}
//��ʾ��Ϸ����

int win_judge(int board[ROW][COL], int row, int col) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 2048)
				return 1;
		}
	}
	return 0;
}
//ʤ���ж�

int lose_judge(int board[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == 0)
				break;
		}
		if (j != COL)
			break;
	}
	if (j != COL)
		return 0;
	else
	{
		for (int a = 0; a < ROW - 1; a++)
		{
			for (int b = 0; b < COL - 1; b++)
			{
				if (board[a][b] == board[a][b + 1] || board[a][b] == board[a + 1][b])
					return 0;
				else if (board[a + 1][b] == board[a + 1][b + 1] || board[a][b + 1] == board[a + 1][b + 1])
					return 0;
			}
		}
		return 1;
	}
}
//ʧ���ж�

void operate_a(int board[ROW][COL], int row, int col)
//������ʱ���鰴����Ҫ���ȡԭ����Ԫ�أ�����������д��
{
	for (int i = 0; i < row; i++)
	{
		int arr[COL] = { 0 };
		for (int j = 0, pos = 0; j < col; j++)
		{
			if (board[i][j] != 0)
			{
				//����Ԫ�����δ������飬����ͬԪ����������
				if (board[i][j] == arr[pos] && arr[pos] != 0)
					arr[pos] += board[i][j];
				else if (arr[pos] == 0)
					arr[pos] += board[i][j];
				else
					arr[++pos] = board[i][j];
			}
		}
		for (int j = 0; j < col; j++)
			board[i][j] = arr[j];
	}
}
//���ƶ�����

void operate_w(int board[ROW][COL], int row, int col)
{
	for (int j = 0; j < col; j++)
	{
		int arr[ROW] = { 0 };
		for (int i = 0, pos = 0; i < row; i++)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] == arr[pos] && arr[pos] != 0)
					arr[pos] += board[i][j];
				else if (arr[pos] == 0)
					arr[pos] += board[i][j];
				else
					arr[++pos] = board[i][j];
			}
		}
		for (int i = 0; i < row; i++)
			board[i][j] = arr[i];
	}
}
//���ƶ�����

void operate_d(int board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int arr[COL] = { 0 };
		for (int j = col - 1, pos = 0; j >= 0; j--)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] == arr[pos] && arr[pos] != 0)
					arr[pos] += board[i][j];
				else if (arr[pos] == 0)
					arr[pos] += board[i][j];
				else
					arr[++pos] = board[i][j];
			}
		}
		for (int j = col - 1; j >= 0; j--)
			board[i][j] = arr[col - 1 - j];
	}
}
//���ƶ�����

void operate_s(int board[ROW][COL], int row, int col)
{
	for (int j = 0; j < col; j++)
	{
		int arr[ROW] = { 0 };
		for (int i = row - 1, pos = 0; i >= 0; i--)
		{
			if (board[i][j] != 0)
			{
				if (board[i][j] == arr[pos] && arr[pos] != 0)
					arr[pos] += board[i][j];
				else if (arr[pos] == 0)
					arr[pos] += board[i][j];
				else
					arr[++pos] = board[i][j];
			}
		}
		for (int i = row - 1; i >= 0; i--)
			board[i][j] = arr[row - 1 - i];
	}
}
//���ƶ�����

//int move_ad(int board[ROW][COL], int arr[COL], int row, int col)
//{	
//	int sum = 0;
//	for (int j = 0, pos = 0; j < col; j++)
//	{
//		if (board[row][j] != 0)
//		{
//			if (board[row][j] == arr[pos] && arr[pos] != 0)
//				arr[pos] += board[row][j];
//			else if (arr[pos] == 0)
//			{
//				arr[pos] += board[row][j];
//				sum++;
//			}
//			else
//			{
//				arr[++pos] = board[row][j];
//				sum++;
//			}
//
//		}
//	}//�������ұ�������0Ԫ�ش�����ʱ����
//	return sum;
//}
////ˮƽ�ƶ�ʱ��ά����ÿ������,����Ԫ������ʱ���飬���������
//
//int move_ws(int board[ROW][COL], int arr[COL], int row, int col)
//{
//	int sum = 0;
//	for (int i = 0, pos = 0; i < row; i++)
//	{
//		if (board[i][col] != 0)
//		{
//			if (board[i][col] == arr[pos] && arr[pos] != 0)
//				arr[pos] += board[i][col];
//			else if (arr[pos] == 0)
//			{
//				arr[pos] += board[i][col];
//				sum++;
//			}
//			else
//			{
//				arr[++pos] = board[i][col];
//				sum++;
//			}
//		}
//	}//�������±�������0Ԫ�ش�����ʱ����
//	return sum;
//}
////��ֱ�ƶ�ʱ��ά����ÿ������,����Ԫ������ʱ���飬���������
//
//void sym(int arr[COL], int max)
//{
//	int box = 0;
//	int step = COL - max;
//	for (int i = max - 1; i >= 0; i--)
//	{
//		box = arr[i + step];
//		arr[i + step] = arr[i];
//		arr[i] = box;
//	}
//}
////����ʱ�������Ԫ���Ҳ༯��
//
//void operate_w(int board[ROW][COL], int row, int col)
//{
//	for (int j = 0; j < col; j++)
//	{
//		int arr[ROW] = { 0 };
//		move_ws(board, arr, row, j);
//		for (int i = 0; i < row; i++)
//			board[i][j] = arr[i];
//	}
//}
////���ƶ�����
//
//void operate_s(int board[ROW][COL], int row, int col)
//{
//	for (int j = 0; j < col; j++)
//	{
//		int arr[ROW] = { 0 };
//		int sum = move_ws(board, arr, row, j);
//		sym(arr, sum);
//		for (int i = 0; i < row; i++)
//			board[i][j] = arr[i];
//	}
//}
////���ƶ�����
//
//void operate_a(int board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		int arr[COL] = { 0 };
//		move_ad(board, arr, i, col);
//		for (int j = 0; j < col; j++)
//			board[i][j] = arr[j];
//	}
//}
////���ƶ�����
//
//void operate_d(int board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		int arr[COL] = { 0 };
//		int sum = move_ad(board, arr, i, col);
//		sym(arr, sum);
//		for (int j = 0; j < col; j++)
//			board[i][j] = arr[j];
//	}
//}
////���ƶ�����
//�ϰ��������ͬ���ֳ���ʱ�޷����ղ��������ϳɷ�ʽ


void play_game(int board[ROW][COL], int row, int col)
{
	while (win_judge(board, ROW, COL) ==0 && lose_judge(board) == 0) 
	{
		char operate = '0';
		add_rnum(board);
		display_board(board, row, col);
		printf("�����>");
		scanf("%c", &operate);
		clear_input_buffer();
		system("cls");
		if (operate == 'a')
			operate_a(board, row, col);
		else if (operate == 'd')
			operate_d(board, row, col);
		else if (operate == 'w')
			operate_w(board, row, col);
		else if (operate == 's')
			operate_s(board, row, col);
		else
			printf("��Ч������������\n");
	}
	if (win_judge(board, ROW, COL) == 1)
	{
		printf("you win!\n");
		Sleep(3000);
		system("cls");
	}
	else
	{
		printf("you lose!\n");
		Sleep(3000);
		system("cls");
	}
}




