#include <iostream>
#include <stdlib.h>
#include "zagolovok.h"
using namespace std;

int main(){
	int x; char c[10];
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
			if (k <= n){
				for (int i = 0; i < m; i++) { cout << M[k][i] << " "; }
			}
			else cout << "error\n";
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
			cout<<M.getnumstr();
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
			cout<<M.getnumcol();
		}
		system("pause");
	} while (x);
}
