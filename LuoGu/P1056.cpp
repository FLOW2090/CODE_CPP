#include<iostream>
#include<algorithm>
using namespace std;

bool mycmp(int a,int b)
{
    return a < b;
}
int main()
{
    int M,N,K,L,D,transverse[2][1000] = {0},vertical[2][1000] = {0};
    cin >> M >> N >> K >> L >> D;
    for(int i = 0;i < M-1;i++)
    {
        transverse[1][i] = i + 1;
    }
    for(int i = 0;i < N -1;i++)
    {
        vertical[1][i] = i + 1;
    }
    for(int i = 1;i <= D;i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 == y2)
        {
            transverse[0][min(x1,x2)-1]++;
        }
        else
        {
            vertical[0][min(y1,y2)-1]++;
        }
    }
    for(int i = 0;i < M-1;i++)
    {
        for(int j = M-1;j > i;j--)
        {
            if(transverse[0][j] > transverse[0][j-1])
            {
                int value,index;
                value = transverse[0][j];
                index = transverse[1][j];
                transverse[0][j] = transverse[0][j-1];
                transverse[1][j] = transverse[1][j-1];
                transverse[0][j-1] = value;
                transverse[1][j-1] = index;
            }
        }
    }
    for(int i = 0;i < N-1;i++)
    {
        for(int j = N-1;j > i;j--)
        {
            if(vertical[0][j] > vertical[0][j-1])
            {
                int value,index;
                value = vertical[0][j];
                index = vertical[1][j];
                vertical[0][j] = vertical[0][j-1];
                vertical[1][j] = vertical[1][j-1];
                vertical[0][j-1] = value;
                vertical[1][j-1] = index;
            }
        }
    }
    sort(transverse[1],transverse[1] + K,mycmp);
    sort(vertical[1],vertical[1] + L,mycmp);
    for(int i = 0;i < K;i++)
    {
        cout << transverse[1][i];
        if(i != K-1) cout << " ";
        else cout << endl;
    }
    for(int i = 0;i < L;i++)
    {
        cout << vertical[1][i];
        if(i != L-1) cout << " ";
    }
    system("pause");
    return 0;
}