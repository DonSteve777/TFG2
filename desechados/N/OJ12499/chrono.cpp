// NO PUEDO GENERAR LA ENTRADA DE ESTE, PUESTO QUE DEBE SEGUIR UNAS NORMAS


#include <cstring>
#include <fstream>
#include<iostream>
using namespace std;


//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3943
// https://github.com/morris821028/UVa/blob/master/temp/UVaDate/12499%20-%20I%20am%20Dumb%203.cpp
/*
!!!!!!!!!!!!******************************
ESTE PROBLEMA NO USA UN FOR DE OBSERVACIONES
!!!!!!!!!!!!******************************
*/

#include "../../utils.h"

#define MAX_CASES 100
#define MAX_N 50
#define MAX_L 1000000
#define MIN_N 1
#define REPETITIONS 10


template <std::size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == nullptr));

  return execvp(file, const_cast<char* const*>(argv));
}

int COINS[MAX_N];

int main(int argc, char* argv[] )
{	
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;

	cout << "Introduce N: [1, 50]\n";
	cin >> currentN;

	try{
		csvFile.open("tiempos.csv", std::ofstream::app);	
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operat ions and it already existed, its previous content is deleted and replaced by the new one.
	cout << "N = " << currentN << "\n";
	srand(time(0)); //seeds the rand() function
	casosFile << REPETITIONS << "\n";    
    // generating data of current case
    int nPiles = 1 + rand() % MAX_N;
    int L = 1 + rand() % MAX_L;
    
    for (int j = nPiles -1; j >= 0; j--) {
		        // for (int j = 0; j < nPiles; j++) {
        COINS[j] = 1 + rand() % L;
        L = COINS[j]; 
    }
    for (int k = 0; k < REPETITIONS; k++){
    	casosFile << nPiles << " " << L << "\n";
        for (int i = 0; i < nPiles; i++) 
		    casosFile << COINS[i] << " ";
		casosFile << "\n";
		
	}
    casosFile.close();
	pid_t pid = fork();
	if (pid == -1) {
		exit(EXIT_FAILURE);	//ERROR
	} else if (pid == 0) {
		const char* const argx[] = {"12499.exe", nullptr};
		if (execvp("./12499.exe", argx ) == -1)
			exit(EXIT_FAILURE);
	} else {
		std::cout << std::fixed << std::setprecision(9) << std::left;
		auto start = steady_clock::now();

		if ((pid = wait(&status)) == -1)
			exit(EXIT_FAILURE);
		else{
			auto end = steady_clock::now();
			std::chrono::duration<double> diff = end - start;
			cout << "N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
			cout << "--------------------------------------------\n";
			cout << "--------------------------------------------\n";
			csvFile << "N,seconds,";
			csvFile << currentN << "," << diff.count() / REPETITIONS;
		}
	}	
	csvFile.close();
	return 0;
}