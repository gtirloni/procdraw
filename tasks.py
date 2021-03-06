import itertools
import os
import sys

from invoke import Collection, task

import procdraw_utils as utils
import website


_project_dir = os.path.abspath(os.path.dirname(__file__))


@task
def check_file_headers(_):
    """
    Check the C++ source file headers
    """
    src_dir = os.path.relpath(os.path.join(_project_dir, "src"))
    files = utils.find_cpp_files([src_dir])
    reporter = utils.CheckResultTapReporter(31)
    checker = utils.Apache2HeaderChecker()
    for file in files:
        reporter.add(checker.check(file, "//"))
    reporter.print_summary()
    if reporter.is_fail():
        sys.exit(1)


@task
def format_cpp(c):
    """
    Format the C++ source files with clang-format
    """
    clang_format = c.config["procdraw"]["clang_format_name"]
    src_dir = os.path.relpath(os.path.join(_project_dir, "src"))
    files = utils.find_cpp_files([src_dir])
    utils.run(itertools.chain([clang_format, "-i", "-style=file"], files))


@task
def validate_xml(_):
    """
    Validate the docs XML
    """
    reporter = utils.CheckResultTapReporter(1)
    reporter.add(
        utils.validate_xml(os.path.join(_project_dir, "docs", "docs.rng"),
                           os.path.join(_project_dir, "docs", "docs.xml")))
    reporter.print_summary()
    if reporter.is_fail():
        sys.exit(1)


ns = Collection(check_file_headers, format_cpp, validate_xml, website)

ns.configure({
    "procdraw": {
        "clang_format_name": "clang-format",
        "web_server_address": "127.0.0.1",
        "web_server_port": 8000
    }
})
