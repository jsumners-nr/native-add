#include <node_api.h>


napi_value Add(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 2;
  napi_value argv[2];
  int32_t a;
  int32_t b;

  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to parse arguments");
  }

  status = napi_get_value_int32(env, argv[0], &a);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to get arg1");
  }
  status = napi_get_value_int32(env, argv[1], &b);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to get arg2");
  }

  int32_t sum = a + b;
  napi_value result;
  status = napi_create_int32(env, sum, &result);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to create result");
  }

  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;

  napi_value fn;
  status = napi_create_function(env, "sum", 3, Add, NULL, &fn);
  if (status != napi_ok) return NULL;

  status = napi_set_named_property(env, exports, "add", fn);
  if (status != napi_ok) return NULL;

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);
// const { add } = require('@jsumners/native-add')
// const result = add(1, 1)
// console.log(result) // 2
