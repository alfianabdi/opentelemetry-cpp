// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/sdk/trace/aws_xray_id_generator.h"
#include "opentelemetry/version.h"
#include "src/common/random.h"
#include <chrono>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace trace
{
namespace trace_api = opentelemetry::trace;

trace_api::SpanId AwsXrayIdGenerator::GenerateSpanId() noexcept
{
  uint8_t span_id_buf[trace_api::SpanId::kSize];
  sdk::common::Random::GenerateRandomBuffer(span_id_buf);
  return trace_api::SpanId(span_id_buf);
}

trace_api::TraceId AwsXrayIdGenerator::GenerateTraceId() noexcept
{
  uint8_t trace_id_buf[trace_api::TraceId::kSize];
  
  const auto p1 = std::chrono::system_clock::now();
  uint64_t ts = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
  uint64_t lo_rand = sdk::common::Random::GenerateRandom64();
  uint64_t hi_rand = sdk::common::Random::GenerateRandom64() & 0x00000000FFFFFFFF;
  uint64_t hi = ts << 32 | hi_rand;
  memcpy(&trace_id_buf[0], &lo_rand, sizeof(uint64_t));
  memcpy(&trace_id_buf[sizeof(uint64_t)], &hi, sizeof(uint64_t));
  for(size_t l=0,h=trace_api::TraceId::kSize-1; l < h; l++, h--) 
  {
    std::swap(trace_id_buf[l], trace_id_buf[h]);
  }
  return trace_api::TraceId(trace_id_buf);
}
}  // namespace trace
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE