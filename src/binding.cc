#include <nan.h>

NAN_METHOD(ResetTz) {
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  tzset();
  isolate->DateTimeConfigurationChangeNotification(v8::Isolate::TimeZoneDetection::kRedetect);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New<v8::String>("resettz").ToLocalChecked(),
           Nan::GetFunction(Nan::New<v8::FunctionTemplate>(ResetTz)).ToLocalChecked());
}

NODE_MODULE(resetv8timezone, Init)
