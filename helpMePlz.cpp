//  1. Sustituid la entrada salida y probad a enviarlo a ver si es Accepted

            // #include <stdio.h>
            #include <iostream>

            long long c, x, y, z;
            // scanf("%lld %lld %lld %lld", &c, &x, &y, &z);
            cin >> c >> x >> y >> z;

            // printf("%02lld %02lld %02lld\n", mn.yy%100, mn.mm, mn.dd);
            cout << pad_zeros( mn.yy%100) << pad_zeros(mn.mm) << pad_zeros(mn.dd) << "\n";





//  2. Codigo que genere un caso, para un N y los escriba en un archiuvo
            std::ofstream csvFile, casosFile;
            casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operat ions and it already existed, its previous content is deleted and replaced by the new one.

            casosFile << N << "\n";
                int num;
                for (int j = 0; j < N; j++) {
                    num = MIN_M + rand() % MAX_M;   // genera numeros aleatoriamente entre MIN_M y MAX_M
                    casosFile << num << "\n";
                }
                casosFile << "\n";





//  3. Rango de la entrada de los datos: de 1 <= N < 1000 por ejemplo

                #define MIN_N 1
                #define MIN_M 1
                #define MAX_N 1000
                #define MAX_M 9999


