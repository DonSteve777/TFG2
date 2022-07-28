//N es la diferencia entre inicio y fin


#include "../../utils.h"

#define MIN_CASOS 1
#define MAX_DATO 1000000000
#define OBSERVATIONS 3
#define REPETITIONS 10	//for decrease the process creation noise, each case is being repeated to stablish an average time measure

//enum { LOGN, N, NLOGN, N2, N3, DOSN };


template <std::size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == nullptr));

  return execvp(file, const_cast<char* const*>(argv));
}


struct INPUT_DATA {   // Declare PERSON struct type
    int ini;   // Declare member types
 	int fin;
} input_data; 

int main(int argc, char* argv[] )
{
	int observaciones, status;
	std::ofstream csvFile, casosFile;
	int inicio;

//data sizes , (percents of max N)
	// INPUT_DATA observations[OBSERVATIONS] = { {1, 2},  {345, 48000}, {1, 999999}};
	INPUT_DATA observations[OBSERVATIONS] = { {1, 10},  {1, 50}, {1, 99}};	//son porcentajes del tamanio maximo
	// INPUT_DATA observations[OBSERVATIONS] = { {1, 2}, {90, 2000}, {345, 48000}, {10000, 700000}, {1, 999999}};

	try{
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile.open("tiemposT.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		else
			csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

		for(int i = 0; i < OBSERVATIONS-1; i++ )
			csvFile << "N,seconds,";
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile << "N,seconds,tipo\n";
		else
			csvFile << "N,seconds\n";
		
	// 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++) {
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		INPUT_DATA currentN = {observations[i].ini * MAX_DATO /100, observations[i].fin * MAX_DATO /100};
		cout << "N = " << currentN.fin << " - " << currentN.ini << "\n";
		srand(time(0)); //seeds the rand() function
		casosFile << currentN.fin << " " <<  currentN.ini << "\n";
		casosFile << "0 0";
		casosFile.close();
		
		for (int k = 0; k < REPETITIONS; k++) {
			// fork a child process to execute erasmus.exe	
			pid_t pid = fork();		
			if (pid == -1) {
				exit(EXIT_FAILURE);	//ERROR
			} else if (pid == 0) {
				const char* const argx[] = {"323.exe", nullptr};
				if (execvp("./323.exe", argx ) == -1)
					exit(EXIT_FAILURE);
			} else {
				// wait until erasmus.exe ends and finding out how much time a erasmus takes
				std::cout << std::fixed << std::setprecision(9) << std::left;
				auto start = steady_clock::now();
				
				if ((pid = wait(&status)) == -1)
					exit(EXIT_FAILURE);
				else{
					auto end = steady_clock::now();
					std::chrono::duration<double> diff = end - start;
					cout << "i = " << i + 1 << " | " << currentN.fin  << " - " <<  currentN.ini << " | seconds = " << std::setw(9) << diff.count() << '\n';
					cout << "--------------------------------------------\n";
					cout << "--------------------------------------------\n";
					csvFile <<  currentN.fin - currentN.ini  << "," << diff.count();
					if (i < OBSERVATIONS-1)
						csvFile << ",";
				}
			}	
		}	
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< LOGN;
	csvFile.close();
	return 0;
}

/*
tiempos inservibles
	cambiado el tamao maximo del problema original, sin efecto
N = 14100654 - 10000000
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.015635400
--------------------------------------------       
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.011607500
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.011576700
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.018434700
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.024949200
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.018954500
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.015106800
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.018334700
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.018815800
--------------------------------------------
--------------------------------------------
14100654
i = 1 | 14100654 - 10000000 | seconds = 0.020152700
--------------------------------------------
--------------------------------------------
N = -15396075 - 10000000
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.016204200
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.014905100
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.007486900
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.011100100
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.008968900
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.014962400
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.009546400
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.012409800
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.008683500
--------------------------------------------
--------------------------------------------
3979644
i = 2 | -15396075 - 10000000 | seconds = 0.013118000
--------------------------------------------
--------------------------------------------
N = 2157521 - 10000000
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.010473000
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.013782000
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.011723200
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.010314700
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.013450300
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.011699900
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.012793000
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.010579500
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.013748000
--------------------------------------------
--------------------------------------------
6078760
i = 3 | 2157521 - 10000000 | seconds = 0.010430700
--------------------------------------------
--------------------------------------------
*/