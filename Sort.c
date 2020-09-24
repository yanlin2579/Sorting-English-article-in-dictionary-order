#include <stdio.h>
#include <fstream>
#include <time.h>
#include <Windows.h>

/*——————求字符串长度函数——————*/
int StrLength(char r[])
{
    int i, n = 0;
    for (i = 0; r[i] != '\0'; ++i)
    {
        ++n;
    }
    return n;
}


/*——————字符串比较函数——————*/
int StrCompare(char r1[], char r2[])
{
    int i, length1, length2;
    length1 = StrLength(r1);
    length2 = StrLength(r2);
    for (i = 0; i < length1 && i < length2; i++)
        if (r1[i] != r2[i])
            return(r1[i] - r2[i]);
    return(length1 - length2);
}


/*——————冒泡排序——————*/
int BubbleSort(char* r[], int num)
{
    int n, i, j;
    int change;
    char* x;
    n = num;
    change = TRUE;

    for (i = 1; i <= n - 1 && change; ++i)
    {
        change = FALSE;
        for (j = 1; j <= n - i; ++j)
            if (StrCompare(r[j], r[j + 1]) > 0)
            {
                x = r[j];
                r[j] = r[j + 1];
                r[j + 1] = x;
                change = TRUE;
            }
    }

    return 0;
}


