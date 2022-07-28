//https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/10019%20-%20Funny%20Encryption%20Method.cpp
//https://onlinejudge.org/external/100/10019.pdf
#include <fstream>
#include<iostream>
#include <cstring>

using namespace std;

int b1(int n){
    int ret = 0;
    
    while(n){
        if(n & 1) ++ret;
        n >>= 1;
    }
    
    return ret;
}

int d[4];

int b2(int n){
    int sz = 0;
    
    while(n){
        d[sz++] = n%10;
        n /= 10;
    }
    
    int m = 0;
    
    for(int i = 0;i<sz;++i)
        m = m*16+d[i];
    
    return b1(m);
}

int main(){
    std::ifstream in("casos.txt");
    std::ofstream out("output.txt");
 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 	auto coutbuf = std::cout.rdbuf(out.rdbuf());
    
    int T,N;
    cin >> T;
    
    while(T--){
        cin >> N;
        cout << b1(N) << " " << b2(N) << "\n";
        // scanf("%d",&N);
        // printf("%d %d\n",b1(N),b2(N));
    }
    
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf); 

 	// system("PAUSE");
    return 0;
}