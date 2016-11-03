#include <stdio.h>
#include <iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int min1(int a, int b, int c) {
	if (a < b){
		if (a < c){
			return a;
		}
		return b;
	}
	else if (b < c){
		if (b < a){
			return b;
		}
		return b;
	}
	else{
		return c;
	}
}

int Assembly1(int a[][1000], int t[][1000], int *m, int *n)
{
	int T1[1000], T2[1000], T3[1000]; 
	int i;

	T1[0] = m[0] + a[0][0]; // time taken to leave first station in line 1
	T2[0] = m[1] + a[1][0]; // time taken to leave first station in line 2
	T3[0] = m[2] + a[2][0]; // time taken to leave first station in line 3
	// Fill tables T1[] and T2[] using the above given recursive relations
	for (i = 1; i < 1000; ++i)
	{
		T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
		T3[i] = min(T2[i - 1] + a[1][i], T3[i - 1] + t[2][i] + a[2][i]);
	}

	// Consider exit times and return minimum
	return min1(T1[1000 - 1] + n[0], T2[1000 - 1] + n[1], T3[1000 - 1] + n[2]);
}
int Assembly2(int a[][10000], int t[][10000], int *m, int *n)
{
	int T1[10000], T2[10000], T3[10000], i;

	T1[0] = m[0] + a[0][0]; // time taken to leave first station in line 1
	T2[0] = m[1] + a[1][0]; // time taken to leave first station in line 2
	T3[0] = m[2] + a[2][0]; // time taken to leave first station in line 3
	// Fill tables T1[] and T2[] using the above given recursive relations
	for (i = 1; i < 10000; ++i)
	{
		T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
		T3[i] = min(T2[i - 1] + a[1][i], T3[i - 1] + t[2][i] + a[2][i]);
	}

	// Consider exit times and return minimum
	return min1(T1[10000 - 1] + n[0], T2[10000 - 1] + n[1], T3[10000 - 1] + n[2]);
}

int main(){
	while (true){
		int input;
		cout << "ENTER YOUR CHOICE:\n";
		cout << "\n1:\tITERATIVE-1000 \n2:\tITERATIVE-10000 \n3:\tITERATIVE-100000";
		cin >> input;
		cout << "\n";
		if (input == 1){
			int a[3][1000] = { 0 };
			int t[3][1000] = { 0 };
			int m[3] = { 0 };
			int n[3] = { 0 };
			for (int i = 0; i < 3; i++){
				int random1 = 0;
				random1 = (rand() % 5) + 1;
				m[i] = random1;
				random1 = (rand() % 5) + 1;
				n[i] = random1;
				for (int j = 0; j < 1000; j++){
					int ran1, ran2 = 0;
					ran1 = (rand() % 5) + 1;
					a[i][j] = ran1;
					ran2 = (rand() % 5) + 1;
					t[i][j] = ran2;
				}

			}
			cout << "For N=1000, TIME is:" << Assembly1(a, t, m, n) << "\tUsing iterative method\n\n\n";
		}
		else if (input == 2){
			int b[3][10000] = { 0 };
			int u[3][10000] = { 0 };
			int f[3] = { 0 };
			int y[3] = { 0 };
			for (int i = 0; i < 3; i++){
				int random1 = 0;
				random1 = (rand() % 5) + 1;
				f[i] = random1;
				random1 = (rand() % 5) + 1;
				y[i] = random1;
				for (int j = 0; j < 10000; j++){
					int ran1, ran2 = 0;
					ran1 = (rand() % 5) + 1;
					b[i][j] = ran1;
					ran2 = (rand() % 5) + 1;
					u[i][j] = ran2;
				}

			}
			cout << "For N=10000, TIME is:" << Assembly2(b, u, f, y) << "\tUsing iterative method\n\n\n";
		}
	}
}