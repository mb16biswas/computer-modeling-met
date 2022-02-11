/*Linear Program . This program has been tested & O K . works on
constrains <= surplus/ slack varibles
n= Total no of varibles
m= Total no of constrains
n1= No of variblesin the objective function
n2= No of slack/ surplus varibles
n3=No of artficial varibles due to >= or + sign in the contrains
n=n1+n2+n3




*/

/*

____________________________________________________________________________________________________


   Roll           students

1911301041		Priyam Biswas	
1911301042		Sushovan Sanfui	
1911301043		Momojit Biswas	
1911301044		Azhar Mahmood	
1911301045		Sayan De	
1911301047		Barun Kumar Rai	


_________________________________________________________________________________________________________________

question given 

A foundry produces two types of wheel: cast iron wheel for rail waggon and steel wheel for cars.
Each steel wheel is 25 kg and the cast-iron wheel is 10 kg . The cost of a steel wheel is 5500 Rs/ piece, 
The cost of a cast iron wheel is 2700 Rs/ piece. The available raw material is 50 tons. Cast iron requires
30% extra raw materials and for steel wheels it is 50%. For cast iron, electricity needed is 15 kw-hr/100 wheels
and for steel wheels it is 30kw-hr/100 wheels.For producing cast iron wheels time taken is 1.5 hrs and for 
steel wheels it is 2.5 hrs. Total energy is 100 kw-hr and total time is 20 hrs. 
Find the maximisation of product so that company makes the highest profit.
__________________________________________________________________________________________________________________-

In this problem we need to maximise 

c = 5500*x1 + 2700*x2(where x1 =number of steel wheels , x2 = number of cast iron wheels)

we need to maximise this c 

37.5*x1 + 13*x2 <= 50000, "1st constraint"
2.5*x1 + 1.5*x2 <= 20, "2nd constraint"
30*x1 + 15*x2 <= 100, "3rd constraint"

or it can be written as 

z = 5500*x1 + 2700*x2 + 0*s1 + 0*s2 + 0*s3 
30*x1 + 15*x2 + s1 + 0*s2 + 0*s3 = 100 
2.5*x1 + 1.5*x2 + 0*s1 + s2 + 0*s3 = 20 
37.5*x1 + 13*x2 + 0*s1 + 0*s2 + s3 = 50000 

there 3 slack variable (s1,s2,s3)




________________________________________________________________________________________________________





*/

#include <bits/stdc++.h>
using namespace std;
#define e 0.000001 // data of zero are replaced by very small value e
#define M 10000    // M is arbitary large value to force artificial varible out of the solution

