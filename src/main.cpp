//
// The MIT License (MIT)
//
// Copyright (c) 2015 Maxim Fedorenko <varlllog@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  main.cpp
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 08/Sep/2015.
//

#include <iostream>

#include <getopt.h>
#include <stdlib.h>

#include "NanoConfig.h"
#include "SomeMaterial.h"

void usage( const char *execName )
{
    std::cout << "Nano magnetic tool. Version " << NANO_VERSION_MAJOR << "."
              << NANO_VERSION_MINOR << "." << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "\t" << execName << " [-h]" << std::endl;
    std::cout << "Where:" << std::endl;
    std::cout << " -h                " << "Show this help." << std::endl;
}

int main( int argc, char *argv[] )
{
    char c;

    while( ( c = getopt( argc, argv, "h" ) ) != -1 )
    {
        switch ( c )
        {
            case 'h':
            {
                usage( argv[0] );
                return EXIT_SUCCESS;
                break;
            }

            default:
            {
                usage( argv[0] );
                return EXIT_FAILURE;
                break;
            }
        }
    }

    int res = EXIT_SUCCESS;

    NanoMagnetic::SomeMaterial material;
    std::cout << "K1 == " << material.K1() << std::endl;

    return res;
}

