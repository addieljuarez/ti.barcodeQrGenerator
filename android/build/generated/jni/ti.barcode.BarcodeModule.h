/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace ti {
namespace barcode {

class BarcodeModule : public titanium::Proxy
{
public:
	explicit BarcodeModule();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Local<v8::Context>);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void cancel(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setUseFrontCamera(const v8::FunctionCallbackInfo<v8::Value>&);
	static void setUseLED(const v8::FunctionCallbackInfo<v8::Value>&);
	static void generateCode(const v8::FunctionCallbackInfo<v8::Value>&);
	static void capture(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getUseLED(const v8::FunctionCallbackInfo<v8::Value>&);
	static void parse(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getUseFrontCamera(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------
	static void getter_useFrontCamera(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_useFrontCamera(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void getter_useLED(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info);
	static void setter_useLED(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);

};

} // barcode
} // ti
