#include<iostream>

int *flag = nullptr;
int v,e;
int *ver,*edge;
int cnt = 0;//记录道路数目
int buf[1000][11];//倒序缓存每条道路
int size[1000] = {0};//记录每条道路的长度

void DFS(int ver);
void calans(void);

int main()
{
    std::cin >> v >> e;
    ver = new int[v+1];
    edge = new int[e];
    flag = new int[v];
    for(int i = 0;i < v;i++) flag[i] = -1;
    for(int i = 0;i <= v;i++)
    {
        std::cin >> ver[i];
    }
    for(int i = 0;i < e;i++)
    {
        std::cin >> edge[i];
    }
    for(int i = 0;i < v;i++)
    {
        for(int j = ver[i] + 1;j < ver[i+1];j++)
        {
            if(edge[j] == edge[j-1]) edge[j] = -1;//对于每个起点，若其有重复终点，则把终点置为-1
        }
    }
    flag[0] = -2;
    DFS(0);
    calans();
    system("pause");
    return 0;
}

void calans(void)
{
    std::cout << cnt << std::endl;
    for(int i = 0;i < cnt;i++)
    {
        for(int j = size[i];j > 0;j--)
        {
            std::cout << buf[i][j] << "->";
        }
        std::cout << buf[i][0] << std::endl;
    }
}

void DFS(int ve)//ve为此时搜索道路的终点
{
    if(ve == v-1)//递归边界
    {
        int i = ve;
        while(i != 0)
        {
            buf[cnt][size[cnt]++] = i;
            i = flag[i];
        }
        buf[cnt][size[cnt]] = 0;
        cnt++;
    }
    else
    {
        for(int i = ver[ve];i < ver[ve+1];i++)
        {
            if(edge[i] != -1 && flag[edge[i]] == -1)//不是重边，且之前没有遍历过
            {
                flag[edge[i]] = ve;
                DFS(edge[i]);
            }
        }
    }
    flag[ve] = -1;//回溯
}