//name: Isaias Cruz
//date: 12/01/2022
//description: Final exam #3

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "input.h"


using namespace std;
int menuOption();
void randomWord(string& puzzle);
void play(string puzzle);






// This is the main function.
int main()          
{

    string puzzle = "unknown";
    do
    {
      //Input what to do with program
        system("cls");

        //calling menu function
        char option = menuOption();
        
        //X for exit program
        if (option == 'X')
            exit(0);
        
        
        if (option == 'R')// Choose Random WORD

            do
            {
                       
                randomWord(puzzle);


                break;
            } while (true);

            if (option == 'S')// solve puzzle
            {
                if (puzzle == "unknown")//making sure file was read from text
                {
                    cout << "Please do R option first\n";
                    system("pause");

                }

                else

                    // input play function AFTER random word is chosen
                    play(puzzle);



            }



    } while (true);
    return EXIT_SUCCESS;



}

//This is the main menu function
int menuOption()
{

    //menu function

    cout << "                           . ?                       ? .\n";
    cout << "                       .????.           ???          .????.\n";
    cout << "                    .????.           ?????????           .????.\n";
    cout << "                 .????.            ???       ???            .????.\n";
    cout << "              .????.              ????       ????              .????.\n";
    cout << "           .????.                  ??        ???                 .????.\n";
    cout << "         .????.                             ????                     .????.\n";
    cout << "     .????.                              ???                            .????.\n";
    cout << "        .????.                          ???                          .????.\n";
    cout << "           .????.                       ???                       .????.\n";
    cout << "              .????.                    ???                    .????.\n";
    cout << "                 .????.                 ???                 .????.\n";
    cout << "                    .????.                                .????.\n";
    cout << "                       .????.           ???           .????.\n";
    cout << "                           .?           ???           ?.\n\n";

    cout << "                                   What are you?\n";

    cout << "\tCMPR120 Exam 3A: C - string array or string object by Isaias Cruz (12-6-2022)\n";
    cout << "\t" + string(60, char(205));
    cout << "\n\t\tR.Randomly choose a word from the PUZZLES.TXT file\n";
    cout << "\t\tS.Solve Implementation";
    cout << "\n\t" + string(60, char(196));
    cout << "\n\t\tX.Exit the program";
    cout << "\n\t" + string(60, char(205));
    // ONLY accept r s x as options
    return  inputChar("\n\t\tOption: ", static_cast<string>("RSX"));
  



}

//This is the getting the random word from text file function
void randomWord(string& puzzle)
{
    srand(time(0));
    system("cls");
    //input file name
    string filename = inputString("\n\tEnter the file name (PUZZLES.TXT): ", true);
    ifstream infile;
    //process file name
    infile.open(filename);
    // if file is not found make sure to show it as non existent
    if (infile.fail())
    {
        cout << "\n\tERROR: " << filename << " does not exist. Try another file.\n";
        system("pause");
        return;
    }
    vector<string> array;
    string value;
    while (infile >> value)
    {
        array.push_back(value);
    }
    //getting the random word
    puzzle = array[rand() % array.size()];

    //make sure to close file after done processing
    infile.close();

    cout << "\n\tAn 'item' has been randomly chosen from the file, " << filename <<".\n";

    system("pause");


}



//This is the counting vowels function
int countVowels(string str)
{
    //counting vowels function
    int count = 0;

    for (int i = 0; i < str.length(); i++)
        switch (tolower(str[i]))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            count++;
        }
    return count;
}



// This is the counting consonants function
int countConsonant(string str)
{
    //counting consonants function
    int count = 0;

    for (int i = 0; i < str.length(); i++)
        if (isalpha(str[i]))
            switch (tolower(str[i]))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                count++;
            }
    return count;
}

//This is the counting digits function
int countDigits(string str)
{
    //counting digit function
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    
        switch ((str[i]))
        {
        case '1': 
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            count++;
        }
    return count++;
}


//This is the counting spaces function
int countSpaces(string str)
{
   
    //counting space function

    int i;
    int space = 0;
    (str);
    for (i = 0; i <= str[i]; i++) {
        if (str[i] == ' ') {
            space++;
        }
    }
   
    return space++;
}


//This is the counting punctuation funciton
int countPunctuation(string str)
{
    //counting digit function

    int count = 0;

    for (int i = 0; i < str.size(); i++)

        switch ((str[i]))
        {
        case '?':
        case '.':
        case ',':
        case ':':
        case '-':
        case '!':
            count++;
        }
    return count++;



}
    

