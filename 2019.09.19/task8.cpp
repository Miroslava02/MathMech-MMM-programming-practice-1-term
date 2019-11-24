//Реализовать структуру string (str)

#include <iostream>
#include <cstring>
using namespace std;
struct str {
	int len; char* s;

	str(char* st) {
		len = strlen(st);
		s = new char[len + 1];
		for (int i = 0; i < len; i++) {
			s[i] = st[i];

		}
		s[len] = '\0';
	}

	str() {
		len = 5;
		s = new char[len + 1];
		strcpy(s, "error");
	}

	~str() {
		delete[]s;

	}

	int getlen() {
		return len;
	}

	str& operator=(const str& a) {
		if (this == &a) return *this;
		char* t = new char[a.len + 1];
		strcpy(t, a.s);
		t[a.len] = '\0';
		delete[]s;
		len = a.len;
		s = t;
		return *this;
	}

	bool poisk(str pst) {
		int i, j;
		for (int i = 0; i < len; i++) {
			for (int j = i; j < pst.len + i; j++) {
				if (s[j] != pst.s[j - i]) break;
				else if ((s[j] == pst.s[j - i]) && (j - i + 1 == pst.len)) {
					cout << "done" << endl;
					return 1;
				}

			}
		}

		cout << "fail" << endl;
		return 0;
	}

	str operator+(const str& dop) {
		char* ns = new char[this->len + dop.len + 1];
		for (int i = 0; i < this->len; i++) { ns[i] = this->s[i]; }
		for (int j = 0, i = this->len; j < dop.len; i++, j++) { ns[i] = dop.s[j]; }
		ns[len + dop.len] = '\0';
		return str(ns);
	}

	friend ostream& operator << (ostream& out, str& str) {
		for (unsigned int i = 0; i < str.getlen(); i++)
			out << str.s[i];
		return out;
	}
};


int main()
{
	int const s11 = 7, s22 = 11;
	char s1[s11] = "hello ";
	str a(s1);
	char s2[s22] = "hell world";
	str b(s2);
	str c = a + b;
	cout << c << endl;
	cout << c.getlen() << endl;
	a.poisk(b);
}
