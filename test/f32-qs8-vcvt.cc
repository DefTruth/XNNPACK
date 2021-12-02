// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-qs8-vcvt.yaml
//   Generator: tools/generate-vcvt-test.py


#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/vcvt.h>
#include "vcvt-microkernel-tester.h"


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEON_X8, batch_eq_8) {
    TEST_REQUIRES_ARM_NEON;
    VCvtMicrokernelTester()
      .batch_size(8)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
  }

  TEST(F32_QS8_VCVT__NEON_X8, batch_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, batch_lt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, batch_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, zero_point) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, saturation) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, overflow) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, qmin) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X8, qmax) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x8, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEON_X16, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON;
    VCvtMicrokernelTester()
      .batch_size(16)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
  }

  TEST(F32_QS8_VCVT__NEON_X16, batch_div_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, zero_point) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, saturation) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, overflow) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, qmin) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X16, qmax) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x16, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEON_X24, batch_eq_24) {
    TEST_REQUIRES_ARM_NEON;
    VCvtMicrokernelTester()
      .batch_size(24)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
  }

  TEST(F32_QS8_VCVT__NEON_X24, batch_div_24) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 48; batch_size < 240; batch_size += 24) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, batch_lt_24) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 24; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, batch_gt_24) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 25; batch_size < 48; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, zero_point) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, saturation) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, overflow) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, qmin) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X24, qmax) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x24, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEON_X32, batch_eq_32) {
    TEST_REQUIRES_ARM_NEON;
    VCvtMicrokernelTester()
      .batch_size(32)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
  }

  TEST(F32_QS8_VCVT__NEON_X32, batch_div_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, batch_lt_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, batch_gt_32) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, scale) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, zero_point) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, saturation) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, overflow) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, qmin) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEON_X32, qmax) {
    TEST_REQUIRES_ARM_NEON;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neon_x32, xnn_init_f32_qs8_cvt_neon_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEONV8_X8, batch_eq_8) {
    TEST_REQUIRES_ARM_NEON_V8;
    VCvtMicrokernelTester()
      .batch_size(8)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, batch_div_8) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, batch_lt_8) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, batch_gt_8) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, scale) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, zero_point) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, saturation) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, overflow) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, qmin) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X8, qmax) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x8, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEONV8_X16, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON_V8;
    VCvtMicrokernelTester()
      .batch_size(16)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, batch_div_16) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, scale) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, zero_point) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, saturation) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, overflow) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, qmin) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X16, qmax) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x16, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEONV8_X24, batch_eq_24) {
    TEST_REQUIRES_ARM_NEON_V8;
    VCvtMicrokernelTester()
      .batch_size(24)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, batch_div_24) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 48; batch_size < 240; batch_size += 24) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, batch_lt_24) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size < 24; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, batch_gt_24) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 25; batch_size < 48; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, scale) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, zero_point) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, saturation) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, overflow) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, qmin) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X24, qmax) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x24, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_QS8_VCVT__NEONV8_X32, batch_eq_32) {
    TEST_REQUIRES_ARM_NEON_V8;
    VCvtMicrokernelTester()
      .batch_size(32)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, batch_div_32) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, batch_lt_32) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, batch_gt_32) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, scale) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, zero_point) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, saturation) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, overflow) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, qmin) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__NEONV8_X32, qmax) {
    TEST_REQUIRES_ARM_NEON_V8;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__neonv8_x32, xnn_init_f32_qs8_cvt_neonv8_params);
      }
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE2_X8, batch_eq_8) {
    TEST_REQUIRES_X86_SSE2;
    VCvtMicrokernelTester()
      .batch_size(8)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
  }

  TEST(F32_QS8_VCVT__SSE2_X8, batch_div_8) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, batch_lt_8) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, batch_gt_8) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, scale) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, zero_point) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, saturation) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, overflow) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, qmin) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X8, qmax) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x8, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE2_X16, batch_eq_16) {
    TEST_REQUIRES_X86_SSE2;
    VCvtMicrokernelTester()
      .batch_size(16)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
  }

  TEST(F32_QS8_VCVT__SSE2_X16, batch_div_16) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, batch_lt_16) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, batch_gt_16) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, scale) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, zero_point) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, saturation) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, overflow) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, qmin) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X16, qmax) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x16, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE2_X24, batch_eq_24) {
    TEST_REQUIRES_X86_SSE2;
    VCvtMicrokernelTester()
      .batch_size(24)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
  }

  TEST(F32_QS8_VCVT__SSE2_X24, batch_div_24) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 48; batch_size < 240; batch_size += 24) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, batch_lt_24) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size < 24; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, batch_gt_24) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 25; batch_size < 48; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, scale) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, zero_point) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, saturation) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, overflow) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, qmin) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X24, qmax) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x24, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE2_X32, batch_eq_32) {
    TEST_REQUIRES_X86_SSE2;
    VCvtMicrokernelTester()
      .batch_size(32)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
  }

  TEST(F32_QS8_VCVT__SSE2_X32, batch_div_32) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, batch_lt_32) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, batch_gt_32) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, scale) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, zero_point) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, saturation) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, overflow) {
    TEST_REQUIRES_X86_SSE2;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, qmin) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE2_X32, qmax) {
    TEST_REQUIRES_X86_SSE2;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse2_x32, xnn_init_f32_qs8_cvt_sse2_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE41_X8, batch_eq_8) {
    TEST_REQUIRES_X86_SSE41;
    VCvtMicrokernelTester()
      .batch_size(8)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
  }

  TEST(F32_QS8_VCVT__SSE41_X8, batch_div_8) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, batch_lt_8) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, batch_gt_8) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, scale) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, zero_point) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, saturation) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, overflow) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, qmin) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X8, qmax) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x8, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE41_X16, batch_eq_16) {
    TEST_REQUIRES_X86_SSE41;
    VCvtMicrokernelTester()
      .batch_size(16)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
  }

  TEST(F32_QS8_VCVT__SSE41_X16, batch_div_16) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, batch_lt_16) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, batch_gt_16) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, scale) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, zero_point) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, saturation) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, overflow) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, qmin) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X16, qmax) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 80; batch_size += 15) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x16, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE41_X24, batch_eq_24) {
    TEST_REQUIRES_X86_SSE41;
    VCvtMicrokernelTester()
      .batch_size(24)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
  }

  TEST(F32_QS8_VCVT__SSE41_X24, batch_div_24) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 48; batch_size < 240; batch_size += 24) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, batch_lt_24) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size < 24; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, batch_gt_24) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 25; batch_size < 48; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, scale) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, zero_point) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, saturation) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, overflow) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, qmin) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X24, qmax) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 120; batch_size += 23) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x24, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_QS8_VCVT__SSE41_X32, batch_eq_32) {
    TEST_REQUIRES_X86_SSE41;
    VCvtMicrokernelTester()
      .batch_size(32)
      .qmin(std::numeric_limits<int8_t>::min())
      .qmax(std::numeric_limits<int8_t>::max())
      .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
  }

  TEST(F32_QS8_VCVT__SSE41_X32, batch_div_32) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 64; batch_size < 320; batch_size += 32) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, batch_lt_32) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size < 32; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, batch_gt_32) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 33; batch_size < 64; batch_size++) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, scale) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(50)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, zero_point) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t zero_point = 0; zero_point < 5; zero_point += 2) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .zero_point(zero_point)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, saturation) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(500)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, overflow) {
    TEST_REQUIRES_X86_SSE41;
    for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
      VCvtMicrokernelTester()
        .batch_size(batch_size)
        .scale(4294967296.0f)
        .qmin(std::numeric_limits<int8_t>::min())
        .qmax(std::numeric_limits<int8_t>::max())
        .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, qmin) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmin = -128; qmin < 127; qmin += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(qmin)
          .qmax(std::numeric_limits<int8_t>::max())
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }

  TEST(F32_QS8_VCVT__SSE41_X32, qmax) {
    TEST_REQUIRES_X86_SSE41;
    for (int16_t qmax = -127; qmax <= 127; qmax += 51) {
      for (size_t batch_size = 1; batch_size <= 160; batch_size += 31) {
        VCvtMicrokernelTester()
          .batch_size(batch_size)
          .scale(500)
          .qmin(std::numeric_limits<int8_t>::min())
          .qmax(qmax)
          .Test(xnn_f32_qs8_vcvt_ukernel__sse41_x32, xnn_init_f32_qs8_cvt_sse4_params);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64