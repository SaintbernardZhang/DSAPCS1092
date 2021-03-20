// 學號 OCE123447012
// 姓名 張祐誠

#include <stdio.h>
#include <stdlib.h>

int addNO();

int main(void)
{
    int command = 0; //選擇執行項目的變數
    do
    {
    	int N;
    	printf("* * * * * Add Numbers Generator * * * *\n");
    	printf("*                                     *\n");
    	printf("* 0. Quit                             *\n");
    	printf("* 1. Add everynumbers from your input *\n");
    	printf("*                                     *\n");
    	printf("* * * * * * * * * * * * * * * * * * * *\n");
    	printf("Input a choice(0, 1): ");
    	scanf("%d", &command); //取得欲執行的項目
    	printf(" \n");
    	
    	if (command == 1)
    	{
 	        printf("Input a number : ");
 	        scanf("%d", &N);
 	        addNO(N); //開始進行遞迴 
    	}
    	else if (command > 2) //判斷輸入數值非所設定執行的項目
        {
            printf("Command does not exist!\n");
            printf(" \n");
        }
    } while (command != 0); //停止執行迴圈
    system("pause"); //暫時停止螢幕畫面

    return 0;
} //主程式結束

int addNO(int k) //此為進行遞迴的函式
{
    printf("%d", k); //輸出目前的數值 
    if (k > 9) //若數值大於10則進行各位數字相加 
    {
    	printf(", "); //加分隔逗號 
    	int m, n;
    	m = k;
    	n = 0;
    	do 
    	{
    		n = n + m % 10;
    	    m = m / 10;
		}while(m != 0);
		addNO(n); //進行下一輪的遞迴輸出 
	}	
	if (k < 10) //遞迴結束時輸入分行 
	{
		printf("\n");
		printf("\n");
	}	
}
