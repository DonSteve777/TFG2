#include<iostream>
#include<cmath>
#include <fstream>


using namespace std;

double log10(double n){
    return log(n)/log(10);
}

int main(){
    std::ifstream in("casos.txt");
    std::ofstream out("output.txt");
 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 	auto coutbuf = std::cout.rdbuf(out.rdbuf());

    long long n,k;
    double ax;
    int dig;

    while(cin>>n>>k){
        ax=0;

        for(int i=0;i<k;i++)
            ax+=log10(n-i)-log10(i+1);

        dig=floor(ax)+1;

        cout<<dig<<endl;
    }
    
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf); 
    
    return 0;
}