namespace Estd { // from TC++PL4e, 42.2.4
  struct guarded_thread : std::thread {
      using std::thread::thread;
      ~guarded_thread() { if (this->joinable()) this->join(); }
  };
}
