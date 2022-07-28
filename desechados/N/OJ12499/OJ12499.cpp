// Staircase Nim, Game Theory
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
int main() {

	std::ifstream in("casos.txt");
    std::ofstream out("output.txt");
 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 	auto coutbuf = std::cout.rdbuf(out.rdbuf());

	int testcase, cases = 0;
	int N, L, A[64];
    cin >> testcase;
	// scanf("%d", &testcase);
	while (testcase--) {
        cin >> N >> L;
		// scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++)
            cin >> A[i];
			// scanf("%d", &A[i]);
		A[N] = L;
		
		int s = 0;
		for (int i = 0; i < N; i += 2)
			s ^= A[i+1] - A[i];
		// s == 1 ? "First Player" : "Second Player";
		string result = s ? "First Player" : "Second Player"; 
        cout << "Case " << ++cases << ": " << result << "\n"; 
 		// printf("Case %d: %s\n", ++cases, s ? "First Player" : "Second Player");
	}
	return 0;
}