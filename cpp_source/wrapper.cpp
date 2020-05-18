#include "wrapper.h"
#include <string>
using namespace Napi;
Napi::FunctionReference Wrapper::constructor;

Napi::Object Wrapper::Init(Napi::Env env, Napi::Object exports)
{

    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "SimpleMath", {
        //The names of functions that nodejs calls and what will be invoked on calls.
        InstanceMethod("add", &Wrapper::add),
        InstanceMethod("substract", &Wrapper::substract),
        InstanceMethod("multiply", &Wrapper::multiply),
        InstanceMethod("divide", &Wrapper::divide),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("SimpleMathNode", func); //We will use this name in nodejs application.
    return exports;
}

Wrapper::Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Wrapper>(info)
{
    this->simpleMath = new SimpleMath(); //Create instance only once when our node app created.
}

Napi::Value Wrapper::add(const Napi::CallbackInfo &info)
{
    try
    {
        checkParameters(info);
        int number_1 = info[0].As<Napi::Number>();
        int number_2 = info[1].As<Napi::Number>();
        int result = simpleMath->add(number_1, number_2);
        return Napi::Number::New(info.Env(), result);
    }
    catch (std::exception &e)
    {
        std::string err = "Exception handled in add: " + std::string(e.what());
        //If we want to catch exceptions thrown by cpp side in javascript side, we need to add this line. 
        Napi::Error::New(info.Env(), err).ThrowAsJavaScriptException();
        return Napi::Number::New(info.Env(), 0);
    }
}

Napi::Value Wrapper::substract(const Napi::CallbackInfo &info)
{
    try
    {
        checkParameters(info);
        int number_1 = info[0].As<Napi::Number>();
        int number_2 = info[1].As<Napi::Number>();
        int result = simpleMath->substract(number_1, number_2);
        return Napi::Number::New(info.Env(), result);
    }
    catch (std::exception &e)
    {
        std::string err = "Exception handled in substract: " + std::string(e.what());
        Napi::Error::New(info.Env(), err).ThrowAsJavaScriptException();
        return Napi::Number::New(info.Env(), 0);
    }
}

Napi::Value Wrapper::multiply(const Napi::CallbackInfo &info)
{
    try
    {
        checkParameters(info);
        int number_1 = info[0].As<Napi::Number>();
        int number_2 = info[1].As<Napi::Number>();
        int result = simpleMath->multiply(number_1, number_2);
        return Napi::Number::New(info.Env(), result);
    }
    catch (std::exception &e)
    {
        std::string err = "Exception handled in multiply: " + std::string(e.what());
        Napi::Error::New(info.Env(), err).ThrowAsJavaScriptException();
        return Napi::Number::New(info.Env(), 0);
    }
}

Napi::Value Wrapper::divide(const Napi::CallbackInfo &info)
{
    try
    {
        checkParameters(info);
        int number_1 = info[0].As<Napi::Number>();
        int number_2 = info[1].As<Napi::Number>();
        int result = simpleMath->divide(number_1, number_2);
        return Napi::Number::New(info.Env(), result);
    }
    catch (std::exception &e)
    {
        std::string err = "Exception handled in divide: " + std::string(e.what());
        Napi::Error::New(info.Env(), err).ThrowAsJavaScriptException();
        return Napi::Number::New(info.Env(), 0);
    }
}

Napi::Value Wrapper::checkParameters(const Napi::CallbackInfo &info)
{
    if (info.Length() != 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        Napi::TypeError::New(info.Env(), "Number expected").ThrowAsJavaScriptException();
        return Napi::Boolean::New(info.Env(), false);
    }
    return Napi::Boolean::New(info.Env(), true);
}
