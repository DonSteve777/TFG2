// https://onlinejudge.org/external/102/10219.pdf  
// Find the ways!

#include "../../utils.h"

#define MIN_N 1
#define MAX_N 2147483647
// #define OBSERVATIONS 3
#define REPETITIONS 10

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

    try
    {
        csvFile.open("tiempos.csv", std::ofstream::app); // If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
        casosFile.open("casos.txt", std::ofstream::trunc); // If the file is opened for output operat ions and it already existed, its previous content is deleted and replaced by the new one.
        // 1. generar caso de tamanio n, y escribirlo en casos.txt
    }
    catch (std::ofstream::failure e)
    {
        cout << " Error opening file";
    }
    cout << "introduce N \n";
    cin >> currentN;
    srand(time(0)); // seeds the rand() function

    // generating data of current case
    int k = 1 + rand() % currentN;
    for (int h = 0; h < REPETITIONS; h++)
        casosFile << currentN << " " <<  k << "\n" ;
    casosFile.close();
    pid_t pid = fork();
    if (pid == -1)
    {
        exit(EXIT_FAILURE); // ERROR
    }
    else if (pid == 0)
    {
        const char *const argx[] = {"10219.exe", nullptr};
        if (execvp("./10219.exe", argx) == -1)
            exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << std::fixed << std::setprecision(9) << std::left;
        auto start = steady_clock::now();

        if ((pid = wait(&status)) == -1)
            exit(EXIT_FAILURE);
        else
        {
            auto end = steady_clock::now();
            std::chrono::duration<double> diff = end - start;
            cout << "N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
            cout << "--------------------------------------------\n";
            cout << "--------------------------------------------\n";
            csvFile << currentN << "," << diff.count() / REPETITIONS << ",";
        }
    }

    csvFile.close();
    return 0;
}
