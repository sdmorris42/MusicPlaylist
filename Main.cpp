/*
Program: Main.cpp
Author: Summer Morris
Date: 4/30/25
Purpose: Simulate a music player with circular queue. 
*/

#include "Header.h"
using namespace std;

int main()
{    
    int loop;       // Number of times the playlist will loop
    int numSongs;   // Number of songs in the playlist

    //ASCII text
    cout << "\n\n                          __  __           _        ____  _             _ _     _                              " << endl;
    cout << "     |~~~~~~~~~~~~~~~|   |  \\/  |_   _ ___(_) ___  |  _ \\| | __ _ _   _| (_)___| |_        |~~~~~~~~~~~~~~~|   " << endl;
    cout << "     |~~~~~~~~~~~~~~~|   | |\\/| | | | / __| |/ __| | |_) | |/ _` | | | | | / __| __|       |~~~~~~~~~~~~~~~|   " << endl;     
    cout << "     |               |   | |  | | |_| \\__ \\ | (__  |  __/| | (_| | |_| | | \\__ \\ |_        |               |   " << endl; 
    cout << " /~~\\|           /~~\\|   |_|  |_|\\__,_|___/_|\\___| |_|   |_|\\__,_|\\__, |_|_|___/\\__|   /~~\\|           /~~\\|   " << endl;   
    cout << " \\__/            \\__/                                             |___/                \\__/            \\__/   " << endl;

    // Enter how many times the playlist will loop
    cout << "\n\n" << right << setw(35) << " " << left << "Welcome to the music playlist simulator!" << endl << endl << endl;
    cout << right << setw(31) << " " << left << "How many times do you want to loop the playlist?\n";
    cout << right << setw(45) << " " << left << "Enter an integer: ";
    
    cin >> loop;
    while(!cin || loop <= 0) // Validate user input
    {
        cin.clear();	
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Used when a user tries to input a string
        cout << right << setw(45) << " " << left << "Enter an integer: ";
        cin >> loop;
    }

    // Enter how many songs to add to the playlist
    cout << "\n\n" << right << setw(31) << " " << left << "How many songs do you want to add to the playlist?" << endl;
    cout << right << setw(31) << " " << left << "(There is a maximum of 10 songs that can be added)" << endl;
    cout << right << setw(45) << " " << left << "Enter an integer: ";

    cin >> numSongs;
    while(!cin || numSongs <= 0 || numSongs > 10) // Validate user input
    {
        cin.clear();	
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Used when a user tries to input a string
        cout << right << setw(45) << " " << left << "Enter an integer: ";
        cin >> numSongs;
    }

    // Countdown to start playlist
    cout << "\n\n" << right << setw(37) << " " << left << "Playlist will begin in 3...";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " 2...";
    this_thread::sleep_for(chrono::seconds(1));
    cout << " 1!" << endl << endl << endl;
    this_thread::sleep_for(chrono::seconds(1));

    MusicPlayer song(numSongs); // Create a circular queue

    //  Define the songs
    Song song1(1, "Ode to Joy", "Beethoven");
    Song song2(2, "The Four Seasons", "Vivaldi");
    Song song3(3, "Eine kleine Nachtmusik", "Mozart");
    Song song4(4, "Clair de Lune", "Debussy");
    Song song5(5, "The Blue Danube", "Johann Strauss II");
    Song song6(6,"Toccata and Fugue in D minor", "J.S. Bach");
    Song song7(7,"Carmen", "Bizet");
    Song song8(8, "In the Hall of the Mountain King", "Grieg");
    Song song9(9, "Nussun Dorma", "Puccini");
    Song song10(10, "Dance of the Knights", "Prokofiev");

    // Add the songs to the queue
    song.addSong(song1);
    song.addSong(song2);
    song.addSong(song3);
    song.addSong(song4);
    song.addSong(song5);
    song.addSong(song6);
    song.addSong(song7);
    song.addSong(song8);
    song.addSong(song9);
    song.addSong(song10);

    // Simulate a playlist by cycling through the queue
    song.cycleSongs(loop);

    // ASCII text
    cout << "\n\n\n" << right << setw(30) << " " << left << "     _____)                          / " << endl;
    cout << right << setw(30) << " " << left << "   /                /) /)           /              " << endl;
    cout << right << setw(30) << " " << left << "  /   ___   _______(/ (/_      _   /               " << endl;
    cout << right << setw(30) << " " << left << " /     / ) (_)(_)(_(_/_) (_/__(/_ o                " << endl;
    cout << right << setw(30) << " " << left << "(____ /                 .-/                        " << endl;
    cout << right << setw(30) << " " << left << "                       (_/                         " << endl;
    return 0;
}
