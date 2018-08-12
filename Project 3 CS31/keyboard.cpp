//
//  keyboard.cpp
//  keyboard
//
//  Created by Jonathan Goh on 10/23/17.
//  Copyright © 2017 Jonathan Goh. All rights reserved.
//

#include <iostream>
using namespace std;

char encodeNote(int octave, char noteLetter, char accidentalSign);
bool hasCorrectSyntax(string song);
int encodeSong(string song, string& instructions, int& badBeat);
string finalSong;

int main() //Asks for input
{
    string input;
    for (;;)
    {
        cerr << "Enter song or enter \"quit\" to terminate: ";
        getline(cin, input);
        if (input == "quit")
            break;
        
        cerr << "hasCorrectSyntax returns ";
        
        if (hasCorrectSyntax(input)) //returns if song string hasCorrectSyntax
            cout << "true" << endl;
        else
            cout << "false" << endl;
        
        string instr = "";
        int bb = 0;
        
        cerr<< encodeSong(input, instr , bb)<<endl<<"----------\n\n"; //Outputs encoded song
    }
}

bool isCorrectChar(char c) //Checks for correct characters
{
    if (c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F'||c=='G')
        return true;
    else
        return false;
}

bool isCorrectAcc(char c) //Checks for correct accidentals
{
    if (c=='#'||c=='b')
        return true;
    else
        return false;
}

bool isCorrectNum(char c) //Checks for correct numbers
{
    if (c=='2'||c=='3'||c=='4'||c=='5')
        return true;
    else
        return false;
}

bool hasCorrectSyntax(string song) //Checks for correct syntax
{
    for(int i=0; i<song.size(); i++)
    {
        if (song[i]==0)
            return true;
        else if(isCorrectChar(song[0]) && isCorrectAcc(song[1]) && isCorrectNum(song[2]))
        {
            song=song.substr(3,song.size()-3); //if ordered char, acc, num
            i=0;
        }
        
        else if(isCorrectChar(song[0]) && isCorrectAcc(song[1]))
        {
            song=song.substr(2, song.size()-2); //if ordered char, acc
            i=0;
        }
        
        else if(isCorrectChar(song[0]) && isCorrectNum(song[1]))
        {
            song=song.substr(2, song.size()-2); //if ordered char, num
            i=0;
        }
        
        else if(isCorrectChar(song[0]))
        {
            song=song.substr(1, song.size()-1); //if ordered char
            i=0;
        }
        
        else if(song[0]=='/')
        {
            song=song.substr(1, song.size()-1); //if has slash
            i=0;
        }
        
        else
            return false; //if does not meet criteria
    }
    if (song[song.size()-1]=='/' || song.size()==0)
        return true; //if ends with slash
    else
        return false;
}


int encodeSong(string song, string& instructions, int& badBeat)
{
    int beat = 1;
    int o;
    char c;
    int instCount=0;
    string temp = "";
    
    
    if(hasCorrectSyntax(song)==true)
    {
        for(int j=0; j<song.size(); j++) //loops for the number of characters in the song
        {
            if(song[0]=='B' && song[1]=='#' && song[2]=='1') //Checks for special case
            {
                instCount++;
                temp+= encodeNote(1,song[0],song[1]); //encodes note
                song = song.substr(3,song.size()-3);
                j=0;
            }
            
            else if(song[0]=='C' && song[1]=='b' && song[2]=='6') //Checks for special case
            {
                instCount++;
                temp+= encodeNote(6,song[0],song[1]); //encodes note
                song = song.substr(3,song.size()-3);
                j=0;
            }
            
            else if(song[0]=='C' && song[1]=='6') //Checks for special case
            {
                instCount++;
                temp+= encodeNote(6,song[0],' '); //encodes note
                song = song.substr(2,song.size()-2);
                j=0;
            }
            
            else if(isCorrectChar(song[0]) && isCorrectAcc(song[1]) && isCorrectNum(song[2]))
            { //checks order of note
                instCount++;
                c = song[2];
                o = c-'0';
                temp+= encodeNote(o,song[0],song[1]); //encodes note
                song = song.substr(3,song.size()-3);
                j=0;
            }
            
            else if(isCorrectChar(song[0]) && isCorrectAcc(song[1]))
            {//checks order of note
                instCount++;
                temp+= encodeNote(4,song[0],song[1]); //encodes note
                song = song.substr(2, song.size()-2);
                j=0;
            }
            
            else if(isCorrectChar(song[0]) && isCorrectNum(song[1]))
            {//checks order of note
                instCount++;
                c = song[1];
                o = c-'0';
                temp+= encodeNote(o,song[0],' '); //encodes note
                song = song.substr(2, song.size()-2);
                j=0;
            }
            
            else if(isCorrectChar(song[0]))
            {//checks order of note
                instCount++;
                temp+= encodeNote(4,song[0],' '); //encodes note
                song = song.substr(1, song.size()-1);
                j=0;
            }
            
            
            
            else
            { //if does not meet song string criteria, outputs badBeat and returns 2
                badBeat=beat;
                return 2;
            }
            
            
            
            if(song[0]=='/' && song[1]=='/') //checks for double slashes
            {
                if(instCount>1) //checks if note is part of a chord, if yes, then adds brackets
                {
                    beat++;
                    instCount=0; //clears  counter
                    instructions+= '[';
                    instructions+= temp; //notes temporarily held in local variable to check if chord, are added to instructions
                    instructions+= ']';
                    instructions+= ' '; //adds space
                    song = song.substr(2, song.size()-2);
                    j=0;
                    temp=""; //local variable cleared
                }
                else //not part of cord does not add brackets
                {
                    beat++;
                    instCount=0; //clears  counter
                    temp += ' ';
                    instructions += temp;
                    song = song.substr(2, song.size()-2);
                    j=0;
                    temp=""; //local variable cleared
                }
            }
            
            else if(song[0]=='/')
            {
                if(instCount>1)
                {
                    beat++;
                    instCount=0; //clears  counter
                    instructions+= '[';
                    instructions+= temp; //notes temporarily held in local variable to check if chord, are added to instructions
                    instructions+= ']';
                    song = song.substr(1, song.size()-1);
                    j=0;
                    temp=""; //local variable cleared
                }
                else //if song string is incorrect at certain beat
                {
                    beat++;
                    instCount=0; //clears  counter
                    instructions += temp; //notes temporarily held in local variable to check if chord, are added to instructions
                    song = song.substr(1, song.size()-1);
                    j=0;
                    temp=""; //local variable cleared
                }
            }
        }
    }
    
    if (hasCorrectSyntax(song)==true) //if song playable, returns encoded song and 0
    {
        cerr << instructions << endl;
        return 0;
    }
    else //if song not playable, returns 1
        return 1;
}



char encodeNote(int octave, char noteLetter, char accidentalSign)
{
    // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
        << octave << endl;
    }
    
    // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
    //      to -1, 0,   1,   2,   3, ...,  11, 12
    
    int note;
    switch (noteLetter)
    {
        case 'C':  note =  0; break;
        case 'D':  note =  2; break;
        case 'E':  note =  4; break;
        case 'F':  note =  5; break;
        case 'G':  note =  7; break;
        case 'A':  note =  9; break;
        case 'B':  note = 11; break;
        default:   return ' ';
    }
    switch (accidentalSign)
    {
        case '#':  note++; break;
        case 'b':  note--; break;
        case ' ':  break;
        default:   return ' ';
    }
    
    // Convert ..., A#1, B1, C2, C#2, D2, ... to
    //         ..., -2,  -1, 0,   1,  2, ...
    
    int sequenceNumber = 12 * (octave - 2) + note;
    
    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}
