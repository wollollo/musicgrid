// assert.h
// Somewhat flexible asserts
//
// Taken from [Stroustrup, TC++PL4 13.4]
// with change: dynamic(false) triggers exception/terminate; S has dynamic(true)

// Usage:   (e.g. n must be in [0,max) )
// (CURRENT_MODE & CURRENT_LEVEL must be set in build environment.)
// Assert::dynamic<Assert::level(2), Assert::Error>(
//    ( n>=0 && n<max ), Assert::compose(__FILE__, __LINE__, "range problem"));
// or accepting defaults, and using Assert::dynamic
// dynamic( n>=0 && n<max );

// Also consider GSL.assert

#include <sstream>
#include <stdexcept>

//#define CURRENT_MODE = throw_ //DEBUG -- remove these, should be done by
//#define CURRENT_LEVEL = 1 //DEBUG        compiler / environment

namespace Assert {
  enum class Mode {throw_,terminate_,ignore_};
  constexpr Mode current_mode = CURRENT_MODE;
  constexpr int current_level = CURRENT_LEVEL;
  constexpr int default_level = 1;

  constexpr bool level(int n){
      return n <= current_level;
  }

  struct Error : std::runtime_error {
      Error(const std::string& p) : runtime_error(p) {}
  };

  std::string compose(const char* file, int line, const std::string& message) {
      std::ostringstream os;
      os << "(" << file << "," << line <<"): " << message;
      return os.str();
  }

  template<bool condition =level(default_level), class Except = Error>
  void dynamic(bool assertion, const std::string& message ="Assert::dynamic failed") {
      if(assertion)
          return;
      if(current_mode == Mode::throw_)
          throw Except(message);
      if (current_mode == Mode::terminate_)
          std::terminate();
  }

  template<>
  void dynamic<false,Error>(bool,const std::string&) {} // do nothing

  void dynamic(bool b, const std::string& s) { // use default error, no level checking
      dynamic<true,Error>(b,s);
  }

  void dynamic(bool b) { // no level check, default error & message
      dynamic<true,Error>(b);
  }

}
