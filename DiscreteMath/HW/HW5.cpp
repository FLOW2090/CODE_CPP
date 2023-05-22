#define MAXN 20
#define MAXE 50
#define INSAT 0
#define SAT 1
#include <iostream>
#include <vector>
using namespace std;

struct edge{
    bool isIn = false;
    bool isChosen = false;;
};

int X[MAXN] = {INSAT},Y[MAXN] = {INSAT};
edge E[MAXN][MAXN];
int size_x,size_y,size_e;
vector<int> que;
bool flag = false;

void update()
{
    flag = true;
    X[que[0]] = SAT;
    Y[que[que.size() - 1]] = SAT;
    for(int i = 0;i < que.size() - 1;i++)
    {
        if(i % 2 == 0)
        {
            if(E[que[i]][que[i+1]].isChosen) E[que[i]][que[i+1]].isChosen = false;
            else E[que[i]][que[i+1]].isChosen = true;
        }
        else
        {
            if(E[que[i+1]][que[i]].isChosen) E[que[i+1]][que[i]].isChosen = false;
            else E[que[i+1]][que[i]].isChosen = true;
        }
    }
}

void DFS(int i,bool isX)
{
    if(flag) return;
    if(isX)
    {
        if(X[i] == SAT)
        {
            if(que.size() == 1) return;
            for(int j = 0;j < size_y;j++)
            {
                bool flag_ = false;
                for(int k = 1;k < que.size();k += 2)
                {
                    if(que[k] == j)
                    {
                        flag_ = true;
                        break;
                    }
                }
                if(flag_) continue;

                if(E[i][j].isIn)
                {
                    if(Y[j] == SAT && !E[i][j].isChosen)
                    {
                        que.push_back(j);
                        DFS(j,false);
                    }
                    else if(Y[j] == INSAT)
                    {
                        que.push_back(j);
                        update();
                    }
                }
                if(flag) break;
            }
            que.pop_back();
        }
        else
        {
            for(int j = 0;j < size_y;j++)
            {
                bool flag_ = false;
                for(int k = 1;k < que.size();k += 2)
                {
                    if(que[k] == j)
                    {
                        flag_ = true;
                        break;
                    }
                }
                if(flag_) continue;

                if(E[i][j].isIn)
                {
                    if(Y[j] == SAT && !E[i][j].isChosen)
                    {
                        que.push_back(j);
                        DFS(j,false);
                    }
                    else if(Y[j] == INSAT)
                    {
                        que.push_back(j);
                        update();
                    }
                }
                if(flag) break;
            }
            que.pop_back();
        }
    }
    else
    {
        for(int j = 0;j < size_x;j++)
        {
            bool flag_ = false;
            for(int k = 0;k < que.size();k += 2)
            {
                if(que[k] == j)
                {
                    flag_ = true;
                    break;
                }
            }
            if(flag_) continue;
            if(E[j][i].isIn)
            {
                if(X[j] == SAT && E[j][i].isChosen)
                {
                    que.push_back(j);
                    DFS(j,true);
                }
            }
            if(flag) break;
        }
        que.pop_back();
    }
}

int main()
{
    cin >> size_x >> size_y >> size_e;
    for(int i = 0;i < size_e;i++)
    {
        int x,y;
        cin >> x >> y;
        E[x][y].isIn = true;
    }
    for(int i = 0;i < size_x;i++)
    {
        que.clear();
        flag = false;
        que.push_back(i);
        DFS(i,true);
    }

    int cnt = 0;
    for(int i = 0;i < size_x;i++)
    {
        if(X[i] == SAT) cnt++;
    }
    cout << cnt << endl;
    for(int i = 0;i < size_x;i++)
    {
        for(int j = 0;j < size_y;j++)
        {
            if(E[i][j].isChosen)
            {
                cout << i << ' ' << j << endl;
                break;
            }
        }
    }
    return 0;
}