#include <cstdio>
#include <string>
using namespace std;

int main(){
	int personas;
    char soy[3];
    char nombre[100];

	scanf("%d", personas);
	for (int i = 0; i< personas; i++){
		scanf("%s", soy);
        scanf("%s", nombre);
		cout << "Hola " << nombre << ". \n";
	}
	return 0;
}