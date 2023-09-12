#ifndef GameInstanceBase_HPP_
#define GameInstanceBase_HPP_

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

namespace Game
{
    namespace Instance 
    {
        class Base
        {
            private:
                bool _ready = false;
                bool _running = true;
                std::mutex _mutex;
                std::condition_variable _cv;
                std::chrono::microseconds _clock;
            public:
                std::thread thread;
            private:
                void loop();
            public:
                Base();
                Base(std::chrono::microseconds clock);
                ~Base();
            public:
                void start();
                void wait();
                void stop();
                virtual bool isRunning();
                virtual void frequency();
                virtual void main() = 0;
        };
    }
}

#endif