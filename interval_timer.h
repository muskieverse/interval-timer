#ifndef __INTERVAL_TIMER_H
#define __INTERVAL_TIMER_H

class   IntervalTimer
{
    public:
    
                        IntervalTimer();
                        IntervalTimer(unsigned long interval_ms);
                        
        bool            Expired();
        void            Reset();
        void            Start();
        
        void            SetIntervalMs(unsigned long ms);
        void            SetIntervalSec(double sec);
    
    private:

        unsigned long   interval_millis_;
        unsigned long   start_millis_;
};

#endif  /* __INTERVAL_TIMER_H */
