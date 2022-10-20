#pragma once
#include <console/position.hpp>

#include <cstdint>
#include <string>

namespace console { namespace progress {
    
    enum class Status : uint8_t
    {
        Continue,
        Complete,
    };

    class ProgressIndicator
    {
    public:
        ProgressIndicator(const uint64_t max)
            : max_(max)
        {
        }

        auto count() const -> uint64_t { return count_; }
        auto max() const -> uint64_t { return max_; }
        
        auto percent() const -> uint16_t 
        {
            const double perc = 100.0 * ((double)count_ / (double)max_);
            return perc;
        }
    
    protected:
        const uint64_t max_;
        uint64_t count_ = 0;
    };
}}
