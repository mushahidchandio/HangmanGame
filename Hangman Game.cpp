#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void saveWrongLetters(string word,char wrongLetters[], int wrongCount) {      
    ofstream fout("MYgame.txt", ios::app); 

    if (!fout) {
        cout << "Error opening file!" << endl;
        return;
    }

	fout<<"\nThe actual word was: " <<word;
    fout << "\n\nWrong Letters: ";
    for (int i = 0; i < wrongCount; i++) {
        fout << wrongLetters[i] << " ";
    }
    fout << "\n--------------------------\n";

    fout.close();
}

void displayHangman(int attempts) {   
    cout << "\n";
    switch(attempts) {                
        case 6:
            cout << "    _______\n";
            cout << "   |       |\n";
            cout << "   O       |\n";
            cout << "  /|\\      |\n";
            cout << "  / \\      |\n";
            cout << "           |\n";
            cout << " 100% Blood|\n";
            cout << " ==========|\n"; 
            break;
        case 5:
            cout << "    _______\n";
            cout << "   |       |\n";
            cout << "   O       |\n";
            cout << "  /|\\      |\n";
            cout << "  / \\      |\n";
            cout << "           |\n";
            cout << "  80% Blood|\n";
            cout << " ==========|\n"; 
            break;
        case 4:
            cout << "    _______\n";
            cout << "   |       |\n";
            cout << "   O       |\n";
            cout << "  /|\\      |\n";
            cout << "  / \\      |\n";
            cout << "           |\n";
            cout << "  60% Blood|\n";
            cout << " ==========|\n"; 
            break;
        case 3:
            cout << "    _______\n";
            cout << "   |       |\n";
            cout << "   O       |\n";
            cout << "  /|\\      |\n";
            cout << "  / \\      |\n";
            cout << "           |\n";
            cout << "  40% Blood|\n";
            cout << " ==========|\n"; 
            break;
        case 2:
            cout << "    _______\n";
            cout << "   |       |\n";
            cout << "   O       |\n";
            cout << "  /|\\      |\n";
            cout << "  / \\      |\n";
            cout << "           |\n";
            cout << "  20% Blood|\n";
            cout << " ==========|\n"; 
            break;
        case 1:
                cout << "    _______           _______\n";
cout << "   |       |         |       |\n";
cout << "   O       |    +    O       |\n";
cout << "  /|\\      |        /|\\      |\n";
cout << "  / \\      |        / \\      |\n";
cout << "           |                 |\n";
cout << " 10% Blood |        10% Blood|\n";
cout << " ==========|       ==========|\n";
cout<<"***********************************************************\n";
cout<<"|A femal partner saved her male partner by sharing blood! |\n";
cout<<"***********************************************************\n";
            break;
        case 0:
                 cout << "    _______           _______\n";
cout << "   |       |         |       |\n";
cout << "   O       |    +    O       |\n";
cout << "  /|\\      |        /|\\      |\n";
cout << "  / \\      |        / \\      |\n";
cout << "           |                 |\n";
cout << " 0% Blood |        0% Blood|\n";
cout << " ==========|       ==========|\n";
cout<<"**************************************************************\n";
cout<<"|Both partners died but were together till the end! 	Wow! |\n";
cout<<"**************************************************************\n";
            break;
    }
}

void displayWord(char guess[], int length) {
    for(int i=0; i<length; i++)
        cout << guess[i] << " ";
    cout << endl;
}

bool checkLetter(string word, char guess[], char letter) {
    bool found = false;
    for(int i=0; i<word.length(); i++) {
        if(word[i] == letter && guess[i] == '_') {  
            guess[i] = letter;
            found = true;
        }
    }
    return found;
}

int main(){
	cout<<"\n=======================================================\n";
	cout<<"\t\tHANGMAN: THE GAME!\n";
	cout<<"*******************************************************\n";
	cout<<"Instructions: Save your Partner from being hanged by guessing the letters in the codeword.\n";
	
	string word;
	cout<<"Enter the word to guess then we will hide it that player 2 do not see it!\n";
	cin>>word;
	
	for(int i=0; i<word.length(); i++){
        if(word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;   
}

system("CLS");      

int length = word.length();
    char guess[length];
    for(int i=0; i<length; i++){
    	guess[i] = '_';                
	}
        
        int attempts;         
    char letter;
    char wrongLetters[26];      
    int wrongCount = 0;
    int difficulty;
    
    cout << "\nChoose difficulty level:\n";
    cout << "1. Easy (8 attempts) \n";
    cout << "2. Medium (6 attempts) \n";
    cout << "3. Hard (4 attempts) \n";
    cout << "4. Extremely Hard (2 attempts) \n";
    cout << "Enter your choice according to your level from 1 to 4. \n";
    cin >> difficulty;
    
    if (difficulty == 1) {
        attempts = 8;
    } else if (difficulty == 2) {
        attempts = 6;
    } else if (difficulty == 3) {
        attempts = 4;
    } else {
        cout << "Invalid choice. Setting default attempts to 6.\n";
        attempts = 6;
    }

    cout << "You have " << attempts << " attempts. Good luck!\n";
	
	cout << "Player 2, start guessing the word!\n";     
	
	while(attempts > 0) {
        cout << "\nWord: ";
        displayWord(guess, length);     

        displayHangman(attempts);         

        cout << "\nEnter a letter: ";
        cin >> letter;
        if(letter >= 'A' && letter <= 'Z') {
		letter += 32;
}
        if(checkLetter(word, guess, letter)) {   
            cout << "Good job! Letter found.\n";
        } else {
            cout << "Wrong guess!\n";         
            wrongLetters[wrongCount++] = letter;
            attempts--;
        }
        
        if(wrongCount > 0) {
            cout << "Wrong letters: ";        
            for(int i=0; i<wrongCount; i++){
                cout << wrongLetters[i] << " ";
            }
            cout << endl;
        }

        bool complete = true;            
        for(int i=0; i<length; i++) {
            if(guess[i] == '_') {        
                complete = false;
                break;
            }
        }
        if(complete) {       
            cout << "\n Congratulations! You guessed the word: " << word << " \n";
            break;
        }
    }

    if(attempts == 0) {         
        displayHangman(attempts);
        cout<<"\nYou are uneducated and you guess all wrong letters!";
        cout<<"\nThe person and his pertner are died and you did not save him!";
        cout << "\n Game Over! The word was: " << word << " \n";
    }
	saveWrongLetters(word,wrongLetters, wrongCount);         
	
	return 0;
}
