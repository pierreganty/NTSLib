#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>




enum {
  OK,
  KO_NOMEM, 
  KO_UNDERFLOW, 
  KO_OVERFLOW
};

/*
 * circular buffer structure
 *
 */

/*
typedef struct {
  char* head;
  char* out;
  char* in;
  int size;
  int free;
  int count;
} buffer_t;

*/
/*
 * basic operations
 *
 */
  

/*
 *
 *
 */

char* head;
char* outp;
char* inp;
int size;
int free_mem;
int count;

void trace(const char* msg) {
  //printf("*** %s\n", msg);
}




int main() {
  // printf("sizeof(char) = %d\n", sizeof(char));
  // printf("sizeof(int)  = %d\n", sizeof(int));

  //buffer_t b;

  //initialize( 24);

  int size_mem=24;
  size_mem += (size_mem % 4) ? (4 - size_mem % 4) : 0;
  size=size_mem;
  head=(char *)malloc(size);


  while (1) {
    //char line[80];
    char* line;
    line = (char *)malloc(80*sizeof(char));
    //scanf("%s", line);
    if (strstr(line, "put") == line) {
      // put the string, including the final '\0'
      printf("main: put '%s' ... \n", line+3);
      //put( strlen(line)-2, line+3);
      {
	int size_mem = strlen(line)-2;
	char * data = line+3;
	if (free_mem < 4 + size_mem) {
	  trace("put: aborted, overflow");
	} //lack of memory, exiting put.

	else {
	  // write the length on 4 bytes
	  if (outp + 4 <= head + size) {
	    (*outp) = size;
	    outp += 4; 
	    free_mem -= 4;
	    // cycle, if needed
	    if (outp == head + size) 
	      outp = head;
	  }
	  // write the data on 'size' bytes
	  if (outp + size_mem <= head + size) {
	    // data fits entirely
	    memcpy(outp, data, size);
	    outp += size; 
	  }
	  else {
	    // data needs to be 'fractioned' in two parts...
	    //int s = (b->head + b->size) - b->out;
    
	    int s=(head+size)-outp;
	    memcpy(outp, data, s);
	    memcpy(head, data + s, size_mem - s);
	    outp = head + size_mem - s;
	  }
	  // update for free space
	  free_mem -= size_mem;
	  count++; 
	  // re-align on 4 bytes
	  if (size_mem % 4) {
	    outp += (4 - size_mem % 4);
	    free_mem -= (4 - size_mem % 4);
	  }
	  // cycle, if needed
	  if (outp == head + size)
	    outp = head;

	  trace("put: ok");
	}//end of put when free memory is plenty

      } // end of put

    }
    if (strstr(line, "get") == line) {
      char* data; 

      //get
      {
	int size_entry;
	if (count == 0) {
	  trace("get: aborted, underflow");
	} //quit.

	else { //enougth memory
	  // read the data size
	  size_entry = * ((int* ) inp);
	  inp += 4;
	  free_mem += 4;
	  // cycle, if needed
	  if (inp == head + size)
	    inp = head;
	  //
	  // allocate memory and read the data
	  data = malloc( size_entry );
	  if ( inp + size_entry <= head + size) {
	    // data comes in one reading
	    memcpy(data, inp, size_entry);
	    inp += size_entry;
	  }
	  else {
	    // data is split, 
	    int s = (head + size) - inp;
	    memcpy( data, inp, s);
	    memcpy( data + s, head, size_entry - s);
	    inp = head + (size_entry - s);
	  }
	  // update for free space
	  free_mem += size_entry;
	  count--;
	  // realign on 4 bytes
	  if ( size_entry % 4 ) {
	    inp += (4 - size_entry % 4);
	    free_mem += (4 - size_entry % 4);
	  }
	  // cycle, if needed
	  if (inp == head + size)
	    inp = head;

	  trace("get: ok");
	} //enough memory block end
	
      }


      if ( data != NULL) {
	printf("main: get '%s' ...\n", data);
	free( data );
      }
    }
    if (strstr(line, "end") == line)
      break;
  }

  return 0;
}
