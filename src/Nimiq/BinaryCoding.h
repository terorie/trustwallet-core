// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <vector>

namespace TW {
namespace Nimiq {

/// Encodes a 16-bit value into the provided buffer.
static inline void encode16(uint16_t val, std::vector<uint8_t>& data) {
    data.push_back(static_cast<uint8_t>(val >> 8));
    data.push_back(static_cast<uint8_t>(val));
}

/// Decodes a 16-bit value from the provided buffer.
static inline uint16_t decode16(const uint8_t *_Nonnull src) {
    return (uint16_t)(src[1]) | ((uint16_t)(src[0]) << 8);
}

/// Encodes a 32-bit value into the provided buffer.
static inline void encode32(uint32_t val, std::vector<uint8_t>& data) {
    data.push_back(static_cast<uint8_t>((val >> 24)));
    data.push_back(static_cast<uint8_t>((val >> 16)));
    data.push_back(static_cast<uint8_t>((val >> 8)));
    data.push_back(static_cast<uint8_t>(val));
}

/// Decodes a 32-bit value from the provided buffer.
static inline uint32_t decode32(const uint8_t *_Nonnull src) {
    return static_cast<uint32_t>(src[3])
        | (static_cast<uint32_t>(src[2]) << 8)
        | (static_cast<uint32_t>(src[1]) << 16)
        | (static_cast<uint32_t>(src[0]) << 24);
}

/// Encodes a 64-bit value into the provided buffer.
static inline void encode64(uint64_t val, std::vector<uint8_t>& data) {
    data.push_back(static_cast<uint8_t>((val >> 56)));
    data.push_back(static_cast<uint8_t>((val >> 48)));
    data.push_back(static_cast<uint8_t>((val >> 40)));
    data.push_back(static_cast<uint8_t>((val >> 32)));
    data.push_back(static_cast<uint8_t>((val >> 24)));
    data.push_back(static_cast<uint8_t>((val >> 16)));
    data.push_back(static_cast<uint8_t>((val >> 8)));
    data.push_back(static_cast<uint8_t>(val));
}

/// Decodes a 64-bit value from the provided buffer.
static inline uint64_t decode64(const uint8_t *_Nonnull src) {
    return static_cast<uint64_t>(src[7])
        | (static_cast<uint64_t>(src[6]) << 8)
        | (static_cast<uint64_t>(src[5]) << 16)
        | (static_cast<uint64_t>(src[4]) << 24)
        | (static_cast<uint64_t>(src[3]) << 32)
        | (static_cast<uint64_t>(src[2]) << 40)
        | (static_cast<uint64_t>(src[1]) << 48)
        | (static_cast<uint64_t>(src[0]) << 56);
}

}} // namespace
