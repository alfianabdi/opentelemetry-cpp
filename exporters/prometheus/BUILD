# Copyright 2020, OpenTelemetry Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "prometheus_exporter",
    srcs = [
        "src/exporter.cc",
    ],
    hdrs = [
        "include/opentelemetry/exporters/prometheus/exporter.h",
    ],
    strip_include_prefix = "include",
    tags = ["prometheus"],
    deps = [
        ":prometheus_collector",
        ":prometheus_exporter_utils",
        "//api",
        "//sdk:headers",
        "@com_github_jupp0r_prometheus_cpp//core",
        "@com_github_jupp0r_prometheus_cpp//pull",
    ],
)

cc_library(
    name = "prometheus_exporter_utils",
    srcs = [
        "src/exporter_utils.cc",
    ],
    hdrs = [
        "include/opentelemetry/exporters/prometheus/exporter_utils.h",
    ],
    strip_include_prefix = "include",
    tags = ["prometheus"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_github_jupp0r_prometheus_cpp//core",
        "@com_github_jupp0r_prometheus_cpp//pull",
    ],
)

cc_library(
    name = "prometheus_collector",
    srcs = [
        "src/collector.cc",
    ],
    hdrs = [
        "include/opentelemetry/exporters/prometheus/collector.h",
    ],
    strip_include_prefix = "include",
    tags = ["prometheus"],
    deps = [
        ":prometheus_exporter_utils",
        "//api",
        "//sdk:headers",
        "@com_github_jupp0r_prometheus_cpp//core",
        "@com_github_jupp0r_prometheus_cpp//pull",
    ],
)

cc_library(
    name = "prometheus_test_helper",
    hdrs = [
        "test/prometheus_test_helper.h",
    ],
    tags = ["prometheus"],
    deps = [
        "//api",
        "//sdk:headers",
        "//sdk/src/trace",
    ],
)

cc_test(
    name = "prometheus_exporter_test",
    srcs = [
        "test/exporter_test.cc",
    ],
    tags = [
        "prometheus",
        "test",
    ],
    deps = [
        ":prometheus_exporter",
        ":prometheus_test_helper",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "prometheus_collector_test",
    srcs = [
        "test/collector_test.cc",
    ],
    tags = [
        "prometheus",
        "test",
    ],
    deps = [
        ":prometheus_collector",
        ":prometheus_test_helper",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "prometheus_exporter_utils_test",
    srcs = [
        "test/exporter_utils_test.cc",
    ],
    tags = [
        "prometheus",
        "test",
    ],
    deps = [
        ":prometheus_exporter_utils",
        ":prometheus_test_helper",
        "@com_google_googletest//:gtest_main",
    ],
)
