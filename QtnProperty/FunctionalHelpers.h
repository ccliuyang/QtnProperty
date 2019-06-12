/*******************************************************************************
Copyright (c) 2012-2016 Alex Zhondin <lexxmark.dev@gmail.com>
Copyright (c) 2015-2019 Alexandra Cherdantseva <neluhus.vagus@gmail.com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#ifndef QTN_PROPERTYWIDGETAPI_H
#define QTN_PROPERTYWIDGETAPI_H

#include "Config.h"

#include <functional>

template <typename T, typename R, class... Types>
std::function<R(Types...)> qtnMemFn(T *t, R (T::*memFn)(Types...) const)
{
	return [t, memFn](Types... args) {
		return std::mem_fn(memFn)(t, std::forward<Types>(args)...);
	};
}

template <typename T, typename R, class... Types>
std::function<R(Types...)> qtnMemFn(T *t, R (T::*memFn)(Types...))
{
	return [t, memFn](Types... args) {
		return std::mem_fn(memFn)(t, std::forward<Types>(args)...);
	};
}

#endif // QTN_PROPERTYWIDGETAPI_H