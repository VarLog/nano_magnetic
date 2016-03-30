#ifndef _NANO_MAGNETIC_ABSTRACT_SPACE_H_
#define _NANO_MAGNETIC_ABSTRACT_SPACE_H_

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
//  abstract_space.h
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 31/Mar/2016.
//

#include <vector>

#include <nano_magnetic/particle.h>

namespace nano_magnetic {

class AbstractSpace {
  public:
    virtual ~AbstractSpace() {};

    virtual double getVolume() const = 0;

  protected:
    std::vector<Particle> particles_;
};

}  // namespace nano_magnetic

#endif  // _NANO_MAGNETIC_ABSTRACT_SPACE_H_