//This is the main playing the game function AFTER word is gotten from file
void play(string puzzle)
{
    std::transform(puzzle.begin(), puzzle.end(), puzzle.begin(), ::toupper);
    string temp = string(puzzle.length(), '?');
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    system("cls");

    do
    {
        //Display menu and options
        system("cls");
        cout << "\n\tEASY level";
        //Display the puzzle as it is being solved
        cout << "\n\n\tPuzzle: " << temp << '\n';
        //Display aplhabet as it is being worked through
        cout << "\n\tHint: " << alphabet << "\n";
        cout << "\n\t\tGame Menu Options (String object Implementation)";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t1. Request Consant ";
        cout << "\n\t\t2. Request Vowel ";
        cout << "\n\t\t3. Solve Puzzle ";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t0. Return ";
        cout << "\n\t" + string(60, char(205));
        //Getitng input from user
        int option = inputInteger("\n\t\tOption:", 0, 3);

        if (option == 1)//consonant guess
        {
            //ask for which letter is guessed 
            char letter = inputChar("\n\t<?> Choose a consanant: ", static_cast<string>(("BCDFGHJKLMNPQRSTUVWXYZ")));
            
            //Check if it is part of puzzle

            for (int i = 0; i < puzzle.length(); i++)
                if (toupper(letter) == toupper(puzzle[i]))
                    temp[i] = letter;
            // Make sure to display if guess is part of puzzle or not
            do 
            {
                for (int i = 0; i < puzzle.length(); i++)
                    if (toupper(letter) == toupper(puzzle[i]))
                cout << "\n\t<?> The consant " << letter << " is found in the puzzle\n";
                break;
            } while (true);
                  
            //process for removing from future guesses
            for (int i = 0; i < alphabet.length(); i++)
                if (toupper(letter) == toupper(alphabet[i]))
                    alphabet[i] = ' ';
                else
                    continue;

            system("pause");
            
        }

        if (option == 2)// syllable guess
        {
            //ask for which letter is guessed 

            char letter = inputChar("\n\t<?> Choose a syllable: ", static_cast<string>(("AEIOU")));
            //Check if it is part of puzzle
            for (int i = 0; i < puzzle.length(); i++)
                if (toupper(letter) == toupper(puzzle[i]))
                    temp[i] = letter;
            // Make sure to display if guess is part of puzzle or not

             for (int i = 0; i < puzzle.length(); i++)
           
                 do
                 {
                     if (toupper(letter) == toupper(puzzle[i]))
                   cout << "\n\t<?> The syllable " << letter << " is found in the puzzle\n";
                break;
            } while (true);

            //process for removing from future guesses

            for (int i = 0; i < alphabet.length(); i++)
                if (toupper(letter) == toupper(alphabet[i]))
                    alphabet[i] = ' ';
                else
                    continue;
            system("pause");
        }





        if (option == 3)// Guess the entire word
        {
            //Input the answer
                string answer;
                cout << "\n\t<?> Your answer: ";
                cin >> answer;
                std::transform(answer.begin(), answer.end(),
                    answer.begin(), ::toupper);
                //Process the answer
                if (answer == puzzle)
                {
                    //Outout the answer and call functions for more data on puzzle
                    cout << "\n\t<?> Correct! You did well. Here are some facts about the puzzle.\n";
                    cout << "\n\tStatistics of the puzzle "     << puzzle << '\n';
                    cout << "\n\t" + string(60, char(196));
                    cout << "\n\tLength of the puzzle        : " << puzzle.length() << '\n';
                    cout << "\tNumber of vowel(s)            : " << countVowels(puzzle) << '\n';
                    cout << "\tNumber of consonant(s)        : " << countConsonant(puzzle) << '\n';
                    cout << "\tNumber of letter(s)           : " << countConsonant(puzzle) + countVowels(puzzle) << '\n';
                    cout << "\tNumber of space(s)            : " << countSpaces(puzzle) << '\n';
                    cout << "\tNumber of digit(s)            : " << countDigits(puzzle) << '\n';
                    cout << "\tNumber of punctuation(s)      : " << countPunctuation(puzzle) << '\n';
                    cout << "\tNumber of other character(s)  : 0\n";


                    system("pause");
                    return;
                }
                else
                {//if guess is wrong start loop for guessing again
                    cout << "\nTry again.\n";
                    system("pause");
                    continue;
                }
            
        }








    } while (true);
}