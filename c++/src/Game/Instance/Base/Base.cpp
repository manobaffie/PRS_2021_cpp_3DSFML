#include "Base.hpp"

Game::Instance::Base::Base():
    thread(&Base::loop, this)
{
}

Game::Instance::Base::Base(std::chrono::microseconds clock):
    _clock(clock),
    thread(&Base::loop, this)
{
}

Game::Instance::Base::~Base()
{
}

void Game::Instance::Base::loop()
{
    std::unique_lock<std::mutex> lk(this->_mutex);

    while (this->isRunning() && this->_running) {
        while (!this->_ready) this->_cv.wait(lk);
         this->main();
        this->frequency();
    }

}

void Game::Instance::Base::start()
{
    std::unique_lock<std::mutex> lk(this->_mutex);
    this->_ready = true;
    this->_cv.notify_all();
}

void Game::Instance::Base::stop()
{
    this->_running = false;
}

void Game::Instance::Base::wait()
{
    this->_ready = false;
}

bool Game::Instance::Base::isRunning()
{
    return this->_running;
}

void Game::Instance::Base::frequency()
{
    std::this_thread::sleep_for(this->_clock);
}