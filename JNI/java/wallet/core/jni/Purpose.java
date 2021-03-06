// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

package wallet.core.jni;


public enum Purpose {
    BIP44 (44),
    BIP49 (49),
    BIP84 (84);

    private final int value;
    Purpose(int value) {
        this.value = value;
    }
    public int value() { return value; }
}
