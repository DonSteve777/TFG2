import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

public class FirstJavaProgram {
  public static void main(String[] args){
    System.out.println("This is my first program in java");

    try
    
  
  }//End of main^

  bool resuelveCaso() {
	int n;	

	cin >> n;
	if (n == 0)
		return 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << erasmus(v, n) << "\n";

	return true;
}

  public void readFile(){
      try{
           File myObj = new File("casos.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
        }
      }
  }
}//End of FirstJavaProgram Class