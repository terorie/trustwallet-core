// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Nimiq/Address.h"
#include "HexCoding.h"
#include "Nimiq/EdPrivateKey.h"

#include <gtest/gtest.h>

using namespace TW;
using namespace TW::Nimiq;

// TODO Valid addresses

TEST(NimiqAddress, IsValid) {
    // No address
    ASSERT_FALSE(Address::isValid(""));
    // Invalid country code
    ASSERT_FALSE(Address::isValid("DE86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA"));
    // Invalid checksum
    ASSERT_FALSE(Address::isValid("NQ42 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA"));
    // Too short
    ASSERT_FALSE(Address::isValid("NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0ML"));
    // Too long
    ASSERT_FALSE(Address::isValid("NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA 0MLA"));
    // Valid, without spaces
    ASSERT_TRUE(Address::isValid("NQ862H8FYGU5RM77QSN9LYLHC56ACYYR0MLA"));
    // Valid, normal format
    ASSERT_TRUE(Address::isValid("NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA"));
}

TEST(NimiqAddress, String) {
    // Address to string
    ASSERT_EQ(
        Address(parse_hex("5b3e9e5f32b89abafc3708765dc8f00216cefbb1")).string(),
        "NQ61 BCY9 UPRJ P2DB MY1P 11T5 TJ7G 08BC VXVH"
    );
    // Without spaces
    ASSERT_EQ(
        Address("NQ862H8FYGU5RM77QSN9LYLHC56ACYYR0MLA").string(),
        "NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA"
    );
    // With spaces
    ASSERT_EQ(
        Address("NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA").string(),
        "NQ86 2H8F YGU5 RM77 QSN9 LYLH C56A CYYR 0MLA"
    );
}

TEST(NimiqAddress, FromPublicKey) {
    std::array<uint8_t, 32> publicKey;
    auto inHex = parse_hex("70c7492aaa9c9ac7a05bc0d9c5db2dae9372029654f71f0c7f95deed5099b702");
    std::copy(inHex.begin(), inHex.end(), publicKey.begin());
    const auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "NQ27 GBAY EVHP HK5X 6JHV JGFJ 5M3H BF4Y G7GD");
}
