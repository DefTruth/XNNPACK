// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <xnnpack/aarch64-assembler.h>
#include <xnnpack/allocator.h>
#include <xnnpack/common.h>

#include "assembler-helpers.h"
#include <gtest/gtest.h>

namespace xnnpack {
namespace aarch64 {

TEST(AArch64Assembler, Initialization) {
  xnn_code_buffer b;
  xnn_allocate_code_memory(&b, XNN_DEFAULT_CODE_BUFFER_SIZE);
  Assembler a(&b);
  ASSERT_EQ(xnn_status_success, xnn_release_code_memory(&b));
}

TEST(AArch64Assembler, InstructionEncoding) {
  xnn_code_buffer b;
  xnn_allocate_code_memory(&b, XNN_DEFAULT_CODE_BUFFER_SIZE);
  Assembler a(&b);

  CHECK_ENCODING(0x4D60C902, a.ld2r({v2.v4s(), v3.v4s()}, mem[x8]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ld2r({v2.v4s(), v3.v4s()}, mem[x8, 16]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ld2r({v2.v4s(), v4.v4s()}, mem[x8, 16]));

  CHECK_ENCODING(0xA9403FEE, a.ldp(x14, x15, mem[sp]));
  CHECK_ENCODING(0xA8C13FEE, a.ldp(x14, x15, mem[sp], 16));
  CHECK_ENCODING(0xA9413FEE, a.ldp(x14, x15, mem[sp, 16]));
  CHECK_ENCODING(0xA9603FEE, a.ldp(x14, x15, mem[sp, -512]));
  CHECK_ENCODING(0xA95FBFEE, a.ldp(x14, x15, mem[sp, 504]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldp(x14, x15, mem[sp], 15));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldp(x14, x15, mem[sp], -520));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldp(x14, x15, mem[sp], 512));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldp(x14, x15, mem[sp, 16], 16));

  CHECK_ENCODING(0xF9400BE8, a.ldr(x8, mem[sp, 16]));
  CHECK_ENCODING(0xF97FFFE8, a.ldr(x8, mem[sp, 32760]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldr(x8, mem[sp, -8]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldr(x8, mem[sp, 7]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldr(x8, mem[sp, 32768]));
  EXPECT_ERROR(Error::kInvalidOperand, a.ldr(x8, MemOperand(sp, 16, AddressingMode::kPostIndex)));

  ASSERT_EQ(xnn_status_success, xnn_release_code_memory(&b));
}

}  // namespace aarch64
}  // namespace xnnpack