#include "Span.hpp"

int main(void) {
  // Deep copy tests
  {
    std::cout << "--------DEEP COPY TESTS--------" << std::endl;
    Span original(5);
    original.addNumber(42);

    std::cout << "Original vector: " << original << std::endl << std::endl;

    std::cout << "Copying and assinging from original vector..." << std::endl;
    Span copy(original);
    Span assigned;
    assigned = original;

    std::cout << "Adding a number to original vector..." << std::endl << std::endl;
    original.addNumber(0);

    std::cout << "Original vector after: " << original << std::endl;
    std::cout << "Copy vector after: " << copy << std::endl;
  }

  // Full vector exceptions and spans
  {
    std::cout << std::endl << "--------FULL VECTOR EXCEPTION TESTS--------" << std::endl;
    Span vector(10);
    for (int i = 0; i < 12; i++) {
		try {
        	vector.addNumber(i);
        	std::cout << "Adding " << i << " to vector..." << std::endl;
		} 
		catch (std::exception &e) {
        	std::cout << e.what() << std::endl;
		}
    }

    std::cout << std::endl << "--------BASIC SPAN TESTS--------" << std::endl;
    std::cout << "Shortest vector: " << vector.shortestSpan() << std::endl;
    std::cout << "Longest vector: " << vector.longestSpan() << std::endl;
  }

  // No span exceptions
  {
    std::cout << std::endl << "--------NO SPAN EXCEPTION TESTS--------" << std::endl;
    Span vector_empty;
    Span vector_size_1(1);
    vector_size_1.addNumber(42);
    try {
		vector_empty.shortestSpan(); 
	}
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl; 
	}
    try {;
		vector_empty.longestSpan(); 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}
    try {
		vector_size_1.shortestSpan(); 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}
    try {
		vector_size_1.longestSpan(); 
	} 
	catch (std::exception &e) {
		std::cout << e.what() << std::endl; 
	}
  }
  
  // Adding vector tests
  {
    std::cout << std::endl << "-----ADDING VECTOR TESTS-----" << std::endl;
    Span vector(200);
    std::vector<int> additional_vector;

    // filling original vector
    for (int i = 0; i < 100; i++) {
    	try {
    		vector.addNumber(i); 
		}
		catch (std::exception &e) {
        	std::cout << e.what() << std::endl; 
		}
    }

	// filling additonal vector
    for (int i = 100; i < 200; i++) {
      additional_vector.push_back(i);
    }

    // adding additional vector to original vector
    try {
		vector.addVector(additional_vector.begin(), additional_vector.end()); 
	}
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
    
    try {
		std::cout << "Shortest span: " << vector.shortestSpan() << std::endl;
		std::cout << "Longest span: " << vector.longestSpan() << std::endl;
		std::cout << "Vector: " << vector << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
  }

  // Big numbers
  {
    std::cout << std::endl << "-----BIG NUMBERS TESTS-----" << std::endl;
    std::vector<int> additional_vector;
    Span vector(10001);

	std::srand(std::time(0)); // initializing randomization
    std::cout << "Adding 10001 numbers to additional vector..." << std::endl;
    for (int i = 0; i < 10001; i++) {
		try {
			additional_vector.push_back(rand());
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
    }
    std::cout << "Adding additional vector to original vector..." << std::endl;
    try {
		vector.addVector(additional_vector.begin(), additional_vector.end());
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
    }
    try {
    	std::cout << "Shortest span: " << vector.shortestSpan() << std::endl;
    	std::cout << "Longest span: " << vector.longestSpan() << std::endl;
    }
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
    }
  }
}