// Lia Bogoev 
// CS3100 - Assign 1

#include <iostream>
#include <exception>
#include <new>

int fibonacci1(int n){
	if (n == 0){return 0;}
	else if (n == 1){return 1;}
	else{return fibonacci1(n-1) + fibonacci1(n-2);}
}

int main(int argc, char* argv[]){
	int par;

	if(argc == 3){
		// correct number of arguments

		if(std::string(argv[1]) == "-fib"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 

		// calculate fibonacci here (0-14 inclusive)
			if(par < 15 && par >= 0){
				std::cout << "The " << par << " fibanacci number is: " << fibonacci1(par) << "\n";
			}
			else { std::cout << "Invalid range.\n";}

		} // end == "-fib"

		else if(std::string(argv[1]) == "-e"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 
		
		// calculate e here (1-100 iterations)
				double tracker = 1;
				float e = 0;

				for(int i = 1; i <= par; i++){
					e = e + (1/tracker);
					tracker = tracker * i;
				}				

				std::cout << "The value of e to " << par << " iterations is: " << e << "\n";

		} // end == "-e"
	 	

		else if(std::string(argv[1]) == "-pi"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 
			
		// calulate pi here (1-10 inclusive)
			long double pi = 3.1415926535;
			switch(par){
					case 1: 
						std::cout << "pi: 3.1"<< "\n";
						break;
					
					case 2: 
						std::cout << "pi: " << printf("%.1f",pi) << "\n";
						break;
					
					case 3: 
						std::cout << "pi: " << printf("%.3f",pi) << "\n";
						break;
					
					case 4: 
						std::cout << "pi: " << printf("%.4f",pi) << "\n";
						break;
					
					case 5: 
						std::cout << "pi: " << printf("%.5f",pi) << "\n";
						break;
					
					case 6:
						std::cout << "pi: " << printf("%.6f",pi) << "\n";
						break;
					
					case 7: 
						std::cout << "pi: " << printf("%.7f",pi) << "\n";
						break;
					
					case 8: 
						std::cout << "pi: " << printf("%.8f",pi) << "\n";
						break;
					
					case 9: 
						std::cout << "pi: " << printf("%.9f",pi) << "\n";
						break;
					
					case 10: 
						std::cout << "pi: " << printf("%.10f",pi) << "\n";
						break;
				
					default:
						std::cout << "Out of range.\n";

			}	
		} // end == "-pi"
	}// end if there are the correct number of inputs

	else{
		// No argument input or incorrect input 
		std::cout << "--- Assign1 Help ---\n";
		std::cout << "-fib [n] Compute the fibonacci of [n]\n";
		std::cout << "-e [n]   Compute the value of 'e' using [n] iterations\n";
		std::cout << "-pi [n]  Compute pi to [n] digits\n";
	} // end else (incorrect number of inputs)


	return 0;
}
