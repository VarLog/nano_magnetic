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
//  CommonMagneticField.cpp
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 13/Sep/2015.
//

#include "CommonMagneticField.h"

#include "Exceptions.h"

namespace NanoMagnetic {
    
CommonMagneticField::CommonMagneticField()
    : mStc( 30 )
    , mKStab( 30 )
    , mKappa( 0.2 )
    , mEpsillon( 1e-12 ) /// \fixme move it to Calculator::CalculateOptions
{
}
    
CommonMagneticField::~CommonMagneticField()
{
}
    
double CommonMagneticField::stc() const
{
    return mStc;
}
    
double CommonMagneticField::kStab() const
{
    return mKStab;
}
    
double CommonMagneticField::kappa() const
{
    return mKappa;
}
    
double CommonMagneticField::epsillon() const
{
    return mEpsillon;
}

Vector CommonMagneticField::magnetic() const
{
    return mMagnetic;
}

void CommonMagneticField::setMagnetic( const Vector &magnetic )
{
    mMagnetic = magnetic;
}

}

