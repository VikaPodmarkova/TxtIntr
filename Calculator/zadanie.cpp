#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main(int argc, char **argv) {
    if(argc == 1) { 
        return 0;
    }
    std::vector<int> numbers; 
    std::string op; 
    int option;
    double sum=0;
    while((option = getopt(argc, argv, "o:")) != -1) { 
        switch(option) {
            case 'o': 
                op = std::string(optarg);
                if(op!="median" && op!="arithmetic"){ 
    				std::cout << "Введено неправильное значение опции"<< "\n";
    				return 0;
    			}else{
                	for(int i=3; i<argc; i++){ 
        				numbers.push_back(atoi(argv[i]));
        			}
        		}
        		  if (numbers.size() < 7 || numbers.size() > 9) {
        std::cerr << "Неверное количество операндов" << std::endl;
        return 1;
    }
        		if (op=="median"){ 
        			std::sort(numbers.begin(), numbers.end());
        			if(numbers.size()%2!=0){
        				std::cout << "Медиана = " << numbers[(numbers.size()-1)/2.0] << "\n";
        			}else{
            			std::cout << "Медиана = "<< (numbers[numbers.size()/2]+numbers[(numbers.size())/2-1])/2.0 << "\n";
        			}
        			return 0;
        		}
        		if(op=="arithmetic"){ 
        			for(uint i=0; i<numbers.size(); i++){
        			sum+=numbers[i];
        			}
            		std::cout << "Среднее арифметическое = "<< sum/numbers.size() << "\n";
        		}
        			return 0;
        }
    }
}
