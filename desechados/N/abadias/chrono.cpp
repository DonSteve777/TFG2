/////////////////////////////////////////
// cases generator and time chrono for 171 problem in aceptaelreto.com
// Linux version
//	O (N)
// Alvaro Abad de Donesteve
////////////////////////////////////////////

#include "../../utils.h"

#define MIN_CASOS 1
// #define MAX_CASOS 100000
#define MAX_DATO 100000000
// #define MAX_DATO 1000000	original

#define OBSERVATIONS 3
#define REPETITIONS 20 // for decrease the process creation noise, each case is being repeated to stablish an average time measure

template <std::size_t N>
int execvp(const char *file, const char *const (&argv)[N])
{
	assert((N > 0) && (argv[N - 1] == nullptr));

	return execvp(file, const_cast<char *const *>(argv));
}

int main(int argc, char *argv[])
{
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

	// data sizes , (percents of max N)
	int observations[OBSERVATIONS] = {2, 50, 99};
	// int observations[OBSERVATIONS] = { 10, 50000, 100000};

	try
	{
		csvFile.open("tiempos.csv", std::ofstream::trunc); // If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		for (int i = 0; i < OBSERVATIONS - 1; i++)
			csvFile << "N,seconds,";
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile << "N,seconds,tipo\n";
		else
			csvFile << "N,seconds\n"; // 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch (std::ofstream::failure e)
	{
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++)
	{
		casosFile.open("casos.txt", std::ofstream::trunc); // If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		currentN = observations[i] * (MAX_DATO / 100);
		cout << "N = " << currentN << "\n";
		srand(time(0)); // seeds the rand() function
		casosFile << currentN << " ";
		for (int j = 0; j < currentN; j++)
		{
			int num;
			num = 1 + rand() % MAX_DATO;
			casosFile << num;
			if (j < currentN - 1)
				casosFile << " ";
		}
		casosFile << "\n";
		casosFile << "0";
		casosFile.close();
		for (int k = 0; k < REPETITIONS; k++)
		{
			// fork a child process to execute erasmus.exe
			pid_t pid = fork();
			if (pid == -1)
			{
				exit(EXIT_FAILURE); // ERROR
			}
			else if (pid == 0)
			{
				const char *const argx[] = {"171.exe", nullptr};
				if (execvp("./171.exe", argx) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				// wait until erasmus.exe ends and finding out how much time a erasmus takes
				std::cout << std::fixed << std::setprecision(9) << std::left;
				auto start = steady_clock::now();

				if ((pid = wait(&status)) == -1)
					exit(EXIT_FAILURE);
				else
				{
					auto end = steady_clock::now();
					std::chrono::duration<double> diff = end - start;
					cout << "i = " << i + 1 << " | N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
					cout << "--------------------------------------------\n";
					cout << "--------------------------------------------\n";
					csvFile << currentN << "," << diff.count();
					if (i < OBSERVATIONS - 1)
						csvFile << ",";
				}
			}
		}
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << "," << N;
	csvFile.close();
	return 0;
}

/*


N = 20000
6
i = 1 | N = 20000 | seconds = 0.034658100
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.027514000
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.032922500
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.025831200
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.023898300
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.024696600
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.028436400
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.023574700
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.032877800
--------------------------------------------
--------------------------------------------
6
i = 1 | N = 20000 | seconds = 0.021711400
--------------------------------------------
--------------------------------------------
N = 500000
i = 2 | N = 500000 | seconds = 0.101765400
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.057220800
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.051148400
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.046800000
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.058494000
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.047214400
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.050589500
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.049521700
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.040267800
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000 | seconds = 0.115109100
--------------------------------------------
--------------------------------------------
N = 990000
i = 3 | N = 990000 | seconds = 0.080248700
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.083479700
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.059800500
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.055435000
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.047523900
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.053071600
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.053701400
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.051517900
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.038434900
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000 | seconds = 0.036671400
--------------------------------------------
--------------------------------------------




Aumentando el tam maximo:	no ha mejorado mucho
N = 2000000
i = 1 | N = 2000000 | seconds = 0.111287000
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.075934600
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.134803800
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.130372500
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.087040900
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.061781800
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.058672200
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.064295200
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.058905200
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.059010200
--------------------------------------------
--------------------------------------------
N = 50000000
i = 2 | N = 50000000 | seconds = 0.106306000
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.051577700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.052239900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.051064900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.054017500
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.052496700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.050167200
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.050020200
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.051321800
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.053013200
--------------------------------------------
--------------------------------------------
N = 99000000
i = 3 | N = 99000000 | seconds = 0.202898200
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.120588900
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.064794100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.074298900
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.076530100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.076046700
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.077814200
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.078808900
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.084265500
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.079466300
--------------------------------------------
--------------------------------------------


20 ejecuciones por tamanio
datos malillos
podria intentar aplicar manejo de outliers
https://brainfood.cl/casos_blog/manejo-de-outliers/ 

N = 2000000
i = 1 | N = 2000000 | seconds = 0.092146400
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.101458100
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.107954500
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.080470100
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.082609400
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.085493600
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.129066000
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.082536600
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.067536700
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.069870700
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.074835300
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.065675600
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.073821400
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.062894100
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.055893300
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.065097300
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.063212500
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.059040400
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.058832300
--------------------------------------------
--------------------------------------------
i = 1 | N = 2000000 | seconds = 0.060378900
--------------------------------------------
--------------------------------------------
N = 50000000
i = 2 | N = 50000000 | seconds = 0.110139600
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.067349900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.051197500
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.224503800
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.051331800
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.054454200
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.050082600
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.085539700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.091850200
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.076744900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.076144400
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.076750700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.126166700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.091750900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.082990900
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.074598300
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.102841200
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.120819500
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.081807700
--------------------------------------------
--------------------------------------------
i = 2 | N = 50000000 | seconds = 0.053590700
--------------------------------------------
--------------------------------------------
N = 99000000
i = 3 | N = 99000000 | seconds = 0.117694800
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.105173100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.105067100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.113779800
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.097270000
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.138104100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.148764100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.103962500
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.048719500
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.046100900
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.065822200
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.099050900
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.081522100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.076728400
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.095121800
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.115153800
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.085390700
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.056770000
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.060191100
--------------------------------------------
--------------------------------------------
i = 3 | N = 99000000 | seconds = 0.072244900
--------------------------------------------
--------------------------------------------
*/