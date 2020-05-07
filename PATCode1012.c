/*
    1. 二分查找要注意mid - 1 (mid + 1)
*/
#include <stdio.h>
#include <stdlib.h>
const char subject[] = {'A', 'C', 'M', 'E'};
void popSort(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
}
int binarySearch(int *array, int size, int aim)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] < aim)
            right = mid - 1;
        else if (array[mid] > aim)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

void average(int *grade, int number)
{
    int sum = 0;
    int i;
    for (i = number * 4 + 1; i < number * 4 + 4; i++)
        sum += grade[i];
    grade[number * 4] = sum / 3;
}

void toRank(int *grade, int *rank, int studentNumber, int subjectNumber)
{
    int *gradeArray = (int *)malloc(sizeof(int) * studentNumber);
    for (int i = 0; i < studentNumber; i++)
        gradeArray[i] = *(grade + subjectNumber + i * 4);
    // 冒泡排序
    popSort(gradeArray, studentNumber);
    // 二分查找算排名
    for (int i = 0; i < studentNumber; i++)
        rank[subjectNumber + i * 4] = binarySearch(gradeArray, studentNumber, *(grade + subjectNumber + i * 4));
}

void outputBestRank(int *rank, int studentNumber)
{
    if (studentNumber == -1)
    {
        printf("N/A\n");
        return;
    }
    int base = studentNumber * 4;
    int min = 0;
    for (int i = 0; i < 4; i++)
    {
        if (rank[base + min] > rank[base + i])
            min = i;
    }
    printf("%d %c\n", rank[base + min] + 1, subject[min]);
}

int main()
{
    int n, m;
    long *sID;
    int *grade;
    int *rank;
    long *candidate;
    scanf("%d%d", &n, &m);
    sID = (long *)malloc(sizeof(long) * n);
    grade = (int *)malloc(sizeof(int) * n * 4);
    rank = (int *)malloc(sizeof(int) * n * 4);
    candidate = (long *)malloc(sizeof(long) * m);

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", sID + i);
        for (int j = 1; j < 4; j++)
            scanf("%d", grade + i * 4 + j);
    }
    for (int i = 0; i < m; i++)
        scanf("%ld", candidate + i);

    // 计算
    // 算平均值
    for (int i = 0; i < n; i++)
        average(grade, i);
    // 算排名
    for (int i = 0; i < 4; i++)
        toRank(grade, rank, n, i);

    // 输出
    for (int i = 0; i < m; i++)
    {
        long studentId = candidate[i];
        int studentNumber = -1;
        for (int j = 0; j < n; j++)
        {
            if (studentId == sID[j])
                studentNumber = j;
        }
        outputBestRank(rank, studentNumber);
    }
    return 0;
}