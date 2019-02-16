/*7/10/2018       Nicola Meneghini

Aim: writing a text formatter without breaking the words.

The basic idead is to find the first blanck space after the given length. That is the point
where I will break the text. To do so I define the string "blanck" and I use the function "find()"
to find it. In addition, I use the function substr() to write only the given length.

*/



#include <iostream>
using namespace std;

#define max_length 10


int main(){

string  my_string, new_string, blank = (" ");
unsigned int i = 1, up = 0, low=0, span; //up and low are the bounds of the string. Span defines the actual length
                                        //of the line


getline(cin, my_string); // here I get the input text

my_string = my_string + blank; //I have to add a blank space at the end of the text because of how I wrote the code.
                              //If I didn't do this I would get an infinite loop.

  if (my_string.length() >= max_length){

    for ( ; ; ){

    low = up; //in the next iteration, the lower bound will be given by the present upper bound

    up =  my_string.find(blank, up+max_length) +1 ; //upper bound of the string (+1 is needed to include the blank)

    span = up - low; //real length of the string

    cout << my_string.substr(low, span) /*<< " " <<i << "->up:" << up << " ->low:" << low */<< endl ;

    if ( up + max_length >= my_string.length()) break;

    }

  cout << my_string.substr(up, my_string.length()) << endl;
  }

  else cout << my_string;




return 0;

}
