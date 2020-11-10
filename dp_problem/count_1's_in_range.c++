


int count_bits(int num)
{
    int countt=0;
    while (num = num >> 1)
    {
        countt += (num & 1);
    }
    return countt;
}
  
int a = 10;
int d = 15;
int count = 0;
  // get numbers of 1's in the binary represntation of numbers in between a and b
    for (int i = a; i <= d; i++)
   {
       if ((a & 1)==0 && i < d)
       {
           /*1010  ->8
           * 1011  ->9 the next number after each even number is just same number of 1's +
           * the lsb bit wich is 1  ,and for the last number in our loop we just count the bits 
           * thats why we have the condidion i<b
           * */
           count += 2 * count_bits(i) + 1;
           i++;
           continue;
       }
       count += count_bits(i);
   }
