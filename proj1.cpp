/**
*File Name: proj1.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.
*Assisted by and Assisted line numbers: N/A
*Your Name: Adrianna MacKenzie
*Your PSU user ID:  ahm5412
*Course title: CMPSC465 Fall 2025
*Due Time: 11:59 pm, Sunday, September 7, 2025
*Time of Last Modification: 2:00 pm, Friday, September 5, 2025

*Description: Determines if a given permutation of train coaches can be achieved using a stack-based station as described in Project 1.
*/


#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // Prompt user for input file path
    string filename;
    cout << "Enter input file path: ";
    getline(cin, filename);

    // Open the input file, or error out if it cannot be opened
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return 1;
    }

    // Process each test case
    while (true)
    {
        // Read the number of coaches
        int N;
        infile >> N;

        // If N is 0, end of input
        if (N == 0) break;

        vector<vector<int>> blocks; // Store all permutations for this N

        // Read all permutations for this N
        while (true)
        {
            // Read the first number of the permutation
            int first;
            infile >> first;
            if (first == 0) break; // End of permutations for this N

            // Read the rest of the permutation
            vector<int> perm(N);
            perm[0] = first;
            for (int i = 1; i < N; ++i) infile >> perm[i];
            blocks.push_back(perm);
        } 

        // Process each permutation
        for (const auto& perm : blocks)
        {
            stack<int> station;
            int next_in = 1, next_out = 0;

            // Pop and push coaches to simulate the station
            while (next_in <= N)
            {
                station.push(next_in);
                while (!station.empty() && station.top() == perm[next_out]) {
                    station.pop();
                    ++next_out;
                }
                ++next_in;
            }

            // Check if all coaches were successfully reordered
            if (station.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
    return 0;
}