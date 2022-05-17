

#include <stdio.h>
#include <emscripten.h>
#include <stdlib.h> 

#include <math.h>


#include <iostream> 

extern "C" {

    EMSCRIPTEN_KEEPALIVE
    float addNums (float *buffer, int bufSize) {
        float total = 0;

        for (int i=0; i<bufSize; i++) {
            total+= buffer[i];
        }

        return total;
    }

    EMSCRIPTEN_KEEPALIVE
    uint8_t* doubleValues (uint8_t *buf, int bufSize) {
    

    /*    for (int i=0; i<bufSize; i++) {
          buf[i] = 1;
        }*/

      /*  for (int i = 0; i < bufSize; i += 4) {
            buf[i] = 0;
            buf[i + 1] = 0;
            buf[i + 2] = 0;
            buf[i + 3] = 255;
        }*/

        for (int i = 0; i < bufSize; i += 4) {

            buf[i + 3] = 255;
            if (buf[i] < 100) {
                buf[i] = 255;
                buf[i + 1] = 255;
                buf[i + 2] = 255;
            }

            if (buf[i] != 255) {
                buf[i] = 0;
                buf[i + 1] = 0;
                buf[i + 2] = 0;
            }
            else {
                buf[i] = 255;
                buf[i + 1] = 255;
                buf[i + 2] = 255;
            }

            if (buf[i] == 255) {
                buf[i] = 0;
                buf[i + 1] = 0;
                buf[i + 2] = 0;
            }
            else {
                buf[i] = 255;
                buf[i + 1] = 255;
                buf[i + 2] = 255;
            }
        }

    
        return buf;
    }

  

    // EMSCRIPTEN_KEEPALIVE
    // int8_t* doubleValues (int8_t *buf, int bufSize) {

    //     int8_t values[bufSize];

    //     for (int i=0; i<bufSize; i++) {
    //         values[i] = buf[i] * 2;
    //     }

    //     auto arrayPtr = &values[0];
    //     return arrayPtr;
    // }

    // EMSCRIPTEN_KEEPALIVE
    // int8_t* changeArr (int8_t *buf, int bufSize) {
    //     int out_array[bufSize];

    //     for (int i=0; i<bufSize; i++) {
    //         out_array[i] = buf[i] * 2;
    //     }

    //     // auto arrayPtr = &values[0];
    //     return out_array;
    // }
}

// EMSCRIPTEN_KEEPALIVE
// int reversenumber(int n) { 
//    int reverse=0, rem; 
//    while(n!=0) { 
//       rem=n%10; reverse=reverse*10+rem; n/=10; 
//    } 
//    return reverse; 
// }

// extern "C" {

//    int int_sqrt(int x) {
//     return sqrt(x);
//     }

// }


// Module._malloc([1,2,3].length * [1,2,3].BYTES_PER_ELEMENT);   Module.HEAPF32.set([1,2,3], buffer >> 2); Module.ccall("addNums", null, ["number", "number"], [buffer, [1, 2, 3].length])

// https://www.npmjs.com/package/wasm-arrays/v/1.0.2?activeTab=readme
