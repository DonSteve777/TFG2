#include <numeric>
#include <iostream>
#include <chrono>
#include <fstream>
#include <windows.h>	
#include <string>
#include <tchar.h>
#include <iomanip>
//#include <strsafe.h>

using namespace std;
using namespace std::chrono;

#define MAX_DATA_SIZE 1000000000	// entero N (1 ≤ N ≤ 10^9).
#define TIMEOUT 3000			// timeout para que termine un proceso. [milisecs]
#define DATA_INCREMENT 1436870		//	incremento de la N del problema de entrada
#define INITIAL_N 1
/**
 * version con incremento variable del tamanio de los datos. Esa variabilidad ha sido 
 * implementada en la funcion int cmdLIncrease(char* charptrN, int i ) 

 INFO sobre errores en el README

----------------------PENDIENTE-----------------------
* comtemplar ejecucionm infinita del erasmus.exe
*/

//  Creaprocess en windows: https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa?redirectedfrom=MSDN
bool startup( LPCSTR lpApplicationName, LPSTR lpCommandLine)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Start the child process. 
    if( !CreateProcess( lpApplicationName,   // No module name (use command line)
        lpCommandLine,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    ) 
    {
	//	ErrorExit(TEXT("CreateProcess"));
        printf( "CreateProcess failed (%d).\n");
        return false;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );

	return true;
}

/*
**	@param observaciones argv[1]
**	@param inicio n argv[2]

for (0 to num observaciones)
	generar caso tamanio n
		escribir datos en casos.txt
	ejecutar cajasBolas.exe 
	escribir tiempo de ejecucion en el .csv
fin for
*/

int _tmain( int argc, TCHAR *argv[] )
{
	/* to make it easier to switch between Unicode (UTF-16) and their multibyte character set, 
they've defined _tmain which, if Unicode is enabled, is compiled as wmain, and otherwise as main.*/
	int observaciones;
	int currentN = INITIAL_N;
	ofstream file;
	DWORD timeout = TIMEOUT;
 	if( argc != 4 )
    {
        printf("Usage: %s [number of observations] [solution.exe] [input file name, .csv ended] \n\n", argv[0]);
		printf("If your pc has various power modes, we recommend to choose the most powerful one", argv[0]);

        return -1;
    }
	observaciones = atoi(argv[1]);
	file.open(argv[3], std::ios_base::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
	file << "N,seconds\n";

	for (int i = 0; i < observaciones; i++) {
	// 1. generar caso de tamanio n, y escribirlo en casos.txt
		cout << "generador.exe N = " << currentN << "\n";
		char * buffer; 
		sprintf(buffer, "%d", currentN);
		if (!startup("generador.exe", buffer))
        	return -1;
		
	// 2.activar temporizador
		cout << "Return del erasmus.exe: ";
		std::cout << std::fixed << std::setprecision(9) << std::left;
		auto start = high_resolution_clock::now();
		
	// ejecutar algoritmo de entrada
		if (!startup(argv[2], NULL ))
			return -1;
			
		auto end = high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		//auto duration = duration_cast<microseconds>(end - start);
	// 3.rellenar csv con el tiempo de ejecucion y el tamanio de los datos
		cout << "i = " << i + 1 << " | N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
		cout << "--------------------------------------------\n";
		cout << "--------------------------------------------\n";
		file << currentN << "," << diff.count() << '\n';

		currentN  += DATA_INCREMENT;

		if (currentN > MAX_DATA_SIZE ){
            cout << "Maximo tamanio de los datos alcanzado (100 000) \n";
			cout << "Obervaciones: " << i << "\n";
            break;
        }
			
	}
	return 0;
}