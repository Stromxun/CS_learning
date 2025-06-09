int max (int num1, int num2) {
  //check if num1 is greater than num2
    //if so, your answer is num1
    //otherwise, your answer is num2
	return (num1 < num2 ? num2 : num1);
}

int main(void) {
  printf("max(42, -69) is %d\n", max(42, -69));
  printf("max(33, 0) is %d\n", max(33, 0));
  printf("max(0x123456, 123456) is %d\n", max(0x123456, 123456));
  //compute the max of 0x451215AF and 0x913591AF and print it out as a decimal number
  printf("max(0x451215AF, 0x913591AF) is %d\n", max(0x451215AF, 0x913591AF));
  return 0;
}


