// The path in the colored field
// The square field consists of M × M cells. Each cell is colored in one of three colors (1,2,3). The initial
// state is chosen in one of the cells of color 1. In each step one allowed to move one cell up, down, left or
// right remaining inside the field.
// You are to define the minimal amount of steps one should make to get a cell of color 3 independent
// on the initial state.
// Note that the field contains at least one cell of color 1 and at least one cell of color 3.
// Input
// The input consists of several input blocks. The first line of each block contains integer M, the size of
// the field. Then there are M lines with colors of the cells.
// Output
// For each input block the output should consist of one line with the integer, the minimal amount of
// steps one should make to get a cell of color 3 independent on the initial state.
// Sample Input

// 4
// 1223
// 2123
// 2213
// 3212
// 2
// 12
// 33


// https://onlinejudge.org/external/101/10102.pdf// https://github.com/morris821028/UVa/blob/master/temp/UVaDate/10942%20-%20Can%20of%20Beans.cpp
// https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/10102%20-%20The%20path%20in%20the%20colored%20field.cpp
// The path in the colored field N2

#include "../../utils.h"

#define MIN_M 1
#define MAX_M 1000
#define MAX_COLOR 3
#define MIN_COLOR 1
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
    casosFile << currentN << "\n";
    int num;
    for (int j = 0; j < currentN; j++)
    {
        for (int l = 0; l < currentN; l++){
            num = MIN_COLOR + rand() % MAX_COLOR;
            casosFile << num;
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
        const char *const argx[] = {"10102.exe", nullptr};
        if (execvp("./10102.exe", argx) == -1)
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

    if (argc > 1 && std::string(argv[1]) == "-t")
        csvFile << "," << N2;
    csvFile.close();
    return 0;
}

