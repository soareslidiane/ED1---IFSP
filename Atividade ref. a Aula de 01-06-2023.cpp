#include <iostream>
using namespace std;

void insertion_sort(int t, int *a)
{
	for(int i=1;i<t;++i)
	{
		cout<<"Comparacao "<<i<<":"<<endl;
		cout << "[" << i-1 << "]= " << a[i-1] << " com [" << i << "]= " << a[i]<<endl;
		
		int y,x;
		y=i;
		while(y>0&&a[y]<a[y-1])
		{
			x=a[y];
			a[y]=a[y-1];
			a[y-1]=x;
			cout<<"Trocou e ficou assim: "<<endl;
			cout << "[" << y-1 << "]= " << a[y-1] << " e [" << y << "]= " << a[y]<<endl;
			y--;
			if(y>0)
			{
			cout<<"Comparando "<<"[" << y-1 << "]= " << a[y-1] << " com [" << y << "]= " << a[y]<<endl;			
			}
		}
		
		cout<<"Comparacao "<<i<<" finalizada."<<endl<<endl;
	}
	cout << "------------------------" << endl;
}

void print(int t, int *a) {
	int i;
	for(i=0; i<t; ++i) {
		cout << "Elemento " << i+1 << " = " << a[i] << endl;
	}
	cout << "------------------------" << endl;
}

int main(int argc, char** argv)
{
	int v[8] = {26,49,38,13,58,87,34,93};
	int tam = sizeof(v)/sizeof(int);
	
	print(tam , v);
	
	insertion_sort(tam , v);
	
	print(tam, v);
	
	return 0;
}