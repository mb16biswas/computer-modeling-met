// Genetic alogorithin to find Mini corrosion with combination of Cl,SO4 & pH  .
// subject to 3 constrains ie Cl<= 24 ,SO4:0-4, pH 4-8

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Math.h>

using namespace std;
// using std::string;

string c[1500], g[100];
// geneLength 6 max no 111111=63, 8- 11111111=255 10-1111111111=1023, 12- 4095
int gDecimal[100];
int chromLength = 18;
int population = 600;
int geneLength = 6;
int Max_No_Generation = 200;
int i, j, k;

float chromoValue[1500], fitness[1500], mini[1500], Mini;
float crossover_rate = 0.7;
float mutation_rate = 0.001;
char ch;

string Rwheel(float Totalfitness);

void crossover(string &offspring1, string &offspring2);
void mutate(string &offspr);
float mini_value(float data[]); // array fn
float chromo_Value(string chromo);
float chromo_fitness(float value);
float target = 0.0;
int main()
{
   //	Generate chromosome population

   srand(1); // random number seed or starter
   for (j = 1; j <= population; j++)
   {
      for (i = 1; i <= chromLength; i++)
      {
         float randf = ((float)rand() / (RAND_MAX + 1));

         if (randf <= 0.5)
         {
            //	cout<<0;
            c[j] += '0';
            // cout<<c[i];
         }
         else
         {
            //  cout<<1;
            c[j] += '1';
         }
      }
      // cout<< "\n Press c to see  "<<j<<"th Chromosomes population \n ";
      // cin>> ch;
      // cout<<"c["<<j<<"]="<<c[j];
      // cout<<"\n";
   }

   int No_of_genration = 1;

   bool solutionFound = false;

   while (!solutionFound) // Loop will continue till solutionFound
   {                      // is not false i e true i e solution found

      // Initially make all population fitness=0

      for (j = 1; j <= population; j++)
      {
         fitness[j] = 0.0;
         // cout<<"t fitness= "<<fitness[j] <<"\n";
      }

      // find fitness from chromo value
      for (j = 1; j <= population; j++)
      {
         // cout<< "\n Press c to see  "<<j<<"th Chromosomes value & fitness \n ";
         // cin>> ch;
         chromo_Value(c[j]);
         // cout<<"\nChromeValue="<<chromoValue[j]<<"\n";
         chromo_fitness(chromoValue[j]);
         // cout<<"fitness= "<<fitness[j] <<"\n";

         // Test if any chromosome has achieved required fitness

         if (fitness[j] >= 999.9)
         {
            cout << "Bset fit chromosome found=" << c[j];
            cout << "\n No_of_genration " << No_of_genration << endl;
            cout << "\n population No." << j << endl;
            cout << "\nChromeValue=" << chromoValue[j] << "\n";
            cout << "fitness= " << fitness[j] << "\n";
            cout << "Gene combiations are \n";
            for (i = 1; i <= (chromLength / geneLength); i++)
            {
               cout << "\n No." << i << " Gene (Binary)" << g[i] << "=" << gDecimal[i];
            }
            cout << endl;
            solutionFound = true;
            break;
         }
      }

      mini_value(chromoValue);
      // cout<<"\nchromoValue Max="<<chromoValue[j]<<"\t at "<<c[j];
      // cout<<endl;

      if (Mini > target)
         target = Mini;
      mini[No_of_genration] = Mini;

      // cout<<"target="<<target;
      // cout<<"\nChromeValue="<<chromoValue[j]<<"\n";

      // cout<<"fitness= "<<fitness[j] <<"\n";

      // cout<<"t fitness= "<<fitness[j] <<"\n";

      float totalfitness = 0;
      for (j = 1; j <= population; j++)
      {

         totalfitness += fitness[j];
      }

      // cout<< "\n Total fitness="<<totalfitness;
      // cout<<endl;

      // Generate New population of chromosomes from total fitness through Rwheel
      // cout<<"\n Generate New population of chromosomes from total fitness through Rwheel\n";
      // cout<<"No of Generation="<<No_of_genration;

      string offspring1;
      string offspring2;
      int pop = 1;
      j = 1;

      do
      {
         // cout<< "\n   2 nos of new offsprings generated from Rwheel ";

         offspring1 = Rwheel(totalfitness);
         offspring2 = Rwheel(totalfitness);
         // cout<<endl;
         // cout<<"\n offspring1="<<offspring1;

         // cout<<"\n offspring2="<<offspring2;
         //  cout<<endl;

         // crossover
         crossover(offspring1, offspring2);

         // cout<<"\n Ater crossover";
         // cout<<"\n offspring1="<<offspring1;
         // cout<<"\n offspring2="<<offspring2;
         // cout<<endl;

         // mutate
         // cout<<"\n After mutation";
         // cout<<endl;
         mutate(offspring1);
         mutate(offspring2);

         // cout<<"\n offspring1="<<offspring1;
         // cout<<"\n offspring2="<<offspring2;

         c[pop] = offspring1;
         c[pop + 1] = offspring2;

         // cout<<"\n\n Total offspring added "<<pop+1<<"\n";

         // cout<<"\n offspring1 C["<<pop<<"]="<<c[pop];
         // cout<<"\n offspring2 C["<<pop+1<<"]="<<c[pop+1];
         // cout<<endl;
         // cout<< "\n Press c to continue  \n ";
         // cin>> ch;

         pop = pop + 2;
      } while (pop <= population);

      No_of_genration = No_of_genration + 1;

      if (No_of_genration > Max_No_Generation)
      {
         cout << "\n solutions not found after " << No_of_genration - 1 << " No of Generations \n";
         solutionFound = true;
      }
   }
   mini_value(mini);
   cout << "Mini=" << Mini;
   cout << endl;
   return 0;
} // end of main

