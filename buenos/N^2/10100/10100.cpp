#include <cstring>
#include <fstream>
#include<iostream>
using namespace std;

int main(){

        std::ifstream in("casos.txt");
    std::ofstream out("output.txt");
 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 	auto coutbuf = std::cout.rdbuf(out.rdbuf());


    int T,N,P,a[100];
    
    cin >> T;
    
    while(T--){
        cin >> N >> P;
        for(int i = 0;i<P;++i) 
            cin >> a[i];
        
        int ans = 0;
        
        for(int i = 1;i<=N;++i){
            if(i%7==6 || i%7==0) continue;
            
            bool found = false;
            
            for(int j = 0;j<P;++j)
                if(i%a[j]==0)
                    found = true;
            
            if(found) ++ans;
        }
        cout << ans << "\n";
    }
       std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf); 

    return 0;
}