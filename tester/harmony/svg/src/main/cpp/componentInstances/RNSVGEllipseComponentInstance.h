/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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
 * SOFTWARE.
 */

#pragma once
#include "RNOH/CppComponentInstance.h"
// #include "SwiperNode.h"
// #include "EventEmitters.h"
#include <folly/dynamic.h>
#include <math.h>
#include "SvgArkUINode.h"
#include "ShadowNodes.h"
#include "SvgEllipse.h"

namespace rnoh {

class RNSVGEllipseComponentInstance : public CppComponentInstance<facebook::react::RNSVGEllipseShadowNode>, public SvgHost {

private:
    SvgArkUINode m_svgArkUINode;

public:
    RNSVGEllipseComponentInstance(Context context);
    
    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override{}
    
    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override{}
    
    SvgArkUINode &getLocalRootArkUINode() override;
    
    void onPropsChanged(SharedConcreteProps const &props) override;
};
} // namespace rnoh