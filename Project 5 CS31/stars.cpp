//
//  stars.cpp
//  CS31 Project 5
//
//  Created by Jonathan Goh on 11/17/17.
//  Copyright © 2017 Jonathan Goh. All rights reserved.
//

#define _CRT_SECURE_NO_DEPRECATE
#include "utilities.h"
#include <iostream>
#include <string>
using namespace std;

/*
const char WORDFILENAME[] = "/Users/jonathangoh/Desktop/smallwords.txt";

int main()
{
    char w[9000][7];
    int n = getWords(w, 9000, WORDFILENAME);
    if (n == 2)
    {
        cout << "getWords successfully found the file and read its two words." << endl;
        cout << "You're ready to start working on Project 5." << endl;
    }
    else if (n == -1)
        cout << "The path to your file of words is probably incorrect" << endl;
    else
        cout << "getWords found the file, but loaded " << n
        << " words instead of 2" << endl;
}
*/

int runOneRound(const char words[][7], int nWords, int wordnum);
bool isWord(string input, int nWords, const char words[][7]);
void data(char scr[], double counts);

int main()
{
    int nRounds;
    double count=0;
    char wordList[9000][7];
    const char WORDFILENAME[] = "/Users/jonathangoh/Desktop/smallwords.txt";
    char scores[9000];
    
    int nWords = getWords(wordList, 9000, WORDFILENAME);
    if(nWords<1)    // makes sure that amount of words is a positive number
    {
        cout << "No words were loaded, so I can't play the game.";
        return -1;
    }
    
    cout << "How many rounds do you want to play? ";
    cin >> nRounds;
    if(nRounds<0)   // makes sure that amount of rounds is positive
    {
        cout << "The number of rounds must be positive.";
        return -1;
    }
    
    for(int i=1; i<=nRounds; i++)   // runs loop for specified number of rounds
    {
        count++;
        cout << "\nRound " << i << endl;
        scores[i-1] = runOneRound(wordList, nWords, randInt(0, nWords-1));
        // scores array filled as each round is played, calls function with random int as 3rd argument
        data(scores, count);
        // summary of round data printed after each ropund is played
    }
    
    
    
    return 0;
}

int runOneRound(const char words[][7], int nWords, int wordnum)
{
    bool answer = false;
    string guess;
    string theWord, copy;
    int score=0;
    int stars=0;
    int planets=0;
    
    if(nWords<0)    // checks that number of words is positive
        return -1;
    if(wordnum>=nWords || wordnum<0)    // checks that array of numbers is positive and less than nWords
        return -1;
    
    theWord = words[wordnum];   // gets secret word
    copy = theWord;
    
    cout << "The secret word is " << theWord.length() << " letters long." << endl;
    //outputs length of secret word
    
    while(answer==false)
    {
        score++;
        cout << "Probe word: ";
        cin >> guess;   // asks for probe word
        
        if(isWord(guess, nWords, words)==true)  // checks that word is part of list of words
        {
            if(guess==theWord)
            {
                if (score==1)   // is answered correctly on first try
                {
                    cout<< "You got it in 1 try.\n";
                    answer = true;
                }
                
                else    // if answered correctly on 2nd try or greater
                {
                    cout << "You got it in " << score << " tries.\n";
                    answer = true;
                }
            }
            
            else    // if guess is not correct
            {
                for(int l=0; l<guess.length(); l++) // loops the length of guess
                {
                    if(guess[l]==theWord[l])    // checks if is a star
                    {
                        stars++;    // increments counter
                        guess[l]='S';   // changes element of string to random capital, won't have equality
                        theWord[l]='T';
                    }
                }
                
                for(int k=0; k<guess.length(); k++)
                {
                    for(int j=0; j<theWord.length(); j++)
                    // for every loop of k, j goes through entire secret word
                    {
                        if(guess[k]==theWord[j])
                        // if any element of guess equals secret word
                        {
                            planets++;  // increment counter
                            theWord[j]='P'; // changes element of string to random capital, won't have equality
                            guess[k]='L';
                        }
                    }
                    theWord = copy; //reverts secret word to original, so that capitals removed
                }

                cout << "Stars: " << stars << ", Planets: " << planets << endl;
                // outputs stars and planets
                planets=0;  //resets counters so that next probe word can be checked
                stars=0;
            }
        }
        
        else
        {
            score--;    // decrement to reverse the default increment if is not a word
            cout << "Your probe word must be a word of 4 to 6 lower case letters.\n";
        }
    }
    
    
    return score;   // returns score
}

bool isWord(string input, int numWords, const char words[][7])
{
    int counter=0;
    
    if(input.length()<4 || input.length()>6)    // checks that word is correct length
    {
        cout << "Your probe word must be a word of 4 to 6 lower case letters.\n";
    }

    for(int j=0; j<numWords; j++)   // loops through entire array
    {
        if (words[j]==input)    // checks that word is in list
            return true;
        else
            counter++;
        
        if(counter==numWords) // if not in list, returns false
            return false;
    }
    return false;   // if has not met any specifications return false
}

void data(char scr[], double counts)
{
    int min=10000, max=-10000;
    double sum=0, avg=0.00;
    
    cout.setf(ios::fixed);  //does not change the number, only changes how the number is displayed
    cout.precision(2);  //2 digits to the right of the decimal point
    
    for(int i=0; i<counts; i++) // loops depending on which round the player is on
    {
        sum+=scr[i];    // adds new score to sum
    }
    
    avg=sum/counts; // calculates average
    
    for(int i=0; i<counts; i++)
    {
        if (scr[i]>max) // checks if a max
            max=scr[i]; // sets max
    }
    
    for(int i=0; i<counts; i++)
    {
        if (scr[i]<min) // checks if a min
            min=scr[i]; // sets min
    }
    
    cout << "Average: " << avg << ", minimum: " << min << ", maximum: " << max << endl;
    // outputs summary of data
}
