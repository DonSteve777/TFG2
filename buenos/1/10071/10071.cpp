#include<iostream>
#include <fstream>

using namespace std;

int main(){

    std::ifstream in("casos.txt");
    std::ofstream out("output.txt");
 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 	auto coutbuf = std::cout.rdbuf(out.rdbuf());


    int v,t;

    while(cin>>v>>t){
        if(t==0){
            cout<<0<<endl;
            continue;
        }

        cout<<2*v*t<<endl;
    }

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf); 
}