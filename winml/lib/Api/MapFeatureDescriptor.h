﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "MapFeatureDescriptor.g.h"

namespace winrt::Windows::AI::MachineLearning::implementation {
struct MapFeatureDescriptor : MapFeatureDescriptorT<
                                  MapFeatureDescriptor,
                                  ILearningModelFeatureDescriptorNative> {
  MapFeatureDescriptor() = delete;

  MapFeatureDescriptor(
      const char* name,
      const char* description,
      bool is_required,
      winml::TensorKind keyKind,
      winml::ILearningModelFeatureDescriptor valueKind);
 
  // IMapDescriptor
  winml::TensorKind
  KeyKind();

  winml::ILearningModelFeatureDescriptor
  ValueDescriptor();

  // IFeatureDescriptor
  hstring
  Name();

  hstring
  Description();

  winml::LearningModelFeatureKind
  Kind();

  bool
  IsRequired();

  STDMETHOD(GetName)
  (
      const wchar_t** name,
      uint32_t* cchName) override;

  STDMETHOD(GetDescription)
  (
      const wchar_t** description,
      uint32_t* cchDescription) override;

 private:
  winrt::hstring name_;
  winrt::hstring description_;
  bool is_required_;
  winml::TensorKind key_kind_;
  winml::ILearningModelFeatureDescriptor value_kind_;
};
}  // namespace winrt::Windows::AI::MachineLearning::implementation