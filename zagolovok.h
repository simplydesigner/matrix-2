#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Matrix{
public:
	Matrix() : n(0), m(0), p(nullptr) {}

	Matrix(int _n, int _m) : n(_n), m(_m){
		p = new int*[n];
		for (int i = 0; i < n; i++) { p[i] = new int[m]; }
	}

	Matrix(const Matrix &M): n(M.n), m(M.m) {
		p = new int*[n];
		for (int i = 0; i < n; i++){
			p[i] = new int[m];
			for (int j = 0; j < m; j++)
				p[i][j] = M.p[i][j];
		}
	}
		
	~Matrix()
	{
		if (p != nullptr)
		{
			for (int i = 0; i < n; i++)
			{
				delete[] p[i];
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

	void print(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << p[i][j] << " ";
			cout << "\n";
		}
	}

	Matrix operator +(const Matrix &M2){
		Matrix M_res(M2.n, M2.m);
		for (int i = 0; i < M2.n; i++)
		for (int j = 0; j < M2.m; j++)
			M_res.p[i][j] = p[i][j] + M2.p[i][j];
		cout << "M1+M2:\n";  M_res.print();
		return M_res;
	}
	Matrix operator *(const Matrix &M2){
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

	int* operator [] (int k){
		int *r = new int[m];
		for (int j = 0; j < m; j++){
			r[j] = p[k][j];
		}
		return r;
	}

	int getnumstr(){
		return n;
	}

	int getnumcol(){
		return m;
	}

	Matrix& operator = (const Matrix &M){
		for (int i = 0; i < n; i++){
			delete[] p[i];
		}
		delete[] p;
		n = M.n;
		m = M.m;
		p = new int*[n];
		for (int i = 0; i < n; i++){
			p[i] = new int[m];
			for (int j = 0; j < m; j++) { p[i][j] = M.p[i][j]; }
		}
		return *this;
	}

private:
	int n;
	int m;
	int **p;

};
