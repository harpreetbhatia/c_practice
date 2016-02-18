#include <iostream>
#include <cmath>

///////////////////////////////////////////////////////////////////
//  cache_dither_addr.cpp
//  Using Dithering Algorithm, a new set index is generated for a 
//  cache-line address. This program creates a cache model and 
//  explores the cases where tags can be allocated to the new set 
//  index without any conflicts within the set.
///////////////////////////////////////////////////////////////////

using namespace std;

unsigned int dithering(int n, int index)
{
    unsigned int result = index;
    unsigned int chunk_size=8;
    // cout << "[DEBUG] result = " << result;

    for (int i = chunk_size; i <= (3*chunk_size); i = i + chunk_size) {

        unsigned int mask = 255 << i;  //i = 8, 16, 24
        unsigned int intermediate_result = n & mask;
        intermediate_result = intermediate_result >> i;
        // cout << " ^ " << intermediate_result;
        result = result ^ intermediate_result;
    }
    // cout << " = " << result << endl;
    return result;
}


int main()
{
    unsigned int cacheline_addr_range= ~(~0 << 27);
    unsigned int cacheline_addr;

    /* initialize the cache model */

    int set = pow (2, 8);
    int way = pow (2, 19);
    // cout <<  "[DEBUG] way: " << way << endl;

    int *cache_model = new int[way*set];

    int i, j;
    for (i = 0; i < set; i++)
        for (j = 0; j < way; j++) {
            cache_model[i*way + j] = 0;
            //cout <<  "[DEBUG] addr: " << (i*way + j) << ",  ";
            //cout <<  cache_model[i*way + j] << endl;
        } // end for

   /* test the cache model */
   for (cacheline_addr = 0; cacheline_addr <= cacheline_addr_range; cacheline_addr++) {

           unsigned int original_set_index = cacheline_addr & 255; // 0xFF
   //         cout << "[DEBUG] original set-index: " << hex << original_set_index << endl;
   //         cout << "[DEBUG] cacheline addr: " << cacheline_addr << endl;
           unsigned int tag = cacheline_addr & 134217472; // 0x7FFFF00
           tag = tag >> 8;

           /* apply dithering */
           unsigned int new_set_index = dithering(cacheline_addr, original_set_index);
    //        cout << "[DEBUG] new set-index: " << new_set_index << endl;

           int num = cache_model[new_set_index*way + tag];

    //        cout << "[DEBUG] accessing set: " << new_set_index << ", tag: " << tag <<  endl;
    //        cout << "[DEBUG] The tag is " << num << endl;


           /* Check property 1
           Fail if tag is already present in the newly calculated set */
           if (num) {
               cout << cacheline_addr << ": test failed" << endl;
               delete [] cache_model;
               return 1;
           }

           /* add tag to the new set index */
           cache_model[new_set_index*way + tag] = 1;

     //       cout << "[DEBUG] accessing set: " << new_set_index << ", tag: " << tag <<  endl;
     //       cout << "[DEBUG] The tag is " << num << endl;


     } // end for


     /* Check property 2
     Fail if Number of tag combinations in any set is less than 2^19
     check to find if Number of Tag combinations in the Set is "more" than 2^19 is covered in property 1
     loop thru the sets to find number of tags in each */
     int count=0;
     for (i = 0; i < set; i++) {
         for (j = 0, count = 0; j < way; j++) {
             int num = cache_model[i*way + j];
             if (num) count++;
         }
         if (count != way) {
             cout << "Test failed! " << "set " << hex << i << ":  " << count  << " tags" << endl;
               delete [] cache_model;
               return 1;
         }
         cout << "[DEBUG] set " << hex << i << ":  " << count  << " tags" << endl;
     } // end for

     cout << "test passed" << endl;
     delete [] cache_model;
     return 0;

}
