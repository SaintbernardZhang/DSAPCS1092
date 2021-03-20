// 學號 OCE123447012
// 姓名 張祐誠

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNO();
int getNO_C();
int swap();

int main(void)
{
	int command = 0; //選擇執行項目的變數
    do
    {
    	int N, M, k, check, r;
    	printf("** Permutation Generator ***\n");
    	printf("*  0. Quit                 *\n");
    	printf("*  1. N numbers from 1...N *\n");
    	printf("*  2. M numbers from input *\n");
    	printf("*  3. M numbers from 1...9 *\n");    	
    	printf("****************************\n");
    	printf("Input a choice(0, 1, 2, 3): ");
    	scanf("%d", &command); //取得欲執行的項目
    	printf(" \n");
    	if (command == 1)
    	{
    	    k = 1; //用來計算並列印出最前面括號內的行號
    	    int start = 0;
            printf("Input a number N : ");
            scanf("%d", &N); //取得欲執行數字個數
            printf(" \n");
            int str[N]; //設定陣列大小
            for (int i=0; i < N; i++) //設定各陣列的值
            {
                str[i] = i+1;
            }
            getNO(start, N-1, &k, str); //執行排序並列印結果
            printf("Mission 1: %d permutations\n", k-1); //列印排列結果數
            printf("L = %d\n", N); //列印最大遞迴層數
            printf(" \n");
    	}
    	else if (command == 2)
        {
            k = 1; //用來計算並列印出最前面括號內的行號
    	    int start = 0;
    	    do
            {
                printf("Input a number M : ");
                scanf("%d", &M); //取得欲執行數字個數
                printf(" \n");
                if (M < 2) //判斷個數若小於2則無法執行
                {
                    printf("### It is NOT in [2,9] ###\n");
                    printf(" \n");
                }
                if (M > 9) //判斷個數若大於9則無法執行
                {
                    printf("### It is NOT in [2,9] ###\n");
                    printf(" \n");
                }
            }while ((M < 2)||(M > 9)); //非以上情形則停止迴圈

            int str[M]; //設定陣列大小
            for (int i=0; i < M; i++)
            {
                printf("Input a number : ");
                scanf("%d", &str[i]); //取得使用者輸入各陣列的值
                if (i > 0) //從第二個輸入的元素開始進行確認是否重複輸入 
                {
                    do
                    {
                    	check = 1; //設定迴圈判斷值為1 
                    	for (int j=0; j < i; j++) //從第一位元素開始進行確認 
                    	{
                		    if (str[i] == str[j])
                		    {
                		    	printf("Dont use the same number, plz input again : ");
                		    	scanf("%d", &str[i]); //重新取得使用者輸入陣列的元素
								check = 0; //重新進行迴圈判斷是否重複 
							}
					    }
				    }while(check != 1); //都無重複則跳開迴圈 
				}
                printf(" \n");
            }
            float cT = clock(); //開始計時
            getNO(start, M-1, &k, str); //執行排序並列印結果
            printf("Mission 2: %d permutations\n", k-1); //列印排列結果數
            cT = clock() - cT; //計算執行遞迴所使用時間
            printf("T = %.0f ms\n", cT * 1000 / CLOCKS_PER_SEC); //列印執行遞迴所使用時間
            printf(" \n");
        }
        else if (command == 3)
        {
        	k = 1; //用來計算並列印出最前面括號內的行號
        	r = 0; //用來確認需要輸出循環的數字個數 
    	    do
            {
                printf("Input a number M : ");
                scanf("%d", &M); //取得欲執行數字個數
                printf(" \n");
                if (M < 1) //判斷個數若小於1則無法執行
                {
                    printf("### It is NOT in [1,9] ###\n");
                    printf(" \n");
                }
                if (M > 9) //判斷個數若大於9則無法執行
                {
                    printf("### It is NOT in [1,9] ###\n");
                    printf(" \n");
                }
            }while ((M < 1)||(M > 9)); //非以上情形則停止迴圈
            float cT = clock(); //開始計時
            int str[9]; //設定陣列大小
            for (int i=0; i < 9; i++)
            {
            	str[i] = i+1; //輸入各陣列的值 
			}
			getNO_C(0, 8, &k, M, &r, str); //執行排序並列印結果
			printf("Mission 3: %d permutations\n", k-1); //列印排列結果數
			cT = clock() - cT; //計算執行遞迴所使用時間
            printf("T = %.0f ms\n", cT * 1000 / CLOCKS_PER_SEC); //列印執行遞迴所使用時間
			printf(" \n");
		}
    	else if (command > 3) //判斷輸入數值非所設定執行的項目
        {
            printf("Command does not exist!\n");
            printf(" \n");
        }
    } while (command != 0); //停止執行迴圈
    system("pause"); //暫時停止螢幕畫面

    return 0;
} //主程式結束

int getNO(int from, int to, int *p, int str[]) //此為進行遞迴的函式
{
    if (from == to) //當每個元素都進行過交換後進行列印
    {
        printf("[%d]", *p); //利用指標去列印排列行數
        *p = *p + 1; //利用指標去計算排列行數加1
        for (int i=0; i <= to; i++) //列印結果
        {
            printf("%d ",str[i]);
        }
        printf("\n");
        return 0; //列印完成跳出此次遞迴
    }

    for (int i = from; i <= to; i++) //從首位起，將每個元素與首位元素交換
    {
        swap( &str[i], &str[from]); //將某陣列元素與首位元素交換
        getNO( from + 1, to, p, str); //將第二位元素當成首位元素
        swap( &str[i], &str[from]); //恢復原本陣列元素排列
    }
}

int swap(int *a, int *b) //此為外部函式進行資料互換
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int getNO_C(int from, int to, int *p, int q, int *r, int str[]) //此為進行遞迴的函式
{
    if (*r == q) //當每個元素都進行過交換後進行列印
    {
        printf("[%d]", *p); //利用指標去列印排列行數
        *p = *p + 1; //利用指標去計算排列行數加1
        for (int i=0; i < q; i++) //列印結果
        {
            printf("%d ",str[i]);
        }
        printf("\n");
        return 0; //列印完成跳出此次遞迴
    }
    
    for (int i = from; i <= to; i++) //從首位起，將每個元素與首位元素交換
    {
    	*r = *r + 1;
        swap( &str[i], &str[from]); //將某陣列元素與首位元素交換
        getNO_C( from + 1, to, p, q, r, str); //將第二位元素當成首位元素
        swap( &str[i], &str[from]); //恢復原本陣列元素排列
        *r = *r - 1;
    }
}
