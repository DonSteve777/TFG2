#include <iostream>
#include <string>
using namespace std;

int main(){
	int personas;
	string nombre, soy;
	cin >> personas;
	
	for (int i = 0; i< personas; i++){
		cin >> soy >> nombre;
		cout << "Hola " << nombre << ". \n";
	}
	return 0;
}