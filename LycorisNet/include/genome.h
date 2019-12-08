/*
    Copyright (c) 2019, RootHarold
    All rights reserved.

    Use of this source code is governed by a LGPL-3.0 license that can be found
    in the LICENSE file.
*/

#ifndef LYCORIS_GENOME_H
#define LYCORIS_GENOME_H

#include <cstdint>
#include <string>

namespace LycorisNet {

    class Lycoris;

    /*
     * The class "Gen" and the class "Ome" form connections between nodes.
     * The former contains the numbers of input and output.
     * The latter consists of weight and the cumulative number of
     * connections ("innovationNum").
     */

    class Gen {
    public:
        Gen();

        Gen(uint32_t in, uint32_t out);

        // Overloading operator.
        inline bool operator<(const Gen &gen) const {
            if (in < gen.in) {
                return true;
            } else if (in == gen.in) {
                return out < gen.out;
            } else {
                return false;
            }
        }

        friend class LycorisUtils;

        friend class Lycoris;

        friend class Individual;

        friend Lycoris *loadModel(const std::string &path, uint32_t capacity);

    private:
        uint32_t in;
        uint32_t out;
    };

    class Ome {
    public:
        Ome();

        Ome(float weight, uint32_t innovationNum);

        friend class LycorisUtils;

        friend class Lycoris;

        friend class Individual;

        friend Lycoris *loadModel(const std::string &path, uint32_t capacity);

    private:
        float weight;
        float delta;
        float delta_backup;
        uint32_t innovationNum;
    };

}

#endif //LYCORIS_GENOME_H
