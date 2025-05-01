# MusicPlaylist
This project is the Honors Project for CSC 1310 Data Structures and Algorithms.
This project uses circular queue to simulate a music playlist. 
Queues are used in programming when the first element 
inserted into a list needs to be the first element out (FIFO). 
Circular queues are queues in which the last element of the 
queue is connected to the first element of the queue. This 
essentially creates a circle. Some real life examples in which 
queues might be used include printers, playlists, appointments, 
or work orders. Overall, queues are necessary for many real life 
applications.

The program was made using C++ on VS Studio Code. The 
program consists of a .cpp file called Main, and a header file 
called Header. The header file includes the classes and functions 
needed to implement the circular queue. The program includes 
a Song, CircularQueue, and MusicPlayer class, along with a 
primaryDisplay, secondaryDisplay, size, addSong, cycleSongs, 
circularQueue constructor and destructor, isFull, isEmpty, 
enqueue, dequeue, front, and rear functions. These classes and 
functions will be discussed later. The header file uses the 
namespace directive, and includes the iostream, chrono, thread, 
iomanip, and limits libraries. The iostream library is used for the 
input and output operations such as cin and cout. The chrono and 
thread libraries are used to set a timer for each song in order to 
better simulate music playing in a playlist. The iomanip 
library is used to manipulate the output of the program, while 
the limits library is used to verify the user’s input.

The Song class is used to store the data types for each song. 
The private members include an integer called songID that holds 
the number of the song, a string called songName that holds the 
name of the song, and a string called artistName that holds the 
name of the artist. The public members of the song class includes 
a constructor that initializes the public members and the 
primaryDisplay and secondaryDisplay functions. The 
primaryDisplay function is used to display the current song 
being played. The secondaryDisplay 
function is used to display the previous and next songs being 
played.  

  The CircularQueue class is used to store the songs in an array 
and store the functions used to implement the circular queue. 
The private member contains the integers for the maximum 
number of songs, the index of the first song in the queue, the 
index of the last song in the queue, and the number of songs 
currently in the queue. The private member also includes a 
pointer that is used to store the memory address of the songs. 
The public member includes the constructor, destructor, isFull, 
isEmpty, enqueue, front, rear, dequeue, and size functions for 
the circular queue. 

  The Size function just returns the number of songs that are 
currently in the playlist, which is important for the cycleSong 
function. The constructor initializes the integers and creates a 
new song array that will hold the maximum number of songs in 
the playlist. It does this by passing the integer of the maximum 
number of songs to the constructor and dynamically allocating a 
new song array equivalent in size to the maximum number of 
songs. The destructor deletes the dynamically allocated song 
array. The isFull function is a Boolean function that returns true 
if and only if the current number of songs in the playlist is 
equivalent to the maximum number songs in the playlist. 
Likewise, the isEmpty function is a Boolean function that 
returns true if the number of songs in the playlist is equivalent 
to zero. The enqueue function is used to add songs to the circular 
queue and passes the memory address of the songs. The function 
works by using an if statement to call the isFull function to check 
if the circular queue is full. If the queue is not full, the index of 
the last song will increase, the song array will add the new song, 
and the number of songs will increase by one. The dequeue 
function is used to remove a song from the circular queue. The 
function works by using an if statement to call the isEmpty 
function to check if the playlist is empty. If the queue is not 
empty, the function will retrieve the first song in the song array, 
change the first integer to the next song in the array, decrease the 
current number of songs in the circular queue, and return the 
song that was dequeued. The front function will return the next 
song to be played in the music playlist. The function 
accomplishes this by using an if statement to call the isEmpty 
function to check if the circular queue is empty before returning 
the first song in the songs array. The rear function is just like the 
front function, except it returns the last song in the circular 
queue. The rear function is used to view the previous song 
played.  

  The last class is the MusicPlayer class, which is used to 
implement the music playlist. The private member includes an 
CircularQueue object called playlist that holds the songs for the 
playlist. The public members include a constructor, addSong, 
and cycleSongs functions. The constructor includes an integer 
which holds the maximum number of songs for the playlist. The 
addSong function passes the memory address of the songs and 
calls the enqueue function. The cycleSongs function passes the 
number of times the playlist will loop and is used to play the 
music playlist. The function works by using an if statement to 
check if the playlist is empty by calling the isEmpty function. If 
the playlist is not empty, the playlist will use a for loop to display 
the songs. The for loop will repeat a number of times equivalent 
to the number of times the function will repeat multiplied by the 
number of songs in the playlist. Within the for loop, the function 
will use the rear, dequeue, and front functions to find the 
previous, current, and next songs. The function will then call the 
primaryDisplay function to display the current song being 
played, and will call the secondaryDisplay function to display 
the previous and next songs. The enqueue function is then called  
and passes the current song being played. The function then 
checks if the playlist has reached the end by using an if statement 
to check if the current iteration of the for loop modulo the 
maximum number of songs in the playlist is equal to zero. If so, 
the function will let the user know the playlist is repeating. After 
that, the function will use the thread and chrono libraries to wait 
for one second. The function does this in order to simulate 
the songs playing in a music playlist and to better showcase the 
circular queue implementation. 

  The Main.cpp file first calls the header file that contains the functions to 
implement the circular queue. The Main.cpp file uses ASCII text and the setw 
function to make the output look cleaner. In the 
main function, the integers called loop and numSongs is defined to hold the 
number of times the playlist will repeat and the number of songs to add  
to the playlist. In order to better test the program, the main 
function will ask the user how many times the playlist will loop 
and input that number into the loop integer. The function will 
then ask the user to input how many songs they want in the 
playlist. In order to ensure the user actually inputs a reasonable 
integer, an while loop is used to check if each input is valid. The 
function then uses the chrono and thread library to count down 
from three to start the playlist. The main function then creates 
the circular queue by setting the maximum number of songs 
equal to the numSongs. The songs are then defined using the 
attributes in the song class. Those songs are then added to the 
queue. The cycleSongs function passes the loop integer, which 
starts the music playlist. After the playlist finishes cycling 
through the songs, the main function then outputs some ASCII 
text and ends the program.
