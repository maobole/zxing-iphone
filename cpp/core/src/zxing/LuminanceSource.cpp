/*
 *  LuminanceSource.cpp
 *  zxing
 *
 *  Created by Ralf Kistner on 16/10/2009.
 *  Copyright 2008 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zxing/LuminanceSource.h>
#include <zxing/common/IllegalArgumentException.h>

namespace zxing {

LuminanceSource::LuminanceSource() {
}

LuminanceSource::~LuminanceSource() {
}

unsigned char* LuminanceSource::getMatrix() {
  int width = getWidth();
  int height =  getHeight();
  unsigned char* matrix = new unsigned char[width * height];
  unsigned char* row = new unsigned char[width];
  for (int y = 0; y < height; y++) {
    getRow(y, row);
    memcpy(&matrix[y * width], row, width);
  }
  return matrix;
}

bool LuminanceSource::isCropSupported() const {
  return false;
}

Ref<LuminanceSource> LuminanceSource::crop(int left, int top, int width, int height) {
  throw IllegalArgumentException("This luminance source does not support cropping.");
}

bool LuminanceSource::isRotateSupported() const {
  return false;
}

Ref<LuminanceSource> LuminanceSource::rotateCounterClockwise() {
  throw IllegalArgumentException("This luminance source does not support rotation.");
}

}
