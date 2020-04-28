// https://codeforces.com/contest/849/problem/B
#include<bits/stdc++.h>
using namespace std;

int i,j,k;

#define ll long long

#define loop1 for(i=1;i<=n;i++)

#define newl printf("\n")
#define debug printf("OKAY\n")
int main()
{

    int n;
    scanf("%d",&n);
    ll y[n+1];
    bool d[n+1];
    loop1
    {
        scanf("%I64d",&y[i]);
    }


    double m12,m13,m23,m,x;
    int index,p;
    bool flag;
    m12 =  y[2]-y[1];
    m13 = (y[3]-y[1])/2.0;
    m23 =  y[3]-y[2];

    for(int j=1; j<=3; j++)
    {
        index=-1;// first kon point kono line e porena shetar index
        loop1
        {
            d[i] = 0;
        }
// either 1,2 or 1,3 or 2,3 points are on same line

        if(j==1)
        {
            x = m12;
            d[1] = 1;
            d[2] = 1; //on the line already
            p = 1; //2
        }
        else if( j==2)
        {
            x = m13;
            d[1] = 1;
            d[3] = 1;
            p = 1;
        }
        else
        {
            x = m23;
            d[2] = 1;
            d[3] = 1;
            p = 3;
        }


        //cout<<x;
        for(i=1; i<=n; i++)
        {

            if(d[i] == 1)
                continue;
            m = y[i]-y[p];
            m = m/(i-p);
            if(m==x)
                d[i] = 1;
            else
            {
                if(index==-1) //just once
                    index = i;
            }
        }

        if(index!=-1)
        {
            flag = 1;
            for(i=index+1; i<=n; i++)
            {
                if(d[i] == 0)
                {

                    m = y[i]-y[index];
                    m = m/(1.0*(i-index));
                    if(m!=x) {
                        flag = 0;
                        break;
                    }
                }

            }
        }
        if(flag == 1)
            break;

    }

    if(flag == 1)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

