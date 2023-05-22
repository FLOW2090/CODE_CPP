#include<iostream>
using namespace std;
int main()
{
    int A[101] = {0};
    int B[200] = {0},w[200] = {0};
    int T[100];//vi到某个节点的最短路径
    int road[100];
    int before[100];
    bool flag[100];
    int v,e,n;
    cin >> v >> e;
    for(int i = 0;i <= v;i++) cin >> A[i];
    for(int i = 0;i < e;i++) cin >> B[i];
    for(int i = 0;i < e;i++) cin >> w[i];//边权
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        for(int i = 0;i < v;i++)
        {
            T[i] = -1;
            flag[i] = true;
            before[i] = -1;
        }
        int vs,ve,tmp;
        cin >> vs >> ve;
        flag[vs] = false;
        T[vs] = 0;
        tmp = vs;
        for(int i = 0;i < v;i++)
        {
            for(int j = A[tmp];j < A[tmp+1];j++)//更新和tmp关联的结点到v的最短路径
            {
                if(T[B[j]] != -1)
                {
                    if(T[B[j]] > T[tmp] + w[j])
                    {
                        T[B[j]] = T[tmp] + w[j];
                        before[B[j]] = tmp;
                    }
                }
                else
                {
                    T[B[j]] = T[tmp] + w[j];
                    before[B[j]] = tmp;
                }
            }
            int minimum = -1;
            for(int j = 0;j < v;j++)
            {
                if(flag[j] && ((minimum == -1 || minimum > T[j])) && T[j] > -1)
                {
                    minimum = T[j];
                    tmp = j;
                }
            }
            flag[tmp] = false;
            if(tmp == ve) break;
        }
        if(T[ve] == -1) cout << "NO PATH" << endl;
        else
        {
            int cnt = 0;
            road[0] = ve;
            while(road[cnt] != vs)
            {
                cnt++;
                road[cnt] = before[road[cnt - 1]];
            }
            cout << "[";
            for(int i = cnt;i > 0;i--)
            {
                cout << road[i] << "->";
            }
            cout << road[0] << " " << T[ve] << "]" << endl;
        }
    }
    system("pause");
    return 0;
}