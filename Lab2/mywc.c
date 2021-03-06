//Won Yong Ha (woha)
//mywc class

#include <stdio.h>

int main() {

  //Declare three Int variables
  //for counting
  int chs = 0;
  int wds = 0;
  int lns = 0;

  //Declare one Int variable
  //count how many time in 'while' loop
  int count = 0;

  //Declare one Int variable
  //for saving the first variable
  int c;

  //Declare one Int variable
  //for saving previous variable
  int pre_c;

  //while loop
  //and checking whether is not EOF
  while ((c = getchar())) {

    //Last break point
    if (c == EOF) {
      chs++;
      if (count == 0)
	break;
      else {
	//printf("%c\n", pre_c);
       	if (pre_c == ' ' || pre_c == '\t' || pre_c == '\r' || pre_c == '\n' || pre_c == '\f' || pre_c == '\v')
	  break;
	else {
	  wds++;
	  break;
	}
      }
    }

    //prefixing the variables
    if(count == 0) {
      lns = 1;
      pre_c = c;
    }

    //if statement
    // when it is nextline
    if (c == '\n') {
      wds++;
      lns++;
    }
    
    //counting every single character
    chs++;

    //if statment
    // when it is whitespaces
    if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v')
      wds++;
    
    //checking overlapped
    if (pre_c == c && count != 0) {
      
      //testing printing
      //printf ("--------");

      if (c == ' ' || c == '\t' || c == 'r' || c == '\f' || c == '\v')
	wds--;
      if (c == '\n') {
	wds--;
      }
    }

    //counting every single steps
    count++;

    //testing printing
    // printf("%c\n", c);
    //printf("chs: %d\n", chs);
    //printf("wds: %d\n", wds);
    //printf("lns: %d\n", lns);

    //changing pre_c varialbe
    pre_c = c;
  }

  //printing thre result
  printf(" %d %d %d\n", lns, wds, chs);
  return 0;
}
