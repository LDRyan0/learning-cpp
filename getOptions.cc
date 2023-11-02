// getOpt() is a function included inside <unistd.h> that is a clean way to deal with command line arguments
//		- parameters line -n 20 -f 4 ...
// 		- eg:
//			opt = getopt(argc, argv, "r:c:s:b:h")
// 		- variable called optind stores the index of the next element to be processed
// 		- ":" after an element means that an argument must proceed
//		- argument can be retreived from the optarg variable
// 		- no ":" means that it's a switch, either it's there or it isn't
//		- 
// 		- 
// getOpt_long() 
// 		either -n 20 -f 4 or --number 20 --frequency 4 ...

#include <iostream>
#include <unistd.h>

void showUsage(char* argv[]) { 
	std::cout << "Usage:" << std::endl;
	std::cout << "\t" << argv[0] << " -r <NR_RECEIVES> -c <NR_CHANNELS> -s <NR_SAMPLES> -b <NR_BITS>" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t-r" << std::endl;
  	std::cout << "\t\tnumber of receivers/antennas" << std::endl;
	std::cout << "\t-c" << std::endl;
	std::cout << "\t\tnumber of frequency channels" << std::endl;
	std::cout << "\t-s" << std::endl;
	std::cout << "\t\tnumber of time samples" << std::endl;
	std::cout << "\t-b" << std::endl;
	std::cout << "\t\tnumber of bits" << std::endl;
	std::cout << "\t\tmust be 4, 8 or 16. check Tensor Core precisions available on your machine" << std::endl;

}

int main(int argc, char* argv[]) { 
	std::cout << "COMMAND LINE OPTIONS:" << std::endl;
	for(int i = 1; i < argc; i++) { 
		std::cout << "\t" << i << ": " << argv[i] << std::endl;
	}

	int opt; 

	if(argc==1) {
		showUsage(argv);
		exit(1);
	}

	while ((opt = getopt(argc, argv, "r:c:s:b:h")) != -1) { 
		switch(opt) {
		case 'r':
			std::cout << "Receivers:    " << optarg << std::endl;
			break;
		case 'c':
			std::cout << "Channels:     " << optarg << std::endl;
			break;
		case 's':
			std::cout << "Samples:      " << optarg << std::endl;
			break;
		case 'b':
			std::cout << "Bits:         " << optarg << std::endl;
			break;
		case 'h': 
			showUsage(argv);
			exit(1);
		default: 
			showUsage(argv);
			exit(1);
		}
	}
	
	return 0;
}
