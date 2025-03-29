#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	char* s;
	int len;
}str;
void get_next(const char* T, int* next) 
{
	int j = 0, k = -1, len = strlen(T);
	next[0] = k;
	while(j<len-1)
	{
		if (k == -1 || T[k] == T[j])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int strstr_kmp(str S, str T)
{
	int i = 0, j = 0;
	int* next = (int*)malloc(sizeof(int) * T.len);
	if (!next)
	{
		printf("nextÊý×é´æ´¢·ÖÅäÊ§°Ü\n");
		return -2;
	}
	get_next(T.s, next);
	
	while (i < S.len && (j < T.len))
	{
		if (j ==-1 || S.s[i] == T.s[j])
			i++, j++;
		else
			j = next[j];
	}
	free(next);
	if (j >= T.len)
		return i - T.len;
	return -1;
}
int main() 
{
	str S, T;
	S.s = "yangshaokfcvme50please";
	S.len = strlen(S.s);
	T.s = "kfcvme50";
	T.len = strlen(T.s);
	printf("%d\n", (int)(strstr(S.s, T.s) - S.s));
	printf("%d\n", strstr_kmp(S, T));
}

