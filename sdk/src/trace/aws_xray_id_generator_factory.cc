// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/sdk/trace/aws_xray_id_generator_factory.h"
#include "opentelemetry/sdk/trace/aws_xray_id_generator.h"
#include "opentelemetry/version.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace trace
{

std::unique_ptr<IdGenerator> AwsXrayIdGeneratorFactory::Create()
{
  std::unique_ptr<IdGenerator> id_generator(new AwsXrayIdGenerator());
  return id_generator;
}

}  // namespace trace
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
