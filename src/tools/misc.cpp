/* The MIT License (MIT)
 *
 * Copyright (c) 2014-2017 David Medina and Tim Warburton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 */

#include "occa/tools/misc.hpp"

namespace occa {
  //---[ Misc Functions ]---------------
  int maxBase2Bit(const int value) {
    if (value <= 0)
      return 0;

    const int maxBits = 8 * sizeof(value);

    for (int i = 0; i < maxBits; ++i) {
      if (value <= (1 << i))
        return i;
    }

    return 0;
  }

  int maxBase2(const int value) {
    return (1 << maxBase2Bit(value));
  }

  udim_t ptrDiff(void *start, void *end) {
    if (start < end)
      return (udim_t) (((char*) end) - ((char*) start));

    return (udim_t) (((char*) start) - ((char*) end));
  }

  void* ptrOff(void *ptr, udim_t offset) {
    return (void*) (((char*) ptr) + offset);
  }
  //====================================
}
