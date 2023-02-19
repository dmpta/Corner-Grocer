
#include <iostream> 
#include <fstream> 
#include <string> 
#include <map> 
#include <sstream>

using namespace std;

int main()
{
    // Open the input file 
    ifstream fin("CS210_Project_Three_Input_File.txt");

    // Check if file was successfully opened 
    if (!fin)
    {
        cout << "Error opening file" << endl;
        return 0;
    }

    // Map to store words and their frequency 
    map<string, int> words;

    // Read words from the file 
    string word;
    while (fin >> word)
        words[word]++;

    // Create the output file 
    ofstream fout("frequency.dat");

    // Write the words and their frequencies to the file 
    for (auto it = words.begin(); it != words.end(); it++)
        fout << it->first << " " << it->second << endl;

    // Prompt user to choose an option 
    cout << "Choose an option: " << endl;
    cout << "1. Enter a word to find its frequency" << endl;
    cout << "2. Enter a string of words to find their frequency" << endl;
    cout << "3. Enter a string of words to find their frequency and print the results by asterisks" << endl;
    cout << "4. Exit" << endl;

    int option;
    cin >> option;

    if (option == 1)
    {
        // Prompt user to enter a word 
        cout << "Enter a word: ";
        string input;
        cin >> input;

        // Check if the word is present in the file 
        if (words.find(input) == words.end())
            cout << "Word not found" << endl;
        else
            cout << "The word '" << input << "' occurs "
            << words[input] << " times in the file"
            << endl;
    }
    else if (option == 2)
    {
        // Prompt user to enter a string of words 
        cout << "Enter a string of words: ";
        string input;
        cin.ignore();
        getline(cin, input);

        // Create a stringstream from the input string 
        stringstream ss(input);

        // Read words from stringstream 
        string word;
        while (ss >> word)
        {
            // Check if the word is present in the file 
            if (words.find(word) == words.end())
                cout << "The word '" << word << "' is not found"
                << endl;
            else
                cout << "The word '" << word << "' occurs "
                << words[word] << " times in the file"
                << endl;
        }
    }
    else if (option == 3)
    {
        // Prompt user to enter a string of words 
        cout << "Enter a string of words: ";
        string input;
        cin.ignore();
        getline(cin, input);

        // Create a stringstream from the input string 
        stringstream ss(input);

        // Read words from stringstream 
        string word;
        while (ss >> word)
        {
            // Check if the word is present in the file 
            if (words.find(word) == words.end())
                cout << "The word '" << word << "' is not found"
                << endl;
            else
            {
                cout << "The word '" << word << "' occurs "
                    << words[word] << " times in the file: ";
                for (int i = 0; i < words[word]; i++)
                    cout << "*";
                cout << endl;
            }
        }
    }
    return 0;
}





