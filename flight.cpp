#include <bits/stdc++.h>
using namespace std;
int adj_mat[50][50] = {0, 0};
int visited[50] = {0};
int main()
{
cout <<"\nEnter no. of cities: ";
int n, u;
cin >> n;
string cities[n];
for (int i=0; i<n; i++)
{
cout <<"Enter city "<<i+1<<" (Airport Code): ";
cin >> cities[i];
}
cout << "\nYour cities are: ";
for (int i=0; i<n; i++)
cout <<"\ncity "<<i+1<<": "<<cities[i];
for (int i=0; i<n; i++)
{
for (int j=i+1; j<n; j++)
{
cout <<"\nEnter distance between "<< cities[i]<<" and "<<cities[j]<<" : ";
cin >> adj_mat[i][j];
adj_mat[j][i] = adj_mat[i][j];
}
}
for (int i = 0; i < n; i++)
cout<<"\t"<<cities[i]<<"\t";
for (int i=0; i<n; i++)
{
cout<<"\n"<< cities[i];
for (int j=0; j<n; j++)
cout<<"\t" << adj_mat[i][j] << "\t";
}
return 0;
}