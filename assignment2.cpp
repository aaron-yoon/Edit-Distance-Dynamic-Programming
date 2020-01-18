/*

    * Aaron Yoon
    * 891365199

    *** How to compile and run the program ***
        ** I use mac OSX terminal **

    1) Change directory to where the .cpp file is located

    2) Compile the assignment2.cpp file in the terminal 
            > Using the following command: g++ -o output assignment2.cpp

    3) Put the output file that was created into the terminal to run the program

*/

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;


void grabString(string &fWord, string &sWord){

    cout << endl;
    cout << "Edit Distance Demonstration!" << endl;
    cout << "Please input two words for the edit distance... " << endl;

    cout << "First word: ";
    cin >> fWord;

    cout << "Second word: ";
    cin >> sWord;
    cout << endl;
    return;
}

void printGrid(string &fWord, string &sWord){

    //      fWord = (rows) vertical        sWord = (columns) horizontal

    int counter = 0;
    int editDistance;
    int grid[fWord.length()+2][sWord.length()+2];
    int path[30];
    int pathindex=0;

    char character;

    string s1[fWord.length()+2];
    string s2[sWord.length()+2];

    cout << "The matrix: " << endl;
    //cout << "row: " << fWord.length() << endl;
    //cout << "column: " << sWord.length() << endl << endl;

    /* These values will always be empty and prevents the computer from creating random junk values */

    s1[0] = ' ';
    s1[1] = ' ';
    s2[0] = '-';
    s2[1] = ' ';

    //characters of first word into 1st column
    for (int a = 0; a < fWord.length(); a++){
        s1[a+1] = fWord[a];
    }
    //puts characters of second word into 1st row
    for (int b = 0; b < sWord.length(); b++){
        s2[b+2] = sWord[b];
    }

    //prints the top row
    for (int c = 0; c  < sWord.length()+2; c++){
        cout << setw(3) << s2[c] << "   " << setw(6);
    }
    cout << endl;
       
    /*  Create the grid here    */
    // i = rows     j = columns

    for(int i = 0; i < fWord.length()+1; i++){    
        
        /* To print a --- line to look better*/

         for(int p = 0; p < sWord.length(); p++){
            cout << "--------";
        }
        cout << endl;

        if(i == 0){
            for(int j = 0; j < sWord.length()+2; j++){                 
                if(j==0){
                    grid[i][j] = j;
                    cout << setw(3) << ' ' << "  |  " << setw(6);
                }
                else{
                    grid[i][j] = j-1;
                    cout << setw(3) << grid[i][j] << " : " << setw(6);
                }
            }
        }
        // starts at i=1
        else{
            for(int j = 0; j < sWord.length()+2; j++){                 
                if(j==0){
                    cout << setw(3) << s1[counter] << "  |  " << setw(6);
                }
                else if (j==1){
                    grid[i][j] = counter;
                    cout << setw(3) << grid[i][j] << " : " << setw(6);
                }
                else{  
                    
                    /* starts filling in the graph */ 
                    
                    //if the strings are the same 
                    if(s2[j] == s1[i]){
                        // if the characters are the same then take the top left corner 
                        grid[i][j] = grid[i-1][j-1];
                        cout << setw(3) << grid[i-1][j-1] << " : " << setw(6);
                    } 
                    else {
                        // compare the left, corner, and on top and +1 to the lowest number

                        // if the left side is the smallest
                        if(grid[i][j-1] < grid[i-1][j-1] && grid[i][j-1] < grid [i-1][j]){
                            grid[i][j] = grid[i][j-1]+1;
                            cout << setw(3) << grid[i][j] << " : " << setw(6);
                        }
                        // if the left corner is the smallest
                        else if(grid[i-1][j-1] < grid[i][j-1] && grid[i-1][j-1] < grid [i-1][j]){
                            grid[i][j] = grid[i-1][j-1]+1;
                            cout << setw(3) << grid[i][j] << " : " << setw(6);
                        }
                        // if the top is the smallest
                        else if (grid [i-1][j] < grid[i][j-1] && grid [i-1][j] < grid[i-1][j-1]){
                            grid[i][j] = grid[i-1][j]+1;
                            cout << setw(3) << grid[i][j] << " : " << setw(6);
                        }
                        //if there are multiple small numbers
                        else if(grid[i][j-1] == grid[i-1][j-1] || grid[i][j-1] == grid[i-1][j] || grid[i-1][j-1] == grid[i-1][j]){
                            
                            //  **** this is likely where any error will occur ****

                            //adds from left
                            if(grid[i][j-1] == grid[i-1][j-1] && grid[i][j-1] < grid[i-1][j]){
                                grid[i][j] = grid[i][j-1]+1;
                                cout << setw(3) << grid[i][j] << " : " << setw(6);
                            }
                            //adds from left
                            else if(grid[i][j-1] == grid[i-1][j] && grid[i][j-1] < grid[i-1][j-1]){
                                grid[i][j] = grid[i][j-1]+1;
                                cout << setw(3) << grid[i][j] << " : " << setw(6);
                            }
                            //adds from diagonal
                            else if (grid[i-1][j-1] == grid[i-1][j] && grid[i-1][j-1] < grid[i][j-1]){
                                grid[i][j] = grid[i-1][j-1]+1;
                                cout << setw(3) << grid[i][j] << " : " << setw(6);
                            }
                            //adds from left
                            else if (grid[i][j-1] == grid[i-1][j-1] == grid[i-1][j]){
                                grid[i][j] = grid[i][j-1]+1;
                                cout << setw(3) << grid[i][j] << " : " << setw(6);
                            }
                            //add from left
                            else if (grid[i-1][j] == grid[i-1][j-1] && grid[i-1][j] == grid[i][j-1] && grid[i][j-1] == grid[i-1][j-1]){
                                grid[i][j] = grid[i][j-1]+1;
                                cout << setw(3) << grid[i][j] << " : " << setw(6);
                            }
                            else{
                                cout << endl << endl << "error 1" << endl << endl;
                            }
                        }
                        else {
                            cout << endl << endl << "error 2" << endl << endl;
                        }
                    }
                }
            }
        }
        counter++;
        cout << endl;
    }
   editDistance = grid[fWord.length()][sWord.length()+1];

    cout << endl << "The edit distance is: " << editDistance << endl << endl;
    cout << "Alignment is: " << endl;
    
    /* 
        Have to get the alignment correct
        Need to backtrace to the starting point

        1 = horizontal
        2 = diagonal 
        3 = vertical
     */

    int length;

    if(fWord.length() != sWord.length()){
        if(fWord.length() < sWord.length()){

            length = sWord.length() - fWord.length();
             cout << fWord;
            for (int i = 0; i < length; i++){
                cout << "_";
            }
           cout << endl << sWord << endl;
        }
        // if the first word is larger than the second word
        else if ((fWord.length() > sWord.length())){
            length = fWord.length() - sWord.length();

            cout << fWord << endl << sWord;
            for (int i = 0; i < length; i++){
                cout << "_";
            }
        }
    }
    else{
        cout << fWord << endl << sWord << endl;
    }
}

int main(){

    string fWord, sWord;

    grabString(fWord, sWord);
    printGrid(fWord, sWord);

    cout << endl << endl;
    cout << "============== Project Completed ==============" << endl << endl;

    return 0;
}