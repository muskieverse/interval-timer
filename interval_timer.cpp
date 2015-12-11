#include "application.h"
#include "interval_timer.h"

IntervalTimer::IntervalTimer()
    : interval_millis_(0)
    , start_millis_(0)
{
}

IntervalTimer::IntervalTimer(unsigned long interval_ms)
    : interval_millis_(interval_ms)
    , start_millis_(0)
{
    Reset();
}

void    IntervalTimer::SetIntervalMs(unsigned long ms)
{
    interval_millis_ = ms;
}

void    IntervalTimer::SetIntervalSec(double sec)
{
    SetIntervalMs((unsigned long) (sec * 1000.0));
}

void    IntervalTimer::Start()
{
    Reset();
}

void    IntervalTimer::Reset()
{
    start_millis_   = millis();
}

bool    IntervalTimer::Expired()
{
    bool            expired     = false;
    unsigned long   now_millis  = millis();
    
    // By using unsigned subtraction without regard for overflow, wrap is accounted for.
    
    if ((now_millis - start_millis_) > interval_millis_)
    {
        expired = true;
    }

    return (expired);
}
