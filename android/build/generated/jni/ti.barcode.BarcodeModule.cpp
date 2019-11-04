/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.barcode.BarcodeModule.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "BarcodeModule"

using namespace v8;

namespace ti {
namespace barcode {


Persistent<FunctionTemplate> BarcodeModule::proxyTemplate;
jclass BarcodeModule::javaClass = NULL;

BarcodeModule::BarcodeModule() : titanium::Proxy()
{
}

void BarcodeModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Barcode"); // use symbol over string for efficiency
	MaybeLocal<Object> maybeInstance = constructor->NewInstance(context);
	Local<Object> moduleInstance;
	if (!maybeInstance.ToLocal(&moduleInstance)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}
	exports->Set(context, nameSymbol, moduleInstance);
}

void BarcodeModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> BarcodeModule::getProxyTemplate(v8::Isolate* isolate)
{
	Local<Context> context = isolate->GetCurrentContext();
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "BarcodeModule::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("ti/barcode/BarcodeModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Barcode");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		isolate,
		titanium::KrollModule::getProxyTemplate(isolate),
		javaClass,
		nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate), FunctionTemplate::New(isolate, titanium::Proxy::inherit<BarcodeModule>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "cancel", BarcodeModule::cancel);
	titanium::SetProtoMethod(isolate, t, "setUseFrontCamera", BarcodeModule::setUseFrontCamera);
	titanium::SetProtoMethod(isolate, t, "setUseLED", BarcodeModule::setUseLED);
	titanium::SetProtoMethod(isolate, t, "generateCode", BarcodeModule::generateCode);
	titanium::SetProtoMethod(isolate, t, "capture", BarcodeModule::capture);
	titanium::SetProtoMethod(isolate, t, "getUseLED", BarcodeModule::getUseLED);
	titanium::SetProtoMethod(isolate, t, "parse", BarcodeModule::parse);
	titanium::SetProtoMethod(isolate, t, "getUseFrontCamera", BarcodeModule::getUseFrontCamera);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in BarcodeModule");
		//return;
	}


			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "TELEPHONE", 3);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CONTACT", 8);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_EAN_8", 5);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_NONE", 0);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "TEXT", 4);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "GEOLOCATION", 6);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_UPC_A", 4);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "EMAIL", 7);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_QR_CODE", 1);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "URL", 1);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_CODE_128", 7);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_CODE_39", 8);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_UPC_E", 3);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_DATA_MATRIX", 2);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "SMS", 2);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_ITF", 9);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CALENDAR", 5);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "UNKNOWN", 0);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BOOKMARK", 9);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "WIFI", 10);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "FORMAT_EAN_13", 6);


	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "useFrontCamera"),
		BarcodeModule::getter_useFrontCamera,
		BarcodeModule::setter_useFrontCamera,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "useLED"),
		BarcodeModule::getter_useLED,
		BarcodeModule::setter_useLED,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);

	// Accessors --------------------------------------------------------------
	Local<String> displayedMessage = NEW_SYMBOL(isolate, "displayedMessage");
	instanceTemplate->SetAccessor(
		displayedMessage,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getDisplayedMessage", titanium::Proxy::getProperty, displayedMessage);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setDisplayedMessage", titanium::Proxy::onPropertyChanged, displayedMessage);
	Local<String> allowRotation = NEW_SYMBOL(isolate, "allowRotation");
	instanceTemplate->SetAccessor(
		allowRotation,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "getAllowRotation", titanium::Proxy::getProperty, allowRotation);
	DEFINE_PROTOTYPE_METHOD_DATA(isolate, t, "setAllowRotation", titanium::Proxy::onPropertyChanged, allowRotation);

	return scope.Escape(t);
}

