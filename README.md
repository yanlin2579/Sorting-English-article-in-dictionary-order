# 多排序算法实现文本排序
## 基本功能
1. 随机生成一篇英文文章，单词之间有空格分隔，存放在程序所在目录下的TextSort_1.txt文本文件中
2. 读取TextSort_1.txt文件，将其中保存的英文文章调入内存
3. 调用排序算法对英文文章按字典顺序进行排序，排序完成后输出排序时间，并将文章存放在程序所在目录下的TextSort_2.txt文本文件中。
   - 直接插入排序
   - 冒泡排序
   - 堆排序
   - 折半插入排序
   - 快速排序
## 完整功能
- 显示界面
   1. 显示程序名称
   2. 显示程序运行步骤
   3. 显示算法选择菜单
- 英文文章生成
   1. 可输入单词数量，控制文章大小
   2. 随机生成英文文章，存放在程序所在目录下的TextSort_1.txt文本文件中
- 排序
   1. 读取TextSort_1.txt文件，将其中保存的英文文章调入内存
   2. 输入需要调用的排序算法序号
      - 直接插入排序
      - 冒泡排序
      - 堆排序
      - 折半插入排序
      - 快速排序
   3. 对英文文章按字典顺序进行排序，排序结束后输出排序算法运行时间
- 排序后英文文章生成
   1. 生成排序后文章
   2. 将文章存放在程序所在目录下的TextSort_2.txt文本文件中
## 函数总览
```
StrLength(char r[]) //求字符串长度
StrCompare(char r1[], char r2[]) //字符串比较
BubbleSort(char* r[], int num) //冒泡排序
AdjustHeap(char* r[], int k, int m) //调整堆顶结点到合适位置上（重建堆）
CrtHeap(char* r[], int num) //创建大顶堆
HeapSort(char* r[], int num) //堆排序
BinSort(char* r[], int num) //折半插入排序
QKOnePass(char* r[], int left, int right) //一趟快速排序
QKSort(char* r[], int low, int high) //快速排序
InsSort(char* r[], int num) //直接插入排序
CrtText(int num) //英文文章随机生成和txt文件创建
CrtSortText(char* r[], int num) //排序后英文文章txt文件创建
ReadIn(char* r[], int num) //txt文件读取
SortInterfacee() //排序算法选择界面
TextCrtInterfacee() //文本创建界面
SortSelect(char* r[], int num) //排序算法选择
main() //主函数
```
## 参考文献
耿国华.数据结构——C语言描述[M].北京:高等教育出版社 ,2011.
