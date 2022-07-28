// #include <stdio.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Date {
	long long yy, mm, dd;
	Date(long long a = 0, long long b = 0, long long c = 0):
		yy(a), mm(b), dd(c) {}
	int validDate() {
		int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if ((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)
			mday[2] = 29;
		if (mm < 1 || mm > 12)	
			return 0;
		if (dd < 1 || dd > mday[mm])
			return 0;
		return 1;
	}
	bool operator<(const Date &a) const {
		if (yy != a.yy)	return yy < a.yy;
		if (mm != a.mm)	return mm < a.mm;
		return dd < a.dd;
	}
};

string pad_zeros(long long x){
	// Convert long to string 
		string x_str = to_string( x);
		size_t n = 2;
		int precision = n - std::min(n, x_str.size());
		std::string s = std::string(precision, '0').append(x_str);
		return s;
}


int main() {
	int testcase;
	// scanf("%d", &testcase);
	cin >> testcase;
	while (testcase--) {
		long long c, x, y, z;
		cin >> c >> x >> y >> z;
		// scanf("%lld %lld %lld %lld", &c, &x, &y, &z);
		
		vector<Date> A;
		if (Date(c * 100 + x, y, z).validDate())
			A.push_back(Date(c * 100 + x, y, z));
		if (Date(c * 100 + x, z, y).validDate())
			A.push_back(Date(c * 100 + x, z, y));
		if (Date(c * 100 + y, x, z).validDate())
			A.push_back(Date(c * 100 + y, x, z));
		if (Date(c * 100 + y, z, x).validDate())
			A.push_back(Date(c * 100 + y, z, x));
		if (Date(c * 100 + z, y, x).validDate())
			A.push_back(Date(c * 100 + z, y, x));
		if (Date(c * 100 + z, x, y).validDate())
			A.push_back(Date(c * 100 + z, x, y));
		
		if (A.size() == 0)
			puts("-1");
		else {
			sort(A.begin(), A.end());
			Date mn = A[0];
			// printf("%02lld %02lld %02lld\n", mn.yy%100, mn.mm, mn.dd);
			cout << pad_zeros( mn.yy%100) << pad_zeros(mn.mm) << pad_zeros(mn.dd) << "\n";
		}
	}
	return 0;
}