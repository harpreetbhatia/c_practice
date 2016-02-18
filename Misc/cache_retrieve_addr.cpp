#include <iostream>
#include <cmath>

///////////////////////////////////////////////////////////////////
//  cache_retrieve_addr.c
//  Using Dithering Algorithm, a new set index is generated for a 
//  cache-line address. Retrieval of the original address is done 
//  using xor’s “self-inverse” property. This program explores 
//  the cases where retrieving the original set index is possible.
///////////////////////////////////////////////////////////////////


using namespace std;

unsigned int dithering(int n)
{
    unsigned int result =0;
    unsigned int chunk_size=8;
    cout << "result = " << result;

    for (int i = 0; i <= (3*chunk_size); i = i + chunk_size) {

        unsigned int mask = 255 << i; //i = 0, 8, 16, 24
        unsigned int intermediate_result = n & mask;
        intermediate_result = intermediate_result >> i;
        result = result ^ intermediate_result;
        cout << " ^ " << result;
        // result = result ^ ((n & mask) >> i);
    }
    cout << endl;
    return result;
}


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


unsigned int dithering(int n, int index, int sp_case)
{
    unsigned int result = index;
    unsigned int chunk_size=8;
    if (sp_case == 0) {
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
}


int main()
{
    unsigned int cacheline_addr_range= ~(~0 << 27);
    // cout << "[DEBUG] cacheline address range: " << cacheline_addr_range << endl;

    unsigned int cacheline_addr;
    int sp_case = 0;

    for (cacheline_addr = 0; cacheline_addr <= cacheline_addr_range; cacheline_addr++) {

        // cout << "[DEBUG] cacheline address: " << cacheline_addr << endl;

        unsigned int original_set_index = cacheline_addr & 255;
        // cout << "[DEBUG] original set index: " << original_set_index << endl;

        /* apply dithering */
        unsigned int new_set_index = dithering(cacheline_addr, original_set_index, sp_case);
        // cout << "[DEBUG] new set index: " << new_set_index << endl; 

        /* reverse dithering */
        unsigned int reverse_set_index = dithering(cacheline_addr, new_set_index, sp_case);
        // cout << "[DEBUG] reverse set index: " << reverse_set_index << endl;

        if(original_set_index != reverse_set_index) {
            cout << cacheline_addr << ": test failed" << endl;
            return 1;
        }
    } // end for

    cout << "test passed" << endl;
    return 0;

}
