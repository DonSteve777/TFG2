#include <cstring>
#include <numeric>
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <sys/wait.h>
#include <cassert>
using namespace std;
using namespace std::chrono;

enum {CTE, LOGN, N, NLOGN, N2, N3, DOSN };
    // 0   1     2     3    4   5    6