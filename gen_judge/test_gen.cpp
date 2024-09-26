#include <iostream>
#include <fstream>
#include <random>
using namespace std;

#define DEFAULT_NO_TC 10

/*
i.e of running command line 
g++ test_gen.cpp -o judge && ./judge 4
*/

std::string generate_random_binary_string(int n) {
    std::string binary_string;
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister engine for randomness
    std::uniform_int_distribution<> dis(0, 1); // Random number between 0 and 1

    for (int i = 0; i < n; ++i) {
        binary_string += std::to_string(dis(gen)); // Append a random '0' or '1'
    }

    return binary_string;
}

int main(int argc, char* argv[]) {
    int tc = (argc > 1 ? atoi(argv[1]) : DEFAULT_NO_TC);

    srand(time(NULL));
    for (int i=1; i<=tc; i++) {
        ofstream inp("gen.txt");
        if (!inp) {
            std::cerr << "Failed to open file!" << std::endl;
            return EXIT_FAILURE;
        }
        /*
        i.e: Test case format like this
        n m (n, m <= 15)
        a1 a2 a3 ... an (ai <= 1e3)
        b1 b2 b3 ... bm (bi <= 1e3)
        */
        int MIN_N = 6, MAX_N = 100;
        int MIN_A = -1e9, MAX_A = 1e9;
        int MIN_M = 1, MAX_M = 10;
        int MIN_B = 1, MAX_B = 1e3;

        int n = MIN_N + rand() % (MAX_N - MIN_N + 1);
        int t = MIN_M + rand() % (MAX_M - MIN_M + 1);

        inp << n << " " << t << "\n";
        string s = generate_random_binary_string(n);
        inp << s;
        inp << "\n";

        for (int j=1; j<=n; j++) {
            int a_j = MIN_A + rand() % (MAX_A - MIN_A + 1);
            inp << a_j;
            inp << (j == n ? "\n" : " ");
        }

        inp.close();

        // Build run brute forces code
        system("g++ test_brute.cpp -DLOCAL -o brute");
        system("brute");

        // Build run solution code
        system("g++ test_solve.cpp -DLOCAL -o solve");
        system("solve");

        int rs = -1;
        #if defined(_WIN32) || defined(_WIN64)
            rs = system("fc brute.ans solve.ans");
        #elif defined(__linux__)
            rs = system("diff brute.ans solve.ans");
        #else
            std::cerr << "Unknow OS" << std::endl;
        #endif

        if (rs != 0) {
            std::cout << "Test " << i << ": Wrong!" << std::endl;
            return EXIT_FAILURE;
        }else {
            std::cout << "Test " << i << ": Correct!" << std::endl;
        }
    }


    return 0;
}