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
//  Particle.cpp
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 13/Sep/2015.
//

#include "Particle.h"

#include <random>

#include "Exceptions.h"

namespace NanoMagnetic {

Particle::Particle( const MaterialPtr &material )
    : mMaterial(material)
{
}
    
void Particle::genRandNormalVector()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-0.5, 0.5);
    
    mNornal(0) = dis(gen);
    mNornal(1) = dis(gen);
    mNornal(2) = dis(gen);
    
    mNornal /= mNornal.squaredNorm();
}

bool Particle::isIntersected( const Particle &that ) const
{
    auto diff = mPosition - that.mPosition;
    auto dist = diff.squaredNorm();
    
    return dist < ( mMaterial->radius() + that.mMaterial->radius() );
}

MaterialPtr Particle::material() const
{
    return mMaterial;
}

Vector Particle::position() const
{
    return mPosition;
}

Vector Particle::magnetic() const
{
    return mMagnetic;
}

Vector Particle::normal() const
{
    return mNornal;
}

Vector Particle::hr() const
{
    return mHr;
}

void Particle::setPosition(const Vector &pos)
{
    mPosition = pos;
}

void Particle::setMagnetic(const Vector &magnetic)
{
    mMagnetic = magnetic;
}

void Particle::setNormal(const Vector &normal)
{
    mNornal = normal;
}

void Particle::setHr(const Vector &hr)
{
    mHr = hr;
}
    
}

