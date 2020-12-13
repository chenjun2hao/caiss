/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: TimerProc.h
@Time: 2020/12/13 8:23 下午
@Desc: 
***************************/

#ifndef CAISS_TIMERPROC_H
#define CAISS_TIMERPROC_H

#include <time.h>
#include <string>
#include "../UtilsProc.h"

class AlgoTimerProc : public UtilsProc {
public:
    explicit AlgoTimerProc (const std::string &algoType) {
        algo_time_cost_ = 0;
        func_time_cost_ = 0;
        this->algo_type_ = algoType;
    }

    void startFunc() {
        algo_time_cost_ = 0;    // 从这个函数之后，计时重新开始
        func_time_cost_ = 0;
        func_start_ = clock();
    }

    void startAlgo() {
        algo_start_ = clock();
    }

    void appendAlgo() {
        algo_time_cost_ += (clock() - algo_start_);
    }

    void endFunc() {
        func_time_cost_ = clock() - func_start_;
    }

    int getAlgoTimeCost() {
        return algo_time_cost_ / 1000;    // 原单位为微秒，转成毫秒
    }

    int getFuncTimeCost() {
        return func_time_cost_ / 1000 + 1;    // 人为加1ms
    }

    const char* getAlgoType() {
        return algo_type_.c_str();
    }

private:
    clock_t func_start_;
    clock_t algo_start_;

    int algo_time_cost_;
    int func_time_cost_;

    std::string algo_type_;
};

#endif //CAISS_TIMERPROC_H