/*————————————————堆排序————————————————*/
int AdjustHeap(char* r[], int k, int m)  //调整堆顶结点到合适位置上
{
    char* t, * x;
    int i, j;
    int finished;
    t = r[k];
    x = r[k];

    i = k;
    j = 2 * i;
    finished = FALSE;
    while (j <= m && !finished)
    {
        if (j < m && StrCompare(r[j], r[j + 1]) < 0)
            j = j + 1;
        if (StrCompare(x, r[j]) >= 0)
            finished = TRUE;
        else
        {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;

    return 0;
}

int CrtHeap(char* r[], int num)    //创建大顶堆
{
    int i, n;
    n = num;
    for (i = n / 2; i >= 1; --i)
        AdjustHeap(r, i, n);
    return 0;
}

int HeapSort(char* r[], int num)    //堆排序
{
    int i, n;
    char* b;
    CrtHeap(r, num);
    n = num;
    for (i = n; i >= 2; --i)
    {
        b = r[1];
        r[1] = r[i];
        r[i] = b;
        AdjustHeap(r, 1, i - 1);
    }

    return 0;
}


/*——————————折半插入排序————————————*/
int BinSort(char* r[], int num)
{
    int i, j;
    char* x;
    int low, high, mid;

    for (i = 2; i <= num; ++i)
    {
        x = r[i];
        low = 1;  high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (StrCompare(r[mid], x) > 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= low; --j)   r[j + 1] = r[j];
        r[low] = x;
    }

    return 0;
}


/*————————————————快速排序————————————————*/
int QKOnePass(char* r[], int left, int right)  //一趟快速排序
{
    char* x;
    int low, high;
    x = r[left];
    low = left;
    high = right;

    while (low < high)
    {
        while (low < high && StrCompare(r[high], x) >= 0)
            high--;
        if (low < high)
        {
            r[low] = r[high];
            low++;
        }
        while (low < high && StrCompare(r[low], x) < 0)
            low++;
        if (low < high)
        {
            r[high] = r[low];
            high--;
        }
    }
    r[low] = x;

    return low;
}

int QKSort(char* r[], int low, int high)   //快速排序
{
    int pos;

    if (low < high)
    {
        pos = QKOnePass(r, low, high);
        QKSort(r, low, pos - 1);
        QKSort(r, pos + 1, high);

    }

    return 0;
}


/*——————————直接插入排序———————————*/
int InsSort(char* r[], int num)
{
    int i, j;

    for (i = 2; i <= num; i++)
    {
        r[0] = r[i];
        j = i - 1;
        while (StrCompare(r[j], r[0]) > 0)
        {
            r[j + 1] = r[j];
            --j;
        }
        r[j + 1] = r[0];
    }

    return 0;
}


/*————————————英文文章随机生成和txt文件创建————————————*/
int CrtText(int num)
{
    int i, j;
    char k, u;
    FILE* fp;

    printf("          随机生成英文文章中...");

    srand((unsigned)time(NULL));
    fopen_s(&fp, "TextSort_1.txt ", "wt");
    for (i = 0; i < num; ++i)
    {
        u = rand() % 7;
        for (j = 0; j <= u; ++j)
        {
            k = rand() % 26;
            k = 'a' + k;
            fputc(k, fp);
        }
        fputc(' ', fp);
    }
    fclose(fp);

    printf("\n          生成成功，文章已存放在“当前目录的TextSort_1.txt”中");

    return 0;
}


/*————————————排序后英文文章txt文件创建————————————*/
int CrtSortText(char* r[], int num)
{
    int i;
    FILE* fp;

    printf("          ------------------------------------------------------------------------------------\n");
    printf("          排序结束，正在生成排序后的文章中...");

    srand((unsigned)time(NULL));
    fopen_s(&fp, "TextSort_2.txt ", "wt");
    for (i = 1; i <= num; ++i)
    {
        fputs(r[i], fp);
        fputc(' ', fp);
    }
    fclose(fp);

    printf("\n          生成成功，文章已存放在“当前目录的TextSort_2.txt”中");
    return 0;
}


/*——————————txt文件读取———————————*/
int ReadIn(char* r[], int num)
{
    int i, j;
    FILE* fp;
    printf("          正在读取文本...");
    fopen_s(&fp, "TextSort_1.txt ", "rt");
    for (i = 1; i <= num; ++i)
    {
        r[i] = (char*)malloc(9 * sizeof(char));

        j = 0;
        while (1)
        {
            r[i][j] = fgetc(fp);
            if (r[i][j] == ' ')
            {
                r[i][j] = '\0';
                break;
            }
            ++j;
        }
    }
    fclose(fp);

    return 0;
}


/*——————————————————————排序界面—————————————————————*/
int SortInterfacee()
{
    printf("\n          ------------------------------------------------------------------------------------\n");
    printf("                                        ——————————\n");
    printf("                                        |【1】直接插入排序 |\n");
    printf("                                        |【2】冒泡排序     |\n");
    printf("                                        |【3】折半插入排序 |\n");
    printf("                                        |【4】快速排序     |\n");
    printf("                                        |【5】堆排序       |\n");
    printf("                                        ——————————\n");

    return 0;
}


/*———————————文本创建界面——————————*/
int TextCrtInterfacee()
{
    printf("                                           **************\n");
    printf("                                           * 大数据排序 *\n");
    printf("                                           **************\n");
    printf("          ------------------------------------------------------------------------------------\n");
    printf("          请输入待排序文章单词数量：");

    return 0;
}


/*——————————排序算法选择——————————*/
int SortSelect(char* r[], int num)
{
    clock_t start, end;

    int option;

switch_start:
    printf("\n          请输入要调用的排序算法序号：");
    scanf_s("%d", &option);
    ReadIn(r, num);

    start = clock();
    switch (option)
    {
    case 1:
    {
        printf("\n          已选择直接插入排序，正在排序中...");
        InsSort(r, num);
        break;
    }
    case 2:
    {
        printf("\n          已选择冒泡排序，正在排序中...");
        BubbleSort(r, num);
        break;
    }
    case 3:
    {
        printf("\n          已选择折半插入排序，正在排序中...");
        BinSort(r, num);
        break;
    }
    case 4:
    {
        printf("\n          已选择快速排序，正在排序中...");
        QKSort(r, 1, num);
        break;
    }
    case 5:
    {
        printf("\n          已选择堆排序，正在排序中...");
        HeapSort(r, num);
        break;
    }
    default:
    {
        printf("\n          输入错误，程序结束！");
        return FALSE;
    }
    }
    end = clock();

    printf("\n          排序成功，算法执行时间为%f秒", (double)(end - start) / CLK_TCK);

    printf("\n          是否重新调用其他排序算法(【1】是  【2】否)：");

    scanf_s("%d", &option);
    switch (option)
    {
    case 1:
        goto switch_start;
    case 2:
        break;
    default:
    {
        printf("          输入错误，执行排序结果生成程序！\n");
        break;
    }
    }
    return 1;
}


/*————————主函数————————*/
int main()
{
    int num, error;
    char** r;

    TextCrtInterfacee();    //显示文本创建界面
    scanf_s("%d", &num);    //输入要生成的文章单词个数到num
    CrtText(num);   //生成随机文章并在exe程序文件所在目录下创建txt文件
    r = (char**)malloc((num + 1) * sizeof(char*));  //在堆中创建动态二维数组

    SortInterfacee();   //显示排序界面
    error = SortSelect(r, num);     //排序算法调用与选择，并返回输入状态
    if (error == FALSE)     //如果输入非法则程序终止
    {
        free(r);
        printf("\n          ");
        system("pause");
        return 0;
    }

    CrtSortText(r, num);    //生成排序后文章并在exe程序文件所在目录下创建txt文件
    free(r);    //释放堆中空间

    printf("\n          ");
    system("pause");
    return 0;
}
