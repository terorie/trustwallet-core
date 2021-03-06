// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "../BinaryCoding.h"
#include "../Hash.h"

using namespace TW;
using namespace TW::Ripple;

const int MIN_FEE = 10;
const int MAX_FEE = 1000000;
const int FLAG_FULLY_CANONICAL = 0x80000000;

void Signer::sign(const PrivateKey& privateKey, Transaction& transaction) const noexcept {
    /// See https://github.com/trezor/trezor-core/blob/master/src/apps/ripple/sign_tx.py#L59
    transaction.flags |= FLAG_FULLY_CANONICAL;
    transaction.pub_key = privateKey.getPublicKey(true);

    auto unsignedTx = transaction.getPreImage();
    auto hash = Hash::sha512(unsignedTx);
    auto half = Data(hash.begin(), hash.begin() + 32);

    transaction.signature = privateKey.signAsDER(half);
}
