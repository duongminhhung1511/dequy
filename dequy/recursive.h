#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;
const char * myitoa(int n)
{
	char *a = new char [10];
	int i = 0;
	while(n>0)
	{
		a[i] = '0' + n%10;
		n = n/10;
		i++;		
	}
	for(int k =0;k<i/2;k++)
	{
		char t = a[k];
		a[k] = a[i-k-1];
		a[i-k-1] = t;
		 
	}
	a[i] = '.';
	a[i+1] = 'h';
	a[i+2] = 't';
	a[i+3] = 'm';
	a[i+4] = 'l';
	a[i+5] = '\0';
	return a;
}

int GiaiThua(int n)
{
	if( n == 1)
		return 1;
	return n*GiaiThua(n-1);
}

int Fib(int n) // so fibnaci thu n;
{
	if(n <= 2)
		return 1;
	return Fib(n-2) + Fib(n-1);
}

void ThapHaNoi(int n, char c1, char c2, char c3) // bai toan thap ha noi;
{									    // n: so tang thap; c1 c2 c3 vi tri;
	if(n == 1)
	{
		cout<<c1<<" -----> "<<c3<<endl;  // dieu kien dung: neu c1 co 1 tang thi chuyen luon sang c3;	
	}
	else
	{
		ThapHaNoi(n-1, c1, c3, c2); // chuyen n-1 tang tu c1 sang c2;
		ThapHaNoi(1, c1, c2, c3); // chuyen 1 thang tu c1 sang c3;
		ThapHaNoi(n-1,c2,c1,c3);	// chuyen n-1 tang tu c2 sang c3;
	}
}
void KhoiTaoBanCo(char bc[][100], int n)
{
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            bc[i][j] = '-';
}

void InBanCo(char  bc[][100], int n)
{
	for(int i = 1;i<=n; i++)
	{
		for(int j = 1; j<=n;j++)
			cout<<bc[i-1][j-1]<<" ";
        cout<<endl;
	}
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}
void LuuXuongFile(char  bc[][100], int n)
{	
	ofstream fout;
	fout.open("data.txt");
	for(int i = 1;i<=n; i++)
	{
		for(int j = 1; j<=n;j++)
			fout<<bc[i-1][j-1]<<" ";
        fout<<endl;
	}
	fout.close();
}

void XuatHTML(char bc[][100], int n, int sc)
{
	//char c = k + 48;
	//char fileName = 'file'+c+'.html'
	ofstream fout(myitoa(sc));

	fout<<"<!DOCTYPE html>"<<endl;
	fout<<"	<html>"<<endl;
	fout<<"	<head>"<<endl;
	fout<<"		<title>Xep hau</title> "<<endl;
	fout<<"		<style type=\"text/css\"> \n";
    fout<<" 			th{ \n";
    fout<<"      			text-align: center; \n";
    fout<<"  			} \n";
    fout<<"  			td{ \n";
    fout<<"      				text-align: center;  \n";
    fout<<" 					}\n";
  	fout<<"			</style> \n";
	fout<<"	</head>"<<endl;
	fout<<"	<body>"<<endl;
	fout<<"		<h2>xep hau </h2>"<<sc<<"\n";
	fout<<"		<table border = \"1\" >\n";
	for(int i = 1;i<=n;i++)
	{
		
		fout<<"			<tr>\n";
			for(int j = 1;j<=n;j++)
			{
				if (bc[i-1][j-1] == 'H')
				{
					fout<<"<td><img src=\"q.jpeg\" width=\"50\" height=\"50\"></td>"<<endl;
					
				}
				else
				{
					if ((i+j) % 2 == 0)
					{
						fout<<"<td><img src=\"w.png\" width=\"50\" height=\"50\"></td>\n";
					}
					else
					{
						fout<<"<td bgcolor=\"black\"><img src=\"b.png\" width=\"50\" height=\"50\"></td>\n";
						

					}
					//fout<<"			<td>"<<bc[i-1][j-1]<<"</td>\n";
				}
			}
		fout<<"			</tr>\n";
	}
	fout<<"		</table>\n";
	fout<<"	</body>\n";
	fout<<"	</html>\n";
	fout.close();
}
bool XepDuocHau(int x, int y, char bc[][100], int n)
{
	 	for(int j = 1; j<y; j++) // check cot;
		   if (bc[x-1][j-1] == 'H')
		       return false;
		for(int i = x-1, j=y-1; i>=1, j>=1; i--, j--)
		{
		    if (bc[i-1][j-1] == 'H')// check cheo tren;
		       return false;
		}
		for(int i = x+1, j=y-1; i<=n, j>=1; i++, j--)
		{
		    if (bc[i-1][j-1] == 'H')// check cheo duoi;
		        return false;
		}
		return true;	
}
void XepHau(int c, char bc[][100], int n,int &sc)// cot c;
{
	if(c>n)
	{
		InBanCo(bc,n); // Het ban co thi in;
		sc++;
		LuuXuongFile(bc,n);
		XuatHTML(bc,n,sc);
	}	
	else
	{
		for(int i = 1;i<= n;i++)
		{
			if(XepDuocHau(i,c,bc,n))
			{
				bc[i-1][c-1] = 'H';
				XepHau(c+1, bc, n,sc);
		          bc[i-1][c-1] = '-';
			}
		}
	}
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 













