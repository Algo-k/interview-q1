#include <stdio.h>
#include <time.h>
#include <math.h>
 
int prop(long int A, long int B, long int C, long int D) {
    return (pow(A, 4) + pow(B, 4) + pow(C, 4) == pow(D, 4));
}


int FindInx(int mod, int maxi)
{
	int inx = (int) (pow(mod,1.0/4.0)+0.0001);
	if(inx>maxi)
		inx = maxi;
	return inx;
}

int d;

int a[3];

void F(int inx, int mod,int maxi,int f)
{
	for(int i=inx;i>=1;i--)
	{
		int I = pow(i,4);
		int nmod = mod - I;
		if(f==2)
		{
			if(nmod==0)
			{
				 printf("FOUND IT!\na = %ld\nb = %ld\nc = %ld\nd = %ld\n", a[0], a[1], a[2], d);
			}
		}
		else
		{
			if(nmod>0)
			{
				int ninx = FindInx(nmod,maxi);
				if(ninx>0)
					F(ninx,nmod,maxi - 200000,f+1);
			}
		}
	}
}

int main() {

    clock_t t;
    t = clock();
	for (d = 1; d < 500000; d++)
	{
		int D = pow(d,4);
		int inx = d -1;
		F(inx,D,500000,0);
		if(d%10==0)
			printf("d = %ld, time = %fs\n", d, ((double)(clock() - t))/CLOCKS_PER_SEC);
	} 
}
