#include <bits/stdc++.h>
#include <graphics.h>
#define G GREEN
#define X_AXIS 100
#define Y_AXIS 1000
using namespace std;

double calculateFreeEnergy(double T, double H1, double S1, double H2, double S2)
{
    double G1 = H1 - (T * S1); // free energy for 1st compound or Element
    double G2 = H2 - (T * S2); // free energy for 2nd compound or element
    double deltaG = G1 - G2;
    return deltaG;
}

void draw_graph(vector<double> X, vector<double> Y)
{

    double px, py, cx = getmaxx() / 2, cy = getmaxy() / 2;
    int c = 1, i;
    for (i = 0; i < X.size(); i++)
    {
        px = X[i] * cx / X_AXIS + cx;
        /* -cy because of origin point in window(top left corner) */
        // since we shift the origin into cx , cy , so px , py are the new coordinates respect to the new origin
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

    outtextxy(cx - 150, cy - cy / 2, "Free Energy");
    outtextxy(cx + cx / 2, cy + 20, "Temp");

    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 2);
    draw_graph(X, Y);

    getch();
    closegraph();
}

int main()
{

    double T, H1, H2, S1, S2;
    vector<double> G(5), X(5);
    // calculating for 1st compound
    cout << "We are calculating for the 1st Compound Fe2O3 -Fe3O4\n";
    cout << "Enter the delta H and delta S value for Fe2O3\n";
    cin >> H1 >> S1;
    cout << "Enter the delta H and delta S value for Fe3O4\n";
    cin >> H2 >> S2;
    cout << "Enter the temperature\n";
    cin >> T;
    X[0] = T;

    cout << "Calculating the free energy difference of Fe3O4 and Fe2O3 \n";
    G[0] = calculateFreeEnergy(T, H1, S1, H2, S2);
    cout << G[0] << "\n";

    // claculating for 2nd compound
    cout << "We are calculating for the 1st Compound Ni-Nio\n";
    cout << "Enter the delta H and delta S value for Ni\n";
    cin >> H1 >> S1;
    cout << "Enter the delta H and delta S value for Nio\n";
    cin >> H2 >> S2;
    cout << "Enter the temperature\n";
    cin >> T;
    X[1] = T;

    cout << "Calculating the free energy difference of Nio and Ni\n";
    G[1] = calculateFreeEnergy(T, H1, S1, H2, S2);
    cout << G[1] << "\n";
    // claculating for 3rd compound
    cout << "We are calculating for the 1st Compound Cr-Cr2O3\n";
    cout << "Enter the delta H and delta S value for Cr\n";
    cin >> H1 >> S1;
    cout << "Enter the delta H and delta S value for Cr2O3\n";
    cin >> H2 >> S2;
    cout << "Enter the temperature\n";
    cin >> T;
    X[2] = T;

    cout << "Calculating the free energy difference of Cr2O3 and Cr\n";
    G[2] = calculateFreeEnergy(T, H1, S1, H2, S2);
    cout << G[2] << "\n";

    // Calculating for 4th Compound
    cout << "We are calculating for the 1st Compound C-CO\n";
    cout << "Enter the delta H and delta S value for C\n";
    cin >> H1 >> S1;
    cout << "Enter the delta H and delta S value for CO\n";
    cin >> H2 >> S2;
    cout << "Enter the temperature\n";
    cin >> T;
    X[3] = T;

    cout << "Calculating the free energy difference of CO and C\n";
    G[3] = calculateFreeEnergy(T, H1, S1, H2, S2);
    cout << G[3] << "\n";

    // Calculating for 5th Compound
    cout << "We are calculating for the 1st Compound H2 to H20\n";
    cout << "Enter the delta H and delta S value for H2\n";
    cin >> H1 >> S1;
    cout << "Enter the delta H and delta S value for H20\n";
    cin >> H2 >> S2;
    cout << "Enter the temperature\n";
    cin >> T;
    X[4] = T;
    cout << "Calculating the free energy difference of H2O and H2\n";
    G[4] = calculateFreeEnergy(T, H1, S1, H2, S2);
    cout << G[4] << "\n";

    cout << "Do you want to see the graphics enter (Y/N)\n";
    char ch;
    cin >> ch;
    if (ch == 'Y')
    {
        display(X, G);
    }
    return 0;
}
