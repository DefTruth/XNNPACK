#!/bin/sh
# Copyright 2023 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.


################################### ARM NEON ##################################
### NR multiple of 4
tools/xngen src/x32-packx/neon.c.in -D MR=4 -D PREFETCH=0 -D KUNROLL=4 -D VARIANT=ST4 -o src/x32-packx/gen/x32-packx-4x-neon-st4.c &
tools/xngen src/x32-packx/neon.c.in -D MR=4 -D PREFETCH=1 -D KUNROLL=4 -D VARIANT=ST4 -o src/x32-packx/gen/x32-packx-4x-neon-st4-prfm.c &
tools/xngen src/x32-packx/neon.c.in -D MR=8 -D PREFETCH=0 -D KUNROLL=4 -D VARIANT=ST4 -o src/x32-packx/gen/x32-packx-8x-neon-st4.c &
tools/xngen src/x32-packx/neon.c.in -D MR=8 -D PREFETCH=1 -D KUNROLL=4 -D VARIANT=ST4 -o src/x32-packx/gen/x32-packx-8x-neon-st4-prfm.c &

wait

### Tests for packing micro-kernels
tools/generate-pack-test.py --spec test/x32-packx.yaml --output test/x32-packx.cc &
