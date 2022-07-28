
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1883
// https://github.com/morris821028/UVa/blob/master/temp/UVaDate/10942%20-%20Can%20of%20Beans.cpp
// CAN OF BEANS O(1)
// no hay un N

/*
!!!!!!!!!!!!******************************
ESTE PROBLEMA NO USA UN FOR DE OBSERVACIONES
!!!!!!!!!!!!******************************
*/

#include "../../utils.h"

#define MIN_C 0
#define MAX_C 1073741824
#define MIN_XYZ 0
#define MAX_XYZ 99
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
        csvFile.open("tiempos.csv", std::ofstream::trunc); // If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
        casosFile.open("casos.txt", std::ofstream::trunc); // If the file is opened for output operat ions and it already existed, its previous content is deleted and replaced by the new one.
        for (int i = 0; i < OBSERVATIONS - 1; i++)
            csvFile << "N,seconds,";
        if (argc > 1 && std::string(argv[1]) == "-t")
            csvFile << "N,seconds,tipo\n";
        else
            csvFile << "N,seconds\n";
        // 1. generar caso de tamanio n, y escribirlo en casos.txt
    }
    catch (std::ofstream::failure e)
    {
        cout << " Error opening file";
    }

    cout << "N = " << currentN << "\n";
    srand(time(0)); // seeds the rand() function

    // generating data of current case
    for (int k = 0; k < REPETITIONS; k++)
    {
        casosFile << currentN << "\n";
        int num;
        for (int j = 0; j < currentN; j++)
        {
            num = MIN_M + rand() % MAX_M;
            casosFile << num << "\n";
        }
        casosFile << "\n";
    }
    casosFile.close();
    pid_t pid = fork();
    if (pid == -1)
    {
        exit(EXIT_FAILURE); // ERROR
    }
    else if (pid == 0)
    {
        const char *const argx[] = {"10019.exe", nullptr};
        if (execvp("./10019.exe", argx) == -1)
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
            csvFile << currentN << "," << diff.count() / REPETITIONS;
        }
    }

    if (argc > 1 && std::string(argv[1]) == "-t")
        csvFile << "," << N2;
    csvFile.close();
    return 0;
}
