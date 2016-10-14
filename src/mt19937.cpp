#include <chrono>
#include <random>
#include <nan.h>

static std::random_device rd;
static std::mt19937 gen{rd()};
static std::uniform_real_distribution<double> dis{0., 1.};

void rand(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
  info.GetReturnValue().Set(dis(gen));
}

void srand(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
  gen.seed(static_cast<unsigned long>(info[0]->Int32Value()));
}

void init(v8::Local<v8::Object> target)
{
  gen.seed(static_cast<unsigned long>(
    std::chrono::high_resolution_clock::now().time_since_epoch().count()));

  target->Set(Nan::New("rand").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(rand)->GetFunction());
  target->Set(Nan::New("srand").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(srand)->GetFunction());
}

NODE_MODULE(mt19937, init);
