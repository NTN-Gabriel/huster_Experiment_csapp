#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define STUDENTS_NUM  10

#pragma pack(1)
typedef struct temp {
	char  name[8];
	char  sid[11];    //  如U202315123
	short  scores[8]; //  8门课的分数
	short  average;   //  平均分
}student;

void display(student* s, int num) {
	for (int i = 0; i < num; i++) {
		printf("%s %s ", s[i].name, s[i].sid);
		for (int j = 0; j < 8; j++) {
			printf("%d ", s[i].scores[j]);
		}
		printf("%d\n", s[i].average);
	}
}
void initStudents(student* s, int num)
{
	for (int i = 0; i < num; i++)
	{
		scanf("%s", s[i].name);
		scanf("%s", s[i].sid);
		for (int j = 0; j < 8; j++)
		{
			scanf("%d", &s[i].scores[j]);
		}
	}
}

void computeAverageScore(student* s, int num)
{
	for (int i = 0; i < num; i++)
	{
		int sum = 0;
		for (int j = 0; j < 8; j++)
		{
			sum += s[i].scores[j];
		}
		s[i].average = sum / 8;
	}
}

void sort(student* s, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (s[i].average < s[j].average)
			{
				student temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

void QuickSort(student* s, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int j = right;
	student temp = s[left];
	while (i < j)
	{
		while (i < j && s[j].average <= temp.average)
		{
			j--;
		}
		s[i] = s[j];
		while (i < j && s[i].average >= temp.average)
		{
			i++;
		}
		s[j] = s[i];
	}
	s[i] = temp;
	QuickSort(s, left, i - 1);
	QuickSort(s, i + 1, right);
}

int main() {
	student s[STUDENTS_NUM];
	LARGE_INTEGER start, finish, freq;
	double duration;

	initStudents(s, STUDENTS_NUM); // 初始化学生信息

	// 获取高性能计数器的频率
	QueryPerformanceFrequency(&freq);

	// 计算平均分的时间测量
	QueryPerformanceCounter(&start);
	computeAverageScore(s, STUDENTS_NUM);
	QueryPerformanceCounter(&finish);
	duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
	printf("计算平均成绩用时： %f 毫秒\n", duration);
	display(s, STUDENTS_NUM);

	student copy1[STUDENTS_NUM];
	for (int i = 0; i < STUDENTS_NUM; i++) {
		for (int m = 0; m < 8; m++) {
			copy1[i].name[m] = s[i].name[m];
		}
		for (int m = 0; m < 11; m++) {
			copy1[i].sid[m] = s[i].sid[m];
		}
		for (int j = 0; j < 8; j++) {
			copy1[i].scores[j] = s[i].scores[j];
		}
		copy1[i].average = s[i].average;
	}

	student copy2[STUDENTS_NUM];
	for (int i = 0; i < STUDENTS_NUM; i++) {
		for (int m = 0; m < 8; m++) {
			copy2[i].name[m] = s[i].name[m];
		}
		for (int m = 0; m < 11; m++) {
			copy2[i].sid[m] = s[i].sid[m];
		}
		for (int j = 0; j < 8; j++) {
			copy2[i].scores[j] = s[i].scores[j];
		}
		copy2[i].average = s[i].average;
	}

	//QueryPerformanceCounter(&start);
	//computeAverageScore2(s, STUDENTS_NUM);
	//QueryPerformanceCounter(&finish);
	//duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
	//printf("计算平均成绩用时（优化前）： %f 毫秒\n", duration);
	//display(s, STUDENTS_NUM);

	//QueryPerformanceCounter(&start);
	//computeAverageScore3(s, STUDENTS_NUM);
	//QueryPerformanceCounter(&finish);
	//duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
	//printf("计算平均成绩用时（优化后）： %f 毫秒\n", duration);
	//display(s, STUDENTS_NUM);

	// 排序的时间测量
	QueryPerformanceCounter(&start);
	sort(copy1, STUDENTS_NUM);
	QueryPerformanceCounter(&finish);
	duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
	printf("排序用时（优化前）： %f 毫秒\n", duration);
	display(s, STUDENTS_NUM);

	QueryPerformanceCounter(&start);
	QuickSort(copy2, 0, STUDENTS_NUM - 1);
	QueryPerformanceCounter(&finish);
	duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
	printf("排序用时（优化后）： %f 毫秒\n", duration);
	display(s, STUDENTS_NUM);

	return 0;
}