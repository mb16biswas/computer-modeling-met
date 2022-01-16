#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define G GREEN
#define X_AXIS 100
#define Y_AXIS 1000



void draw_graph(vector<double> X, vector<double> Y)
{

    double px, py, cx = getmaxx() / 2, cy = getmaxy() / 2;
    int c = 1, i;
    for (i = 0; i < X.size(); i++)
    {
        px = X[i] * cx / X_AXIS + cx;
        /* -cy because of origin point in window(top left corner) */
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

        delay(200);
    }
}

void display(vector<double> X, vector<double> Y)
{
    int gd = DETECT, gm, n;

    initgraph(&gd, &gm, NULL);

    // /* Draw the axis */
    int cx = getmaxx() / 2, cy = getmaxy() / 2;
    // cout << "cx " << cx << " "
    //      << "cy " << cy << "\n";

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
        for (auto x : T)
        {
            myFile << x << " ";
        }

        myFile << "\n";

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