Local<FunctionTemplate> BarcodeModule::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------
void BarcodeModule::cancel(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "cancel()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "cancel", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'cancel' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void BarcodeModule::setUseFrontCamera(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setUseFrontCamera()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "setUseFrontCamera", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setUseFrontCamera' with signature '(Z)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setUseFrontCamera: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	if (!args[0]->IsBoolean() && !args[0]->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
		titanium::JSException::Error(isolate, error);
		return;
	}
	
	if (!args[0]->IsNull()) {
		MaybeLocal<Boolean> arg_0 = args[0]->ToBoolean(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Boolean and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[0].z =
				titanium::TypeConverter::jsBooleanToJavaBoolean(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].z = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.useFrontCamera = value; or obj['useFrontCamera'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void BarcodeModule::setUseLED(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setUseLED()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "setUseLED", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setUseLED' with signature '(Z)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setUseLED: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	if (!args[0]->IsBoolean() && !args[0]->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
		titanium::JSException::Error(isolate, error);
		return;
	}
	
	if (!args[0]->IsNull()) {
		MaybeLocal<Boolean> arg_0 = args[0]->ToBoolean(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Boolean and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[0].z =
				titanium::TypeConverter::jsBooleanToJavaBoolean(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].z = NULL;
	}

	LOGW(TAG, "Automatic setter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please modify the property in standard JS style: obj.useLED = value; or obj['useLED'] = value;");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void BarcodeModule::generateCode(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "generateCode()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "generateCode", "(Ljava/lang/String;II)Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'generateCode' with signature '(Ljava/lang/String;II)Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 3) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "generateCode: Invalid number of arguments. Expected 3 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[3];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	
		if ((titanium::V8Util::isNaN(isolate, args[1]) && !args[1]->IsUndefined()) || args[1]->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
		if (!args[1]->IsNull()) {
		MaybeLocal<Number> arg_1 = args[1]->ToNumber(context);
		if (arg_1.IsEmpty()) {
			const char *error = "Invalid argument at index 1, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[1].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_1.ToLocalChecked());
		}
	} else {
		jArguments[1].i = NULL;
	}

	
		if ((titanium::V8Util::isNaN(isolate, args[2]) && !args[2]->IsUndefined()) || args[2]->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
		if (!args[2]->IsNull()) {
		MaybeLocal<Number> arg_2 = args[2]->ToNumber(context);
		if (arg_2.IsEmpty()) {
			const char *error = "Invalid argument at index 2, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[2].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_2.ToLocalChecked());
		}
	} else {
		jArguments[2].i = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void BarcodeModule::capture(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "capture()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "capture", "(Ljava/util/HashMap;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'capture' with signature '(Ljava/util/HashMap;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}


	jvalue jArguments[1];




	bool isNew_0;
	if (args.Length() <= 0) {
		jArguments[0].l = NULL;

	} else {
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void BarcodeModule::getUseLED(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getUseLED()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "getUseLED", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getUseLED' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	LOGW(TAG, "Automatic getter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please access the property in standard JS style: obj.useLED; or obj['useLED'];");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}
void BarcodeModule::parse(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "parse()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "parse", "(Ljava/util/HashMap;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'parse' with signature '(Ljava/util/HashMap;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "parse: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void BarcodeModule::getUseFrontCamera(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getUseFrontCamera()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "getUseFrontCamera", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getUseFrontCamera' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	LOGW(TAG, "Automatic getter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please access the property in standard JS style: obj.useFrontCamera; or obj['useFrontCamera'];");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}

// Dynamic property accessors -------------------------------------------------

void BarcodeModule::getter_useFrontCamera(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "getUseFrontCamera", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getUseFrontCamera' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}

void BarcodeModule::setter_useFrontCamera(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, useFrontCamera wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "setUseFrontCamera", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setUseFrontCamera' with signature '(Z)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	if (!value->IsBoolean() && !value->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
	}
	
	if (!value->IsNull()) {
		MaybeLocal<Boolean> arg_0 = value->ToBoolean(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Boolean and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].z = NULL;
		} else {
			jArguments[0].z =
				titanium::TypeConverter::jsBooleanToJavaBoolean(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].z = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}


void BarcodeModule::getter_useLED(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "getUseLED", "()Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getUseLED' with signature '()Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}

void BarcodeModule::setter_useLED(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, useLED wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BarcodeModule::javaClass, "setUseLED", "(Z)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setUseLED' with signature '(Z)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	if (!value->IsBoolean() && !value->IsNull()) {
		const char *error = "Invalid value, expected type Boolean.";
		LOGE(TAG, error);
	}
	
	if (!value->IsNull()) {
		MaybeLocal<Boolean> arg_0 = value->ToBoolean(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Boolean and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].z = NULL;
		} else {
			jArguments[0].z =
				titanium::TypeConverter::jsBooleanToJavaBoolean(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].z = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}



} // barcode
} // ti
