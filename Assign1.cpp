// Lia Bogoev 
// CS3100 - Assign 1

#include <iostream>
#include <exception>
#include <iomanip>

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

			if(par < 31 && par > 0){
				for(int i = 1; i <= par; i++){
					e = e + (1/tracker);
					tracker = tracker * i;
				}			
				std::cout << "The value of e to " << par << " iterations is: " << e << "\n";
			}				
			else{ std::cout << "Invalid Range.\n";}

		} // end == "-e"
	 	

		else if(std::string(argv[1]) == "-pi"){
			try{
				par = std::stoi(argv[2]);
			} catch(...){
				std::cout << "Invalid Parameter\n";	
			} // end try catch block 
			
		// calulate pi here (1-10 inclusive)
		  double pi = 0;
			double count;
			for(int i = 1; i < 10000000; i++){
				count = i;
				if(i%2 == 1){
					pi = pi + 4/(2*count - 1);
				}
				else{
					pi = pi - 4/(2*count -1);
				}
		
			} // end for

			switch(par){
					case 1:
						std::cout << "pi: " << std::setprecision(2) << pi << "\n"; 
						break;
					
					case 2: 
						std::cout << "pi: " << std::setprecision(3) << pi << "\n"; 
						break;
					
					case 3: 
						std::cout << "pi: " << std::setprecision(4) << pi << "\n"; 
						break;
					
					case 4: 
						std::cout << "pi: " << std::setprecision(5) << pi << "\n"; 
						break;
					
					case 5: 
						std::cout << "pi: " << std::setprecision(6) << pi << "\n"; 
						break;
					
					case 6:
						std::cout << "pi: " << std::setprecision(7) << pi << "\n"; 
						break;
					
					case 7: 
						std::cout << "pi: " << std::setprecision(8) << pi << "\n"; 
						break;
					
					case 8: 
						std::cout << "pi: " << std::setprecision(9) << pi << "\n"; 
						break;
					
					case 9: 
						std::cout << "pi: " << std::setprecision(10) << pi << "\n"; 
						break;
					
					case 10: 
						std::cout << "pi: " << std::setprecision(11) << pi << "\n"; 
						break;
				
					default:
						std::cout << "Out of range.\n";

			}	
		} // end == "-pi"
		
		//else correct number of inputs but nothing matches:
		else{
			std::cout << "--- Assign1 Help ---\n";
			std::cout << "-fib [n] Compute the fibonacci of [n]\n";
			std::cout << "-e [n]   Compute the value of 'e' using [n] iterations\n";
			std::cout << "-pi [n]  Compute pi to [n] digits\n";
		}
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
