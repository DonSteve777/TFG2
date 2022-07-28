/////////////////////////////////////////
// cases generator and time chrono for Nos invaden problem (353 aceptaelreto.com)
// Linux version
//	O (N ^ 2)
// Alvaro Abad de Donesteve

////////////////////////////////////////////


#include "/mnt/c/Users/alvar/xXx/ML/repoTFG/utils.h"

#define MIN_CASOS 1
#define MAX_DATO 100
#define OBSERVATIONS 3
#define REPETITIONS 10	//for decrease the process creation noise, each case is being repeated to stablish an average time measure
#define MAX_T 10000
#define MAX_P 500
#define MAX_ORO 10000



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
	int observations[OBSERVATIONS] = { (MAX_DATO*10)/100, (MAX_DATO*50)/100, MAX_DATO};

	try{
		csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		for(int i = 0; i < OBSERVATIONS-1; i++ )
			csvFile << "N,seconds,";
		if (argc > 1 && std::string(argv[1]) == "-t")
				csvFile << "N,seconds,tipo\n";
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
		int p, oro;

		// generating data of current case
		for (int k = 0; k < REPETITIONS; k++) {
            casosFile << 1 + rand() % MAX_T << "\n"; 
			casosFile << currentN << "\n";
			for (int j = 0; j < currentN; j++){
				p = 1 + rand() % MAX_P;
				oro = 1 + rand() % MAX_ORO;
				casosFile << p << " ";
				casosFile << oro << "\n";
			}
			//casosFile << "\n";
		}
		casosFile.close();
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"353.exe", nullptr};
			if (execvp("./353.exe", argx ) == -1)
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
		csvFile << ","<< N2;
	csvFile.close();
	return 0;
}