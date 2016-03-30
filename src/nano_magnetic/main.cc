//
// The MIT License (MIT)
//
// Copyright (c) 2016 Maxim Fedorenko <varlllog@gmail.com>
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
//  main.cc
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 12/Feb/2016.
//

#include <cmath>
#include <cstdlib>

#include <random>

#include "nano_magnetic/material.h"
#include "nano_magnetic/particle.h"

int main( int argc, char **argv ) {
    namespace nm = nano_magnetic;

    constexpr auto kAnisotropy = 4000.;
    constexpr auto kSaturation = 800.;
    constexpr auto kRadius = 20.e-7;

    const auto kDamping = ( 20. * kAnisotropy ) / kSaturation;

    constexpr auto kGyromagneticRatio = 1.76e+7;

    auto material = nm::Material( kAnisotropy, kSaturation, kDamping, kGyromagneticRatio, kRadius );

    auto particle = nm::Particle( material );


    std::mt19937 mt_generator;
    mt_generator.seed( 42 );

    //std::random_device rd;
    //mt_generator.seed( rd() );

    std::uniform_int_distribution<double> dis( 0., 1. );

    auto field = nm::Vector( dis( mt_generator ), dis( mt_generator ), dis( mt_generator ) );
    field *= 100.;

    constexpr auto kDeltaT = 1.e-8;
    constexpr auto kEpsilon = 1.e-4;

    particle.anisotropy = nm::Vector( dis( mt_generator ), dis( mt_generator ), dis( mt_generator ) );
    particle.anisotropy.normalize();

    particle.magnetic = particle.anisotropy;

    constexpr auto kMaxIterationCount = 50;

    for( auto i = 0; i < kMaxIterationCount; ++i ) {
        particle.magnetic.normalize();

        auto field_effective_anisotropy = nm::Vector( - kDamping * particle.magnetic.x(),  - kDamping * particle.magnetic.y(), 0 );

        auto field_effective = field_effective_anisotropy + field;


        auto field_r = field_effective - field_effective.cross( particle.magnetic ) * kDamping;

        auto field_r_norm = field_r.norm();

        field_r.normalize();

        auto dte = ( kGyromagneticRatio * field_r_norm * kDeltaT ) / ( 1. + std::pow( kDamping, 2. ) );
    }

    return EXIT_SUCCESS;
}

