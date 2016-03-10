#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Matrix{
public:
	Matrix() : n(0), m(0), p(nullptr) {}

	Matrix(int _n, int _m) : n(_n), m(_m){
		p = new int*[n];
		for (int i = 0; i < n; i++) p[i] = new int[m];
	}

	Matrix(const Matrix &M){
		n = M.n;
		m = M.m;
		p = new int*[n];
		for (int i = 0; i < n; i++)
			p[i] = new int[m];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				p[i][j] = M.p[i][j];
		}
	}

	~Matrix()
	{
	if (p!=nullptr)
	{
	for (int i = 0; i < n; i++)
	{
	delete [] p[i];
	}
	delete[] p;
	}
	}

	int set_matrix(char* a){
		ifstream fin;
		fin.open(a);
		if (!fin.is_open()) {
			cout << "file not found" << "\n"; return 0;
		}
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++)
					fin >> p[i][j];
		}
		return 0;
	}

	int print(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << p[i][j] << " ";
			cout << "\n";
		}
		return 0;
	}

	Matrix operator +(Matrix &M2){
		Matrix M_res(M2.n, M2.m);
		for (int i = 0; i < M2.n; i++)
		for (int j = 0; j < M2.m; j++)
			M_res.p[i][j] = p[i][j] + M2.p[i][j];
		cout << "M1+M2:\n";  M_res.print();
		return M_res;
	}
	Matrix operator *(Matrix &M2){
		Matrix M_res(n, M2.m);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < M2.m; j++)
		{
			M_res.p[i][j] = 0;
			for (int k = 0; k < M2.m; k++)
				M_res.p[i][j] += (p[i][k] * M2.p[k][j]);
		}
		cout << "M1*M2:\n";  M_res.print();
		return M_res;
	}

	Matrix operator [] (int k){
		Matrix o;
		for (int i = k - 1; i < k; i++)
		for (int j = 0; j < m; j++)
			cout << p[i][j] << " ";
		return o;
	}

	void getnumstr(){
		cout << n << "\n";
	}

	void getnumcol(){
		cout << m << "\n";
	}
private:
	int n;
	int m;
	int **p;

};



int main(){
	int x = 777; char c[10];
	cout << "set_=1, sum=2, mult=3, getstr=4, getnumstr=5, getnumcol=6, exit=0" << "\n";
	do{
		cout << "x="; cin >> x;
		if (x == 1){
			int n, m;
			cout << "n="; cin >> n;
			cout << "m="; cin >> m;
			Matrix M(n, m);
			char c[10];
			cout << "name of file:";  cin >> c;
			M.set_matrix(c);
			M.print();
		}
		if (x == 2){
			int n1, m1, n2, m2;
			cout << "n1="; cin >> n1;
			cout << "m1="; cin >> m1;
			Matrix M1(n1, m1);
			cout << "name of file_1: ";  cin >> c;
			M1.set_matrix(c);
			M1.print();
			cout << "n2="; cin >> n2;
			cout << "m2="; cin >> m2;
			Matrix M2(n2, m2);
			cout << "name of file_2: ";  cin >> c;
			M2.set_matrix(c);
			M2.print();
			if (n1 == n2 && m1 == m2)
				M1 + M2;
			else cout << "error" << "\n";
		}
		if (x == 3){
			int n1, m1, n2, m2;
			cout << "n1="; cin >> n1;
			cout << "m1="; cin >> m1;
			Matrix M1(n1, m1);
			cout << "name of file_1: ";  cin >> c;
			M1.set_matrix(c);
			M1.print();
			cout << "n2="; cin >> n2;
			cout << "m2="; cin >> m2;
			Matrix M2(n2, m2);
			cout << "name of file_2: ";  cin >> c;
			M2.set_matrix(c);
			M2.print();
			if (m1 == n2)
				M1 * M2;
			else cout << "error" << "\n";
		}
		if (x == 4){
			int n, m, k;
			cout << "n="; cin >> n;
			cout << "m="; cin >> m;
			Matrix M(n, m);
			char c[10];
			cout << "name of file:";  cin >> c;
			M.set_matrix(c);
			M.print();
			cout << "k="; cin >> k;
			M[i];
		}
		if (x == 5){
			int n, m;
			cout << "n="; cin >> n;
			cout << "m="; cin >> m;
			Matrix M(n, m);
			char c[10];
			cout << "name of file:";  cin >> c;
			M.set_matrix(c);
			M.print();
			M.getnumstr();
		}
		if (x == 6){
			int n, m;
			cout << "n="; cin >> n;
			cout << "m="; cin >> m;
			Matrix M(n, m);
			char c[10];
			cout << "name of file:";  cin >> c;
			M.set_matrix(c);
			M.print();
			M.getnumcol();
		}
		system("pause");
	} while (x);
}
