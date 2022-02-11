#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define G GREEN
#define X_AXIS 100
#define Y_AXIS 1000

/*Group-4 
______________________________________________________________________________

Tensile strength of brass vs composition of Zn


   Roll           students

1911301041		Priyam Biswas	
1911301042		Sushovan Sanfui	
1911301043		Momojit Biswas	
1911301044		Azhar Mahmood	
1911301045		Sayan De	
1911301047		Barun Kumar Rai	



In this program a user can save the data for Zn composition and the Tesile strength of brass into a text file
If needed the user can also plot the graph. 


The user can plot tensile strength upto 1000 mpa.


The text file will save the data in this format ->

Tensile Strength of Brass 
T1,T2,T3..........
Zn Composition 
Zn1,Zn2,Zn3...........


________________________________________________________________________________

*/

void draw_graph(vector<double> X, vector<double> Y)
{

    double px, py, cx = getmaxx() / 2, cy = getmaxy() / 2;
    int c = 1, i;
    for (i = 0; i < X.size(); i++)
    {
        px = X[i] * cx / X_AXIS + cx;
        /* -cy because of origin point in window(top left corner) */
        //since we shift the origin into cx , cy , so px , py are the new coordinates respect to the new origin
        py = Y[i] * -cy / Y_AXIS + cy;

        if (py < 0 || py > getmaxy())
        {
            // cout << "py " << py << "\n";
            break;
        }
        if (c)
        {
            moveto(px, py);
            c = 0;

        } // only for first loop

        /* Draw segment line */
        lineto(px, py);

        moveto(px, py);

        delay(500);
    }
}

void display(vector<double> X, vector<double> Y)
{
    int gd = DETECT, gm, n;

    initgraph(&gd, &gm, NULL);

    // /* Draw the axis */
    int cx = getmaxx() / 2, cy = getmaxy() / 2;

    line(20, cy, getmaxx() - 20, cy);
    line(cx, 20, cx, getmaxy() - 20);

    outtextxy(cx - 150, cy - cy / 2, "Tensile Str (mpa)");
    outtextxy(cx + cx / 2, cy + 20, "Zn composition (%)");

    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 2);
    draw_graph(X, Y);

    getch();
    closegraph();
}

int main()
{

    int i, n;
    char b;
    fstream myFile;
    string fname;
    cout << "enter the file name ";
    cin >> fname;
    cout << "\n";
    fname = fname + ".txt";
    cout << "Insert No. of rows of expt. data ";
    cin >> n;
    cout << "\n";
    vector<double> T(n, 0), Zn(n, 0);

    cout << "Insert Expt data T(Tensile Strength of Brass) in mpa & Zn(Composition of Zinc)  in mA/sq.m \n";
    cout << "\n";
    for (i = 0; i < n; i++)
    {
        cout << "T " << i + 1 << " = ";
        cin >> T[i];

        cout << "Zn " << i + 1 << " = ";
        cin >> Zn[i];
        cout << "\n";
    }

    myFile.open(fname, ios ::out);
    if (myFile.is_open())
    {
        myFile << "Tensile Strength of Brass "
               << "\n";
        for (auto x : T)
        {
            myFile << x << " ";
        }
        myFile << "\n";
        myFile << "Zn Composition "
               << "\n";

        for (auto x : Zn)
        {
            myFile << x << " ";
        }

        myFile.close();
    }

    cout << "Data saved...\n";
    cout << "Do you want to see the graph (y/n) ";
    cin >> b;
    if (b == 'y')
    {
        display(Zn, T); //IT will plot the graph
    }

    return 0;
}
