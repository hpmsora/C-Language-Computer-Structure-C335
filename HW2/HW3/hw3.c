//////////////////////////////////////////////////////////
//
// Won Yong Ha(woha)
//
// CSCI-C 335 HW3
//
// Start: Feb 29 2016
// End: Mar 1 2016
//
//
//////////////////////////////////////////////////////////

#include <stdio.h>

//checking first 6 bits
#define checking(x) (((x) >> 10) & 0x3f)
//check add or sub
#define addorsub(x) (((x) >> 9) & 0x1)
//find rm
#define rm(x) (((x) >> 6) & 0x7)
//find rn
#define rn(x) (((x) >> 3) & 0x7)
//find rd
#define rd(x) (((x) >> 0) & 0x7)
//opcode for data reg
#define opcode(x) (((x) >> 6) & 0xf)

int main() {
  // saving number
  int inst;

  printf(".text\n");
  printf(".syntax unified\n");
  printf(".thumb\n");

  /*
  int num[5];
  printf("Input 5 hexadecimal number:");*/
  while (scanf("%x", &inst) == 1) {
    // printf("%d\n", inst);
    //variable declare
    //regnames
    char *regnames[] = {"r0", "r1", "r2", "r3", "r4", "r5", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"};
    //opname
    char *opname[] = {"ands ", "eors ", "lsls ", "lsrs ", "asrs ", "adcs ", "sbcs ", "rors ", "tst ", "rsbs ", "cmp ", "cmn ", "orrs", "muls", "bics", "mvns"};
    
    //000110
    //add_sub
    if (checking(inst) == 6){
      //chekcing add or sub by Operation
      //0 = add || 1 = sub
      if (addorsub(inst) == 0)
	printf("\tadds %s, %s, %s\n", regnames[rd(inst)], regnames[rn(inst)], regnames[rm(inst)]);
      else
	printf("\tsubs %s, %s, %s\n", regnames[rd(inst)], regnames[rn(inst)], regnames[rm(inst)]);
    }
    //010000
    //Data Reg
    else if (checking(inst) == 16)
      printf("\t%s%s, %s\n", opname[opcode(inst)], regnames[rd(inst)], regnames[rn(inst)]);
    
    else{
      printf(".hword 0x.... %x", inst);
    }
  }
}
