#include <stdio.h>
#define MAX 99
void Input(int at[], int bt[], int *n)
{
    printf("Enter the number of process :");
    scanf("%d", n);
    int i;
    for (i = 0; i < *n; i++)
    {
        printf("Arrival time [%d] :", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time [%d] :", i + 1);
        scanf("%d", &bt[i]);
        printf("\n");
    }
}
void Calculate(int at[], int bt[], int tat[], int wt[], int ct[], int n, int *SUM, int *total_tat, int *total_wt)
{
    //Calculate Complete Time
    int j;
    for (j = 0; j < n; j++)
    {
        (*SUM) += bt[j];
        ct[j] += (*SUM);
    }
    //Calculate Total Turnaround time and Total waiting time
    for (j = 0; j < n; j++)
    {
        tat[j] = ct[j] - at[j];
        (*total_tat) += tat[j];
    }
    for (j = 0; j < n; j++)
    {
        wt[j] = tat[j] - bt[j];
        (*total_wt) += wt[j];
    }
}
void Output(int at[], int bt[], int tat[], int wt[], int n, float total_tat, float total_wt)
{
    printf("Result Table :\n\n");
    printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("P%d\t %7d\t %5d\t %15d\t %9d\t\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Turnaround Time : %.3f\n", (float)total_tat / n);
    printf("Average Waiting Time  : %.3f\n\n", (float)total_wt/ n);
}
int main()
{
    /*bt = burst time - Thoi gian thuc thi
    at = arrival time - Thoi gian den
    tat = Turnaround time - Thoi gian quay lai
    wt= waiting time - Thoi gian doi
    ct = complete time - Thoi gian hoan thanh */
    int at[MAX], bt[MAX], tat[MAX], wt[MAX], ct[MAX] = {0};
    int n;
    int SUM = 0, total_tat = 0, total_wt= 0; //Total TurnAround Time and Total Waiting Time
    //Data
    Input(at, bt, &n);
    //Handle
    Calculate(at, bt, tat, wt, ct, n, &SUM, &total_tat, &total_wt);
    //Result
    Output(at, bt, tat, wt, n, total_tat, total_wt);
    return 0;
}