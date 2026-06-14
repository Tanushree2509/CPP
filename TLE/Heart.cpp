/*#include<iostream>
#include<cmath>
#include<vector>
#include<tuple>
using namespace std;


tuple<std::vector<double>,std::vector<double>>generate_points(const int no_pieces){
   vector <double> vx, vy;

   constexpr double P1 = 3.141592653589793238462643383277950288;
   double dt = 2.0*P1/ no_pieces;
   for(double t = 0.0; t<= 2.0*P1; t+= dt){
      vx.emplace_back(16.0*sin(t)*sin(t)*sin(t));
      vy.emplace_back(13.0*cos(t) - 5.0*cos(2.0*t)- 2.0*cos(3.0*t)- cos(4.0*t));

   }

   return make_tuple(vx, vy);
}


int main()
{
   double x, y;
   double size = 10;

   for (x=0; x<size; x++)
   {
      for (y=0; y<=4*size; y++)
      {
         double dist1 = sqrt(pow(x-size,2) + pow(y-size,2)) ;
         double dist2 = sqrt(pow(x-size,2) + pow(y-3*size,2)) ;
        
         if (dist1 < size + 0.5 || dist2 < size + 0.5)
         cout << "V";
         else
         cout << " ";

      }
      cout << endl;
   
   }

   for (x = 1; x<2*size; x++)
   {
      for (y= 0; y<x; y++)
      cout << " ";

      for (y=0; y<4*size+1-2*x; y++)
      cout << "V";

      cout << endl;
   }
   
   return 0;
}

*/

#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;

// Function to generate heart points
tuple<vector<double>, vector<double>> generate_points(const int no_pieces){
   vector<double> vx, vy;

   constexpr double PI = 3.14159265358979323846;
   double dt = 2.0 * PI / no_pieces;

   for(double t = 0.0; t <= 2.0 * PI; t += dt){
      vx.emplace_back(16.0 * sin(t) * sin(t) * sin(t));
      vy.emplace_back(13.0 * cos(t) - 5.0 * cos(2.0*t)
                     - 2.0 * cos(3.0*t) - cos(4.0*t));
   }

   return make_tuple(vx, vy);
}

int main()
{
   // YOUR FIRST CODE (ASCII HEART)
   double x, y;
   double size = 10;

   for (x=0; x<size; x++)
   {
      for (y=0; y<=4*size; y++)
      {
         double dist1 = sqrt(pow(x-size,2) + pow(y-size,2));
         double dist2 = sqrt(pow(x-size,2) + pow(y-3*size,2));
        
         if (dist1 < size + 0.5 || dist2 < size + 0.5)
            cout << "V";
         else
            cout << " ";
      }
      cout << endl;
   }

   for (x = 1; x<2*size; x++)
   {
      for (y= 0; y<x; y++)
         cout << " ";

      for (y=0; y<4*size+1-2*x; y++)
         cout << "V";

      cout << endl;
   }

   // SECOND CODE USAGE
   cout << "\nGenerated Points:\n";
   auto result = generate_points(10);
   vector<double> vx = get<0>(result);
   vector<double> vy = get<1>(result);

   for (int i = 0; i < vx.size(); i++) {
      cout << "(" << vx[i] << ", " << vy[i] << ")\n";
   }

   return 0;
}
