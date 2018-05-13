#ifndef LYCORIS_ARGS_H
#define LYCORIS_ARGS_H

#include <string>
#include <vector>
#include <thread>
#include <climits>

class Args {
public:
    Args();

    ~Args();

    float c1;
    float c2;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
    float p6;
    std::string activateFuncName;

    uint32_t mutateTime;
    uint32_t cpuNum;
    float mateOdds;
    float mutateOdds;
    uint32_t maxMutateTime;
    float distanceThreshold;
    float weightA;
    float weightB;
    float biasA;
    float biasB;

    float cleanOdds;

    float (*activateFunc)(float);

    uint32_t tock;
    std::vector<float> *gapList;
    uint32_t maxTock;
    uint32_t maxGap;
    bool memOverFlag;
    bool memLimitFlag;
    bool firstOver;
    float p1B;
    float p2B;
    float p3B;
    float p4B;
    float p5B;
    float p6B;
    float mateOddsB;
    float mutateOddsB;
    uint32_t mutateTimeB;
    bool checkFlag;
    uint32_t miss;
    uint32_t hit;
    uint32_t tick;
    uint32_t limitSize;
    bool gapListFlag;
    bool firstRun;
};

#endif //LYCORIS_ARGS_H
