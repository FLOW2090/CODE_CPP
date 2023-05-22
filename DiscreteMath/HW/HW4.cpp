#include <iostream>
#include <vector>
#define MAXN 100
#define MAXE 1000

using namespace std;

int Node[MAXN];
int Edge[MAXE];
int Weight[MAXE];
int Distance[MAXN];
bool Flag[MAXN];
vector<int*> Tree;
int cnt = 0;

int Pick(int v)
{
    int min = -1,record,parent;
    for(int i = 0;i < v;i++)
    {
        if(Flag[i] && Distance[i] != -1 && (min == -1 || Distance[i] < min))
        {
            min = Distance[i];
            record = i;
        }
    }
    if(cnt != 0)
    {
        for(int i = Node[record];i < Node[record+1];i++)
        {
            if(Distance[record] == Weight[i] && !Flag[Edge[i]])
            {
                parent = Edge[i];
                break;
            }
        }
        Tree[cnt][0] = parent;
        Tree[cnt][1] = record;
        Tree[cnt][2] = Distance[record];
    }
    cnt++;
    Flag[record] = false;
    return record;
}

void Update(int node)
{
    for(int i = Node[node];i < Node[node+1];i++)
    {
        if(Distance[Edge[i]] == -1 || Weight[i] < Distance[Edge[i]])
        {
            Distance[Edge[i]] = Weight[i];
        }
    }
}

int main()
{
    //cin
    int v,e;
    cin >> v >> e;
    for(int i = 0;i <= v;i++) cin >> Node[i];
    for(int i = 0;i < e;i++) cin >> Edge[i];
    for(int i = 0;i < e;i++) cin >> Weight[i];
    
    //initialization
    for(int i = 0;i < v;i++)
    {
        Distance[i] = -1;
        Flag[i] = true;
        Tree.push_back(new int[3]);
    }
    Distance[0] = 0;

    while(cnt < v)
    {
        Update(Pick(v));
    }

    int length = 0;
    for(int i = 1;i < v;i++)
    {
        cout << '[' << Tree[i][0] << "->" << Tree[i][1] << ']';
        length += Tree[i][2];
    }
    cout << ' ' << length << endl;
    return 0;
}