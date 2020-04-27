#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst, caseno = 0, tmp = 0;

    stack <string> back_stck, for_stck;
    string cmnd, page;
    cin >> tst;
    while(tst--)
    {
        tmp = 0;
        printf("Case %d:\n", ++caseno);
        while(1)
        {
            cin >> cmnd;
            if(cmnd == "VISIT")
            {
                cin >> page;
                back_stck.push(page);
                cout << page << endl;
                while(!for_stck.empty())for_stck.pop();
            }
            else if(cmnd == "BACK")
            {
                if(back_stck.empty())
                    printf("Ignored\n");
                else
                {
                    for_stck.push(back_stck.top());
                    back_stck.pop();
                    if(back_stck.empty())
                        printf("http://www.lightoj.com/\n");
                    else
                        cout << back_stck.top() <<endl;
                }
            }
            else if(cmnd == "FORWARD")
            {
                if(for_stck.empty())
                    printf("Ignored\n");
                else
                {
                    back_stck.push(for_stck.top());
                    for_stck.pop();
                    cout << back_stck.top() << endl;
                }
            }
            else if(cmnd == "QUIT")
                break;
        }
        while(!back_stck.empty())back_stck.pop();
        while(!for_stck.empty())for_stck.pop();
    }
    return 0;
}
