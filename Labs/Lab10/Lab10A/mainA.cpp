/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include "SevenSegment.h"
#include "DE1SoCfpga.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

/**
* Main operates the DE1-SoC 7-Segment Displays
* This program writes an integer number on the 7-Segment Displays
*/
int main(void)
{
  int count = -25;
  // Create a pointer object of the SevenSegment class
  SevenSegment *display = new SevenSegment;
  cout << "Program Starting...!" << endl;
  // Update the display every second
  while( count <= 25 ) {
    int value = count*count*count; // Value to display
    cout << "Count: " << count << ", Value = " << value << endl;
    display->Hex_WriteNumber(value); // display value
    sleep(1); // wait for 1 second
    count++; // increment count
  }
  cout << "Press any key to terminate..."; //wait before clearing the displays
  getchar(); getchar();
  delete display; // delete class object
  cout << "Terminating...!" << endl;
  return 0;
}