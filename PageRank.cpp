#include <iostream>
#include <math.h>
using namespace std;


void ki (double tomb[], int db)
{
	int i;
	for (i=0; i<db; i++)
	{
		cout<<"PageRank ["<< i<<"] : " << tomb[i] << endl;
	}
}

double tavolsag(double PR[],double PR_v[],int db)
{
	double tav = 0.0;
	int i;
	for(i=0;i<db;i++)
	{
		tav+=abs(PR[i] - PR_v[i]);
	}	
	return tav;
}

int main(void){

double L[4][4] = {
	{0.0, 0.0, 1.0 / 3.0, 0.0},
	{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
	{0.0, 1.0 / 2.0, 0.0, 0.0},
	{0.0, 0.0, 1.0 / 3.0, 0.0}
};

double PR[4] = {0.0, 0.0, 0.0, 0.0};
double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};
long int i=0,j=0;

	for (;;)
	{
		for(int i = 0; i < 4;++i)
		{
			PR[i] = 0.0;
			for(int j = 0;j<4;++j)
			{
				PR[i] += (L[i][j]*PRv[j]);
			}
		}
		
		if ( tavolsag(PR,PRv, 4) < 0.0000001)
		break;
	
		for(i=0;i<4;++i)
		{
			PRv[i]	= PR[i];
		}
	}
	
	ki (PR,4);
	return 0;
}