// All functions

// assign fitness
float chromo_fitness(float value)
{
   //	float target;

   if (target == chromoValue[j])

      fitness[j] = 1000.0;

   else

      fitness[j] = 1 / fabs((target - chromoValue[j]));

   return fitness[j];
}

float chromo_Value(string chromo)
{
   // split each chromosome population into genes
   int geneNo = 1;
   for (i = 0; i < chromLength; i += geneLength)
   {

      g[geneNo] = c[j].substr(i, geneLength);
      //  cout<<"g[geneNo]"<<g[geneNo]<<"\t";
      geneNo = geneNo + 1;
   }

   // convert each gene from binary to decimal integer

   for (geneNo = 1; geneNo <= (chromLength / geneLength); geneNo++)
   {
      int temp = 0, sum = 0;

      for (k = 0; k < geneLength; k++)
      {

         if (g[geneNo].at(k) == '1')
         {
            temp = pow(2, (geneLength - (k + 1)));
         }
         else
         {
            temp = 0;
         }

         sum = sum + temp;
      }

      gDecimal[geneNo] = sum;

      //  cout<<"\tBinary"<<g[geneNo]<<"="<<gDecimal[geneNo];
   }

   // z=4x1 + 3x2 +6x3

   double b0 = 40.787, b1 = 20.52, b2 = 2.0, b3 = -3.75, b4 = 4.0, b5 = -8.12, b6 = -3.4675, b7 = -8.615;
   double c1 = 21.5, d1 = 2.5, c2 = 2.1, d2 = 1.3, c3 = 6, d3 = 2;
   double x1, x2, x3;

   x1 = (gDecimal[1] - c1) / d1;
   x2 = (gDecimal[2] - c2) / d2;
   x3 = (gDecimal[3] - c3) / d3;

   chromoValue[j] = b0 + b1 * x1 + b2 * x2 + b3 * x3 + b4 * x1 * x2 + b5 * x2 * x3 + b6 * x1 * x3 + b7 * x1 * x2 * x3;

   // cout<<"\nchromoValue Max="<<chromoValue[j]<<"\t at "<<c[j];
   // cout<<endl;
   if (gDecimal[1] > 24 || gDecimal[2] < 0.0 || gDecimal[2] > 4 || gDecimal[3] < 4.0 || gDecimal[3] > 8.0)
      chromoValue[j] = -500;
   return chromoValue[j];
}

// mini
float mini_value(float data[])
{
   Mini = chromoValue[1];
   for (j = 1; j <= population; j++)
   {

      if (Mini > chromoValue[j])
         Mini = chromoValue[j];
   }
   // cout<< " mini ="<<mini<<endl;

   for (j = 1; j <= population; j++)
   {

      if (Mini == chromoValue[j])
         break;
   }

   return Mini;
}

void mutate(string &offspr)
{
   float randf = ((float)rand() / (RAND_MAX + 1));
   //	cout<<"randf"<<randf;
   if (randf < mutation_rate)
   {
      for (i = 0; i < offspr.length(); i++)
      {

         if (offspr.at(i) == '1')
            offspr.at(i) = '0';
         else
            offspr.at(i) = '1';
      }
   }
}

void crossover(string &offspring1, string &offspring2)
{
   int cross_pt;

   float randf = ((float)rand() / (RAND_MAX + 1));
   // cout<<"randf"<<randf;
   // cout<<endl;
   if (randf < crossover_rate)
   {
      cross_pt = (int)(randf * chromLength);
      // cout<<"cross_pt"<<cross_pt;;
      // cout<< "\n Press c to see   Chromosomes population fitness\n ";
      //   cin>> ch;
      string s1 = offspring1.substr(0, cross_pt) + offspring2.substr(cross_pt, chromLength);
      string s2 = offspring2.substr(0, cross_pt) + offspring1.substr(cross_pt, chromLength);
      offspring1 = s1;
      offspring2 = s2;
      // cout<<"s1="<<s1;
      // cout<<"s1="<<s1;
   }
}

string Rwheel(float Totalfitness)
{

   // srand(1);

   float randf = ((float)rand() / (RAND_MAX + 1));

   // cout<<"randf"<<randf;
   float slice = (float)(randf * Totalfitness);
   // cout<<endl;
   // cout<<"slice="<<slice;
   float fitnessSoFar = 0;
   for (j = 1; j <= population; j++)
   {

      fitnessSoFar += fitness[j];
      // cout<<"fitnessSoFar=" <<fitnessSoFar ;

      if (fitnessSoFar >= slice)
      {

         return c[j];
      }
      //  cout<<"Best fit chromo "<<c[j]<<"\t Chromo value ="<<chromoValue[j];
      //	 cout<< "\n Press c to see   Chromosomes population fitness\n ";
      //  cin>> ch;
   }
   return "";
}
