 /*
    * 1-first xor all numbers you will left with result of non repeating numbers scince xor same 
    * number result 0 
    * 2-know where first 1' in the result ,that mean this bit is one for the original number 
    * e.g 011^010 ->001   011   , 101 ^001 -->100  مزودها علي الفاضي
    * 3-get the index of that place and shift number 1 by it(index up is 2) sift 1<<2 100
    * 
      4- Get the numbers in the array that have this corrsponding bit on
      5-then xor them to remove any rebeated numbers
      6-now we have one of the unique numbers 
      7-if we xor that with the result we will get the other number 
      1,1,2,3
      xor them all you will get 001 then get all numbers that and with this (1,1,3)
      xor them you left with (3),that one of the unique numbers ,xor that with 001 
      011^001->010 you will get the other unique number
    */
     int tt[] = {3,3,4,4,5,1,6};
     int res = 0;
     //xor all the numbers to get the unique ones
     for (int i = 0; i <7; i++)   
     {
         res ^= tt[i];
      }
     int  temp = res,index=0;
    //while (temp)
    //{
    //    if (temp & 1)
    //        break;
    //    index++;
    //    temp = temp >> 1;
    //}
    //int mask = 1 << index;
    
     // add only those numbers with same bit one as the result 
     vector<int>temparr;
     for (int i = 0; i < 7; i++)
     {
         if (tt[i] & res)
         {
             cout << tt[i] << endl;
             temparr.push_back(tt[i]);
         }
     }
     int a = 0;
     //xor them to get the unique number
     for (auto& v : temparr)
     {
         a ^= v;
     }
     //xor the unique number with the res to get the other unique number
     int b = res ^ a;
     if (a > b)
         cout << b << " " << a << endl;
     else cout << a << " " << b << endl;
