/*
    Copyright (c) 2018, RootHarold
    All rights reserved.

    Use of this source code is governed by an Apache license that can be found
    in the LICENSE file.
*/

#include "genome.h"

namespace LycorisNet {

    Gen::Gen() {

    }

    Gen::Gen(uint32_t in, uint32_t out) {
        this->in = in;
        this->out = out;
    }

    Ome::Ome() {
        delta = 0;
    }

    Ome::Ome(float weight, uint32_t innovationNum) {
        this->weight = weight;
        this->innovationNum = innovationNum;
        delta = 0;
    }

}
