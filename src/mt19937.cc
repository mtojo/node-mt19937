#include <ctime>
#include <boost/random.hpp>
#include <node.h>

boost::mt19937 eng;
boost::uniform_real<double> dst(0.0, 1.0);
boost::variate_generator<
  boost::mt19937&, boost::uniform_real<double> > gen(eng, dst);

v8::Handle<v8::Value> rand(const v8::Arguments& args)
{
  v8::HandleScope scope;
  return scope.Close(v8::Number::New(gen()));
}

v8::Handle<v8::Value> srand(const v8::Arguments& args)
{
  v8::HandleScope scope;
  eng.seed(static_cast<unsigned long>(args[0]->Int32Value()));
  return scope.Close(v8::Undefined());
}

extern "C"
void init(v8::Handle<v8::Object> target)
{
  v8::HandleScope scope;

  eng.seed(static_cast<unsigned long>(time(0)));

  target->Set(v8::String::New("rand"),
    v8::FunctionTemplate::New(rand)->GetFunction());

  target->Set(v8::String::New("srand"),
    v8::FunctionTemplate::New(srand)->GetFunction());
}

NODE_MODULE(mt, init);
