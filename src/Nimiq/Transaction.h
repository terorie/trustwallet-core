// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"

namespace TW {
namespace Nimiq {

class Transaction {
    /// TODO: Only supports Nimiq basic transactions atm
public:
    // Sender public key
    std::array<uint8_t, 32> sender_pub_key;
    // Recipient address
    Address destination;
    // Recipient account type
    uint8_t destination_type;
    // Transaction value
    uint64_t amount;
    // Transaction fee
    uint64_t fee;
    // Validity start (block) height
    uint32_t vsh;
    // Sender signature
    std::vector<uint8_t> signature;

    Transaction() = default;
    Transaction(std::array<uint8_t, 32> sender, Address dest, uint8_t dest_type, uint64_t amount, uint64_t fee, uint32_t vsh)
        : sender_pub_key(sender)
        , destination(dest)
        , destination_type(dest_type)
        , amount(amount)
        , fee(fee)
        , vsh(vsh)
        {}

public:
    std::vector<uint8_t> serialize() const;
    std::vector<uint8_t> getPreImage() const;
};

}} // namespace

