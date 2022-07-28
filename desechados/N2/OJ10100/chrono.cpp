
// https://onlinejudge.org/external/101/10100.pdf
// https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/10100%20-%20Longest%20Match.cpp

#include "../../utils.h"

#define MIN_CASOS 1
#define MAX_LINE_LENGTH 1000	
#define OBSERVATIONS 3
#define REPETITIONS 10	

string input1 = "LAS COMPETENCIAS COMUNICATIVAS.";
// 500 words
string input2 = "LAS COMPETENCIAS COMUNICATIVAS. La sociedad como cultura, tiene su origen en la creación y desarrollo del lenguaje, en sus inicios, el ser humano era una especie más que poblaba el planeta. Al comenzar a expresar a sus semejantes sus ideas, se logran varios cambios que se transforman en cultura. El lenguaje da fundamentos para ponernos de acuerdo fortaleciendo estrategias de vida como la recolección y la caza. Al aparecer el lenguaje, trae consigo la idea de establecer tiempos como el pasado, presente y futuro. Esta idea se centra en la necesidad de relacionar lo existente como un presente y al no estar, viene la idea de traerlo al presente, dicho de otra forma, se desarrolla la posibilidad de pensar en lo que ahora no esta presente pero estará. El lenguaje trae en forma inherente al conocimiento que hoy en día se concentra en variadas disciplinas las que a su ves se clasifican y codifican por áreas de competencias, pero no se trata de de la competencia en el sentido de rivalidad, sino, que como un conjunto de saberes, habilidades y actitudes que se aplicaran por el profesional o encargado del área para resolver problemas. De lo antes mencionado, se destacan las competencias, cuyo concepto nos invita a centrarnos en el hablante como un componente que logra tanto producir como interpretar en forma clara y precisa los enunciados adecuados a la situación en que participa a lo largo de su vid, es decir proyectarse como capital huno avanzado sin dejar atrás el camino del perfeccionamiento continuo. En la formación por competencias se deben tener en cuenta tres aspectos fundamentales; el saber, el  saber hacer y el querer hacer. El primero tiene relación con datos, conceptos y procesos vale decir, elementos intangibles, el segundo dice relación al dominio practico de herramientas y equipos que permiten el desarrollo del trabajo cualquiera que este sea, el tercero compete a las actitudes que debe poseer y aplicar el profesional idóneo para la resolución de problemas. Reflexionado acerca de la comunicación, esta se define como el proceso mediante el cual los humanos, gracias al lenguaje, comparten ideas, pensamientos y símbolos con su especie, sin ella, seria imposible la actividad humana. De este modo, la comunicación se hace fundamental en todos sus niveles, es así como surgen distintos tipos de competencias. Competencias comunicativas; se describen como las formas mediante las cuales las personas pueden establecer interrelaciones con otras y con el medio, tomando como base el autoconocimiento. Estas competencias se pueden obtener gracias a la incursión de las personas en la cultura a la que pertenecen, vale decir incursionar en el ambiente familiar, educacional, institucional y natural. Competencias lingüísticas; esta se relaciona con el desarrollo del lenguaje pero no solo se refiere al lenguaje por lo dicho, sino que también por lo pensado, ósea si una persona que hable otro idioma al nuestro, entonces podremos saber lo que nos quiere decir solo por que poseemos la condición de ser humano, vale decir que esta competencia es una";
// 100 words
string input3 = "LAS COMPETENCIAS COMUNICATIVAS. La sociedad como cultura, tiene su origen en la creación y desarrollo del lenguaje, en sus inicios, el ser humano era una especie más que poblaba el planeta. Al comenzar a expresar a sus semejantes sus ideas, se logran varios cambios que se transforman en cultura. El lenguaje da fundamentos para ponernos de acuerdo fortaleciendo estrategias de vida como la recolección y la caza. Al aparecer el lenguaje, trae consigo la idea de establecer tiempos como el pasado, presente y futuro. Esta idea se centra en la necesidad de relacionar lo existente como un presente y al no estar, viene la idea de traerlo al presente, dicho de otra forma, se desarrolla la posibilidad de pensar en lo que ahora no esta presente pero estará. El lenguaje trae en forma inherente al conocimiento que hoy en día se concentra en variadas disciplinas las que a su ves se clasifican y codifican por áreas de competencias, pero no se trata de de la competencia en el sentido de rivalidad, sino, que como un conjunto de saberes, habilidades y actitudes que se aplicaran por el profesional o encargado del área para resolver problemas. De lo antes mencionado, se destacan las competencias, cuyo concepto nos invita a centrarnos en el hablante como un componente que logra tanto producir como interpretar en forma clara y precisa los enunciados adecuados a la situación en que participa a lo largo de su vid, es decir proyectarse como capital huno avanzado sin dejar atrás el camino del perfeccionamiento continuo. En la formación por competencias se deben tener en cuenta tres aspectos fundamentales; el saber, el  saber hacer y el querer hacer. El primero tiene relación con datos, conceptos y procesos vale decir, elementos intangibles, el segundo dice relación al dominio practico de herramientas y equipos que permiten el desarrollo del trabajo cualquiera que este sea, el tercero compete a las actitudes que debe poseer y aplicar el profesional idóneo para la resolución de problemas. Reflexionado acerca de la comunicación, esta se define como el proceso mediante el cual los humanos, gracias al lenguaje, comparten ideas, pensamientos y símbolos con su especie, sin ella, seria imposible la actividad humana. De este modo, la comunicación se hace fundamental en todos sus niveles, es así como surgen distintos tipos de competencias. Competencias comunicativas; se describen como las formas mediante las cuales las personas pueden establecer interrelaciones con otras y con el medio, tomando como base el autoconocimiento. Estas competencias se pueden obtener gracias a la incursión de las personas en la cultura a la que pertenecen, vale decir incursionar en el ambiente familiar, educacional, institucional y natural. Competencias lingüísticas; esta se relaciona con el desarrollo del lenguaje pero no solo se refiere al lenguaje por lo dicho, sino que también por lo pensado, ósea si una persona que hable otro idioma al nuestro, entonces podremos saber lo que nos quiere decir solo por que poseemos la condición de ser humano, vale decir que esta competencia es una condición que nos permite como hablantes, la capacidad de producir signos verbales y en el estricto significado, es el conocimiento y empleo adecuado del código lingüístico que le permiten al individuo crear, reproducir e interpretar un numero infinito de oraciones. Competencia paralinguistica; esta competencia posee estrecha relación con la anterior y surge de la misma entendiéndose como la capacidad del hablante para utilizar de forma adecuada algunos signos no lingüísticos que se generan de la comunicación propia de las personas, las que expresan actitudes relacionadas con el interlocutor y lo que se dice, estableciendo parámetros como declarar, interrogar, intimidar, ordenar, etc. Conforme a lo oral, este tipo de comunicación se manifiesta empleando signos entonacionales como el tono de la voz, el volumen del sonido emitido, el ritmo, o el énfasis de  lo que se pronuncia. Competencia pragmática; es la que se utiliza en forma estratégica en un medio social determinado, esta establece acciones sociales mediante el empleo adecuado de signos lingüísticos utilizados de acuerdo a intenciones según se pretenda con el acto comunicativo como informar, ordenar, interrogar sugerir, etc. Con esta competencia se desarrolla una situación comunicativa basada en la intención. Competencia textual; esta competencia esta dada por la capacidad de  articular e interpretar signos organizados en un marco coherente, denominado texto, en rigor, se trata del manejo de dispositivos para escribir, como la pluma, el lapicero, la maquina de escribir, el computador y otros. Competencia quinésica; esta se manifiesta como capacidad del que expresa conciente o inconciente de entregar la información a través de signos gestuales, siendo el ejemplo mas claro la mímica que utiliza todo el cuerpo para entregar su comunicación al otro,  ósea expresiones faciales, movimientos  corporales y uso de su entorno físico. Estos signos gestuales pueden ser las expresiones propias y aprendidas, tanto originales como convencionales. Competencia proxemica; esta es manifestada por los hablantes como una capacidad de manejar los espacios y las distancias interpersonales dentro de un marco comunicativo. La distancia entre los interlocutores, la opción de tocarse o estar separados poseen significados que serán de mayor o menor importancia de acuerdo con cada cultura. Surgen así los llamados códigos proxemicos que se establecerán conforme a culturas, relaciones sociales, roles, sexo, edad etc. Competencia cronetica; es la competencia que aborda la problemática del tiempo que nos demoremos en responder o cuanto demoramos en decir algo, ocasionalmente se pueden crear problemas por lo que se dice pero también por el tiempo en generar una respuesta a la comunicación, de aquí que se recomienda considerar tiempos prudentes para generar o procesar la información en función del tiempo del otro vale decir es bueno para las relaciones comunicacionales el ser empático ante el o las personas que nos comunican. Finalmente, se puede señalar que las competencias comunicativas, están fundadas en habilidades y actitudes que llevan al profesional por un camino de autocrítica constructiva y mejora continua, sabiendo, sabiendo hacer, queriendo hacer, ligados a las facetas humanas que son el hacer, el sentir y el pensar.";

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

	string observations[OBSERVATIONS] = { input2, input2, input3 };
	int sizeObservations[OBSERVATIONS] = { 3, 500, 1000 };	//1000 max line length

	try{
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

	for (int i = 0; i < 1; i++) {
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operat ions and it already existed, its previous content is deleted and replaced by the new one.
		currentN = sizeObservations[i];
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function
		
		// generating data of current case
		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << observations[i] << "\n";
			casosFile <<  "primero tiene relación con datos" << "\n";
		}
		casosFile.close();
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"10100.exe", nullptr};
			if (execvp("./10100.exe", argx ) == -1)
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
/*
i = 1 | N = 3 | seconds = 0.260538800
--------------------------------------------
--------------------------------------------
N = 500
i = 2 | N = 500 | seconds = 0.027473600
--------------------------------------------
--------------------------------------------
N = 1000
i = 3 | N = 1000 | seconds = 0.124001400
--------------------------------------------
--------------------------------------------
godenvyus@LG-barvaro:/mnt/c/Users/alvar/xXx/ML/r
*/