// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_METRICS_HISTOGRAM_FLATTENER_H_
#define BRICK_METRICS_HISTOGRAM_FLATTENER_H_

#include <map>
#include <string>

#include "brick/macros.h"
#include "brick/metrics/histogram.h"

namespace base {

class HistogramSamples;

// HistogramFlattener is an interface used by HistogramSnapshotManager, which
// handles the logistics of gathering up available histograms for recording.
class BRICK_EXPORT HistogramFlattener {
 public:
  virtual void RecordDelta(const HistogramBase& histogram,
                           const HistogramSamples& snapshot) = 0;

 protected:
  HistogramFlattener() = default;
  virtual ~HistogramFlattener() = default;

 private:
  DISALLOW_COPY_AND_ASSIGN(HistogramFlattener);
};

}  // namespace base

#endif  // BRICK_METRICS_HISTOGRAM_FLATTENER_H_
