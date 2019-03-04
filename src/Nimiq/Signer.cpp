// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include <TrezorCrypto/ed25519.h>

using namespace TW;
using namespace TW::Nimiq;

const uint64_t MIN_FEE = 0; // TODO MIN_FEE
const uint64_t MAX_FEE = 100000000; // TODO MAX_FEE

void Signer::sign(const EdPrivateKey& privateKey, Transaction &transaction) const noexcept {
    std::vector<uint8_t> proof;
    
    // Signer public key
    auto publicKey = privateKey.getPublicKey();
    proof.insert(proof.end(), publicKey.begin(), publicKey.end());
    
    // Merkle Path nodes count (+ 0 bytes of Merkle Path)
    proof.push_back(0);

    // Signature
    auto preImage = transaction.getPreImage();
    auto signature = privateKey.sign(preImage);
    proof.insert(proof.end(), signature.begin(), signature.end());

    transaction.signature = proof;
}
