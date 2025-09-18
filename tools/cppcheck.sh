#!/bin/bash
###
 # @Author: aurson jassimxiong@gmail.com
 # @Date: 2025-09-14 14:58:23
 # @LastEditors: aurson jassimxiong@gmail.com
 # @LastEditTime: 2025-09-18 15:19:36
 # @Description: 
 # Copyright (c) 2025 by Aurson, All Rights Reserved. 
 # @Author: aurson jassimxiong@gmail.com
 # @Date: 2025-09-14 17:33:37
 # @LastEditors: aurson jassimxiong@gmail.com
 # @LastEditTime: 2025-09-18 15:16:46
 # @Description:
 # Copyright (c) 2025 by Aurson, All Rights Reserved.
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
###
tool_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_dir="${tool_dir}/.."
build_dir="${project_dir}/build"
build_type="Release"
report_xslt="${tool_dir}/cppcheck.xslt"
report_xml="${build_dir}/${build_type}/cppcheck.xml"
report_html="${build_dir}/${build_type}/cppcheck.html"
toolchain_file="${project_dir}/cmake/toolchain/ToolchainX64.cmake"

cmake -B "${build_dir}/${build_type}" \
      -DENABLE_CPPCHECK=ON \
	  -DCPPCHECK_REPORT_XML="$report_xml" \
      -DCMAKE_TOOLCHAIN_FILE="${toolchain_file}" \
      -DCMAKE_BUILD_TYPE="${build_type}" \
      "${project_dir}" || return 1
cmake --build "${build_dir}/${build_type}" --parallel || return 1
cmake --build "${build_dir}/${build_type}" --target pack --parallel || return 1



# 生成报告
xsltproc "$report_xslt" "$report_xml" > "$report_html" || exit
echo "静态分析报告: $report_html"
# 浏览报告
/bin/python3 << !EOF!
import os, webbrowser, sys
try:
	from urllib import pathname2url
except:
	from urllib.request import pathname2url
def main():
    webbrowser.open("file://" + pathname2url(os.path.abspath("$report_html")))
main()
!EOF!
