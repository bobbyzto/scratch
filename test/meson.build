project('testsuite', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

incdir = include_directories('include')

exe = executable('testsuite', 'testsuite.c',
  include_directories : incdir)

test('basic', exe)
