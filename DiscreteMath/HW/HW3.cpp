#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100

int _map[MAXN+1][MAXN+1] = {0},map_[MAXN+1][MAXN+1] = {0}; 
    int time_[MAXN],_time[MAXN],earlist_time[MAXN+1],latest_time[MAXN+1],delay_time[MAXN];
    int index_[MAXN];
    int cnt = 0;
    bool flag[MAXN],essential[MAXN];
    vector<int> road;

void calans(int n)
{
    cout << '[';
    for(int i = 0;i < road.size();i++)
    {
        cout << index_[road[i]] << "->";
    }
    cout << "end]" << endl;
}

void DFS(int k,int n)
{
    if(essential[k] == false) return;
    for(int i = 0;i < n;i++)
    {
        if(_map[k][i] && essential[i])
        {
            if(_map[i][n])
            {
                bool test1 = true,test2 = true;
                for(int j = 0;j < road.size();j++)
                {
                    if(road[j] == k)
                    {
                        test1 = false;
                        break;
                    }
                }
                for(int j = 0;j < road.size();j++)
                {
                    if(road[j] == k)
                    {
                        test2 = false;
                        break;
                    }
                }
                if(test1) road.push_back(k);
                if(test2) road.push_back(i);
                int tottime = 0;
                for(int k = 0;k < road.size();k++)
                {
                    tottime += _time[road[k]];
                }
                if(tottime == earlist_time[n]) calans(n);
                
                road.pop_back();
            }
            else
            {
                bool test = true;
                for(int j = 0;j < road.size();j++)
                {
                    if(road[j] == k)
                    {
                        test = false;
                        break;
                    }
                }
                if(test) road.push_back(k);
                DFS(i,n);
                road.pop_back();
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    

    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            _map[i][j] = 0;
            map_[i][j] = 0;
        }
    }

    //cin
    for(int i = 0;i < n;i++)
    {
        int useless,pre;
        char test;
        cin >> useless >> time_[i];
        test = getchar();
        while(test != '\n')
        {
            cin >> pre;
            map_[pre][i] = 1;
            test = getchar();
        }
    }
    for(int i = 0;i < n;i++)
    {
        _time[i] = time_[i];
        for(int j = 0;j < n;j++) _map[i][j] = map_[i][j];
    }
    

    for(int i = 0;i < n;i++)
    {
        flag[i] = true;
        index_[i] = -1;
    }

    //topo-sort
    while(cnt < n)
    {
        for(int i = 0;i < n;i++)//column
        {
            if(flag[i] == false) continue;
            bool test = true;
            for(int j = 0;j < n;j++)//row
            {
                if(_map[j][i])
                {
                    test = false;
                    break;
                }
            }
            if(test == false) continue;
            index_[cnt++] = i;
            flag[i] = false;
            for(int k = 0;k < n;k++)
            {
                _map[i][k] = 0;
            }
            break;
        }
    }
    for(int i = 0;i < n;i++)
    {
        _time[i] = time_[index_[i]];
        for(int j = 0;j < n;j++)
        {
            _map[i][j] = map_[index_[i]][index_[j]];
        }
    }
    for(int i = 0;i < n;i++)//setting the virtual end node
    {
        bool test = true;
        for(int j = 0;j < n;j++)
        {
            if(_map[i][j])
            {
                test = false;
                break;
            }
        }
        if(test == false) continue;
        _map[i][n] = 1;
    }

    //calculating delay time
    vector<int> start;
    for(int i = 0;i <= n;i++)
    {
        earlist_time[i] = -1;
        latest_time[i] = -1;
    }
    for(int i = 0;i < n;i++)
    {
        bool test = true;
        for(int j = 0;j < n;j++)
        {
            if(_map[j][i])
            {
                test = false;
                break;
            }
        }
        if(test == false) continue;
        earlist_time[i] = 0;
        start.push_back(i);
    }
    
    for(int i = 1;i <= n;i++)//column
    {
        for(int j = 0;j < n;j++)//row
        {
            if(earlist_time[j] != -1 && _map[j][i])
            {
                earlist_time[i] = max(earlist_time[i],earlist_time[j] + _time[j]);
            }
        }
    }
    latest_time[n] = earlist_time[n];
    for(int i = n;i >= 0 ;i--)//column
    {
        for(int j = 0;j < n;j++)//row
        {
            if(_map[j][i] && latest_time[i] != -1)
            {
                if(latest_time[j] == -1) latest_time[j] = latest_time[i] - _time[j];
                else latest_time[j] = min(latest_time[j],latest_time[i] - _time[j]);
            }
        }
    }
    
    for(int i = 0;i < n;i++) delay_time[i] = latest_time[i] - earlist_time[i];

    //cout the length of essential road
    cout << earlist_time[n] << endl;

    for(int i = 0;i < n;i++)
    {
        if(delay_time[i] == 0)
        {
            essential[i] = true;
        }
        else essential[i] = false;
    }

    //cout the essential road
    for(int i = 0;i < start.size();i++)
    {
        DFS(start[i],n);
    }

    //cout delay time
    cnt = 0;
    while(cnt <= n)
    {
        for(int i = 0;i < n;i++)
        {
            if(index_[i] == cnt)
            {
                cout << delay_time[i] << endl;
                cnt++;
                break;
            }
        }
    }

    return 0;
}