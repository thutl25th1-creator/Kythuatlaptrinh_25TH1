#include <string>
using namespace std;

struct Account {
	string lnk, usr, pwd, desc;
	friend ostream& operator<<(ostream& os, const Account& b) {
		os << "\t+ Link:" << b.lnk <<endl;
		os << "\t+ User name: " << b.usr << endl;
		os << "\t+ Password: " << b.pwd << endl;
		os << "\t+ Description; " << b.desc << endl;
		return os;
	}
	friend istream& operator>>(istream& in, & b) {
		cout << "information:" << endl;
		cout << "\t+ Link: ";
		in >> b.id;
		cout << "\t+ User name: ";
		in.ignore();
		getline(in, b.name);
		in >> b.author;
		return in;
	}
};
