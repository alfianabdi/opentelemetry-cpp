// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/sdk/trace/tracer_context_factory.h"
#include "opentelemetry/sdk/trace/multi_span_processor.h"
#include "opentelemetry/sdk/trace/aws_xray_id_generator_factory.h"
#include "opentelemetry/sdk/trace/random_id_generator_factory.h"
#include "opentelemetry/sdk/trace/samplers/always_on_factory.h"
#include "opentelemetry/sdk/trace/tracer_context.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace trace
{

std::unique_ptr<TracerContext> TracerContextFactory::Create(
    std::vector<std::unique_ptr<SpanProcessor>> &&processors)
{
  auto resource = opentelemetry::sdk::resource::Resource::Create({});
  return Create(std::move(processors), resource);
}

std::unique_ptr<TracerContext> TracerContextFactory::Create(
    std::vector<std::unique_ptr<SpanProcessor>> &&processors,
    const opentelemetry::sdk::resource::Resource &resource)
{
  auto sampler = AlwaysOnSamplerFactory::Create();
  return Create(std::move(processors), resource, std::move(sampler));
}

std::unique_ptr<TracerContext> TracerContextFactory::Create(
    std::vector<std::unique_ptr<SpanProcessor>> &&processors,
    const opentelemetry::sdk::resource::Resource &resource,
    std::unique_ptr<Sampler> sampler)
{
  // auto id_generator = RandomIdGeneratorFactory::Create();
  auto id_generator = AwsXrayIdGeneratorFactory::Create();
  return Create(std::move(processors), resource, std::move(sampler), std::move(id_generator));
}

std::unique_ptr<TracerContext> TracerContextFactory::Create(
    std::vector<std::unique_ptr<SpanProcessor>> &&processors,
    const opentelemetry::sdk::resource::Resource &resource,
    std::unique_ptr<Sampler> sampler,
    std::unique_ptr<IdGenerator> id_generator)
{
  std::unique_ptr<TracerContext> context(new TracerContext(
      std::move(processors), resource, std::move(sampler), std::move(id_generator)));
  return context;
}

}  // namespace trace
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