// i Row No, constrain eqn. No. ,j column varible X1,X2
int main()
{
    float c[20], a[20][20], x[20], b[20], s[20], Z[20], CB[20], C[20], q[20], Cjsum;
    char ch, p;
    int i, j, k, kk, r, n, m, m1, m2, m3;
    cout << "Total No of unknown X"
         << "\n";
    cin >> n; // No of x1, x2, s1,s2 etc

    cout << " No of slack varibles in the Constrain Equations"
         << "\n";
    cin >> m1;
    cout << " No of surplus varibles in the Constrain Equations"
         << "\n";
    cin >> m2;
    m = m1 + m2;
    cout << "Enter value of c, coefficient of X in Z=c1x1 + c2x2 .."
         << "\n";
    for (j = 1; j <= n; j++)
    {
        cin >> c[j]; //{5500, 2700, 0, 0, 0}
    }
    cout << "Enter value of aij, coefficient of X in in each constrain equn.& thn b[i] value."
         << "\n";
    for (i = 1; i <= m; i++)
    {
        
        for (j = 1; j <= n; j++)
        {   cout << "a[" << i <<"][" <<j <<"] ->  ";
            cin >> a[i][j];
            cout << "\n" ; 
        }
        cout << "b[" <<i <<"] -> ";

        cin >> b[i];
        cout << "\n" ; 
    }

    /*
    a[][] = {//should intialis the A[][] array here
                    {30, 15, 1, 0, 0},
                    {2.5, 1.5, 0, 1, 0},
                    {37.5, 13, 0, 0, 1}};

    b = {100, 20, 50000} 


    */

    // Making all CB zero
    for (i = 1; i <= m; i++)
    {
        CB[i] = c[n - i + 1];
        // x[i]=b[n-i+1];
    }
    // Determining Z= summation (CB[i]*a[i][j])
    do
    {
        Z[1] = 0;
        for (j = 1; j <= n; j++)
        {
            for (i = 1; i <= m; i++)
            {

                // cout<<"CB[i]"<<CB[i]<<"a[i][j]"<<a[i][j]<<"\n";
                Z[j] = Z[j] + CB[i] * a[i][j];
            }
        }
        for (j = 1; j <= n; j++)
        {
            C[j] = c[j] - Z[j];
        }
        // Begin Table
        cout << "c[j]"
             << "\t";
        for (j = 1; j <= n; j++)
        {
            cout << c[j] << "\t";
        }
        cout << "\n";
        cout << "\t";
        for (j = 1; j <= n; j++)
        {
            cout << "x" << j << "\t";
        }
        cout << "\n";
        for (i = 1; i <= m; i++)
        {
            cout << "x" << i << "\t";
            // cout<<"\t";
            for (j = 1; j <= n; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << b[i] << "\t" << q[i];
            cout << "\n";
        }
        cout << "Z"
             << "\t";
        for (j = 1; j <= n; j++)

        {
            cout << Z[j] << "\t";
        }
        cout << "\n";
        cout << "Cj"
             << "\t";
        for (j = 1; j <= n; j++)
        {
            cout << C[j] << "\t";
        }
        cout << "\n";
        cout << "CB"
             << "\t";
        for (i = 1; i <= m; i++)
        {
            cout << CB[i] << "\t";
        }
        cout << "\n\n";
        // end of table
        kk = k;
        // rr=n+1;
        // cout<<"x"<<k<<"="<<b[r]<<"\t";
        for (i = 1; i <= m; i++)
        {
            x[i] = b[i];
            cout << "x" << i << "=" << x[i] << "\t";
        }
        // find key column j of max Cj ,to select key column, call that column k=j
        float max;
        max = (C[1]);
        for (j = 1; j <= n; j++)
        {
            if (max <= (C[j]))
            {
                max = C[j];
                k = j;
            }
        }
        // Find Key row
        // Divide b column by corresponding a of k coloumn.
        for (i = 1; i <= m; i++)
        { //cout<<"b[i]"<<b[i]<<"\t";
            if (a[i][k] == 0)
                a[i][k] = e;
            q[i] = b[i] / a[i][k];
            //cout<<"q[i]"<<q[i]<<"\t";
        }
        cout << "\n";
        float mini;
        mini = q[1];
        for (i = 1; i <= m; i++)
        {
            if (q[i] <= mini)
            {
                mini = q[i];
                r = i;
            }
        }
        CB[r] = c[k]; // value of CB becomes coeffient of incomoing x
        x[r] = x[k];
        float temp = a[r][k];
        b[r] = b[r] / a[r][k];
        cout << "\n";
        for (j = 1; j <= n; j++)
        {
            a[r][j] = a[r][j] / temp;
        }
        for (i = 1; i <= m; i++)
        {
            if (i != r)
                b[i] = b[i] - b[r] * a[i][k];
        }
        for (i = 1; i <= m; i++)
        {
            if (i != r)
            {
                temp = a[i][k];
                for (j = 1; j <= n; j++)
                {
                    a[i][j] = a[i][j] - temp * a[r][j];
                }
            }
        }
        cout << "\n\n";
        float Zmax = 0;
        for (j = 1; j <= n - 4; j++) // 4 no of slack + artificial variables
        {
            Zmax = Zmax + c[j] * x[j];
        }
        cout << "\n"
             << "Zmax=" << Zmax << "\n";
        cout << "\n";
        Cjsum = 0;
        for (j = 1; j <= n; j++)
        {
            Cjsum = Cjsum + C[j];
        }
        //ut<<"\n"<<"Cjsum="<<Cjsum<<"\n";
    } while (Cjsum <= 0);
}
