#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  int sum;
  sum = info[0]->Int32Value(context).FromMaybe(0) +
    info[1]->Int32Value(context).FromMaybe(0);

  info.GetReturnValue().Set(Nan::New(sum));
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->GetCreationContext().ToLocalChecked();

  exports->Set(
    context,
    Nan::New("add").ToLocalChecked(),
    Nan::New<v8::FunctionTemplate>(Add)->GetFunction(context).ToLocalChecked()
  );
}

NODE_MODULE(native_add, Init)
// const { add } = require('@jsumners/native-add')
// const result = add(1, 1)
// console.log(result) // 2
