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
//  SomeMaterial.cpp
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 08/Sep/2015.
//

#include "SomeMaterial.h"

#define PI 3.14 /// \fixme So rude!

namespace NanoMagnetic
{

SomeMaterial::SomeMaterial()
    : mK1(0.1)
    , mMs(0.1)
    , mRadius(1)
    , mDiametr(mRadius*2)
    , mHk(2 * mK1 / mMs)
    , mVolume(4 * PI * mRadius * mRadius * mRadius / 3)
{
}

double SomeMaterial::K1() const {
  return mK1;
}

double SomeMaterial::Ms() const {
  return mMs;
}

double SomeMaterial::Hk() const {
  return mHk;
}

double SomeMaterial::Radius() const {
  return mRadius;
}

double SomeMaterial::Diametr() const {
  return mDiametr;
}

double SomeMaterial::Volume() const {
  return mVolume;
}

}

