
#include "SvgNode.h"
#include <native_drawing/drawing_path.h>

namespace rnoh {

class SvgQuote : public SvgNode {
 public:
  SvgQuote() : SvgNode() {
    InitHrefFlag();
  }
  ~SvgQuote() override = default;

  OH_Drawing_Path* AsPath() const override {
    auto* path = OH_Drawing_PathCreate();
    for (const auto& child : children_) {
      auto* childPath = child->AsPath();
      //   path.Op(path, childPath, RSPathOp::UNION);
    }
    return path;
  }

  void Draw(OH_Drawing_Canvas* canvas) override {
    // render composition on other svg tags
    OnDrawTraversedBefore(canvas);
    OnDrawTraversed(canvas);
    OnDrawTraversedAfter(canvas);
  }

 protected:
  virtual void OnDrawTraversedBefore(OH_Drawing_Canvas* canvas, Size viewPort) {}
  virtual void OnDrawTraversedAfter(OH_Drawing_Canvas* canvas, Size viewPort) {}

  // mask/pattern/filter/clipPath
  void InitHrefFlag() {
    hrefFill_ = true;
    hrefRender_ = false;
    passStyle_ = true;
    inheritStyle_ = false;
    drawTraversed_ = false;
  }
};

} // namespace rnoh
