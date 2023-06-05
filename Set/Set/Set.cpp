#include <iostream>
using namespace std;

template <typename TypeE>
class Univers
{
public:
	int n;
	TypeE* U;
	Univers(int nn, TypeE* u) : n(nn)
	{
		U = new TypeE[n];
		for (int i = 0; i < n; i++)
			U[i] = u[i];
	}
	TypeE& operator [] (int i)
	{
		return U[i];
	}
	int N() { return n; }
};

template <typename TypeE>
class Set {
private:
	Univers <TypeE>* Uni;
public:
	int n;
	int* shk;
	Set(Univers<TypeE>& U) {
		n = U.N();
		cout << "n=" << n << endl;
		shk = new int[n];
		for (int i = 0; i < n; i++)
			shk[i] = 0;
		Uni = &U;
	}

	void add(int i) { // Метод добавления элемента
		shk[i] = 1;
	}

	void add2(TypeE x) {
		for (int i = 0; i < n; i++) {
			if ((*Uni)[i] == x) {
				add(i);
				break;
			}
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			if (shk[i] == 1)
				cout << (*Uni)[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int m[5] = { 17,35,22,34,45 };
	Univers<int> intU(5, m);
	cout << "intU="; for (int i = 0; i < 5; i++) cout << intU[i] << ' ';
	cout << endl;

	Set <int> s1(intU);
	cout << "s1=";
	s1.print();
	cout << endl;
	s1.add2(35);
	s1.add2(45);
	cout << "s1=";
	s1.print();
	cout << endl;

	float mm[6] = { 0.0,1.1,2.2,3.3,4.4,5.5 };
	Univers<float> floatU(6, mm);
	for (int i = 0; i < 6; i++) intU[i] = i; cout << endl;
	cout << "floatU="; for (int i = 0; i < 6; i++) cout << floatU[i] << ' ';
	cout << endl;

	Set<float> s2(floatU);
	cout << "s2=";
	for (int i = 0; i < 6; i++)
		cout << s2.shk[i];
	cout << endl;

	s2.add(3);
	cout << "s2="; for (int i = 0; i < 6; i++) cout << s2.shk[i]; cout << endl;
	cout << "s2=";
	for (int i = 0; i < 6; i++)
		if (s2.shk[i] == 1)
			cout << floatU[i] << " ";
	cout << endl;

	s2.add2(4.4);
	cout << "s2="; for (int i = 0; i < 6; i++) cout << s2.shk[i]; cout << endl;
	cout << "s2=";
	for (int i = 0; i < 6; i++)
		if (s2.shk[i] == 1)
			cout << floatU[i] << " ";
	cout << endl;


	return 0;
}
