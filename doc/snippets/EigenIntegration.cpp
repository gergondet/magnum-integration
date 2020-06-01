/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019,
                2020 Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include <Corrade/Utility/DebugStl.h>

#include "Magnum/Magnum.h"
#include "Magnum/EigenIntegration/GeometryIntegration.h"
#include "Magnum/Math/Matrix3.h"
#include "Magnum/Math/Matrix4.h"

using namespace Magnum;
using namespace Magnum::Math::Literals;

int main() {
{
/* The include is already above, so doing it again here should be harmless */
/* [namespace] */
#include <Magnum/EigenIntegration/Integration.h>

Eigen::Vector3f a{1.0f, 2.0f, 3.0f};
Vector3 b(a);

auto c = Matrix4::rotation(35.0_degf, Vector3(a));
/* [namespace] */
static_cast<void>(c);
}

{
/* [Integration] */
Eigen::Vector3f a{1.0f, 2.0f, 3.0f};
Vector3 b(a);

auto c = Matrix3::rotation(35.0_degf);

// It's not possible to convert using Eigen::Matrix3f(c)
auto d = EigenIntegration::cast<Eigen::Matrix3f>(c);

Debug{} << Eigen::Array3i{1, 42, -3}; // prints   1
                                      //         42
                                      //         -3
/* [Integration] */
static_cast<void>(d);
}

{
/* [GeometryIntegration] */
auto a = Matrix3::translation({-1.5f, 0.3f})*
         Matrix3::rotation(25.0_degf)*
         Matrix3::scaling({1.23f, 2.0f});
auto b = Eigen::Affine2f(a);

auto c = Matrix4d(Eigen::Isometry3d::Identity());
/* [GeometryIntegration] */
static_cast<void>(b);
static_cast<void>(c);
}
}
