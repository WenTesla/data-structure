#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length = 0;
} SqlList;

// 从顺序表中删除具有最小值的元素(假设唯一)并返回被删除元素的值。
// 空出的位置由最后一个元素填补
// 若顺序表为空，则显示出错信息并退出运行
bool deleteMinElem(SqlList &L, ElemType &e)
{
    if (L.length == 0)
    {
        printf("表为空");
        return false;
    }
    // 初始化最小值和位置
    int pos = 0;
    e = L.data[0];
    // 遍历
    for (int j = 0; j < L.length; j++)
    {
        if (L.data[j] < e)
        {
            e = L.data[j];
            pos = j;
        }
    }
    // 替换
    L.data[pos]=L.data[L.length-1];
    L.length--;
    return true;
}

int main()
{
    SqlList l;

}