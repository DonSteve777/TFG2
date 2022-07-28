/////////////////////////////////////////
// cases generator and time chrono for Nos invaden problem (305 aceptaelreto.com)
// Linux version
//	O (N log N)
// Alvaro Abad de Donesteve

////////////////////////////////////////////


#include "../../utils.h"

#define MIN_CASOS 1
#define MAX_USUARIOS 2500
#define MAX_K 10000
#define OBSERVATIONS 3
#define REPETITIONS 10	//for decrease the process creation noise, each case is being repeated to stablish an average time measure



template <std::size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == nullptr));

  return execvp(file, const_cast<char* const*>(argv));
}


int main(int argc, char* argv[] )
{
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	int observations[OBSERVATIONS] = { (MAX_USUARIOS*10)/100, (MAX_USUARIOS*50)/100, MAX_USUARIOS};

	try{
			//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
        if (argc > 1 && std::string(argv[1]) == "-t")
            csvFile.open("tiemposT.csv", std::ofstream::trunc);
        
        else
            csvFile.open("tiempos.csv", std::ofstream::trunc);
        
		for(int i = 0; i < OBSERVATIONS-1; i++ )
	        csvFile << "N,seconds,";
        if (argc > 1 && std::string(argv[1]) == "-t")
            csvFile << "N,seconds,tipo\n";	// 1
        else
            csvFile << "N,seconds\n";	// 1
        
		
	// 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++) {
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		currentN = observations[i];
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function
		int periodicidad;

		// generating data of current case
		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << currentN << "\n";
			for (int j = 0; j < currentN; j++){
                casosFile << j << " "; //id
				periodicidad = 1 + rand() % MAX_USUARIOS;   //no especifica maximos
				casosFile << periodicidad << "\n";
			}
            k = 1 + rand() % MAX_K;
            casosFile << k << "\n";
		}
        casosFile << 0;
		casosFile.close();
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"351.exe", nullptr};
			if (execvp("./351.exe", argx ) == -1)
				exit(EXIT_FAILURE);
		} else {
			std::cout << std::fixed << std::setprecision(9) << std::left;
			auto start = steady_clock::now();

			if ((pid = wait(&status)) == -1)
				exit(EXIT_FAILURE);
			else{
				auto end = steady_clock::now();
				std::chrono::duration<double> diff = end - start;
				cout << "i = " << i + 1 << " | N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
				cout << "--------------------------------------------\n";
				cout << "--------------------------------------------\n";
				csvFile << currentN << "," << diff.count() / REPETITIONS;
				if (i < OBSERVATIONS-1)
					csvFile << ",";
			}
		}	
		
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< NLOGN;
	csvFile.close();
	return 0;
}

/*
N = 1250
i = 1 | N = 1250 | seconds = 0.000630700
--------------------------------------------
--------------------------------------------
N = 1250
i = 2 | N = 1250 | seconds = 0.000743800
--------------------------------------------
--------------------------------------------
N = 1250
i = 3 | N = 1250 | seconds = 0.002260400
--------------------------------------------
--------------------------------------------




*/