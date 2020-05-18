#include <napi.h>
#include "simple-math-node-addon/simple_math.h"

class Wrapper : public Napi::ObjectWrap<Wrapper> {

public:
    Wrapper(const Napi::CallbackInfo& info); 
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

private:
    static Napi::FunctionReference constructor; //reference to store the class definition that needs to be exported to JS
    Napi::Value add(const Napi::CallbackInfo& info);
    Napi::Value substract(const Napi::CallbackInfo& info);
    Napi::Value multiply(const Napi::CallbackInfo& info);
    Napi::Value divide(const Napi::CallbackInfo& info);
    Napi::Value checkParameters(const Napi::CallbackInfo& info);

    SimpleMath *simpleMath; //internal instance of actualclass used to perform actual operations.
};


