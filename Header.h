#ifndef HEADER_H
#define HEADER_H

#include <iostream> // Input and ouput operations
#include <chrono>   // Set timer for playlist simulation
#include <thread>   // Set timer for playlist simulation
#include <iomanip>  // Set width of playlist
#include <limits>   // For user verification
using namespace std;

// Class for songs
class Song 
{
private:
    int songID;             // ID for song
    string songName;        // Name of song
    string artistName;      // Name of artist
public:   
    // Constructor for song class
    Song() : songID(-1), songName("Ode to Joy"), artistName("Beethoven") {}    
    Song(int songID, string songName, string artistName) : songID(songID), songName(songName), artistName(artistName) {} 
    
    // Display current song
    void primaryDisplay()
    {
        cout << right << setw(40) << " " << left << "Track number: " << songID << endl;
        cout << right << setw(40) << " " << left << "Song title: \"" << songName << "\"" << endl;
        cout << right << setw(40) << " " << left << "Artist: " << artistName << endl;
    }
    
    // Display previous and next songs
    void secondaryDisplay() 
    {
        cout << "\"" << songName << "\" by " << artistName << endl;
    } 
};

// Class for circular queue
class CircularQueue 
{
private:
    Song* songs;        // Pointer used store songs
    int maxSongs;       // Maximum number of songs in playlist
    int first;          // Index of the first song
    int last;           // Index of the last song
    int numSongs;       // Number of songs in queue

public:
    CircularQueue(int maxSong);     // Constructor to initialize the playlist
    ~CircularQueue();               // Destructor for the playlist   
    bool isFull();                  // Check if playlist is full
    bool isEmpty();                 // Check if playlist is empty
    void enqueue(Song& song);       // Add song to playlist
    Song front();                   // Used to view next song
    Song rear();                    // Used to view the previous song played
    Song dequeue();                 // Remove song from playlist
    int size()                      // Return the number of songs in the queue
    {                    
        return numSongs;
    }
};

// Class for playlist
class MusicPlayer 
{
private:
    CircularQueue playlist;     // Object used to store the songs in the playlist
public:
    MusicPlayer(int playlistSize) : playlist(playlistSize) {}   // Constructor for playlist
    
    void addSong(Song& song)    // Add song to playlist
    {
        playlist.enqueue(song);
    }
    
    void cycleSongs(int loop)           // Cycle through the songs in the playlist
    {
        int Size = playlist.size();             // Number of songs in playlist
        
        if (playlist.isEmpty())                 // Check if there are songs in the playlist
        {
            cout << "Oops, the playlist is empty! No songs can be played." << endl;
            return;
        }

        for (int i = 0; i < loop*Size; ++i)     // The for loop repeats for the number of songs times the number of times the playlist repeats
        {
            Song previous = playlist.rear();    // Previous song played in playlist
            Song current = playlist.dequeue();  // Current song being played in playlist
            Song next = playlist.front();       // Next song to be played in playlist
            
            cout <<"\n" << right << setw(58) << "~ Now playing ~" << endl;  // Display the current song
            cout << ".-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-~-._.-\n";
            current.primaryDisplay();
            cout << ".-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-.-~-._.-~-._.-~-._.-~-._.-~-._.-\n";

            cout << "\n" << right << setw(30) << " " << left << "<~ Previously played: ";    // Display the previous song
            previous.secondaryDisplay();                 

            cout << "\n" << right << setw(30) << " " << left << "~> Next up: ";              // Display the next song
            next.secondaryDisplay();
            cout << "\n\n";

            playlist.enqueue(current);          // Add song to circular queue

            if ((i + 1) % Size == 0)            // Check if playlist is at end
            {          
                cout << "\n\n" << right << setw(41) << " " << left << "~ Let's go again! ~\n";
            }

            this_thread::sleep_for(chrono::seconds(1)); // Timer to simulate cycling through playlist
        }
    }
};
    
// Constructor to initialize the circular queue for the playlist
CircularQueue::CircularQueue(int maxSong) 
{
    maxSongs = maxSong;
    songs = new Song[maxSongs];
    first = 0;
    last =  -1; 
    numSongs = 0; 
}

// Destructor 
CircularQueue::~CircularQueue() 
{
    delete[] songs;                 // Delete songs array
}

// Check if the circular queue for the playlist is full
bool CircularQueue::isFull() 
{
    return numSongs == maxSongs;    // Full if the current number of songs equal the playlist size
}

// Check if the circular queue for the playlist is empty
bool CircularQueue::isEmpty() 
{
    return numSongs == 0;           // Empty if the number of songs is equal to zero
}

// Add a song to the circular queue for the playlist
void CircularQueue::enqueue(Song& song) 
{
    if (isFull())                   // Check if playlist is full
    {
        return;
    }

    last = (last + 1) % maxSongs;   // Increase playlist
    songs[last] = song;             // Add song to next spot in queue
    numSongs++;                     // Increase the number of songs
    return;
}

// Remove a song from the circular queue for the playlist
Song CircularQueue::dequeue() 
{
    
    if (isEmpty())                  // Check if playlist is empty
    {
        cout << "Oops, the playlist is empty! No songs can be removed." << endl;
        return Song();              // Return the default Song type 
    }

    Song song = songs[first];       // Retrieve first song in playlist
    first = (first + 1) % maxSongs; // Used to cycle through songs 
    numSongs--;                     // Decrease the number of songs in playlist
    return song;                    // Return the song
}

// View the next song to be played in queue
Song CircularQueue::front() 
{  
    if(isEmpty())                   // Check if the playlist is empty
    {
        cout << "No upcoming songs." << endl;
        return Song();
    }
    
    return songs[first];                // Return the next song in the playlist
}

// View previous song played
Song CircularQueue::rear() 
{
    if(isEmpty())                       // Check if the playlist is empty
    {
        cout << "No previous songs." << endl;
        return Song();
    }
    return songs[last];                 // Return the last song played
}

#endif
