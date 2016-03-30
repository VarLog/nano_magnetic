#ifndef _NANO_MAGNETIC_PARTICLE_H_
#define _NANO_MAGNETIC_PARTICLE_H_

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
//  particle.h
//
//  Created by Maxim Fedorenko <varlllog@gmail.com> on 12/Feb/2016.
//

#include <nano_magnetic/material.h>
#include <nano_magnetic/types.h>

namespace nano_magnetic {

class Particle {
  public:
    template<typename M>
    Particle( M &&material ) :
        material_( std::forward<M>( material ) ) {
    }

    Material material() const {
        return material_;
    }

    Vector magnetic;
    Vector anisotropy;
    Vector position;

    double getVolume() const;

  private:
    Material material_;
};

}  // namespace nano_magnetic

#endif  // _NANO_MAGNETIC_PARTICLE_H_